#ifndef daniar_h
#include <math.h>
#include <stdbool.h>

void CalArit();
void mainMenu();

int prioritas(char operator) {
    
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^' || operator =='V')
        return 3;
    else if (operator == '(' || operator == ')')
        return 0; 
    else if (operator =='=' || operator=='>' || operator =='<')
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

bool isOperator(char op);

#endif
