#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	int data;
	struct NODE *next;
	}node;
	
typedef struct QUEUE{
	node *front;
	node *rear;
	}queue;






void enqueue(queue *q , int x){
	
	node *newnode;
	newnode = malloc(sizeof(node));
	
	if(newnode == NULL){
		printf(" Memory Not Available !");
		return;
	}
	
	else{
		newnode->next = NULL;
		newnode->data = x;
		
		if(q->front == NULL){
			q->front  = newnode;
			q->rear = newnode;
		}
		else{
			q->rear->next = newnode;
			q->rear = newnode;
		}
	}
}







void dequeue(queue *q){
	
	if(q->front == NULL)
		printf(" Stack is Empty !");
	else{
		node *temp;
		temp = q->front;
		q->front = q->front->next;
		free(temp);
		
		if(q->front == NULL)
			q->rear =NULL;
		
		
	}
}






void displayqueue(queue *q){
	
	if(q->front == NULL)
		printf(" Stack is Empty !");
	
	else{
		node *travPtr;
		travPtr = q->front;
		
		printf(" QUEUE : \n");
		
		while(travPtr != NULL){
			printf(" %d \n",travPtr->data);
			travPtr = travPtr->next;
		}
	}
}





int main (){
	
	int i,freecounters,n;
	queue q;
	
	q.front = NULL;
	q.rear = NULL;
	
	printf(" Enter number of people : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		enqueue(&q , i+1);
	
	
	do{
		printf(" How many counters are free :  ");
		scanf("%d",&freecounters);
	
		for(i=0;i<freecounters;i++)
			dequeue(&q);
	
		
		displayqueue(&q);
	
	}while(q.front != NULL);
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
			
