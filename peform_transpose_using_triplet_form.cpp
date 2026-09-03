/* perform Transpose using triplet form
Algorithm
Step1: Create a triplet trans matrix with row = (non zero count from header row of original triplet) + 1(header row)
      : col = 3 (to store r,c,v)
Step2: populate the triplet trans matrix with values swapped for col1 and col2. keep the col3 values unchanged
Step3: display the triplet
Step4: display the sparse from the triplet
*/
#include<stdio.h>
void display_triplet_matrix(int[][3]);
void display_sparse_from_triplet(int [][3]);
int get_element_from_triplet(int [][3],int,int);
int main(){
	int triplet_mat[][3]={
							{4,5,5},
						    {0,2,3},
						   	{0,4,4},
						   	{1,2,5},
						   	{1,3,7},
						   	{3,0,6}
						   };
	//print the triplet
	display_triplet_matrix(triplet_mat);
	//step1 
	int trip_tran_rows = triplet_mat[0][2]+1 ; //non zero count + 1(for the header)
	int triplet_trans_mat[trip_tran_rows][3];
	//step2
	for(int i=0;i<trip_tran_rows;i++){
		triplet_trans_mat[i][0] = triplet_mat[i][1];  //r = store col value of original triplet matrix
		triplet_trans_mat[i][1] = triplet_mat[i][0];  //c = store row value of original triplet matrix
		triplet_trans_mat[i][2] = triplet_mat[i][2];  //v = store value of original triplet matrix
	}
	//step3
	display_triplet_matrix(triplet_trans_mat);
	//step4
	display_sparse_from_triplet(triplet_trans_mat);
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
void display_sparse_from_triplet(int triplet_mat1[][3]){
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
void display_triplet_matrix(int triplet_mat[][3]){
	int rows = triplet_mat[0][2]+1;
	printf("\nTriplet Matrix :\n");
	printf("\nRows \tCol \tValue\n");
	for(int i=0;i<rows;i++){	
		printf("\n%d \t%d \t%d", triplet_mat[i][0],triplet_mat[i][1],triplet_mat[i][2]);
	}
}
