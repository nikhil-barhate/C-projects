#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 101

int main()
   {
	int flag,cntr,j,i,n;
	char *str;
	
	printf("Enter the number of charcters in the String\n");
	scanf("%d",&n);
	
	str = malloc(n*sizeof(char));
	
	printf("Enter the string:\n");
	scanf("%s",str);

	for(i=0;i<n;i++)
	   {
	   	cntr=0;
		flag=0;
	   	

		for(j=i+1;j<n;j++)
		{
		if (str[i]==str[j])
			
			flag = 1;
		}
		

		if (flag==0)
		{
		for(j=0;j<n;j++)
	   	   {
	   		if(str[i]==str[j])
	   		cntr = cntr+1;
	   	   }
	   	printf("%c is repeated %d times\n",str[i],cntr);
		}
	   }	
	   
	return 0;
   } 

