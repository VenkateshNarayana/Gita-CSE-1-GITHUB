#include<stdio.h>
void display_matrix(int mat[][5],int ,int );
int main(){
	int mat_sparse[][5]={ {1,3,0,1,0 },
				          {2,1,4,0,0 },
					      {0,3,1,5,0 },
					      {0,0,5,1,6 },
						  {0,0,0,3,1 }	
					};
	int rows = sizeof(mat_sparse)/sizeof(mat_sparse[0]); //total matrix size / size of 1 row
	int cols = sizeof(mat_sparse[0])/sizeof(mat_sparse[0][0]); //size of 1 row / size of one element
	int tridiagonal = 1;
	display_matrix(mat_sparse,rows,cols);
	
    //check for band one element before(predecessor) and one element after(successor) of the principal diagonal
    //should be non zero(first row only successor and last row to contain only predecessor).
	//All other elements other than above should be zero.
	for (int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if (i==j && mat_sparse[i][j]==0) {
				tridiagonal = 0; //if diagonal element is zero
			}
			if (i==j && i==0 && mat_sparse[i][i+1]==0) {
				tridiagonal = 0; //1st element of principal diagonal has successor as zero
			}
			if (i==j && i==(rows-1) && mat_sparse[i][i-1]==0) {
				tridiagonal = 0; //last element of principal diagonal has predecessor as zero
			}
			if (i==j && i!=0 && i!=(rows-1) && (mat_sparse[i][j-1]==0 || mat_sparse[i][j+1]==0)){ 
				tridiagonal = 0; //principal diagonal has successor/predecessor as zero
			}
			if( i==0 && j>(i+1) && mat_sparse[i][j]!=0){
				tridiagonal = 0; //All other elements of first row of principal diagonal excluding the successor is not zero
			}
			if( i==(rows-1) && j<(i-1) && mat_sparse[i][j]!=0){
				tridiagonal = 0; //All other elements of last row of principal diagonal excluding the predecessor is not zero
			}
			if( i>0 && i<(rows-1) && j<(i-1) && mat_sparse[i][j]!=0){
				tridiagonal = 0; //All other elements between first and  last row of principal diagonal excluding the predecessor is not zero
			}
			if( i>0 && i<(rows-1) && j>(i+1) && mat_sparse[i][j]!=0){
				tridiagonal = 0; //All other elements between first and  last row of principal diagonal excluding the successor is not zero
			}
		}
	}
	if(tridiagonal){
		printf("\nThe given matrix is Tridiagonal.");
	}else{
		printf("\nThe given matrix is NOT Tridiagonal.");	
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
