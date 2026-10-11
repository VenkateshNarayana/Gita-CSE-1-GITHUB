#include<stdio.h>

void bubble_sort(int arr[], int n);
void display_array(int arr[], int n);

int main(){
	int arr[] = {10,5,6,15,29,12,35,2};
	int size = sizeof(arr)/sizeof(int);
	printf("\nUnsorted Array");
	display_array(arr,size);
	
	printf("\nBubble Sort");
	bubble_sort(arr,size);
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
void bubble_sort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
