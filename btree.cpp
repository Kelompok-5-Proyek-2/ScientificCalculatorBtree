#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "daniar.h"

Node create_node(double operand, char operat){
	Node new_node = (Node)malloc(sizeof(struct bstnode));
	new_node->operand = operand;
	new_node->operat = operat;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

Node insert_tree(Node root, double operand1, double operand2, char operat) {
    if (root == NULL) {
        root = create_node(0, operat);
        root->left = create_node(operand1, 'l');
        root->right = create_node(operand2, 'l');
        return root;
    }

    if (operat == '+' || operat == '-') {
        if (root->operat == '*' || root->operat == '/') {
            root->right = insert_tree(root->right, operand1, operand2, operat);
        } else {
            Node new_node = create_node(0, operat);
            new_node->left = create_node(operand1, 'l');
            new_node->right = create_node(operand2, 'l');
            new_node->left = root;
            return new_node;
        }
    } else if (operat == '*' || operat == '/') {
        root->right = insert_tree(root->right, operand1, operand2, operat);
    }

    return root;
}


void traverse_preorder(Node node) {
    if (node == NULL) {
        return;
    }
    if(node->operat != 'l'){
    	printf("%c ", node->operat);
	}
    if(node->operand != 0){
    	printf("%g ", node->operand);
	}
    traverse_preorder(node->left);
    traverse_preorder(node->right);
}
