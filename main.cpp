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

double kalkulasi(double operand1, double operand2, char operat){
	if(isOperator(operat)){
		switch (operat) {
        case '^':
            return exponent(operand2, operand1);
        case '*':
            return operand2 * operand1;
        case '/':
            return operand2 / operand1;
        case '+':
            return operand2 + operand1;
        case '-':
            return operand2 - operand1;
        case 'V':
        	return sqroot(operand2, operand1);
        case '=':
        	return sama(operand2, operand1);
        case '>':
        	return lebih_besar(operand2,operand1);
        default:
            return lebih_kecil(operand2,operand1);
    	}
	}else{
		printf("Invalid Operator %c\n", operat);
		return 0;
	}
}

bool isOperator(char op){
	if(op=='+' || op=='-' || op=='*' || op =='/' || op =='V' || op == '>' || op =='<' || op=='=' || op =='^' || op=='(' || op ==')'){
		return true;
	}else{
		return false;
	}
}

bool isNegative(char input[], int i){
	if(input[i]=='-' && !isdigit(input[i++])){
		return true;
	}else{
		return false;
	}
}

int main(int argc, char** argv) {
	tampilan();
	char input[100], op;
	bool cekNegative;
	OperandStack operand, insertOperand;
	Stack operat, insertOperat;
	double bil1, bil2;
	createOperandStack(&operand);
	createStack(&operat);
	
	//input handling
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
		else if (input[i]=='(' &&  input[i+1] == '-'){
			//printOperandStack(operand);
        	char number[100];
        	int k;
        	k = i+2;
            int number_top = 0;
            while ((isdigit(input[k]) || input[k] == '.') && input[k]!=')') {
				number[number_top++] = input[k++];	
            }
            number[number_top] = '\0';
            pushOperand(&operand, -1*atof(number));
            i = k--;
		}
		else if (input[i] == '(' && !isNegative(&input[i+1], i)) {
            push(&operat, input[i]);
        }
		else if (input[i] == ')') {
            while (operat.Top->info != '(') {
                double bil2 = operand.Top->info;
				popOperand(&operand);
				double bil1 = operand.Top->info;
				popOperand(&operand);
				char op = operat.Top->info;
				pop(&operat);
				pushOperand(&operand, kalkulasi(bil2,bil1, op));
                if(sizeOperand(operand)==0){
                	break;
				}
            }
            pop(&operat);
        }
        else if(input[i]=='!'){
			int j = i - 1;
			int k;
			//char number[100];
			double bil;
			int result;
			int index = 0;
			while (j >= 0 && isdigit(input[j])) {
			    j--;
			}
			for (k = j + 1; k < i; k++) {
			   // number[index] = input[k];
			    index++;
			}
		    //pushOperand(&operand, atof(number));
			bil = operand.Top->info;   
			result = faktorial(bil);
			popOperand(&operand);
			//popOperand(&operand);
			pushOperand(&operand,(double)result);
			//printOperandStack(operand);
		}
		else if (input[i] == 'l'){
	        	char log[4];
	        	int j=0;
	        	char temp[1], temp2[1];
	        	char number[100];
	        	int number_top = 0;
	        	temp[0] = input[i-1];
	        	while(input[i] != ')' && (input[i] != '+' || input[i] != '-' || input[i] != '*' || input[i] != '/') && input[i] != ' '){
	        		if(isdigit(input[i]) || input[i] == '.'){
	        			number[number_top++] = input[i++];
					}else {
				        log[j++] = input[i++];
				        log[4] = '\0';
				    }
				}
				number[number_top] = '\0';
				if(strcmp(log, "log(")){
					printf("invalid expression, maybe input = 'log()'?\n");
				}else{
					if(j!=4){
					printf("Invalid expression for logaritma, example 'log(10) or 2log(4) and input number should be greater than 0'\n");
					}else{
						
						//operand_stack[++operand_top] = atof(number);
						pushOperand(&operand, atof(number));
					//	printOperandStack(operand);
						bil2 = operand.Top->info;
						popOperand(&operand);
						if(bil2 <= 0) {
				            printf("Invalid expression for logaritma, the input number should be greater than 0\n");
				        }
						else if(!isdigit(temp[0])){
							pushOperand(&operand,logbase(bil2, 10));
						}else{
							bil1 = operand.Top->info;
							popOperand(&operand);
							pushOperand(&operand,logbase(bil2, bil1));
						}
					
					}	
				}
			}
			
		else{
			if(!isdigit(input[i]) && !isdigit(input[i+1]) && input[i+1] !='(' && input[i+1]!='[' && input[i+1]!='|' && input[i+1]!= 'l' && input[i+1]!='s' && input[i+1]!='c' && input[i+1]!='t'){
				printf("The operator is incorrect, the '%c' and '%c' operators should not be adjacent to each other\n", input[i], input[i+1]);
			}
			else{
				while (sizeOperat(operat)>0 && (prioritas(operat.Top->info) >= prioritas(input[i])) && sizeOperand(operand)>1) {
					double bil2 = operand.Top->info;
					popOperand(&operand);
					double bil1 = operand.Top->info;
					popOperand(&operand);
					char op = operat.Top->info;
					pop(&operat);
					pushOperand(&operand, kalkulasi(bil2,bil1, op));
            	}
            	push(&operat, input[i]);
	     	}
		}
		
	}
	//insert to btree
	Node root = NULL;
	if(operand.Top != NULL && operat.Top != NULL){
		createOperandStack(&insertOperand);
		createStack(&insertOperat);
		int sizeOperatt = sizeOperat(operat);
		int sizeOperandd = sizeOperand(operand);
		//reverse stack
		for(int j=0; j<sizeOperatt; j++){
			push(&insertOperat, operat.Top->info);
			pop(&operat);
		}
		for(int j=0; j<sizeOperandd; j++){
			pushOperand(&insertOperand, operand.Top->info);
			popOperand(&operand);
		}
		bstree temp;
		int sizeStack = sizeOperand(insertOperand) + sizeOperat(insertOperat);
		for(int j=0; j<sizeStack; j++){
			if(root==NULL || (sizeOperat(insertOperat)>=1 && temp.pointer->left !=NULL )){
				root = insert_tree(root, 0, insertOperat.Top->info);
				pop(&insertOperat);
			}else {
				root = insert_tree(root, insertOperand.Top->info, 'e');
				popOperand(&insertOperand);
			}
			if(root !=NULL && j==0){
	        	temp.pointer =  root;
	    	}
		    while(temp.pointer != NULL && temp.pointer->right != NULL){
		        temp.pointer = temp.pointer->right;
		    }
			
		}
	}
	

	//traverse_preorder(root);
	double hasil;
	if(root!=NULL){
		hasil = BtreeCalc(root);
	}
	else{
		hasil = operand.Top->info;	
	}
	printf("\nHasil = %g\n", hasil);
	freeTree(&root);
	return 0;
}
