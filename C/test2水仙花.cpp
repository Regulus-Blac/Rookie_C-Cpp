#include<stdio.h>
//试一波水仙花数
int main()
{
    int x;
    scanf("%d",&x);
    int mark=1;int num=x;
    while(num>1)
    {num--;
    mark*=10;}
    
    int t=mark;
    
    for(;t<mark*10;t++)
    {int sum=0;
    int y=t;int m=mark;
        while(m>0)
        {
        int ret=y/m;
		y%=m;
        m/=10;
        int i=1;
        int r=ret;
            while(i<x)
            {i++;
            ret*=r;
            }
        sum+=ret ;
        }
        if(sum==t)
        printf("%d ",t);
    }
    return 0;
}
