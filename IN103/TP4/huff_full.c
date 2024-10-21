#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hufftree.h"
#include "code.h"
#include "encode.h"
#include "decode.h"
#include "freq.h"

/** \brief Libération de la mémoire utiliser par un arbre. La fonction procède
    en libérant récursivement les fils gauche et droite avant de libérer le
    noeud courant.
    \param tree : Pointeur sur l'arbre à libérer. */
void free_tree (struct huff_node_t *tree)
{
  if (tree != NULL) {
    free_tree (tree->left) ;
    free_tree (tree->right) ;
    free (tree) ;
  }
}

/** \brief Construction de l'arbre de Huffman associé au fichier dont le nom
    est passé en argument.
    \param fname : Nom du fichier à analyser et pour lequel créer l'arbre.
    \return Le pointeur sur l'arbre créé ou NULL si une erreur s'est produite
    durant le traitement. L'arbre obtenu devra être libéré ultérieurement en
    fin d'utilité. */
struct huff_node_t* build_tree(char* fname)
{
  FILE* file = fopen(fname, "rb");
  struct huff_node_t *trees[256];
  struct huff_node_t *min_tree1; struct huff_node_t* min_tree2;
  int nb_tree;
  unsigned int min;

  unsigned int *occs_table = get_occs_table(fname);
  if (occs_table == NULL) {printf("Error"); exit(1);}

  for (int i = 0; i < 256; ++i)
  {
    trees[i] = malloc(sizeof(struct huff_node_t));
    if (trees[i] == NULL) 
    {
    printf("Error. Memory no allocated.\n");
    for (int j = i - 1; j >= 0; j--) {free(trees[j]);}
    free(occs_table);
    return NULL;
    }
    trees[i]->letter = (char) i;
    trees[i]->left = NULL;
    trees[i]->right = NULL;
    trees[i]->occurence = occs_table[i];
  }
  nb_tree = 256;
  /*Combine the two smallest trees until one tree is left.*/
  while (nb_tree > 1)
  {
    min = 0;
    for (int i = 0; i < nb_tree; i++) {if (trees[i]->occurence < trees[min]->occurence) min = i;}
    min_tree1 = trees[min];
    trees[min] = trees[nb_tree - 1]; /*get rid of this tree*/
    nb_tree--;

    min = 0;
    for (int i = 0; i < nb_tree; i++) {if (trees[i]->occurence < trees[min]->occurence) min = i;}
    min_tree2 = trees[min];

    trees[min] = malloc(sizeof(struct huff_node_t));
    if (trees[min] == NULL) {return NULL;}
    trees[min]->left = min_tree1;
    trees[min]->right = min_tree2;
    trees[min]->occurence = min_tree1->occurence + min_tree2->occurence;
  }
  return trees[0];
}