#define _CRT_SECURE_NO_WARNINGS	1
//异常处理引入
#include <iostream>
#include <string>
using namespace std;
class Exception
{
public:
    Exception(int errid,const string& msg)
        :_errid(errid)
        ,_errmsg(msg)
    {}
    string GetMsg() const
    {
        return _errmsg;
    }
    int GetErrid() const
    {
        return _errid;
    }
private:
    int _errid;//错误码
    string _errmsg;//错误信息
};
double Division(int a, int b)
{
    if (b == 0)
    {
        /*Exception e(1, "Division by zero condition!");
        throw e;*/
        throw Exception(1, "Division by zero condition!");
        
    }
    else
        return ((double)a / (double)b);
}
void Func()
{
    int len, time;
    cin >> len >> time;
    cout << Division(len, time) << endl;
    cout << "void Func()" << endl;
}
int main()
{
    try
    {
        Func();
    }
    catch (const Exception& e)
    {
        cout << e.GetErrid() << ":" << e.GetMsg() << endl;
    }
    catch (...)//捕获任意类型的异常
    {
        cout << "未知异常" << endl;
    }
    return 0;
}