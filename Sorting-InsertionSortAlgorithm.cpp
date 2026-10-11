#include<stdio.h>

void insertion_sort(int arr[], int size);
void display_array(int arr[], int size);

int main(){
	int arr[] = {10,5,6,15,29,12,35,2};
	int size = sizeof(arr)/sizeof(int);
	printf("\nUnsorted Array");
	display_array(arr,size);
	
	printf("\nInsertion Sort");
	insertion_sort(arr,size);
	display_array(arr,size);
	
	return 0;
}
void display_array(int arr[], int size){
	printf("[");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("]");
}

void insertion_sort(int arr[], int size){
    int i, j, key;

    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
