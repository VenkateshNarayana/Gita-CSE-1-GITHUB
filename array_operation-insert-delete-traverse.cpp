/* Array operations - insert, delete, traverse
1. insert - insert_at_end -O(1), insert_at_index -O(n), insert_at_begin -O(n)
2. delete - delete_at_end -O(1), delete_at_index -O(n), delete_at_begin -O(n)
3. traverse -display_array - O(n) -- visiting every element of array
*/
#include <stdio.h>
#define MAX_SIZE 5
int curr_index = 0 ; //to track the current index & size of the array
void insert_at_end(int[],int);//param1-array name,param2-value
void insert_at_index(int[],int,int);//param1-array name,param2-index,param3-value
void insert_at_begin(int[],int);//param1-array name,param2-value

void display_array(int[]);//param1-array name
void delete_at_end(int[]);//param1-array name
void delete_at_index(int[],int);////param1-array name,param2-index
void delete_at_begin(int[]);////param1-array name

int get_array_value_from_user();//
int get_array_index_from_user();//

void show_menu();
int main(){
	int my_arr[MAX_SIZE]={0};//declare and initialize elements to zero
	int choice=0,index=0,value=0;
	do{
		show_menu();
		scanf("%d",&choice);
		switch(choice){
			//insert at begin
			case 1: value =  get_array_value_from_user();   //accept the array value from user
					insert_at_begin(my_arr,value);
					break;
			//insert at index
			case 2: index = get_array_index_from_user();   //accept index from user
			        value =  get_array_value_from_user();  //accept the array value from user
					insert_at_index(my_arr, index, value);
					break;
			//insert at end	
			case 3: value =  get_array_value_from_user();  //accept the array value from user
					insert_at_end(my_arr, value);
					break;
			//delete at begin
			case 4: delete_at_begin(my_arr);
					break;
			//delete at index
			case 5: index = get_array_index_from_user();
					delete_at_index(my_arr,index);
					break;
					
			//delete at end
			case 6: delete_at_end(my_arr);
					break;
			//traverse
			case 7: display_array(my_arr);
				    break;
			case 8: break;
			default: printf("\nInvalid choice,please select between (1-8).");
		}
	}while(choice!=8);
	printf("\nThank you.Exitted Application successfully!!!");
	
}
int get_array_index_from_user(){
	int user_input;
	printf("\nEnter the index :");
	scanf("%d",&user_input);
	return user_input;
}
int get_array_value_from_user(){
	int user_input;
	printf("\nEnter the value :");
	scanf("%d",&user_input);
	return user_input;
}
void show_menu(){
	printf("\n****************************ARRAY OPERATIONS - TRAVERSE , INSERT, DELETE*****************************");
	printf("\nOption 1. INSERT AT BEGIN   		\tOption 4. DELETE AT BEGIN");
	printf("\nOption 2. INSERT AT INDEX   		\tOption 5. DELETE AT INDEX");
	printf("\nOption 3. INSERT AT END     		\tOption 6. DELETE AT END");
	printf("\nOption 7. TRAVERSE(DISPLAY ARRAY) \tOption 8. Exit");
	printf("\n\nEnter your choice[option 1-8]: ");
}
void delete_at_begin(int arr[]){
	delete_at_index(arr,0);
}
void delete_at_index(int arr[],int index){
	if(index<0 || index>curr_index){
		printf("\nInvalid index(%d).....",index);
		return;
	}
	if(curr_index<=0){
		printf("Array is empty,cannot perform delete..!!!!");
		return;
	}	
	for(int i=index;i<curr_index-1;i++){
		arr[i] = arr[i+1];
	}
	arr[curr_index]=0;
	curr_index--; //decrement the size by 1
	printf("\nDeleted value from array successfully.");
}
void delete_at_end(int arr[]){
if(curr_index<=0){
	printf("Array is empty,cannot perform delete..!!!!");
	return;
}	
	curr_index--;
	arr[curr_index]=0;
	printf("\nDeleted value from array successfully.");
}
void insert_at_begin(int arr[],int value){
	insert_at_index(arr,0,value);
}
void insert_at_index(int arr[],int index,int value){
	if(index<0 || index>curr_index){
		printf("\nInvalid index(%d).....",index);
		return;
	}
	if(curr_index>=MAX_SIZE){
		printf("Array is full,cannot insert %d value..!!!!",value);
		return;
	}
	for(int i=curr_index-1;i>=index;i--){
		arr[i+1]=arr[i];//right shift
	}
	arr[index]=value;
	curr_index++;//increment the size by 1	
	printf("\nInserted @%d value into array successfully.",value);
}
void insert_at_end(int arr[],int value) {
//param1-array name,param2-value
if(curr_index>=MAX_SIZE){
	printf("Array is full,cannot insert %d value..!!!!",value);
	return;
}
	arr[curr_index++]=value;
	printf("\nInserted @%d value into array successfully.",value);
}
void display_array(int arr[]){
//param1-array name
	printf("\nMyArray[CURR SIZE=%d]: ",curr_index);
	for(int i=0;i<curr_index;i++){
		printf("%d ",arr[i]);
	}	
}

