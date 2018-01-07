

/*	A Project by :
	---------------------------------
	1. Nikhil Barhate 
	2. Gaurav Dalmia
	3. Mihir Gadkar
	4. Omkar Deshmukh
	---------------------------------
*/




/* ---- A program to maintain a queue of patients ---- */ 





#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int capacity = 3;
int total_patients = 0;
int patient_count = 0;





/*
	The following two structs are used to implement
	a QUEUE data structure.
*/


typedef struct PATIENT{
	
	char name[20];
	int seat_number;
	int time;	
	struct PATIENT *next;
	
	}patient;



typedef struct QUEUE{

	patient *front;
	patient *rear;
	
	}queue;



	

/*
	The following function is used to enqueue new patients
	in the queue.
*/


void enqueue(queue *q){

	patient *p;
	p = malloc(sizeof(patient));
	
	if(p == NULL)
		printf(" Memory full !");
	
	else if(patient_count >= capacity)
		printf("\n -> NO MORE SEATS REMAINING !\n");

	else{
		printf("\n -> Enter patient name : ");
		scanf("%s",p->name);
		printf(" -> Enter time in p.m. (hhmm): ");
		scanf("%d",&p->time);
		
		if((p->time > 1000) || (p->time < 0700)){		/* if the time is out of the given time limit end the enqueue function */ 
										
			printf(" -> Out of Timelimit ! ");
			free(p);
			return;
		}
		
		else{
		
			total_patients++;
			patient_count++;
			
			p->seat_number = (total_patients % capacity);		/*--Seat number will be mod of total patients and the 
										max capacity , i.e. the total number of seats--*/
		
		
			if(p->seat_number == 0)					/*--Seat number cannot be zero--*/ 
				p->seat_number = capacity;
		
			printf(" -> Your seat number is %d.\n",p->seat_number);
		
			if(q->front == NULL)
				q->front = q->rear = p;
		
			else{
				q->rear->next = p;
				q->rear = p;
			}
		}
	}
	
}





/*
	The following function simply prints the current 
	elements in the queue.
*/


void print_queue(queue q){

	if(q.front == NULL)
		printf("\n -> The Queue is Empty ! \n");
	
	
	
	else{
		patient *travPtr;
		travPtr = q.front;
		printf("\n -> THE QUEUE : \n\n");
		
		int counter = 0;
		
		printf("--- Sr.No. ------- Name ------- Seat No. ---\n");
		
		while(travPtr != NULL){
			
			counter ++;
			printf("    %d.              %s 	%d\n",counter,travPtr->name,travPtr->seat_number);
			travPtr = travPtr->next;
		}
		
	}
}





/*
	The following function removes a patient from the front
	of the queue.
*/


void dequeue(queue *q){
	
	patient *temp;
	
	if(q->front == NULL)
		printf("\n -> The Queue is Empty ! \n");
	
	else{
		temp = q->front;
		q->front = q->front->next;
		free(temp);
		
		patient_count--;
			
			if(q->front == NULL)
				q->rear = NULL;
	}

}





/*
	The following main function implements a simple menu system
	using switch case.
*/


int main(){
	
	int cmd;
	queue q;
	
	q.rear = q.front = NULL;
	

	printf("---------------------------------------------\n");
	printf("  Main Menu\n");
	printf("---------------------------------------------\n");
	printf(" 0. EXIT.\n");
	printf(" 1. Add Patients.\n");
	printf(" 2. Dequeue Patient.\n");
	printf(" 3. View Queue.\n");
	printf("---------------------------------------------\n");
	printf(" -> Command : ");
	scanf("%d",&cmd);
	printf("---------------------------------------------\n");
	
	while(cmd != 0){
		
		switch(cmd){
			
			case 1 : enqueue(&q);break;	 
			
			case 2 :{ 
				
				if(q.front == NULL)
					printf("\n -> The Queue is Empty ! \n");
				
				else{
					printf("\n -> %s has been removed from the queue.\n",(q.front)->name);
					printf("    Seat number %d is now empty.\n",(q.front)->seat_number);
					dequeue(&q);
				}
				break;
			}
			
			case 3 : print_queue(q);break;
			
			default : printf(" -> ERROR ! Invalid Command\n");
			
		}

		printf("\n---------------------------------------------\n");
		printf(" -> New Command : ");
		scanf("%d",&cmd);
		printf("---------------------------------------------\n");
	}
	
	return 0;
	
}









