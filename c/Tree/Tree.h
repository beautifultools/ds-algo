#pragma once

typedef int t_data;
typedef struct _node {
	t_data data;
	struct _node* left;
	struct _node* right;
} Node;


typedef struct _tree {
	Node* root;
} Tree;

Tree* make_init_tree();
int insert_tree(Tree*, t_data);
int del_tree(Tree*, t_data);
t_data find(Tree*, t_data);
int is_empty(Tree*);
void traverse_pre(Node*);
void traverse_in(Node*);
void traverse_post(Node*);
void traverse_for_pre(Node*);
void traverse_for_in(Node*);
void traverse_for_post(Node*);
void destroy_tree(Tree*);

