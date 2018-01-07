



						/* A program to solve a postfix expression using stacks */




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct NODE{
		int data;
		struct NODE *next;
	}node;









void push(node **topPtr , int x){
	
	node * newnode;
	
	newnode = malloc(sizeof(node));
	
	if(newnode == NULL)
		printf("\n ** Memory Full !!\n");
	else{
		
		newnode->data = x;
		
		newnode->next = *topPtr;
		
		*topPtr = newnode;
		
	}
		
}









int pop(node **topPtr , int *x){

	if(*topPtr == NULL)
		return 1;
	
	else{

		node* temp = *topPtr;
		*topPtr = (*topPtr)->next;
		*x = temp->data;
		free(temp);
		
		return 0;
	}

}







	
bool check(char pfstr[]){
	
	int i;
	
	for(i = 0 ; pfstr[i] !='\0' ; i++){
		
		if( (pfstr[i] > '9' || pfstr[i] <'0') && pfstr[i] != '+' && pfstr[i] != '-' && pfstr[i] != '*' && pfstr[i] != '/')
		
		return false;
		
	}
	
	return true;
}











int evaluate(char pfstr[] ,int *result ){

	node *top = NULL;
	int i , ans = 0;
	
	for(i = 0 ; pfstr[i] !='\0' ; i++){
	
		if((pfstr[i] < '9' && pfstr[i] >'0') || pfstr[i] == '9' || pfstr[i] == '0')
			push(&top , (pfstr[i] - '0'));

		else{
			int chk , op1 , op2;
			chk = pop(&top , &op2 );
			chk = pop(&top , &op1 );
			
			if(chk == 1)
				return 1;
			
			switch(pfstr[i]){
			
				case '+' : ans = op1 + op2;break;
				
				case '-' : ans = op1 - op2;break;
				
				case '*' : ans = op1 * op2;break;
				
				case '/' : ans = op1 / op2;break;
			}
			
			push(&top , ans);
		}
	}
	
	pop(&top , result);
	
	if(top == NULL)
		return 0;
	
	else
		return 1;

} 












int main(){
	
	char pfstr[50];
	int cmd;
	

	
	do{
	
		printf("\n -> Enter the postfix string to be evaluated : ");
		scanf("%s",pfstr);
		
		if(check(pfstr)){
			
			int status , result;
			status = evaluate(pfstr , &result);
			
			if(status == 0)
				printf("\n -> Answer = %d ",result);
			else
				printf("\n ** ERROR : INVALID Postfix String !!");
			
		}
		else 
			printf("\n ** ERROR : INVALID Postfix String !!");
		
		printf("\n\n -> To evalute another string enter 1 \n    To exit enter 0 : ");
		scanf("%d",&cmd);
	
	}while(cmd == 1);
	
	printf("\n");
	
	return 0;
	
}
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
