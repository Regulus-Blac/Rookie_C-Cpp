#include <stdio.h>
int main()
{
	int x,y;
    scanf("%d %d",&x,&y);
    
    int d=x;
    
    for(d=x;d>1;d--)   //d=2时是最后一次进循环，但是会--，所以刚好可以输出1的正确结果 
    {
    	if(x%d==0)
    	{
			if(y%d==0)
				goto out;	
		}
	}
  
    out:printf("%d",d);
	return 8;
}
