#include <stdlib.h>
#include <stdio.h>
#include "Syaiful.h"
#include "adhiya.h"
#include "barry.h"
#include "daniar.h"
#include <stdbool.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int prioritas(char operat) {
    
    if (operat == '+' || operat == '-')
        return 1;
    else if (operat == '*' || operat == '/')
        return 2;
    else if (operat == '^' || operat =='V')
        return 3;
    else if (operat == '(' || operat == ')')
        return 0; 
    else if (operat =='=' || operat=='>' || operat =='<')
    	return 0;
    else
        return -1;
        exit(1);
    
}

bool isNegative(char input[], int i){
	if(input[i]=='-' && !isdigit(input[i++])){
		return true;
	}else{
		return false;
	}
}

int main(int argc, char** argv) {
	char input[100];
	bool cekNegative;
	OperandStack operand;
	Stack operat;
	createOperandStack(&operand);
	createStack(&operat);
	
	system("cls");
    printf("\tKalkulator Scientific Kelompok 5\n\n");
    printf("Input : ");
	scanf("%s", &input);
	for (int i = 0; input[i]; i++){
		if (isdigit(input[i])) {
            char number[100];
            int number_top = 0;
            while (isdigit(input[i]) || input[i] == '.') {
				number[number_top++] = input[i++];
            }
            number[number_top] = '\0';
            pushOperand(&operand, atof(number));
            i--;
        }
		else{
			push(&operat, input[i]);
		}
		
	}
	printOperandStack(operand);
	printStack(operat);
	return 0;
}
