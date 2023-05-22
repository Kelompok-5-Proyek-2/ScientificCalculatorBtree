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

//call trigonometri function
double perform_trig_operation(double sudut, char op[]) {
    if (strcmp(op, "sec(") == 0) {
		return 1.0 / cosinus(sudut);
    } else if (strcmp(op, "csc(") == 0) {
		return 1.0 / sinus(sudut);
    } else if (strcmp(op, "cot(") == 0) {
		return 1.0 / tangen(sudut);
    } else if (strcmp(op, "sin(") == 0) {
    	return sinus(sudut);
    } else if (strcmp(op, "cos(") == 0 && sudut != 90) {
        return cosinus(sudut);
    } else if (strcmp(op, "cos(") == 0 && sudut == 90) {
        return 0;
    } else if (strcmp(op, "tan(") == 0) {
        return tangen(sudut);
    } else {
    	printf("invalid operator trigonometri, example 'sin(), cos(), tan(), sec(), cot(), csc()'\n");
    	system("pause");
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
	for(;;){
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
		//digit handling, push to operand_stack
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
        //negative digit handling, push to operand_stack
		else if (input[i]=='(' &&  input[i+1] == '-'){
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
		
		//'(' and ')' handling, push to operat_stack
		else if (input[i] == '(' && !isNegative(&input[i+1], i)) {
            push(&operat, input[i]);
        } else if (input[i] == ')') {
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
		
		//faktorial handling 
		else if(input[i]=='!'){
			int j = i - 1;
			int k;
			double bil;
			int result;
			int index = 0;
			while (j >= 0 && isdigit(input[j])) {
			    j--;
			}
			for (k = j + 1; k < i; k++) {
			    index++;
			}
			bil = operand.Top->info;   
			result = faktorial(bil);
			popOperand(&operand);
			pushOperand(&operand,(double)result);
		} 
		
		//logaritma handling
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
		
		//trigonometri handling 'sin(', 'cos(', 'tan(', 'sec(', 'cot(', 'scs('
		else if (input[i] == 's' || input[i] == 'c' || input[i] == 't'){
            	char trigono[5];
            	int j=0;
            	char nomor[100], cek;
            	int bil, negative;
            	int nomor_top = 0;
            	negative = 0;
			    cek = input[i+4]; // Skip "sin(" or "cos(" or "tan("
				
				//Handle angka sebelum sin
				if(isdigit(input[i-1])){
					printf("invalid expression for trigonometri, example 'sin(90) or sec(90) etc'\n");
				}		
			    // Handle negative number
			    if (cek == '-') {
			    	negative = 1;
			    }
            	while(input[i] != ')' && (input[i] != '+' || input[i] != '*' || input[i] != '/') && input[i] != ' '){
            		if(isdigit(input[i]) || input[i] == '.'){
            			nomor[nomor_top++] = input[i++];
            			
					}else {
				        // menyimpan operator trigonometri
				        trigono[j++] = input[i++];
				        trigono[4] = '\0';
				    }
				}
				nomor[nomor_top] = '\0';
				if(negative){
					j--;
				}
				if(j!=4){
					printf("invalid expression for trigonometri, example 'sin(90) or sec(90) etc'\n");
				}else{
					if (negative) { // jika bilangan negatif, konversi ke nilai negatif saat disimpan di stack
			            pushOperand(&operand, -1 * atof(nomor));
			        } else {
			            pushOperand(&operand, atof(nomor));
			        }
					bil = operand.Top->info;
					popOperand(&operand);
					pushOperand(&operand, perform_trig_operation(bil, trigono));
				}
		}
		
		//absolute handling
		else if(input[i]=='|'){
            	i++;
            	char number[100];
                int number_top = 0;
                
                while (input[i] != '|') {
                    number[number_top++] = input[i++];
                }
                number[number_top] = '\0';
                pushOperand(&operand, atof(number));
                double bil=operand.Top->info;
                popOperand(&operand);
                pushOperand(&operand, nilai_mutlak(bil));
		}
		
		//operat handling and priority handling ex = 2*3+4, this code will result 6+4
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
	
	//insert to btree handling
	Node root = NULL;
	if(operand.Top != NULL && operat.Top != NULL){
		createOperandStack(&insertOperand);
		createStack(&insertOperat);
		int sizeOperatt = sizeOperat(operat);
		int sizeOperandd = sizeOperand(operand);
		//reverse stack handling
		for(int j=0; j<sizeOperatt; j++){
			push(&insertOperat, operat.Top->info);
			pop(&operat);
		}
		for(int j=0; j<sizeOperandd; j++){
			pushOperand(&insertOperand, operand.Top->info);
			popOperand(&operand);
		}
		
		//insert to btree from reverse stack
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
	

	//calculate the result from binary tree
	double hasil = 0;
	if(root!=NULL){
		hasil = BtreeCalc(root);
	}
	else{
		if(operand.Top != NULL){
			hasil = operand.Top->info;	
		}
			
	}
	printf("\nHasil = %g\n", hasil);
	freeTree(&root);
	system("pause");
	}
	return 0;
}

/*Reference: SDA Praktikum Module infix to prefix, 
			 Binary tree program from tugas besar SDA, link : "https://github.com/mahesyasn18/Kamus-bahasa-indonesia-inggris",
			 Scientific calculator group 5 with array, link : "https://github.com/Kelompok-5-Proyek-2/KalkulatorScientificKelompok5" 
*/
