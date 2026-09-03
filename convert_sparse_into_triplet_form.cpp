/* converting a sparse matrix into triplet form
Algorithm
step1 : find the count of non zero elements . They will become the rows for the triplet matrix
		cols = 3 (to store r = row dimension,c = col dimension,v =actual values of the non zero element from the original matrix)
step2 : declare the triplet matrix with row as non zero count + 1(for the header information- orig mat rows, orig mat cols , no of non zero elements)
step3 : insert the (r,c,v ) int 1st row(header row) 
		r--> orig mat rows 
		c--> orig mat cols
		v--> no of non zero elements
step4 : store the (r,c,v) in the triplet matrix for all the non zero elements present in the original matrix
		r--> orig mat row vlaue = i 
		c--> orig mat col value = j
		v--> non zero element = mat[i][j]
*/
#include<stdio.h>
void convert_sparse_to_triplet(int [][5],int [][3]);//param1=sparse matrix , param2 = triplet matrix
void display_matrix_from_triplet(int[][3]);//param1=triplet matrix
void get_input_from_user_for_sparse(int[][5],int,int);
int get_element_from_triplet(int[][3],int,int);
void display_triplet_matrix(int[][3],int,int);//param1=triplet matrix 2d name;param2=rows of triplet matrix param3=cols of triplet matrix
void display_2d_matrix(int[][5],int,int);

int main(){
	int sparse_mat1[][5]={
						    {0,0,3,0,4},
						   	{0,0,5,7,0},
						   	{0,0,0,0,0},
						   	{6,0,0,0,0}
						   }; //declared 2d sparse matrix
	int sparse_rows = sizeof(sparse_mat1)/sizeof(sparse_mat1[0]); //total size of the 2d matrix/size of 1 row
	int sparse_cols = sizeof(sparse_mat1[0])/sizeof(int); //sizeof(sparse_mat1[0][0]); //total size of the 1 row/size of 1 element
	

	//take inputs from user
//	get_input_from_user_for_sparse(sparse_mat1,rows,cols);
	
	//display the matrix
	display_2d_matrix(sparse_mat1,sparse_rows,sparse_cols);
	
	//step1 : find the count of non zero elements 
	int non_zero_counter=0;
	for(int i=0;i<sparse_rows;i++){
		for(int j=0;j<sparse_cols;j++){
			if(sparse_mat1[i][j]!=0) {
				non_zero_counter++;
			}
		}
	}
	printf("\nNon zero count=%d",non_zero_counter);
	//step2 : declare the triplet matrix with row as non zero count + 1
	int triplet_mat1[non_zero_counter+1][3];
	
//	step3 : insert the (r,c,v ) int 1st row(header row) 
//		r--> orig mat rows 
//		c--> orig mat cols
//		v--> no of non zero elements
	triplet_mat1[0][0] = sparse_rows ;//rows
	triplet_mat1[0][1] = sparse_cols ;//rows
	triplet_mat1[0][2] = non_zero_counter ;//no of non zero elements
//  step4 : store the (r,c,v) in the triplet matrix for all the non zero elements present in the original matrix
//		r--> orig mat row vlaue = i 
//		c--> orig mat col value = j
//		v--> non zero element = mat[i][j]
	convert_sparse_to_triplet(sparse_mat1,triplet_mat1);
	
	//display the triplet matrix
	display_triplet_matrix(triplet_mat1,non_zero_counter+1,3);
	
	
	//display the matrix using triplet form
	display_matrix_from_triplet(triplet_mat1);
	
	return 0;
}
int get_element_from_triplet(int triplet[][3],int i,int j){
	int trip_row = triplet[0][2]+1; //no of non zero count + 1(for the header)
	for(int row=1;row<trip_row;row++){
		if (triplet[row][0]==i && triplet[row][1]==j ){
			return triplet[row][2]; //return the actual value
		}
	}
	return 0;//if not found in the triplet matrix return 0
}
void display_matrix_from_triplet(int triplet_mat1[][3]){
	//display matrix from triplet
	int sparse_rows = triplet_mat1[0][0]; //rows
	int sparse_cols = triplet_mat1[0][1]; //cols
	printf("\nOriginal Matrix:\n");
	for(int i=0;i<sparse_rows;i++){
		for(int j=0;j<sparse_cols;j++){
			printf("%d ",get_element_from_triplet(triplet_mat1,i,j));
		}
		printf("\n");
	}
}

void convert_sparse_to_triplet(int sparse_mat1[][5],int triplet_mat1[][3]){
	int sparse_rows = triplet_mat1[0][0]; //rows
	int sparse_cols = triplet_mat1[0][1]; //cols
	int k = 1; //row tracker for the triplet matrix
	for(int i=0;i<sparse_rows;i++){
		for(int j=0;j<sparse_cols;j++){
			if(sparse_mat1[i][j]!=0) {
				triplet_mat1[k][0] = i ;//rows
				triplet_mat1[k][1] = j ;//rows
				triplet_mat1[k][2] = sparse_mat1[i][j] ;//no of non zero elements
				k++; //increment the row counter by 1
			}
		}
	}
}
void display_triplet_matrix(int mat[][3],int rows,int cols){
	printf("\nTriplet Matrix :\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
void display_2d_matrix(int mat[][5],int rows,int cols){
	printf("\nMatrix :\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
void get_input_from_user_for_sparse(int sparse_mat1[][5],int  rows,int cols){
	printf("\nEnter the elements for the Matrix:\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("Enter the matrix[%d,%d] element:",i,j);
			scanf("%d",&sparse_mat1[i][j]);
		}
	}
	
}
	
