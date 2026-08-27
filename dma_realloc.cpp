/*3. Demonstrate realloc() by increasing an array size*/
#include<stdlib.h>
#include<stdio.h>
void display_array(int*,int);//param1-pointer to base address ,param2-no of elements
int main(){
	int* ptr_mal = (int*)malloc(5*sizeof(int));
	if(ptr_mal==NULL){
		printf("Memory allocation failed....");
		return 1;
	}
	display_array(ptr_mal,5);
	printf("\nInitializing values : ");
	for(int i=0;i<5;i++){
		ptr_mal[i]=i+1;
	}
	display_array(ptr_mal,5);
	
	printf("\nResizing the array to 10 elements : ");
	//using realloc to resize it to 10 from 5
	ptr_mal = (int*)realloc(ptr_mal,10*sizeof(int));
	if(ptr_mal==NULL){
		printf("Memory allocation failed....");
		return 1;
	}
	display_array(ptr_mal,10);
	
	//free the pointer to prevent memory leak
	free(ptr_mal);
}

void display_array(int* arr,int size){
	for(int i=0;i<size;i++){
		printf("\n%d-%d",(arr +i),*(arr+i));
	}
}
