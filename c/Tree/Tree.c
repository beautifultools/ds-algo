#include <stdio.h>
#include "Tree.h"
#include "StackForTree.h"


Tree* make_init_tree() {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}

int insert_tree(Tree* tree, t_data data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	Node** temp = &(tree->root);

	while (*temp)
	{
		if ((*temp)->data > data)
			temp = &((*temp)->left);
		else if ((*temp)->data < data)
			temp = &((*temp)->right);
		else
			return 0;
	}

	*temp = new_node;
	return 1;
};


int del_tree(Tree* tree, t_data data) {
	Node** temp = &(tree->root);

	while (*temp) {
		if ((*temp)->data > data)
			temp = &((*temp)->left);
		else if ((*temp)->data < data)
			temp = &((*temp)->right);
		else
		{
			*temp = NULL;
			return 1;
		}
	}
	return 0;
};

t_data find(Tree* tree, t_data data) {
	Node** temp = &(tree->root);

	while (*temp) {
		if ((*temp)->data > data)
			temp = &((*temp)->left);
		else if ((*temp)->data < data)
			temp = &((*temp)->right);
		else
			return (*temp)->data;
	}
	return NULL;
};

void traverse_pre(Node* node) {
	if (!node)
		return;
	printf("%d\n", node->data);
	traverse_pre(node->left);
	traverse_pre(node->right);
}

void traverse_in(Node* node) {
	if (!node)
		return;
	traverse_in(node->left);
	printf("%d\n", node->data);
	traverse_in(node->right);
}


void traverse_post(Node* node) {
	if (!node)
		return;
	traverse_post(node->left);
	traverse_post(node->right);
	printf("%d\n", node->data);
}


void traverse_for_pre(Node* node) {
	printf("### for pre\n");
	Stack* stack = init_stack();
	push_stack(stack, node);

	while (!is_empty_stack(stack)) {
		Node* tmp = pop_stack(stack);
		printf("%d\n", tmp->data);

		if (tmp->right != NULL) {
			push_stack(stack, tmp->right);
		}

		if (tmp->left != NULL) {
			push_stack(stack, tmp->left);
		}
	}
	destroy_stack(stack);
}

void traverse_for_in(Node* node) {
	printf("### for in\n");
	Stack* stack = init_stack();
	push_stack(stack, node);
	Node* pop_stack_tmp = NULL;
	while (!is_empty_stack(stack)) {
		Node* tmp = peek_stack(stack);
		if (tmp->left == NULL
			|| tmp->left == pop_stack_tmp
			|| (pop_stack_tmp != NULL && tmp->right != pop_stack_tmp && pop_stack_tmp->right != tmp)) {
			pop_stack_tmp = pop_stack(stack);
			printf("%d\n", pop_stack_tmp->data);
			if (tmp->right != NULL) {
				push_stack(stack, tmp->right);
			}
			continue;
		}

		push_stack(stack, tmp->left); // tmp->left is not null because it's checked already.
		
	}
	destroy_stack(stack);
}

void traverse_for_post(Node* node) {
	printf("### for post\n");
	Stack* stack = init_stack();
	push_stack(stack, node);
	Node* pop_stack_tmp = NULL;
	while (!is_empty_stack(stack)) {
		Node* tmp = peek_stack(stack);

		if ((tmp->right == NULL && tmp->left == NULL)
			|| (tmp->right == pop_stack_tmp)
			|| (tmp->left == pop_stack_tmp && tmp->right == NULL)) {
			pop_stack_tmp = pop_stack(stack);
			printf("%d\n", pop_stack_tmp->data);
			continue;
		}

		if (tmp->right != NULL) {
			push_stack(stack, tmp->right);
		}

		if (tmp->left != NULL) {
			push_stack(stack, tmp->left);
		}
	}
	destroy_stack(stack);
}

void trv_destroy(Node* node) {
	if (!node)
		return;
	trv_destroy(node->left);
	trv_destroy(node->right);
	free(node);
}

void destroy_tree(Tree* tree) {
	trv_destroy(tree->root);
};