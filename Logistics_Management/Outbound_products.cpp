#include "Product.h"
void Product_clearance(LinkList<Product>& d), Decrease_inventory(LinkList<Product>& d);
void Outbound_menu()
{
	cout << "\n��Ʒ����"
		 << "\n��ѡ����Ҫִ�еĲ�����";
	cout << "\n1 --- ��Ʒ���          "
		 << "\n2 --- ���ٿ��          "
		 << "\n0 --- ȡ������          "
		 << endl;
}
void Outbound_products(LinkList<Product>& d)
{
	char choice = '0';
	do
	{
		Outbound_menu();
		cin >> choice;
		switch (choice)
		{
		case '1':	Product_clearance(d);		break;//��Ʒ���
		case '2':	Decrease_inventory(d);		break;//���ٿ��
		case '0':
		case 27:	choice = 0;		break;
		default:	cout << "ѡ���������ѡ��" << endl;	break;
		}
	} while (choice);
	system("pause");
	system("cls");
	return;
}

void Product_clearance(LinkList<Product>& d)
{
	if (d.IsEmpty())
	{
		cout << "�ֿ�Ϊ�գ��޷�������" << endl;
		return;
	}
	else
	{
		string _id;
		cout << "����������ӿ��Ĳ�Ʒ��ţ�XXXX����" << endl;
		cin >> _id;
		if (d.Search(_id) == NULL)
		{
			cout << "�ò�Ʒ�����ڣ�" << endl;
			return;
		}
		else
		{
			int i = d.LocateElem(_id);
			Product e;//�������ձ���ֵĲ�Ʒ
			d.DeleteElem(i, e);
			cout << "��Ʒ��ţ�" << setw(8)<< e.id << "\t��Ʒ����" << e.name 
				 << "\t����֣�" << "�����⣺" << e.num << "��" << endl;	
		}
	}
}

void Decrease_inventory(LinkList<Product>& d)
{
	if (d.IsEmpty())
	{
		cout << "�ֿ�Ϊ�գ��޷�������" << endl;
		return;
	}
	else
	{
		string _id;
		cout << "�����������Ĳ�Ʒ��ţ�XXXX����" << endl;
		cin >> _id;
		if (d.Search(_id) == NULL)
		{
			cout << "�ò�Ʒ�����ڣ�" << endl;
			return;
		}
		Node<Product>* p = d.Search(_id);
		int n = 0, m = 0;
		cout << "��������ٵĿ������" << endl;
		cin >> n;
		m = p->data.num - n;//���ٺ�Ŀ����
		if (m < 0)
		{
			cout << "��Ʒ��治�㣡��������" << p->data.num << "��" << endl;
			return;
		}
		else
		{
			p->data.num -= n;
			if (m == 0)//���Ϊ0�������
			{
				int i = d.LocateElem(_id);
				Product e;//�������ձ���ֵĲ�Ʒ
				d.DeleteElem(i, e);
				cout << "����ɹ���" << "\t��Ʒ��ţ�" << setw(8) << e.id << "\t��Ʒ����" << e.name
					 << "\t�����!" << endl;
				return;
			}
			else
			{
				cout << "����ɹ���" << p->data.name << "���ڵĿ����Ϊ��" << p->data.num << endl;
				return;
			}
			
		}
	}
}