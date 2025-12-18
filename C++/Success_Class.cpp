#include <bits/stdc++.h>
using namespace std;
namespace C{int j = 3;}
using namespace C;
class A{
private: 
    int a;
public:
    A( ):a(8) { cout<<a<<" " ; }
    A(int x):a(x) { cout<<a<<" "; }
    ~A( ){ cout<<a; }
};

class B: public A{
private: 
    int b, c;
    const int d; //有只读成员d， 故B必须定义构造函数
    A x, y, z;
public:
    B(int v):b(v), y(b+2), x(b+1), d(b), A(v) {//   z利用的是无参默认构造函数
        c=v;
        cout<<b<<c<<d;
        cout<<"ConstructB "; //b, c可再次赋值
    }
    ~B( ){ cout<<"Destory"; }
};

int x = 2 * j;      //  用的命名空间中的j
int j = 5;          //  全局变量

int main(){ 
    // A v(2);
    // B u(1); 
    // A* pa;  B* pb;
    printf("%d %d",x,::j);

    return 0;
}
/*1 2 3 8 111ConstructB Destory8321*/
/*去掉A(v)之后 8 2 3 8 111ConstructB Destory8328*/