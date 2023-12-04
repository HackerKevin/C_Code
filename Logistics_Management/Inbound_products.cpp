#include "Product.h"
void NewProduct_inbound(LinkList<Product>& d), Increase_inventory(LinkList<Product>& d);
void Inbound_menu()
{
	cout << "\n��Ʒ���"
		 << "\n��ѡ����Ҫִ�еĲ�����";
	cout << "\n1 --- ��Ʒ���          "
		 << "\n2 --- ���ӿ��          "
		 << "\n0 --- ȡ�����          "
		 << endl;
}
void Inbound_products(LinkList<Product>& d)
{
	char choice = '0';
	do
	{
		Inbound_menu();
		cin >> choice;
		switch (choice)
		{
		case '1':	NewProduct_inbound(d);		break;//��Ʒ���
		case '2':	Increase_inventory(d);		break;//�޸Ŀ��
		case '0':
		case 27:	choice = 0;		break;
		default:	cout << "ѡ���������ѡ��" << endl;	break;
		}
	} while (choice);
	system("pause");
	system("cls");
	return;
	
}

void NewProduct_inbound(LinkList<Product>& d)
{
	cout << "�������Ʒ��Ϣ����Ʒ���XXXX����Ʒ���ƣ���Ʒ��棩��" << endl;
	Product NewProduct;
	cin >> NewProduct;
	if (d.Search(NewProduct) != NULL)
	{
		cout << "�ò�Ʒ����Ѵ��ڣ�" << endl;
		return;
	}
	else
	{
		if (NewProduct.num > 1000)
		{
			cout << "��Ʒ�������࣡" << endl;
			return;
		}
		if (NewProduct.num == 0||NewProduct.num < 0)
		{
			cout << "������Ϸ���������" << endl;
			return;
		}
		else
		{
			d.InsertElem(NewProduct);
			cout << "���ɹ���";
			return;
		}
	}
}

void Increase_inventory(LinkList<Product>& d)
{
	string _id;
	cout << "����������Ĳ�Ʒ��ţ�XXXX����" << endl;
	cin >> _id;
	if (d.Search(_id) == NULL)
	{
		cout << "�ò�Ʒ�����ڣ�" << endl;
		return;
	}
	else
	{
		Node<Product>* p = d.Search(_id);
		int n = 0, m = 0;
		cout << "���������ӵĿ������" << endl;
		cin >> n;
		m = p->data.num + n;//���Ӻ�Ŀ����
		if (m > 1000)
		{
			cout << "�����࣡������Ϊ��1000" << endl;
			return;
		}
		else
		{
			p->data.num += n;
			cout << "���ɹ���" << p->data.name << "���ڵĿ����Ϊ��" << p->data.num << endl;
			return;
		}
	}
}
