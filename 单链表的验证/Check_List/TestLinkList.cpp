#include "LinkList.h"		// 单链表类
#include "Node.h"
typedef struct Student//学生结构体
{

	int id = -1;
	string name;
	string sex;
	string clas;
	string tele;

	friend ostream& operator<<(ostream& _cout, const Student& d)
	{
		_cout << d.id << "-" << d.name << "-" << d.sex << "-" << d.clas << "-" << d.tele << endl;
		return _cout;
	}

	bool operator==(const Student& d) const
	{
		return id == d.id;
	}
	bool operator==(const int d) const
	{
		return id == d;
	}

	bool operator<(const Student& d) const
	{
		return id < d.id;
	}
	bool operator>(const Student& d) const
	{
		return id > d.id;
	}
	bool operator<=(const Student& d) const
	{
		return *this < d || *this == d;
	}
}Student;




void Test_InsertElem()//测试顺序插入
{
	Student a[] = { {2,"张三","男","1班","12345678900"} ,{11,"李四","男","2班","13445678900"} ,
				  {7,"王五","女","1班","16645678900"} ,{1,"赵六","男","4班","17745678900"} ,
				  {10,"张三","男","1班","12345678900"} ,{6,"李四","男","2班","13445678900"} ,
				  {8,"王五","女","1班","16645678900"} ,{9,"赵六","男","4班","17745678900"} };
	LinkList<Student> Student_List1;
	size_t num1 = sizeof(a) / sizeof(*a);
	for (int i = 0; i < num1; i++)
		Student_List1.InsertElem(a[i]);
	Student_List1.Traverse(Print);
}
void Test_reversal()
{
	Student a[] = { {2,"张三","男","1班","12345678900"} ,{11,"李四","男","2班","13445678900"} ,
				  {7,"王五","女","1班","16645678900"} ,{1,"赵六","男","4班","17745678900"} ,
				  {10,"张三","男","1班","12345678900"} ,{6,"李四","男","2班","13445678900"} ,
				  {8,"王五","女","1班","16645678900"} ,{9,"赵六","男","4班","17745678900"} };
	LinkList<Student> Student_List1;
	size_t num1 = sizeof(a) / sizeof(*a);
	for (int i = 0; i < num1; i++)
		Student_List1.InsertElem(a[i]);
	Student_List1.Traverse(Print);
	cout << "反转后：" << endl;
	Student_List1.reversal();
	Student_List1.Traverse(Print);
}
void Test_merge()
{
	Student a[] = { {2,"张三","男","1班","12345678900"} ,{11,"李四","男","2班","13445678900"} ,
				  {7,"王五","女","1班","16645678900"} ,{1,"赵六","男","4班","17745678900"} ,
				  {10,"张三","男","1班","12345678900"} ,{6,"李四","男","2班","13445678900"} ,
				  {8,"王五","女","1班","16645678900"} ,{9,"赵六","男","4班","17745678900"} };
	Student b[] = { {4,"张三","男","1班","12345678900"} ,{3,"李四","男","2班","13445678900"} ,
				{5,"王五","女","1班","16645678900"} ,{12,"赵六","男","4班","17745678900"} };
	LinkList<Student> Student_List1;
	LinkList<Student> Student_List2;
	LinkList<Student> Student_List3;
	size_t num1 = sizeof(a) / sizeof(*a);
	size_t num2 = sizeof(b) / sizeof(*b);
	for (int i = 0; i < num1; i++)
		Student_List1.InsertElem(a[i]);
	for (int i = 0; i < num2; i++)
		Student_List2.InsertElem(b[i]);
	cout << "链表1：" << endl;
	Student_List1.Traverse(Print);
	cout << "链表2：" << endl;
	Student_List2.Traverse(Print);
	cout << "合并后：" << endl;
	Student_List3 = merge(Student_List1, Student_List2, Student_List3);
	Student_List3.Traverse(Print);
}
int main()
{
	/*Test_InsertElem();*/
	/*Test_reversal();*/
	Test_merge();
	return 0;               // 返回值0, 返回操作系统
}
