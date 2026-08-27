#include<stdio.h>
void display_2D_matrix(int[][4],int,int);
int main(){
	int diag_matrix[][4] = {{1,  0,  0,  0},
 					 	   {0,  1,  0,  0},
 					 	   {0,  0,  1,  0},
 					 	   {0,  0,  0,  1}
					};
	int identity=1;//assume the given matrix as identity
	//display the matrix
	display_2D_matrix(diag_matrix,4,4);
	
	//check for diagonal
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==j && diag_matrix[i][j]!=1){
				identity = 0; //set identity as false
				break;
			}else if(i!=j && diag_matrix[i][j]!=0){
				identity = 0; //set identity as false
				break;
			}
		}
		if (identity==0) break;
	}
	if(identity){
		printf("Its identity matrix!!!");	
	}else{
		printf("Its NOT identity matrix!!!");	
	}
	return 0;
}
void display_2D_matrix(int mat[][4],int mat_rows,int mat_cols){
	printf("\nMatrix Data:\n");
	for(int i =0 ;i<mat_rows;i++){
		for(int j=0;j<mat_cols;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}
