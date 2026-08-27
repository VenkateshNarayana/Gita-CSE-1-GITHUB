/*1. Allocate memory for 5 integers using malloc() and display them.
*/
#include<stdlib.h>
#include<stdio.h>
void display_array(int*,int);//param1-pointer to base address ,param2-no of elements
int main(){
	int* ptr_mal = (int*)malloc(5*sizeof(int));
	display_array(ptr_mal,5);
	printf("\nInitializing values to zero: ");
	for(int i=0;i<5;i++){
		ptr_mal[i]=0;
	}
	display_array(ptr_mal,5);
	//free the pointer to prevent memory leak
	free(ptr_mal);
}
void display_array(int* arr,int size){
	for(int i=0;i<size;i++){
		printf("\n%d-%d",(arr +i),*(arr+i));
	}
}
