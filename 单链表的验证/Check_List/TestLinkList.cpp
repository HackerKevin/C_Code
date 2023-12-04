#include "LinkList.h"		// ��������
#include "Node.h"
typedef struct Student//ѧ���ṹ��
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




void Test_InsertElem()//����˳�����
{
	Student a[] = { {2,"����","��","1��","12345678900"} ,{11,"����","��","2��","13445678900"} ,
				  {7,"����","Ů","1��","16645678900"} ,{1,"����","��","4��","17745678900"} ,
				  {10,"����","��","1��","12345678900"} ,{6,"����","��","2��","13445678900"} ,
				  {8,"����","Ů","1��","16645678900"} ,{9,"����","��","4��","17745678900"} };
	LinkList<Student> Student_List1;
	size_t num1 = sizeof(a) / sizeof(*a);
	for (int i = 0; i < num1; i++)
		Student_List1.InsertElem(a[i]);
	Student_List1.Traverse(Print);
}
void Test_reversal()
{
	Student a[] = { {2,"����","��","1��","12345678900"} ,{11,"����","��","2��","13445678900"} ,
				  {7,"����","Ů","1��","16645678900"} ,{1,"����","��","4��","17745678900"} ,
				  {10,"����","��","1��","12345678900"} ,{6,"����","��","2��","13445678900"} ,
				  {8,"����","Ů","1��","16645678900"} ,{9,"����","��","4��","17745678900"} };
	LinkList<Student> Student_List1;
	size_t num1 = sizeof(a) / sizeof(*a);
	for (int i = 0; i < num1; i++)
		Student_List1.InsertElem(a[i]);
	Student_List1.Traverse(Print);
	cout << "��ת��" << endl;
	Student_List1.reversal();
	Student_List1.Traverse(Print);
}
void Test_merge()
{
	Student a[] = { {2,"����","��","1��","12345678900"} ,{11,"����","��","2��","13445678900"} ,
				  {7,"����","Ů","1��","16645678900"} ,{1,"����","��","4��","17745678900"} ,
				  {10,"����","��","1��","12345678900"} ,{6,"����","��","2��","13445678900"} ,
				  {8,"����","Ů","1��","16645678900"} ,{9,"����","��","4��","17745678900"} };
	Student b[] = { {4,"����","��","1��","12345678900"} ,{3,"����","��","2��","13445678900"} ,
				{5,"����","Ů","1��","16645678900"} ,{12,"����","��","4��","17745678900"} };
	LinkList<Student> Student_List1;
	LinkList<Student> Student_List2;
	LinkList<Student> Student_List3;
	size_t num1 = sizeof(a) / sizeof(*a);
	size_t num2 = sizeof(b) / sizeof(*b);
	for (int i = 0; i < num1; i++)
		Student_List1.InsertElem(a[i]);
	for (int i = 0; i < num2; i++)
		Student_List2.InsertElem(b[i]);
	cout << "����1��" << endl;
	Student_List1.Traverse(Print);
	cout << "����2��" << endl;
	Student_List2.Traverse(Print);
	cout << "�ϲ���" << endl;
	Student_List3 = merge(Student_List1, Student_List2, Student_List3);
	Student_List3.Traverse(Print);
}
int main()
{
	/*Test_InsertElem();*/
	/*Test_reversal();*/
	Test_merge();
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
