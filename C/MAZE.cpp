/*标记为 1 的为障碍，标记为 0 的为可以通行的地方
迷宫的入口为左上角，出口为右下角.从入口开始，可以按 DRRURRDDDR 的顺序通过迷宫，
其中D、U、L、R 分别表示向下、向上、向左、向右走
请找出一种通过迷宫的方式，其使用的步数最少，在步数最少的前提下
请找出字典序最小的一个作为答案。
请注意在字典序中 D<L<R<U
*/
#include <stdio.h>
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
