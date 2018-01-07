#include<stdio.h>
#include<stdlib.h>



int main(){
	typedef struct player{
		int name;
		int score;
		struct player *ptr;
		}player;
		
	
	char x[] = {'A','B','C','D','E','F','G','H'};
	char *p = (char*)malloc(8*sizeof(char));
	int i;
	player *head,*temp;
	head = NULL;
	player *k[8];	


	for(i=0;i<8;i++){
		
		p[i] = x[i];
		printf(" %c     %p\n",p[i],&p[i]);
	}
	
	for(i=0;i<8;i++){
	
		k[i] = malloc(sizeof(player));

	
		k[i]->name = i;
		k[i]->score = i+100;
		k[i]->ptr = NULL;
	
	
		if(i==0)
			head = k[0];
		else
			k[i-1]->ptr = k[i];
	
	}
	
	
	temp = head;
	int flag = 0;
	
	while(flag == 0){
	
		printf(" name : %d  score : %d aadress : %p  pointer :  %p\n",temp->name,temp->score,temp,temp->ptr);

		if(temp->ptr == NULL)
			flag = 1;
			
		temp = temp->ptr;
		
       }
		
	int *a;
	
	a = NULL;
	printf("\naadress of a is : %p \n",a);
	
	return 0;
}







