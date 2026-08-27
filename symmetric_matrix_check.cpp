#include<stdio.h>
void display_matrix(int mat[][5],int ,int );
int main(){
	int mat_sparse[][5]={ {1,0,0,4,0 },
				          {0,1,0,0,5 },
					      {0,0,1,0,0 },
					      {4,0,0,1,0 },
						  {0,5,0,0,1 }	
					};
	int rows = sizeof(mat_sparse)/sizeof(mat_sparse[0]); //total matrix size / size of 1 row
	int cols = sizeof(mat_sparse[0])/sizeof(mat_sparse[0][0]); //size of 1 row / size of one element
	int symmetric = 1;
	display_matrix(mat_sparse,rows,cols);
	
	  // Symmetric matrix must be square
    if (rows != cols) {
        printf("Matrix is not symmetric.\n");
        return 0;
    }
    
	for (int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if (mat_sparse[i][j]!=mat_sparse[j][i]) symmetric = 0; 
		}
	}
	if(symmetric){
		printf("\nThe given matrix is symmetric.");
	}else{
		printf("\nThe given matrix is NOT symmetric.");	
	}
	
	return 0;
}
void display_matrix(int mat[][5],int row,int col){
	for (int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",mat[i][j]);	
		}
		printf("\n");
	}
}
