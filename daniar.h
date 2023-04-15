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
void pop (Stack *L);
void printStack(Stack L);
int size(Stack L);
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
void popOperand (OperandStack *L);
void printOperandStack(OperandStack L);


//Btree handling
typedef struct bstnode *Node;

typedef struct bstnode {
    infotype info;
    Node left;
    Node right;
} btree;

typedef struct{
	Node pointer;
} bstree;


void CalArit();
void mainMenu();

int prioritas(char operat);

bool isNegative(char input[], int i);

bool isOperator(char op);

#endif