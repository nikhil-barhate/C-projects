#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct NODE{
	char word[20];
	struct NODE * next;
	}node;
	

void push(node **topPtr , char usr_word[20]){
	
	node* newnode ;
	newnode = malloc(sizeof(node));
	
	if(newnode == NULL)
		printf(" -> ERROR : MEMORY FULL !");

	else{
		strcpy(newnode->word , usr_word);
		
		newnode->next = *topPtr;
		
		*topPtr = newnode;
		
	}

}

void print_pop(node **topPtr){
	
	if(*topPtr == NULL)
		printf(" -> ERROR : INVALID STRING !");
	
	else{
		printf(" %s",(*topPtr)->word);
		
		node *temp;
		temp = *topPtr;
		*topPtr = (*topPtr)->next;
		free(temp);
	}
}


void reverse_string(char str[100]){
	
	node *top = NULL;
	int i = 0;
	int j;
	
	while(str[i] != '\0'){
		
		j = 0;
		
		char usr_word[20];
		
		while(str[i] != ' '){
			
			usr_word[j] = str[i];
			i++;
			j++;
		}
		push( &top , usr_word);
		i++;		
				
	}
	
	while(top != NULL)
		print_pop(&top);
}
	


int main(){
	
	char str[100];
	
	printf(" -> Enter your string : ");
	
	fgets(str,100,stdin);
	
	printf("\n -> Reversed string : ");
	
	reverse_string(str);
	
	printf("\n");
	
	return 0;
}
	
	

