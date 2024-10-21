#include <stdio.h>
#include <stdbool.h>



/** \details Encodage du fichier \a in_fname selon la table de codes de Huffman
    \a codes et �criture du r�sultat dans le fichier \a out_fname.
    \param in_fname : Fichier source � lire et � encoder.
    \param out_fname : Fichier destination dans lequel �crire le r�sultat de
    l'encodage.
    \param codes : Table des codes de Huffman construite � partir de l'analyse
    du fichier source \a in_fname � encoder.
    \return Bool�en disant si l'encodage s'est pass� sans erreur. */
bool encode (char *in_fname, char *out_fname, char **codes)
{
  FILE *in, *out ;
  int c ;

  in = fopen (in_fname, "rb") ;
  if (in == NULL) {
    printf ("Error. Unable to open input file '%s'.\n", in_fname) ;
    return (false) ;
  }

  out = fopen (out_fname, "wb") ;
  if (out == NULL) {
    printf ("Error. Unable to open output file '%s'.\n", out_fname) ;
    fclose (in) ;
    return (false) ;
  }

  /* Lecture caract�re par caract�re du fichier d'entr�e. */
  c = fgetc (in) ;
  while (c != EOF) {
    fprintf (out, "%s", codes[c]) ;
    c = fgetc (in) ;
  }

  fclose (in) ;
  fclose (out) ;
  return (true) ;
}
