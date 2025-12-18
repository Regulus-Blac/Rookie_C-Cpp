#include <bits/stdc++.h>
using namespace std;

//  1.初始化
class A {
    //定义时初始化
public:
    int x {10}; // 初始化 x=10; 可写成 int x=10;
    int &y {x}; // y 中的内容为 x的地址
    const int z{20};
    int u=30;
    // A a;   类中不能包含自己类型的完整对象，会无限递归
    A ()
    {
        cout<<"Construct A"<<endl;
    }
    void display()
    {
        printf("Class A :\bx = %d y = %d z = %d u = %d\n",this->x,this->y,this->z,this->u);
    }
};
class B {
    //构造函数前（初始化列表中）初始化
public:
    int x;
    int &y;
    const int z;
    static int u;
    static const int uu = 5;
    A a;
    A b{};
    A *p;
    A &q;
    B(int &t1,int t2):y(t1),z(t2),a(),q(a){this->x = 0;cout<<"Construct B"<<endl;};
    //  其中a是调用的A类的默认无参构造函数
    void display()
    {
        printf("Class B :\bx = %d y = %d z = %d u = %d\n",this->x,this->y,this->z,this->u);
        a.display();
        b.display();
    }
};
int B::u = 4;

//  2.成员指针
class Student {
public: 
    int number = 10;
    char name[15];
    float score;
public:
    void SetNum(int x){number = x;}
    void display()
    {
        cout<<"number = "<<number<<endl<<"name = "<<name<<endl<<"score = "<<score<<endl;
    }
};
void fun_classptr()
{
    Student Zhang;
    //  成员指针，为类中的偏移地址
    int Student::*p = &Student::number;
    cout<<Zhang.*p<<endl;
    //  普通指针只能通过具体的实例来进行，为具体内存的地址
    int *q = &Zhang.number;
    // int *p = &Student::number;

    //  成员函数指针
    void (Student::*pf)(int) = Student::SetNum;
    void (Student::*pf1)() = Student::display;
    (Zhang.*pf)(20);
    (Zhang.*pf1)();
}
//  3.const volatile mutable
class C{
public:
    int x;
    static int y;
    mutable int z;
    void f()const{
        //x ++;   //收到this指针为const的限制
        y = 40; //  可以修改静态成员变量,但这里不是初始化
        z = 30; //mutable可改
    }
};
void fun_words()
{

}
int main()
{
    //  非类的成员变量可以用()初始化，在类中要用大括号
    // int x(10);
    // B b(x,2);
    // b.display();
    //  成员指针
    // fun_classptr();
    // const volatile mutable
    fun_words();
    return 0;
}