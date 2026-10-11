#include<stdio.h>

void selection_sort(int arr[], int n);
void display_array(int arr[], int n);

int main(){
	int arr[] = {10,5,6,15,29,12,35,2};
	int size = sizeof(arr)/sizeof(int);
	printf("\nUnsorted Array");
	display_array(arr,size);
	
	printf("\nSelection Sort");
	selection_sort(arr,size);
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
void selection_sort(int arr[], int n){
    int i, j, temp,min_idx;
    for (i = 0; i < n - 1; i++){
    	min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if (min_idx!=i){
        	//swap
        	temp = arr[i];
        	arr[i] = arr[min_idx];
        	arr[min_idx] = temp;
		}
    }
}
