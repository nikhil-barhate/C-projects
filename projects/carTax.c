#include<stdio.h>

int main()
 {
	int netamt , tax , grossamt;

	printf(" Net Price		Sales Tax		Gross Price\n");
	printf("------------------------------------------------------------\n");

	for(netamt=1000;netamt<4001;netamt += 250)
	{
		if(netamt<2000)
			tax = 0.15*netamt;
		else if(1999 < netamt && netamt < 3001)
			tax = 300;
		else
			tax = 0.1*netamt;

		grossamt = netamt + tax;

		printf("   %d			   %d			   %d\n",netamt,tax,grossamt);
	}
	return 0;
 }
