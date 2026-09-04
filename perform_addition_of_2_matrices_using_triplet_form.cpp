/* perform Addtion of 2 matrices using triplet form
Algorithm- Perform matric addition addition
//step1 : check if rows and cols of matrix 1 are same as rows and cols of matrix 2, if not then addition cannot be performed

//step2: create the result_mat[r=?][c=?]
//step3: populate the header row
//step4: populate the result matrix by perform addition(matrix 1 with matrix 2)
	//case1: if rows & cols are same then we add only entry with 
		//r = mat1 row 
		//c = mat1 col
		//v = value of mat1 + value mat2
	//case2: if rows are same but cols are different 
		// then we add first entry col is less 
		//r = mat1 row  (if col of mat1 is less than col of mat2)
		//c = mat1 col (if col of mat1 is less than col of mat2)
		//v = value of mat1 (if col of mat1 is less than col of mat2)
	//case3: if rows & cols are different 
		// then we add first entry row is less
		//r = mat1 row (if row of mat1 is less than row of mat2)
		//c = mat1 col (if row of mat1 is less than row of mat2)
		//v = value of mat1 (if row of mat1 is less than row of mat2)
//step5:A) add any leftover from matA add it to result matrix
		B) add any leftover from matB add it to result matrix
//step6: display the triplet
//step7: display sparse from triplet

*/
#include<stdio.h>
void display_triplet_matrix(int[][3]);
void display_sparse_from_triplet(int [][3]);
int get_element_from_triplet(int [][3],int,int);
int main(){
	int trip_matA[][3]={
						{3,3,3},
					    {0,0,5},
					   	{1,2,3},
					   	{2,1,4}
						};
	//print the triplet
	
	display_triplet_matrix(trip_matA);
	int trip_matB[][3]={
						{3,3,3},
					    {0,0,2},
					   	{1,2,6},
					   	{2,0,1}
						};
	//print the triplet
	display_triplet_matrix(trip_matB);
	//perform addition
	//step1: create the result_mat[r=?][c=?]
	int res_mat_rows = trip_matA[0][2]+trip_matB[0][2] +1 ; //1 for the header row
	int res_trip_mat[res_mat_rows][3]={0}; //declare and initialize the values to 0
	
	//step2: populate the header row
	res_trip_mat[0][0]=  trip_matA[0][0]; //r
	res_trip_mat[0][1]=  trip_matA[0][1]; //c
	res_trip_mat[0][2]=  trip_matA[0][2]+trip_matB[0][2]; //v = non zero count of matA + non zero count of matB
	
	//step3: populate the result matrix by perform addition
	int i=1,j=1,k=1;
	int matA_rows = trip_matA[0][2]+1; //non zero count + 1 (add for the header)
	int matB_rows = trip_matB[0][2]+1; //non zero count + 1 (add for the header)
	
	while(i<matA_rows && j<matB_rows){
		//case1: if rows & cols are same then we add only entry with r = mat1 row, c= mat1 col and value = value of mat1 + value mat2
		if(trip_matA[i][0]==trip_matB[i][0] && trip_matA[i][1]==trip_matB[i][1]){
			res_trip_mat[k][0]=  trip_matA[i][0]; //r
			res_trip_mat[k][1]=  trip_matA[i][1]; //c
			res_trip_mat[k][2]=  trip_matA[i][2]+trip_matB[j][2]; //v = non zero count of matA + non zero count of matB
			i++;
			j++;
			k++;
		}
		//case2: if rows are same but cols are different 
		// then we add first entry col is less 
		else if(trip_matA[i][0]==trip_matB[i][0] && trip_matA[i][1]<trip_matB[i][1]){
			res_trip_mat[k][0]=  trip_matA[i][0]; //r
			res_trip_mat[k][1]=  trip_matA[i][1];//c
			res_trip_mat[k][2]=  trip_matA[i][2]; //v = non zero count of matA 
			i++;
			k++;
		}
		else if(trip_matA[i][0]==trip_matB[i][0] && trip_matA[i][1]>trip_matB[i][1]){
			res_trip_mat[k][0]=  trip_matB[j][0]; //r
			res_trip_mat[k][1]=  trip_matB[j][1];//c
			res_trip_mat[k][2]=  trip_matB[j][2]; //v = non zero count of matB
			j++;
			k++;
		}
		//case3: if rows & cols are different 
		// then we add first entry row is less
		else if(trip_matA[i][0]<trip_matB[i][0]){
			res_trip_mat[k][0]=  trip_matA[i][0]; //r
			res_trip_mat[k][1]=  trip_matA[i][1]; //c
			res_trip_mat[k][2]=  trip_matA[i][2]; //v = non zero count of matA 
			i++;
			k++;
		}else{
			res_trip_mat[k][0]=  trip_matB[j][0]; //r
			res_trip_mat[k][1]=  trip_matB[j][1]; //c
			res_trip_mat[k][2]=  trip_matB[j][2]; //v = non zero count of matB
			j++;
			k++;
		}
	}
	//any leftover from matA add it to result matrix
	while(i<matA_rows){
		res_trip_mat[k][0]=  trip_matA[i][0]; //r
		res_trip_mat[k][1]=  trip_matA[i][1]; //c
		res_trip_mat[k][2]=  trip_matA[i][2]; //v = non zero count of matA 
		i++;
		k++;
	}
	//any leftover from matB add it to result matrix
	while(j<matB_rows){
		res_trip_mat[k][0]=  trip_matB[j][0]; //r
		res_trip_mat[k][1]=  trip_matB[j][1]; //c
		res_trip_mat[k][2]=  trip_matB[j][2]; //v = non zero count of matB
		j++;
		k++;
	}
	
	//step4 of displaying triplet
	display_triplet_matrix(res_trip_mat);
	
	//step5 sparse from triplet
	display_sparse_from_triplet(res_trip_mat);
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
