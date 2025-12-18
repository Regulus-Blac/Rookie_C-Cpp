#include <bits\stdc++.h>
#include <assert.h>
using namespace std;

int main()
{
    int *elem = new int[5];
    //  实参为真继续执行，为假则输出程序所在文件号、行号，调用abort()终止程序。
    assert(elem);
    //  静态断言在编译时就会报错
    static_assert(sizeof(elem) == 8, "size of Elem is wrong\n");
    return 0;
}