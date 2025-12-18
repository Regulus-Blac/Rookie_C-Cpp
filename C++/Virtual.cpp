#include <iostream>
using namespace std;

class Base {
public:
    int base_var = 10;
    
    void base_func() {
        cout << "Base function" << endl;
    }
    
    virtual void virtual_func() {
        cout << "Base virtual function" << endl;
    }
};

class Derived : public Base {
public:
    int derived_var = 20;
    
    void derived_func() {
        cout << "Derived function" << endl;
    }
    
    void virtual_func() override {
        cout << "Derived virtual function" << endl;
    }
};

void test_basic() {
    Base c; Derived d;
    Base* pa = &c;
    Base* pb = &d;  // ✅ 基类指针指向子类对象
    // Derived* pc = &c; // ❌ 编译错误，不能将基类对象地址赋给子类指针
    Derived* pd = &d; // ✅ 子类指针指向子类对象
    
    cout << pa->base_var << endl;
    pa->base_func(); 
    // 可以访问基类成员
    cout << pb->base_var << endl;      // ✅ 输出：10
    pb->base_func();                   // ✅ 输出：Base function

    cout << pd->base_var << endl;
    pd->base_func();
    // 不能访问子类特有成员
    // cout << pb->derived_var << endl; // ❌ 编译错误
    // pb->derived_func();              // ❌ 编译错误
    
    pa->virtual_func();                // ✅ 输出：Base virtual function
    // 虚函数调用子类版本
    pb->virtual_func();                // ✅ 输出：Derived virtual function
    pd->virtual_func();                // ✅ 输出：Derived virtual function
}
int main() {
    test_basic();
    return 0;
}