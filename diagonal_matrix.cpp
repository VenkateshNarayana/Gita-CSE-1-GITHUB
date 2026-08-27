#include<stdio.h>
void display_2D_matrix(int[][4],int,int);
int main(){
	int diag_matrix[][4] = {{1,  0,  0,  0},
 					 	   {0,  2,  0,  0},
 					 	   {0,  0,  3,  0},
 					 	   {0,  0,  0,  4}
					};
	int diagonal=1;
	//display the matrix
	display_2D_matrix(diag_matrix,4,4);
	
	//check for diagonal
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==j && diag_matrix[i][j]==0){
				diagonal = 0;
				break;
			}else if(i!=j && diag_matrix[i][j]!=0){
				diagonal = 0;
				break;
			}
		}
		if (diagonal==0) break;
	}
	if(diagonal){
		printf("Its diagonal matrix!!!");	
	}else{
		printf("Its NOT diagonal matrix!!!");	
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
