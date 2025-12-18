/*	回溯！ 
求解N皇后问题
即在N×N的棋盘上摆放N个皇后，要求任意两个皇后不能在同一行、同一列、同一对角线上
输入棋盘的大小N（N取值1-10）
如果能满足摆放要求，则输出所有可能的摆放法的数量，否则输出“无解”*/

#include<stdio.h>
	
	int col[10]={0};//列 
	int d1[20]={0},d2[20]={0};//反对角线和对角线 
	int ret=0;
	
void Queen(int n,int row)//行数 
{
	int c; 
	for(c=0;c<n;c++){
		
		if(col[c]==0&&d1[row+c]==0&&d2[row-c+n]==0){
			col[c]=1;d1[row+c]=1;d2[row-c+n]=1; //占领列和对角线
			
			if(row<n-1){
				Queen(n,1+row); 
					
			}else{	ret++;	}//不放在这个里面是因为不管if还是else,递归完了都要回溯 
			
			col[c]=0;d1[row+c]=0;d2[row-c+n]=0;	//回溯 
		}
			//回溯不放在这里是因为，若放在这里即使不符合的皇后走完循环也会清零，造成限制条件减少 
	
	}	
} 
int main()
{
	int n;	
	scanf("%d",&n);
	
	if(n>3&&n<11){
		Queen(n,0);
		printf("%d",ret);
	}else{printf("无解"); 
	}
	return 0;
}


