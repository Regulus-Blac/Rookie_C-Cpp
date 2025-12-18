#include <bits/stdc++.h>

using namespace std;

void fun_const();
void fun_rodata();
void fun_cite1();
void fun_cite2();
void fun_cite3();
void f1(int &&x,int &&y)
{
    cout<<"x = "<<x<<" y = "<<y<<endl;
    x *= 10;
    y *= 10;
    cout<<"x = "<<x<<" y = "<<y<<endl;
}
void f2(const int &x,const int &y)
{
    cout<<"x = "<<x<<" y = "<<y<<endl;
    //  常量不可修改
    *(int*)&x *= 10;
    *(int*)&y *= 10;
    cout<<"x = "<<x<<" y = "<<y<<endl;
}
void swap(int *x, int *y)
{   int t=*x;
    *x=*y;
    *y=t;
    printf("version ptr\n");
}
void swap(int &x, int &y)
{   int t=x;
    x=y;
    y=t;
    printf("version &\n");
}

int main()
{
    // fun_const();
    // fun_rodata();
    // fun_cite1();
    // fun_cite2();
    fun_cite3();
    return 0;
}
void fun_const()
{
    
    int x = 1;
    const int y = x;            //通过强制类型转换修改内存的值从而改变const int 的值
    *(int *)&y = 10;
    const int yy = 2;           //被编译器优化了
    *(int *)&yy = 20;
    volatile const int yyy = 3; //每次访问都要访问对应的内存
    *(int *)&yyy = 30;  
    printf("y = %d, yy = %d, yyy = %d\n",y,yy,yyy);
    /*10 2 30*/
}
void fun_rodata()
{
    //  字符串存在.rodata
    char *p1 = (char *)"hello";
    const char *p2 = "hello";
    char p3[] = "hello";
    // p1[0] = 'H'; //会直接修改rodata节的内容，程序会die
    // p2[0] = 'H'; //const char *类型无法修改指向的内容
    p3[0] = 'H';
    for(int i = 0;i < 5;i ++)   printf("%c ",p1[i]);
    for(int i = 0;i < 5;i ++)   printf("%c ",p3[i]);
}
void fun_cite1()
{
    int a = 10,b = 20;
    swap(&a,&b);
    swap(a,b);

    int x = 1,&y = x;
    y = 20;
    cout<<x<<" "<<y;
/*      version ptr     version &   */
/*      20      20      */
}
void fun_cite2()
{
    int x = 20;
    int &y = x;
    int &z = y;
    printf("&x = %p,&y = %p,&z = %p\nx = %d,y = %d,z = %d\n",&x,&y,&z,x,y,z);
    
    int xx = 5;
    int &yy = xx;
    const int &cyy = xx;
    const int &w = 4;
    //int &ww = 5;      //必须为左值
}
void fun_cite3()
{
    int x = 3,y = 4;
    f1(x++,y++);
    cout<<"x = "<<x<<" y = "<<y<<endl;
    f2(x++,y++);
    cout<<"x = "<<x<<" y = "<<y<<endl;   
}
