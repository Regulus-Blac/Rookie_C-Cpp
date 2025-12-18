/*01*/
/*回字形扫描矩阵，列数为4*/
//#include<stdio.h> 
//#define N 4
//int HUIscan(int matrix[][4],int m,int n,int start)
//{
//	if(n>0&&m>0) {
//		int row,col;
//	for(col=start;col<n+start;col++)
//		printf("%d ",matrix[start][col]);
//	for(row=start+1;row<m+start;row++)
//		printf("%d ",matrix[row][n+start-1]);
//	for(col=n+start-2;col>start;col--)
//		printf("%d ",matrix[m+start-1][col]);
//	for(row=m+start-1;row>start;row--)
//		printf("%d ",matrix[row][start]);
//	return HUIscan(matrix,m-2,n-2,start+1);
//	}else
//		return 0;
// } 
//int main()
//{
//	int M,n;
//	scanf("%d",&M);
//	int matrix[M][N];
//	getchar();
//	for (int i=0;i<M;i++) {
//		for (int j=0;j<N;j++) {
//			scanf("%d",&n);
//			getchar();
//			matrix[i][j]=n;	
//		}
//	}
//		
//	HUIscan(matrix,M,N,0);	
//	return 0;
//}
/*02*/
/*Z字形扫描*/
//#include<stdio.h>
//int upgo(int M,int N,int **matr,int i,int j)
//{
//	printf("%d ",matr[i][j]);
//	if(i==M-1&&j==N-1) {
//		return 0;
//	}else if(i-1<0) {
//		return downgo(M,N,matr,i,j+1);
//	}else if(j+1>N-1) {
//		return downgo(M,N,matr,i+1,j);
//	}else{
//		return upgo(M,N,matr,i-1,j+1);
//	}	
//}
//int downgo(int M,int N,int **matr,int i,int j)
//{
//	printf("%d ",matr[i][j]);
//	if(i==M-1&&j==N-1) {
//		return 0;
//	}else if(i+1>M-1) {
//		return upgo(M,N,matr,i,j+1);
//	}else if(j-1<0) {
//		return upgo(M,N,matr,i+1,j);
//	}else{
//		return downgo(M,N,matr,i+1,j-1);
//	}	
//}
/*                                               错误1：上面的不可以，因为两函数互相调用，必然在声明一个的时候另一个还没有声明*/
#include <stdio.h>
int jumpgo(int M,int N,int *matr,int i,int j,int flag)
{
	/*int jumpgo(int M,int N,int matr[][N],int i,int j,int flag)
{
    
    if(i==M-1&&j==N-1) {
        printf("%d",matr[i][j]);
        return 0;
        }
    printf("%d ",matr[i][j]);*/             //   错误2：二维数组若传进去要明确列（为常数），变量不可以，为此我们可以传入指针 
	if(i==M-1&&j==N-1) {
		printf("%d",*(matr+i*N+j));			// equals to i行j列 
		return 0;
		}
	printf("%d ",*(matr+i*N+j));	
	if(flag==1){	//up
		if(i-1<0&&j+1>N-1) {//up特殊情况（交集） 
			return jumpgo(M,N,matr,i+1,j,0);
		}else if(i-1<0) {	//up->right
			return jumpgo(M,N,matr,i,j+1,0);
		}else if(j+1>N-1) {	//up->down
			return jumpgo(M,N,matr,i+1,j,0);
		}else{
			return jumpgo(M,N,matr,i-1,j+1,1);
		}		
	}else {			//down
		if(i+1>M-1&&j-1<0) {
			return jumpgo(M,N,matr,i,j+1,1);
		}else if(i+1>M-1) {
			return jumpgo(M,N,matr,i,j+1,1);
		}else if(j-1<0) {
			return jumpgo(M,N,matr,i+1,j,1);
		}else{
			return jumpgo(M,N,matr,i+1,j-1,0);
		}
	}
}
int main()
{
	int M,N,a;
	scanf("%d %d",&M,&N);
	int matr[M][N];
	for (int i=0;i<M;i++) {
		for (int j=0;j<N;j++) {
			scanf("%d",&a);
			getchar();
			matr[i][j]=a;	
		}
	}	
	jumpgo(M,N,matr[0],0,0,1);
										//传入首行地址（类型为指针） 
return 0;
}

