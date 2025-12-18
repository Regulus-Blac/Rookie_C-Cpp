#include <bits/stdc++.h>
using namespace std;

class C_CHANGE{
public:
    void test1();
    void test2();
    void test3();
};
class CPP_CHANGE : public C_CHANGE {
public:
    void example();
};


int main()
{
    CPP_CHANGE c;     c.test1();   c.test2();  c.test3();
    return 0;
}

void C_CHANGE::test1()
{
    int x = 0,(y) = 1;
    // (short) x = 2;  //  强制类型转换后为传统右值，不能在左边
    (short &)x = 3;
    // &x = 4;         //  取址后为常量指针，不可修改
    *(short *)&x = 5;
}
void C_CHANGE::test2()
{
    const int x = 0;
    int y = 1;
    const int z = y;    //const int和int定义是可以互相初始化，但const int不可以再赋值，除非通过指针绕过
    int w = x;
    //  由于编译器的优化，第一句出现后编译器就把后续的所有x全部变成了0
    //  但是z的替换为y,程序需要在内存中寻找，但是内存中被强制更改为20，所以输出20
    (int &)x = 20;  // 0
    (int &)z = 20;  // 20
    cout<<x<<" "<<z<<" "<<w<<endl;
}
void C_CHANGE::test3()
{
    int xxx = 10;
    char pa[10]="012345";
    char* pc;
    // xxx =(int)pa;       //把char数组首地址强制转换为int
    // printf("(int)pa=0x%x\n",xxx);
    xxx = *pa;          //xxx = pa[0]
    printf("char* pa=0x%x\n",xxx);
    xxx = *(int*)pa;    //pa当做一个int指针来取值
    printf("*(int*)pa=0x%x\n",xxx);

}