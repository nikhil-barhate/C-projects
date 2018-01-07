	#include<stdio.h>
	#include<string.h>


	int main()
  	 {
		char *str;
	
		int flag[SIZE],cntr,j,i,n;

		for(i=0;i<SIZE;i++)
			flag[i] = 0;

		printf("Enter the number of charcters in the String\n");
		scanf("%d",&n);
		
		str = malloc(n*sizeof(char));
		
		printf("Enter the string:\n");
		scanf("%s",str);

		for(i=0;i<n;++i)
	 	  {
			cntr = 0;
	
			if (flag[i]==0)
			 {
				for(j=0;j<n;++j)
	   	   		 {
	   				if(str[i]==str[j])
	   				{
					cntr = cntr+1;
					flag[j] = 1;
					}	
	   	   		 }
	   			printf("%c is written %d times\n",str[i],cntr);
			}
	  	 }	
	   
		return 0;
  	 } 
