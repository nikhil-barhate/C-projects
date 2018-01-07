#include<stdio.h>
#include<string.h>
#include<stdlib.h>



void brtfrcSort(int x[],int n){

	int max,i,temp,j;
	
	for(i=0 ; i<n-1 ; i++){
		
		max = x[i];
		
		for(j=i+1 ; j<n ; j++)
			if(x[j] > max){
			    max = x[j];
			    temp = x[i];
			    x[i] = x[j];
			    x[j] = temp;
			  }
		x[i] = max;
		}
	}



void bubSort(int x[],int n){

	int i,j,temp;

	 for(i=0 ; i<n-1 ; i++)

		for(j=0; j<n-i-1 ; j++)
			
			if(x[j] < x[j+1]){
			
			temp = x[j+1];
			x[j+1] = x[j];
			x[j] = temp;
			
			}
	    
	}
	

	

int main(){
	int x[]={7,8,6,5,3,4,1,2,9};
	int i;
	for(i=0;i<9;i++)
		printf("%d\n",x[i]);
	printf("\n\n");
		
	bubSort(x,9);
	
	for(i=0;i<9;i++)
		printf("%d\n",x[i]);
	
	return 0;		
}
	
	
	
				

		
