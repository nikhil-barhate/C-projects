#include<stdio.h>
#include<string.h>

typedef struct{
	char name[20];
	char rollno[10];
	int marks;
	}student;





void writeStudent(FILE *fp){
	
	int flag = 1;
	student s;
	
	while(flag != 0){
	
		printf("\n Enter the name of the student : ");
		scanf("%s",s.name);
		printf(" Enter the roll number : ");
		scanf("%s",s.rollno);
		printf(" Enter the marks : ");
		scanf("%d",&s.marks);
	
		fprintf(fp," %s %s %d\n",s.name,s.rollno,s.marks);
	
		printf("\n To stop adding press 0 \n To add more students press 1 : ");
		scanf("%d",&flag);
	
	}
}









void displayResult(FILE *fp){
	
	student s;
	
	printf("\n -> Students with marks above 50 : \n\n");
	
	while(fscanf(fp," %s %s %d\n",s.name,s.rollno,&s.marks) != EOF){
		
		
		if(s.marks > 50)
			printf("    %s \n",s.name);
	}
	
}









int main(){
	
	FILE *fp;
	int cmd;
	
	printf("\n MAIN MENU\n-----------------------------------\n");
	printf(" 0. EXIT\n 1. Add student data\n 2. Display students above 50 marks\n");
	printf("-----------------------------------\n -> Enter a Command : ");
	scanf("%d",&cmd);
	printf("-----------------------------------");
	
	while(cmd != 0){
	
	switch(cmd){
	
		case 1 :{
	
			fp = fopen("studentData.txt" , "a");

			writeStudent(fp);
			fclose(fp);
		}break;
		
		case 2 :{
		
			fp = fopen("studentData.txt" , "r");
	
			if(fp == NULL)
				printf("ERROR 404 : file not found !");
			else{
		
				displayResult(fp);
				fclose(fp);
			}
		}break;
		
		default : printf("\n\n ERROR : Invalid Command !\n\n");break;
	}
	
	printf("-----------------------------------\n -> Enter a new Command : ");
	scanf("%d",&cmd);
	printf("-----------------------------------\n");
	
	}
	 
	
	return 0;
	
}
























	
