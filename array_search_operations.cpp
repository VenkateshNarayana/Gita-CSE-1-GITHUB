/*Array - Searching operations
1. Linear Search
2. Binary Search
*/
#include <stdio.h>
#define MAX_SIZE 10
void accept_array_elements_from_user(int[]);//param1=array name
void display_array(int[]);
int get_input_search_element(); //return the user input
void linear_search(int[],int);  //param1=array name ;param2=search element
void binary_search(int[],int);  //param1=array name ;param2=search element
void show_menu();
int main(){
	int search_element;
	int my_arr[MAX_SIZE]={0};//array declaration with initialization to zero.
	int choice=0;
	do{
		show_menu();
		scanf("%d",&choice);
		switch(choice){
			case 1: accept_array_elements_from_user(my_arr);
					break;
			case 2: search_element = get_input_search_element();
					linear_search(my_arr,search_element);
					break;
			case 3: search_element = get_input_search_element();
					binary_search(my_arr,search_element);
					break;
			case 4: display_array(my_arr);
					break;
			case 5: break;
			default: printf("Invalid choice,please enter between(1-5).");
		}
		
	}while(choice!=5);
	printf("\nThank you.Exitted Search Application Successfully!!!");
	
	return 0;
}
void binary_search(int arr[],int search_val){
	int low = 0,high= MAX_SIZE-1;
	int mid = (low + high)/2;

	while(low<=high){
		if (arr[mid]==search_val){
			printf("\nThe search value is found @index=%d",mid);
			return;
		}
		if(search_val>arr[mid]){
			low = mid+1;
		}else{
			high = mid-1;
		}
		mid = (low + high)/2;
	
	}
	printf("\nThe search value(%d) is NOT FOUND.",search_val);	
	return;
}
void linear_search(int arr[],int search_val){
	for(int i =0;i< MAX_SIZE;i++){
		if(arr[i]==search_val){
			printf("\nSearch value(%d) is found @%d index.",search_val,i);
			return;
		}
	}
	printf("\nSearch value(%d) is NOT FOUND!!!",search_val);
	return;
}
void accept_array_elements_from_user(int arr[]){
	printf("\nEnter %d elements:",MAX_SIZE);
	for(int i=0;i<MAX_SIZE;i++){
		printf("\nEnter the data for %d element :",i+1);
		scanf("%d",&arr[i]);
	}
	return;
}
void show_menu(){
	printf("\n****************************ARRAY SEARCH OPERATIONS - LINEAR , BINARY*****************************");
	printf("\nOption 1. INSERT ARRAY VALUES");
	printf("\nOption 2. LINEAR SEARCH");
	printf("\nOption 3. BINARY SEARCH  ");
	printf("\nOption 4. TRAVERSE(DISPLAY)  ");
	printf("\nOption 5. Exit");
	printf("\n\nEnter your choice[option 1-4]: ");
}
void display_array(int arr[]){
//param1-array name
	printf("\nArray-Elements[CURR SIZE:%d] :",MAX_SIZE);
	for(int i=0;i<MAX_SIZE;i++){
		printf("%d ",arr[i]);
	}
}
int get_input_search_element(){
	int search_value;
	printf("Enter the element to search:");
	scanf("%d",&search_value);
	return search_value;
}
