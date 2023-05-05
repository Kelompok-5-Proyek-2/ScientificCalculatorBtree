#ifndef daniar_h
#define daniar_H
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

typedef char* infotype;
//stack handling
typedef struct tElmtList *address;
typedef struct tElmtList {
	 char info;
	 address  next;
} ElmtList;

typedef struct {
	  address Top;
} Stack;

address alokasi(char item);
void createStack(Stack *L);
void push(Stack *L,char item);
/*
operator_stack[++operator_top] = atof(number) == push(&operator_stack, input[i])
*/
void pop (Stack *L);
/*
operator_stack[operator_top--] = atof(number) == push(&operator_stack)
*/
void printStack(Stack L);
int sizeOperat(Stack L);
bool isEmpty(Stack L);

typedef struct OperandList *OpAddress;
typedef struct OperandList {
	 double info;
	 OpAddress  next;
} OpList;

typedef struct {
	  OpAddress Top;
} OperandStack;

OpAddress OperandAlokasi(double item);
void createOperandStack(OperandStack *L);
void pushOperand(OperandStack *L, double item);
/*
operand_stack[++operand_top] = atof(number) == pushOperand(&operand_stack, atof(number))
*/
void popOperand (OperandStack *L);
/*
operand_stack[operand_top--] == popOperand(&operand_top)
*/
void printOperandStack(OperandStack L);
int sizeOperand(OperandStack L);


//Btree handling
typedef struct bstnode *Node;

typedef struct bstnode {
    char operat;
    double operand;
    Node left;
    Node right;
} btree;

typedef struct{
	Node pointer;
} bstree;

Node insert_tree(Node root, double operand, char operat);
Node create_node(double operand, char operat);
void traverse_preorder(Node node);
void freeTree(Node *root);
double BtreeCalc(Node root);


//calculation handling;
void CalArit();
void mainMenu();
int prioritas(char operat);
double kalkulasi(double operand1, double operand2, char operat);
bool isNegative(char input[], int i);
bool isOperator(char op);

#endif
