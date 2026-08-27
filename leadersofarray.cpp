/* Create a udf for finding Leaders of the given array */
#include<stdio.h>

int main(){
	int max;
	int arr[]={16,17,4,5,2};
	int size =sizeof(arr)/sizeof(int);
	printf("Leaders of the array:");
	for(int i=size-1;i>=0;i--){
		if(i==size-1){
			max=arr[i];
			printf("%d ",arr[i]);
		}else if(arr[i]>max){
			max=arr[i];
			printf("%d ",arr[i]);
		}
	}
		
}
