#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T mAx(T a, T b)
{
    return a > b ? a : b;
}
// const char *mAx(const char *x, const char *y)
// { 
//  return strcmp(x, y)>0?x:y;
// }

int main()
{
    int a = 1,b = 2, imax;
    double aa = 9,bb = 6, dmax;
    string aaa = "123456", bbb = "456789",cmax = "";

    imax = mAx(a,b);
    dmax = mAx(aa,bb);
    cmax = mAx(aaa,bbb);
    cout<<imax<<endl<<dmax<<endl<<cmax<<endl;
    return 0;
}