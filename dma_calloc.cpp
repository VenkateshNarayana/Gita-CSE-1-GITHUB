/*2.Use calloc() to create an array of 5 integers and display initial values*/
#include<stdlib.h>
#include<stdio.h>
void display_array(int*,int);//param1-pointer to base address ,param2-no of elements
int main(){
	int* ptr_cal =  (int*)calloc(5,sizeof(int));
	display_array(ptr_cal,5);
	printf("\nAssigning values to my memory block: ");
	//assigning values to my dynamic memory block
	for(int i=0;i<5;i++){
//		ptr_cal[i]=i+1;
		*(ptr_cal+i) = i+1;
	}
	//displaying after assignment
	display_array(ptr_cal,5);
	
	//free the pointer to prevent memory leak
	free(ptr_cal);
}
void display_array(int* arr,int size){
	for(int i=0;i<size;i++){
		printf("\n%d-%d",(arr +i),*(arr+i));
	}
}
