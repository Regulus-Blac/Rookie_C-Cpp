#include <bits/stdc++.h>
using namespace std;
//  1.缺省参数
void multi_args_sum();
int sum1(int n,...);
int sum2(int n,...);
int sum3(initializer_list<int>nums);
//  2.函数重载
//  (1)无法按返回值重载
double f(int);
// float f(int);
//  (2)可根据参数区分
int g(int);
int g(int ,int x= 3);
int g(int ,...);
//  (3)可参数顺序区分
int h(int,char);
int h(char,int);

int main()
{
    multi_args_sum();
    return 0;
}
void multi_args_sum()
{
    int (*sum_ptr[2])(int,...)={sum1,sum2};
    for(int i = 0;i < 2;i ++){
        int a = sum_ptr[i](7,1,2,3,4,5,6,7),b = sum_ptr[i](2,4,-5);
        printf("a = %d, b = %d\n",a,b);
    }
    int c = sum3({5,4,6,3,1,-5,-6,8,-1});
    printf("beat way's result is %d\n",c);
}
int sum1(int n,...)
//  只适用于参数由栈传递的情况（32位）
{
    int ans = 0;
    int *p = &n + 1;
    for(int i = 0;i < n;i ++)   ans += p[i];
    return ans;
}
int sum2(int num,...)
//  普适
{
    int ans = 0;
    va_list ap;                 //char *ap
    va_start(ap,num);           //ap = (char*)&num + sizeof(int)
    for(int i = 0;i < num;i ++) ans += va_arg(ap,int);//s+=*(int*)ap;ap+=4;
    va_end(ap);                 //ap=0
    return ans;
}
int sum3(initializer_list<int>nums)
{
    int ans = 0;
    for(auto n : nums)  ans += n;
    return ans;
}

