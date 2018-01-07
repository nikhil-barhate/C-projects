#include<stdio.h>
#define SIZE 100
int main ()
{
	int i,n,x[SIZE],range,max,min;
	
	printf("Enter total number of Students : \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter marks of student %d : ",(i+1));
		scanf("%d",&x[i]);
	}
	
	max = x[0];
	min = x[0];
	
	for(i=0;i<n;i++)		
		if(x[i]>max)
		max = x[i];

	for(i=0;i<n;i++)
		if(x[i]<min)
		min = x[i];

	
	range = max - min;
	
	printf("\n	Student No.		Marks		Grade\n");

	for(i=0;i<n;i++)
	
	{	
	
	if(x[i]>(max - (0.25*range)))
	printf("	%d			 %d 		  A\n",(i+1),x[i]);

	else if(x[i]<(min + (0.30*range)))
	printf("	%d			 %d 		  C\n",(i+1),x[i]);

	else
	printf("	%d			 %d 		  B\n",(i+1),x[i]);

	}


	return 0;

}
