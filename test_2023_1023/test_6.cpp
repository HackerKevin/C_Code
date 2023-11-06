#define _CRT_SECURE_NO_WARNINGS	1
//�쳣��������
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
    int _errid;//������
    string _errmsg;//������Ϣ
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
    catch (...)//�����������͵��쳣
    {
        cout << "δ֪�쳣" << endl;
    }
    return 0;
}