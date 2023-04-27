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

Node insert_tree(Node root, double operand, char operat) {
	if(root == NULL){
		return create_node(operand, operat);
	}
	
	if(root->left==NULL){
		root->left = insert_tree(root->left, operand, operat);
	}else if(root->left != NULL){
//		if (operand < root->left->operand && operat =='e') {
//            double temp = root->left->operand;
//            root->left->operand = operand;
//            operand = temp;
//        }
        root->right = insert_tree(root->right, operand, operat);
	}else{
		return root;
	}
	return root;
}

//void BtreeCalc(Node *root){
//	Node *temp = root;
//	do{
//		if((*root)->right !=NULL){
//			while((*root)->right->operat != 'e'){
//				(*root) = (*root)->right;
//			}
//			(*root)->operand = kalkulasi((*root)->right->operand, (*root)->left->operand, (*root)->operat);
//			(*root)->operat = 'e';
//			(*root)->left = NULL;
//			(*root)->right = NULL;
//			(*root) = *temp;
//		}
//	}while((*root)->operat != 'e');
//}

double BtreeCalc(Node root){
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->operand;
    }
    char operat = root->operat;
    root->operat = 'e';
    double left = BtreeCalc(root->left);
    double right = BtreeCalc(root->right);
    return kalkulasi(right, left, operat);	
}

void freeTree(Node *root) {
    if (*root == NULL) {
        return;
    }
    freeTree(&(*root)->left);
    freeTree(&(*root)->right);
    free(*root);
}


void traverse_preorder(Node node) {
    if (node == NULL) {
        return;
    }
    if(node->operat != 'e'){
    	printf("%c ", node->operat);
	}
    if(node->operand != 0){
    	printf("%g ", node->operand);
	}
    traverse_preorder(node->left);
    traverse_preorder(node->right);
}
