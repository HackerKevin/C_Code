#define _CRT_SECURE_NO_WARNINGS	1
//�ඨ������ַ�ʽ
#include <iostream>
using namespace std;
//�����Ͷ���ȫ������������
//��
class Person
{
public:
	//��ʾ������Ϣ
	void showInfo()
	{
		cout << _name << " " << _sex << " " << _age << endl;
	}
public:
	const char* _name;//����
	const char* _sex;//�Ա�
	int _age;//����
};
int main()
{
	//δʵ����
	/*Person._age = 100;*/   // ����ʧ�ܣ�error C2059: �﷨����:��.��
	//ʵ����
	Person man;
	man._name = "jack";
	man._age = 10;
	man._sex = "��";
	return 0;
}
