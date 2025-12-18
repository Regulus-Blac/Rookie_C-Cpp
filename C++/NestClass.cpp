#include<iostream>
using namespace std;

class OutClass {
private: 
    int x; 
public: 
    int y; // 大小 8 个字节
public:
    OutClass(int x, int y) :x(x), y(y){
        cout << "sizeof(OutClass)=" << sizeof(OutClass) << endl;
    } // 8
    void display() { cout << x << " " << y << endl; }
public:
    class NestClass { // 嵌套类
    private: 
        int u; 
    public: 
        int v, w; // 大小 12
    public:
        NestClass(int u, int v, int w) :u(u), v(v), w(w){
            cout << "sizeof(NestClass)=" << sizeof(NestClass) << endl;
        } 
        void display() { cout << u << " " << v <<" "<<w<< endl; }
    };
};

int main()
{
    return 0;
}