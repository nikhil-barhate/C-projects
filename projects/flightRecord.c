#include<stdio.h>
#include<string.h>

typedef struct{
	int seats;
	char strpt[4];
	char despt[4];
	char strtime[5];
	char arvtime[5];
	} flightRecord;


void read_record(flightRecord f[],int n)
	
	{
	  int i;
	  for(i=0;i<n;i++)
	    {	
		printf("\nFLIGHT NUMBER %d ",i+1);

		printf("\n\nEnter Starting Point : ");
		scanf("%s",f[i].strpt);
		
		printf("Enter Destination Point : ");
		scanf("%s",f[i].despt);
		
		printf("Enter starting time : ");
		scanf("%s",f[i].strtime);
		
		printf("Enter arival time : ");
		scanf("%s",f[i].arvtime);
		
		printf("Enter Total number of available seats : ");
		scanf("%d",&f[i].seats);
		printf("---------------------------------------------");
	   }
	}
	


void read_query(char usr_strpt[],char usr_despt[])
	
	{
	  
	  printf("\nQUERY : \n\nEnter starting point : ");
	  scanf("%s",usr_strpt);
	  printf("Enter destination point : ");
	  scanf("%s",usr_despt);
	}
	


int chk_query(flightRecord f[],char usr_strpt[],char usr_despt[],int n)
	
	{
	  int i;
	  
	  for(i=0;i<n;i++)
	   {
	  	 if(strcmp(f[i].strpt,usr_strpt)==0 && strcmp(f[i].despt,usr_despt)==0 && f[i].seats>0)
		 return i+1;
	 	
	   }
	  	 return 0;
	}
	
	
	  
int main()
	{
	  flightRecord f[100];
	  int flag,n;
	  char usr_strpt[5],usr_despt[5];
	  
	  printf("Enter number of flights : ");
	  scanf("%d",&n);
	  
	  printf("\nENTER THE FLIGHT RECORDS BELOW :-  \n\n**********************************************");
	  read_record(f,n);
	  
	  read_query(usr_strpt,usr_despt);
	  
	  flag = chk_query(f,usr_strpt,usr_despt,n);

	  printf("**********************************************\n");
	  
	  if(flag == 0)
	  printf("No flights are available !\n");
	  
	  else
	  printf("Seat is available in flight %d\n",flag);
	  
	  return 0;
	  
	 }	
