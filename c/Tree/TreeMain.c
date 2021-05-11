#include <stdio.h>
#include "Tree.h"

int main() {
	Tree* tree = make_init_tree();
	insert_tree(tree, 7);
	insert_tree(tree, 3);
	insert_tree(tree, 4);
	insert_tree(tree, 5);
	insert_tree(tree, 10);
	insert_tree(tree, 9);
	insert_tree(tree, 8);
	insert_tree(tree, 11);

	printf("### pre\n");
	traverse_pre(tree->root);
	traverse_for_pre(tree->root);
	printf("### in\n");
	traverse_in(tree->root);
	traverse_for_in(tree->root);
	printf("### post\n");
	traverse_post(tree->root);
	traverse_for_post(tree->root);
	
	destroy_tree(tree);
}