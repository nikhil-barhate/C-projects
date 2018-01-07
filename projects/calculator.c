#include<stdio.h>

int main()
{
	int cmd,no1,no2;
	double ans;
	
	printf("Choose your Operand :\n----------------------------------------\n1.Remainder\n2.Multiplication\n3.Division\n4.Factorial\n5.Summation\n----------------------------------------\n");
	scanf("%d",&cmd);
	
	switch(cmd)
	{

	case 1:case 2:case 3:

	  {
	
	printf("Enter Number 1 : ");
	scanf("%d",&no1);
	printf("Enter Number 2 : ");
	scanf("%d",&no2);
	if(cmd==1)ans=no1%no2;	
	if(cmd==2)ans=no1*no2;
	if(cmd==3)ans=no1/no2;
	break;

	  }

	case 4:

	  {
	printf("Enter the Number of which the Factorial is to be found : ");
	scanf("%d",&no1);
	ans=1;
	for(int cntr=0;cntr<no1;cntr++)
	{ans=ans*(no1-cntr);}break;
	  }

	case 5:

	  {
	printf("Enter the Number of which the Summation is to be found : ");
	scanf("%d",&no1);
	ans=0;
	for(int cntr=0;cntr<no1;cntr++)
	{ans=ans+no1-cntr;}break;
	  }

	default : printf("ERROR");

	}
	printf("Answer : %f\n",ans);
	return 0;
}
