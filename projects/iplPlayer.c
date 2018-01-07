



	/*-----------------------------------------    COPYRIGHTS - NIKHIL BARHATE (2017)    ----------------------------------------*/
	
      
      
	/*  IMPORTANT : Publishing this code without the consent of the author will lead to prosecution without any further notice.  */


      
	/*-----------------------------------------    email : nikhilbarhate99@gmail.com    -----------------------------------------*/



	/*-------------------------------------------------    FE - ETRX (2017)    --------------------------------------------------*/
	
	
						
						
						
						
						
						

						
						
						
	/* A simple code to maintain a team of players in a linkedlist */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int playercount = 0;


typedef struct PLAYER{
	char country[20],name[20];
	int score;
	
	struct PLAYER *next;
	}player;
	
		
		
		
	
	/*................................ADD PLAYER FUNCTION................................*/





void addPlayer(player **headptr){

	player *newplayer;
	newplayer = malloc(sizeof(player));
	
	if(newplayer == NULL)
		printf(" **  Memory full !!");
	
	else{

		printf("\n -----------------ADD PLAYER-----------------\n\n");
		printf("  -> Enter name of the player : ");
		scanf("%s",newplayer->name);
		printf("  -> Enter country of player : ");
		scanf("%s",newplayer->country);
		printf("  -> Enter the score of the player : ");
		scanf("%d",&newplayer->score);
	
		newplayer->next = NULL;
	
		playercount++;
	
		if(*headptr == NULL)
			*headptr = newplayer;
		
		else{
			player *travPtr;
			travPtr = *headptr;
		
			while(travPtr->next != NULL)
				travPtr = travPtr->next;
		
			travPtr->next = newplayer;
		
		}

	}
}

	
	/*................................END OF FUNCTION................................*/


				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				





	/*................................DISPLAY ALL PLAYERS FUNCTION................................*/



void displayAll(player *head){
	
	if(head == NULL)
		printf("  ** The list is empty !!");
	
	else{
		player *travPtr = head;
		int cntr = 1;
			      
		printf("\n	| | ...LIST OF PLAYERS... | | \n"); 
		printf("	v v			  v v \n");
	
		while(travPtr != NULL){
		
			printf("\n ----------------------%d----------------------\n\n",cntr);
			printf("  -> Name : %s\n     Country : %s\n     Score : %d\n",travPtr->name,travPtr->country,travPtr->score);
		
			
			travPtr = travPtr->next;
			cntr ++;
		}
		
		printf("\n\n");
	}	
}

	/*................................END OF FUNCTION................................*/
						
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				




	/* ................................DELETING FUNCTION................................ */



int deletePlayer(char name[] , player **headptr){
	
	player *travPtr = *headptr;
		

	if((*headptr)->next == NULL && strcmp((*headptr)->name , name) == 0 ){
		
		free(*headptr);
		*headptr = NULL;
		playercount--;
		return 1;
	}
			
			
	else if(strcmp((*headptr)->name , name) == 0){
		player *temp = *headptr; 
		*headptr = (*headptr)->next;
		free(temp);
		playercount--;
		return 2;
		}

	else{
		while(travPtr->next != NULL){
	
			if(strcmp((travPtr->next)->name , name) == 0){
						
					player *temp = travPtr->next;
					travPtr->next = (travPtr->next)->next; 
					free(temp);
					playercount--;
					return 2;
			      	}
			      		
			travPtr = travPtr->next;
					
		}
	
	}
	
	return 3;
	

}

	
	/*................................END OF FUNCTION................................*/




































	
	
	
	/*................................DISPLAY SELECTED PLAYERS FUNCTION................................*/




void displaySelected(player *head , int *avg){
	
	
	if(head == NULL)
		printf("  ** The list is empty !!");
	else{
	
		player *travPtr;
		travPtr = head;
	
		int total ,cntr1;
		total = 0;
		cntr1 = 0;
		
		while(travPtr != NULL){
			total = total + travPtr->score;
			cntr1++;
			travPtr = travPtr->next;
		}
	
		*avg = total / cntr1;
		
		printf("	| | .......LIST OF PLAYERS........ | | \n"); 
		printf("	v v   SELECTED FOR THE MATCH ARE   v v \n");
		
		cntr1 = 0;
		
		travPtr = head;
		
		while(travPtr != NULL){
			

			if(travPtr->score >= *avg){
				cntr1++;
				printf("\n ----------------------%d----------------------\n\n",cntr1);
				printf("   -> Name : %s\n     Country : %s\n     Score : %d\n",travPtr->name,travPtr->country,travPtr->score);
				
			}
			
			travPtr = travPtr->next;				
					
		}
		
		printf("\n\n  -> Number of Players Selected = %d \n     Total Players in the list = %d \n", cntr1 , playercount);
		printf("\n  -> The AVERAGE SCORE = %d \n\n",*avg);
	}			
					
}					
					
	
	
	/*................................END OF FUNCTION................................*/		
					
					
					
					






















					
					











	/* ................................MAIN FUNCTION................................ */



int main(){

	player *head = NULL;
	int cmd,i,n;
	
	printf("\n\n -- A CODE BY NIKHIL BARHATE --\n\n");
	
	printf("\n Enter the number of players : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		addPlayer(&head);
	
							
							
								/* .........SIMPLE MENU ......... */
	
	
	
	printf("\n\n *******************************************************\n ENTER A COMMAND \n");
	printf(" ******************************************************* \n\n");
		
	printf(" 0. EXIT \n\n 1. Delete a player from the list.\n\n 2. Add another player to the list.\n\n");
	printf(" 3. Display all the players in the list. \n\n 4. Display Selected Players. \n\n 5. Display Head pointer's aadress. \n\n");
	
	printf(" ******************************************************* \n");
	
	printf("  -> Your command : ");
	scanf("%d",&cmd);
	printf(" ******************************************************* \n\n");
	
	
	while(cmd != 0){ 
	
		int status = 0;
		
		switch(cmd){
		
							
			case 0 : break;
		
			case 1:{
				
				if(head != NULL){
				
			
					char yesno = 'y', playername[20];
					int flag ;
			
					while(yesno == 'y'){
			
					printf("\n  -> Enter the name of the player to be deleted : ");
					scanf("%s",playername);
			
			
					printf("\n  -> Are you sure you want to delete player '%s' ? (y/n) : ",playername);
					scanf(" %c",&yesno);
				
						if(yesno == 'y'){
					
							flag = deletePlayer(playername , &head);
					
					
							if(flag == 1){
								printf("\n  -> '%s' successfully deleted from the list !! \n\n",playername);
								status = 1;
								break;
			
							}
					
							else if(flag == 2){
								printf("\n  -> '%s' successfully deleted from the list !!\n",playername);
								printf("\n  -> Do you want to delete another player ? (y/n) : ");
								scanf(" %c",&yesno);
							}
							else {
								printf("\n  ** ERROR : Player not found !!\n\n");
								printf("  -> Do you want to review the list ? (y/n) : ");
								scanf(" %c",&yesno);
								printf("\n");
							
								if(yesno == 'y')
									displayAll(head);
							
								printf("  -> Do you want to delete another player ? (y/n) : ");
								scanf(" %c",&yesno);
							
								if(yesno =='n')
									break;
							
							}
						}
				
				
						else if(yesno == 'n'){
							printf("  -> Do you want to delete another player ? (y/n) : ");
							scanf(" %c",&yesno);
						}
				    	}
				
				}
				
				else 
					printf("  ** The list is empty !!");
				
				break;
			}
		
		
			case 2 :{ 
				
				addPlayer(&head);
				printf("\n\n  -> Player added succesfully !");
				break;
			}	
		
			case 3 :{
				
				displayAll(head);
				break;
			}
			
			case 4 :{
				
				int avg = 0;
				displaySelected(head , &avg);
				break;
			}
			
			case 5 : printf("  -> Address of the head is %p ",head);
				break;
					
			default : printf("  ** ERROR : Invalid command !!");
		
		}
		
		printf("\n\n *******************************************************\n");
		
		if(status == 1)
			printf(" ** WARNING : The list is now empty !!\n");
		else
			printf("    TOTAL PLAYERS = %d ",playercount);
		
		
		printf("\n    Enter a new command : ");
		scanf("%d",&cmd);
		printf(" ******************************************************* \n\n");
		

	
	}	
	
	
	return 0;
	
}










	
	
	
	
	








	/*------------------------------   That's All Folks    ------------------------------*/
























