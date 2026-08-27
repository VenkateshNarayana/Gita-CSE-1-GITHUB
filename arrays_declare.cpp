/*WAP to input and display array */
#include<stdio.h>
void print_array(int[],int);
int main(){
	int arr1[5];                    //method 1 - declare with size
	int size = sizeof(arr1)/sizeof(int);
	//storing
	arr1[0]= 11;
	arr1[1]= 12;
	arr1[2]= 13;
	arr1[3]= 14;
	arr1[4]= 15;
	//accessing
	print_array(arr1,size);
	
	int arr2[5]={1,2,3,4,5};        //method 2 - declare and initialize with size
//	printf("\nElements of array2: ");
	size = sizeof(arr2)/sizeof(arr2[0]);
	print_array(arr2,size);
	
	int arr3[]={10,20,30,40,50,60}; //method 3 - declare without size but initialize it with values
//	printf("\nElements of array3: ");
	size = sizeof(arr3)/sizeof(arr3[0]); //sizeof gives no of bytes the variable or datatype stores in memory
	print_array(arr3,size);
		
}
void print_array(int arr[],int size){
	printf("\nElements of array: ");
	printf("[Size=%d] :",size);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);	
	}
}

