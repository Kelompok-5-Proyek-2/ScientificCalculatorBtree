#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "daniar.h"

address alokasi (char item)
{
	/* Kamus Lokal */
	address P;
	/* Algoritma */
	P = (address) malloc (sizeof (ElmtList));
	if (P != NULL)		/* Alokasi berhasil */
	{
		P->info = item;
		P->next = NULL;
	}
	return (P);
}

void createStack(Stack *L){
	(*L).Top = NULL;
}

void push(Stack *L, char item){
	address P, Q;
	P = alokasi(item);
	Q = (*L).Top;
	if(P!=NULL){
		P->next = Q;
		(*L).Top = P; 
	}
}

void pop(Stack *L){
	address temp;
	temp = (*L).Top;
	if(temp == NULL){
		printf("Underflow\n");
	}
	else{
		
		if(temp->next ==NULL){
			(*L).Top = NULL;
		}else{
			(*L).Top = temp->next;
		}
		free(temp);
	}
}

void printStack(Stack L){
	address P;
	P = L.Top;
	printf("Isi Dari Stack : \n");
	while(P!=NULL){
		printf("|%c|\n", P->info);
		P = P->next;
	}
}
int sizeOperat(Stack L){
    address P;
    P = L.Top;
    int count = 0;
    while(P!=NULL){
        count++;
        P = P->next;
    }
    return count;
}

bool isEmpty(Stack L) {
    return (L.Top == NULL);
}

//Operand Stack
OpAddress alokasi (double item)
{
	/* Kamus Lokal */
	OpAddress P;
	/* Algoritma */
	P = (OpAddress) malloc (sizeof (OperandList));
	if (P != NULL)		/* Alokasi berhasil */
	{
		P->info = item;
		P->next = NULL;
	}
	return (P);
}

void createOperandStack(OperandStack *L){
	(*L).Top = NULL;
}

void pushOperand(OperandStack *L, double item){
	OpAddress P, Q;
	P = alokasi(item);
	Q = (*L).Top;
	if(P!=NULL){
		P->next = Q;
		(*L).Top = P; 
	}
}

void popOperand(OperandStack *L){
	OpAddress temp;
	temp = (*L).Top;
	if(temp == NULL){
		printf("Underflow\n");
	}
	else{
		(*L).Top = temp->next;
		free(temp);
	}
}

void printOperandStack(OperandStack L){
	OpAddress P;
	P = L.Top;
	printf("Isi Dari Stack : \n");
	while(P!=NULL){
		printf("|%g|\n", P->info);
		P = P->next;
	}
}

int sizeOperand(OperandStack L){
    OpAddress P;
    P = L.Top;
    int count = 0;
    while(P!=NULL){
        count++;
        P = P->next;
    }
    return count;
}
