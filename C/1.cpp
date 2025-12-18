/*蓝桥杯*/
#include <stdio.h>
#include <math.h>
#include <time.h>
/*2.*/
//#define STDA 10000
//int main()
//{
//	int ret=0;
//	int a=1,b=1,c=1,d=0;
//	for(int i=3;i<20190324;i++){
//		d=(a+b+c)%STDA;
//		a=b;
//		b=c;
//		c=d;		
//	}	
//	printf("%d",d);
//
//	return 0;
// } 
/*3.*/
//int main(){
//	int card[7][4]={0},sum=0;
//	
//	for (int i=0;i<7;i++){
//		static int num=49;
//		for(int j=0;j<4;j++){
//			card[i][j]=num--;
//		} 
//	}
//	for(int k=0;k<7;k++){
//		sum+=card[k][3];
//	}
//printf("%d",sum);
//return 0;
//}
/*4.*/
#define ROW 4
#define COL 6
#define MAX 100
	int maze[ROW][COL];
	char order[MAX];
void Solve(int r,int c,int num)
{
	if(r==ROW-1&&c==COL-1);
	else{
		if(r+1<ROW&&!maze[r+1][c]){
			order[num++]='D';
			r++;
		}else if(c-1>=0&&!maze[r][c-1]){
			order[num++]='L';
			c--;	
		}else if(c+1<COL&&!maze[r][c+1]){
			order[num++]='R';
			c++;	
		}else if(r-1>=0&&!maze[r-1][c]){
			order[num++]='U';	
			r--;
		}else {
			maze[r][c]=1;	return;
		}
		return Solve(r,c,num);
	}
	return ;
}
int main()
{
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			scanf("%d",&maze[i][j]);		
		}
		getchar();		
	}

	Solve(0,0,0);
	printf("%s",order);
	return 0;
}	



//	clock_t start, end;    double cpu_time_used;
//	start = clock(); // 开始计时
//    end = clock(); // 结束计时
//    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // 计算时间，单位为秒
//    printf("\n运行时间：%f秒\n", cpu_time_used);
