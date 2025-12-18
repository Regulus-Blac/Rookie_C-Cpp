/*不能仅因异常规范不同而重载,可以根据第一参数是否可修改而重载
错误重载    void f() void f() noexcept
正确重载    void f() void f() const */
#include<bits/stdc++.h>
using namespace std;
#define LENGTH 80

class MyException{
public:
    char description[LENGTH];
    MyException(const char *t){
        //  strnpy不会在最后添加空字符，除非src小于cnt
        strncpy(description,t,strlen(t));
        cout << description << "Construct A"<<endl;
    }
    ~MyException(){
        cout<< description <<"Deconstruct A"<<endl;
    }
};
void f1()
{
   MyException exc("f1");
   throw "exception" ;
   cout<<"f1 end\n";
}

void f2()
{
    MyException exc("f2");
    f1();
    cout<<"f2 end\n";
}
class A {
public:
    A() {      cout << "construct A" << endl; }
    ~A() { cout << "deconstruct A" << endl; }
};
void  test_deconstruct()
{    A  a;
    throw("exception occur");   //  抛出后就会进行析构
    cout << "test end" << endl;
}

int example();
void myterminate();
int input_char_2();
// void f1(char a);
void abnormal_class();
void myfunc();

int main( )
{ 
    // example();
    // //若未处理异常或没有与异常值匹配的，就要向上一级传递异常，比如说函数中没有处理就会向调用函数（main为例）的地方传递异常；如果已经是最后一级，那么程序调用terminate并用abort终止程序
    // input_char_2();
    // f1(getchar());
    // abnormal_class();
    // myfunc();
    // try {
    //     test_deconstruct();
    //     cout << "try end" << endl;
    // }
    // catch(const char* p)
    // { cout << p << endl; }

    try{
        // const int a = 10;
        // throw(&a/*"123"*/);
        const char c = '1';
        throw(&c);
    }
    catch(void *){
        cout<<"catch void *"<<endl;
    }
    catch (const char*){
        cout<<"catch const char *"<<endl;
    }
    catch(const int*){
        cout<<"catch const int *"<<endl;
    }

    return 0;
}

int example()
{
    int m,n;
    cout<<"Please input two integers:"; cin >>m >>n;
    try //try块包含需要监控的程序段
    { 
        set_terminate(myterminate);
        //  可以设置自己的终止函数
        if (n==0) throw 0;  //抛出整形异常
        cout<< (m/n)<<endl; 
    }
    catch(int arg) // 紧跟try语句，指出异常的类型，可定义接收参数arg
    {
        cout<<"Divided by 0!"<<endl;
        return -1;
    }
    catch(...)  //通配符，把其他所有的throw值捕获
    {
        cout<<"throw else(not int )"<<endl;
        return -1;
    }
    return 0;
}

void myterminate()
{
    cout << "My Terminater : program died!" << endl;
    exit(1);
}

int input_char_2() /*代表可以throw，不写后面那一句亦可*/noexcept(false)
/*动态异常规范，c++17已经移除该用法throw(int)
当调用了不在异常规范中的异常时，会调用unexpected()默认时终止，可以通过set_except()自定义*/
{
    getchar();
    char c = getchar();
    if(c != '2')    throw "10086";
    cout<<"The program goes well!\n";
    int a = 10010;
    getchar();
    return a;
}

// void f1(char a) noexcept
// //  已经noexcept就不可抛出了，编译报错
// {
//     if(a < '0' || a > '9')  throw 5;
//     cout<<"No Error\n";
// }

void abnormal_class()
{
    try{f2();}
    catch(...){
        cout<<"catch processing"<<endl;
    }
    //  throw之后往上层找catch时，会进行相应层的析构
}

void myfunc()
{
    try {
        cout << "try start" << endl;
        throw("exception occur");   //  抛出后立即去找catch，不会执行下面的语句
        throw(10);
        cout << "try end" << endl;
    }
    catch (int x)
    {    cout << x << endl;  }
    catch (const char* p)
    {    cout << p << endl; }
    cout << "myfunc over" << endl;
}