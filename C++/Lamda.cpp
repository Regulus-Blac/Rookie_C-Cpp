#include <iostream>
#include <vector>
#include <algorithm>    //for_each
using namespace std;
int main()
{
    vector<int> vec = { 10,30,20,5,15,45 };
//  for_each是一个函数模版，最后一个参数是函数
    for_each(vec.begin(), vec.end(), [](int x) {cout << x << " "; });

    cout << endl << "sort " << endl;

    sort(vec.begin(), vec.end(), [](int a, int b) {return a < b; });

    for_each(vec.begin(), vec.end(), [](int x) {cout << x << " "; });

    vector<string> str = { "lambda","hello","welcome","for_each"};

    for_each(str.begin(), str.end(), [](string x) {cout << x << " "; });
}