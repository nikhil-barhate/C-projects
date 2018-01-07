#include<stdio.h>
#include<stdbool.h>


bool trufalse(int x){
	if(x == 1)
		return true;
	else 
		return false;

	}
		


int main (){
	int x;
	printf(" Enter 1 or 0 : ");
	scanf("%d",&x);
	
	if(!trufalse(x))
		printf(" TRUE \n");
	else
		printf(" FALSE \n");
		
}
