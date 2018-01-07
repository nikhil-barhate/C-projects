#include<stdio.h>
#include<string.h>

int main(){
	char str[20];
	int i,count;
	i = 0;
	count = 0;
	
	
	printf("\n Enter the String : ");
	
	fgets(str , 20 , stdin ); 
	
	while(str[i] != '\0'){
		if(str[i] == ' ')
			count++;
		i++;
		}
	
	printf("\n The string contains %d spaces\n\n",count);
}
	
