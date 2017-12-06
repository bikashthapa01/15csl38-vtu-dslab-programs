#include <stdio.h>
#include <string.h>

int f(char symbol){
	switch(symbol){
		case '+':
		case '-':return 2;
		case '/':
		case '*':return 4;
		case '$':
		case '^':return 5;
		case '(':return 0;
		case '#':return -1;
		default:return 8;
	}
}

int g(char symbol){
	switch(symbol){
		case '+':
		case '-':return 1;
		case '/':
		case '*':return 3;
		case '$':
		case '^':return 6;
		case '(':return 9;
		case ')': return 0;
		default:return 7;
	}
}

void infix_postfix(char infix[],char postfix[]){
		int i,j,top=-1;
		char s[20],symbol;
		s[top] = '#'; // forgot to add this
			j =0;
		for(i=0;i<strlen(infix);i++){
			symbol = infix[i];

			while(f(s[top]) > g(symbol)){
				postfix[j++]  = s[top--]; 
			}

			if(f(s[top]) != g(symbol)){
				s[++top] = symbol;
			}else {
				top--;
			}

		}

		while(s[top] !='#'){
				postfix[j++] = s[top--];
		}

		postfix[j] = '\0';



}


int main(){
	char postfix[20],infix[20];
	printf("Enter Infix Expression:\n");
	gets(infix);
	infix_postfix(infix,postfix);

	printf("The postfix Expression is: %s \n",postfix);
	return 0;
}