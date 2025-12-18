/*单例模式要点：
1.将构造函数定义为私有函数
2.定义一个私有的类的静态实例指针
3.提供一个公有的静态方法，实现创建唯一实例对象指针，获取指针的功能
4.
5.
*/
#include <bits\stdc++.h>
using namespace std;
class singleton {
private:
//  静态数据成员独立分配内存，不属于任何对象内存，所有对象共享静态数据成员内存
    string s;
    singleton(): s("very good") { }     //私有的构造函数
    static singleton *instance;         //静态的私有对象指针，类体内只是声明
public:
    static singleton* getInstance() {   //静态、公有的函数，
        if (instance == nullptr) { instance = new singleton(); }
        return instance; //可以获取唯一的指向对象
    }
    void show() { cout << s << endl; }
    void setstring(const string &a) { s = a; }
};
//  类静态成员在类体内声明，在类体外定义并初始化
//  静态数据成员不能在函数体前初始化
singleton* singleton::instance = nullptr;

int main()
{
    singleton::getInstance()->setstring("hello world");
    singleton::getInstance()->show();
}
// 1.
// if(a == b || b == c || c == a)  printf("same");
// else{
//     if(a < b && a < c)  printf("A");
//     else if(b < a && b < c)  printf("B");
//     else if(c < a && c < b)  printf("C");
// }
// 2.
//     if(a < b && a < c)  printf("A");
//     else if(b < a && b < c)  printf("B");
//     else if(c < a && c < b)  printf("C");
//     else printf("same");

