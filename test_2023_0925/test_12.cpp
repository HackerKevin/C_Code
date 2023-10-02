#define _CRT_SECURE_NO_WARNINGS	1
//类定义的两种方式
#include <iostream>
using namespace std;
//声明和定义全部放在类体中
//人
class Person
{
public:
	//显示基本信息
	void showInfo()
	{
		cout << _name << " " << _sex << " " << _age << endl;
	}
public:
	const char* _name;//姓名
	const char* _sex;//性别
	int _age;//年龄
};
int main()
{
	//未实例化
	/*Person._age = 100;*/   // 编译失败：error C2059: 语法错误:“.”
	//实例化
	Person man;
	man._name = "jack";
	man._age = 10;
	man._sex = "男";
	return 0;
}
