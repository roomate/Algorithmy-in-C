#ifndef HUFFTREE_H
#define HUFFTREE_H
struct huff_node_t {
	unsigned int occurence;
	unsigned char letter;
	struct huff_node_t* left;
	struct huff_node_t* right;
};

struct list_occ {
	unsigned int previous_index;
	int occ;
};

void insertion_sort(struct list_occ** liste);
struct huff_node_t* build_tree(char* fname);
int Huffman_coding(char* fname, char* out, char** code);
void free_tree(struct huff_node_t*);
#endif