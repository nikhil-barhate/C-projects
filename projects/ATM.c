#include<stdio.h>
int main()
{
	int amt,money,cmd,n;
	amt = 10000;
	printf("\nMain Menu:\n---------------------------------\n0-EXIT\n1-WITHDRAW\n2-DEPOSIT\n3-BALANCE\n---------------------------------\n");
	printf("\nEnter a Command : ");
	scanf("%d",&cmd);

	while(cmd!=0)
    {
		switch(cmd)
		{

		case 1:printf("\nEnter the amount of money to be Withdrawn : ");
			scanf("%d",&money);
			amt = amt-money;
			printf("Amount of Rs. %d has been withdrawn from your Account Successfully.\n\nAvailable Balance : %d\n",money,amt);
			break;

		case 2:printf("\nEnter the amount of money to be Deposited : ");
			scanf("%d",&money);
			amt = amt+money;
			printf("Amount of Rs. %d has been Deposited to your Account Successfully.\n\nAvailable Balance : %d\n",money,amt);
			break;

		case 3:printf("\nYour Current Bank Balance is : %d\n\n",amt);
			break;

		default:printf("\nERROR!\n");
		}
	
	printf("\n---------------------------------\n\n");
	
	printf("Enter a new Command : ");
	
	scanf("%d",&cmd);
    }

return 0 ;

}
