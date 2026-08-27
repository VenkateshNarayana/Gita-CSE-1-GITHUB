#include<stdio.h>
void display_matrix(int mat[][4],int ,int );
int main(){
	int tri_matrix[][4] = {{1,  5,  6,  0},
 					 	   {0,  2,  8,  9},
 					 	   {0,  0,  3,  10},
 					 	   {0,  0,  0,  4}
					};
	int upper = 1;
	int lower = 1;
	display_matrix(tri_matrix,4,4);
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			//check if all the elements below main diagonal are zero
			if(j>=i && tri_matrix[i][j]==0){
				upper=0;//set upper as false
			}
			if(j<=i && tri_matrix[i][j]==0){
				lower=0; //set lower as false
			}
		}
	}
	if(!upper && !lower){
		printf("The matrix is not triangular!!!");
	}
	if(upper){
		printf("The matrix is upper triangular matrix!!!");
	}
	if(lower){
		printf("The matrix is lower triangular matrix!!!");
	}
	
	return 0;
}
void display_matrix(int mat[][4],int row,int col){
	for (int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",mat[i][j]);	
		}
		printf("\n");
	}
}
