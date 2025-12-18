#include<iostream>
#include<functional>
using namespace std;

int Add(int a, int b)   {return a + b;}
int Minus(int a,int b)  {return a - b;}
auto ABS = [](int a,int b){return (a - b) >= 0 ? (a - b): (b - a);};
struct Multiply{
    int operator()(int a,int b){return a * b;}
};
int main()
{
    function<int(int,int)> func;
    func = Add;
    cout<<func(2 , 3)<<endl;
    func = Minus;
    cout<<func(2 , 3)<<endl;
    func = ABS;
    cout<<func(2 , 3)<<endl;
    func = Multiply();
    cout<<func(2 , 3)<<endl;
    return 0;
}