#include <iostream>
#include <cstring>
using namespace std;

class MAT
{
    int *e; // 指向所有整型矩阵元素的指针
    int r, c;

public:
    MAT(int r, int c); // 矩阵定义
    MAT(const MAT &a); // 深拷贝构造
    MAT(MAT &&a);
    ~MAT();
    // MAT &operator*=(const MAT &a);
    MAT &operator=(const MAT &a);        // 深拷贝赋值运算
    MAT &operator=(MAT &&a);             // 移动赋值运算
    MAT operator+(const MAT &obj) const; // 需要新对象，且不可以引用临时变量，所以为MAT类；同时保护源对象并且支持常量
    MAT &operator+=(const MAT &a);       // “+=”运算
    MAT &operator-=(const MAT &a);       // “-=”运算
};

MAT::MAT(int r, int c)
{
    this->r = r;
    this->c = c;
    if (e)
        delete[] e;
    e = new int[r * c];
}
MAT::MAT(const MAT &a) // 深拷贝构造
{
    cout << "deep copy" << endl;
    r = a.r;
    c = a.c;
    if (e)
        delete[] e;
    e = new int[r * c];
    memcpy(e, a.e, r * c * sizeof(int));
}
MAT::MAT(MAT &&a)
{
    cout << "move copy" << endl;
    r = a.r;
    c = a.c;
    if (e)
        delete e;
    e = a.e;
    a.e = NULL;
    a.c = 0;
    a.r = 0;
}
MAT::~MAT()
{
    cout << "deconstruct mat " << endl;
    if (e)
        delete e;
    e = NULL;
}
MAT &MAT::operator=(const MAT &a) // 深拷贝赋值运算
{
    if (this == &a)
        return *this;
    cout << "oprator =" << endl;
    r = a.r;
    c = a.c;
    if (e)
        delete e;
    e = new int[r * c];
    memcpy(e, a.e, r * c * sizeof(int));
    return *this; // C++强制类型转换为MAT&
}
MAT &MAT::operator=(MAT &&a) // 移动赋值运算
{
    if (this == &a)
        return *this;
    cout << "moving assign operation ..." << endl;
    r = a.r;
    c = a.c;
    if (e)
        delete e;
    e = a.e;
    a.e = NULL;
    a.c = 0;
    a.r = 0;
}

class STRING
{
private:
    char *s;

public:
    STRING(const char *str)
    {
        if (s)
            delete[] s;
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    }
    char &operator[](int i)
    {
        return *(s + i);
    }
};

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    Clock()
    {
        hour = minute = second = 0;
    }
    Clock(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    Clock &operator++(); // 前置++
    Clock operator++(int);//后置++
};
Clock &Clock::operator++()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
                hour = 0;
        }
    }
    return *this;
}
Clock Clock::operator++(int)//等号优先级最低，所以先计算++部分，而后置需要返回++前的值，这就需要创建一个副本保存之前的值
{
    Clock temp(*this);

    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
                hour = 0;
        }
    }
    return temp;
}
