#include<stdio.h>
int main()
{
	float workhrs,rate,amt,totamt;
	int n,ctr;
	
	totamt=0;
	ctr=0;

	printf("Enter number of Employees : ");
	scanf("%d",&n);
	
	printf("----------------------------------------------\n");
	
	while(ctr<n)
  	 {
		printf("Enter Working Hours for Employee number %d : ",ctr+1);
		scanf("%f",&workhrs);
		printf("Enter Rate for Employee number %d : ",ctr+1);
		scanf("%f",&rate);
		printf("----------------------------------------------\n");	
		amt = workhrs*rate;
		totamt = totamt+amt;
		ctr++;
  	 }
	
	printf("Total Amount :%f\n",totamt);
	
	return 0;

}

