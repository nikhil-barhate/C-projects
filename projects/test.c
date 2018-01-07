#include<stdio.h>

int main(){
	
	int a[] = {1,2,3,4,5,6};
	
	int *ptr = a + 2;
	
	printf("%p , %p %d\n",ptr,&a[2],a[2]);
	
	printf("%d %d\n",--*ptr+1,1+*--ptr);
	
	return 0;
}
