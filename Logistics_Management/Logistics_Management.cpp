#include "Product.h"

LinkList<Product> Product_List;//ȫ������

void showMenu()
{
	cout << "=========��������ϵͳ=========" << endl;
	cout << "1 -------- �ֿ��̵� ----------" << endl;
	cout << "2 -------- ��Ʒ��� ----------" << endl;
	cout << "3 -------- ��Ʒ���� ----------" << endl;
	cout << "0 -------- �˳�ϵͳ ----------" << endl;
	cout << "�밴��ʾ�������ѡ��";
}

void oldProduct()
{
	Product p1("1", "����", 200);
	Product p2("2", "��ë��", 270);
	Product p3("3", "����",220 );
	Product_List.InsertElem(p1);
	Product_List.InsertElem(p2);
	Product_List.InsertElem(p3);

}

int main()
{
	oldProduct();

	while (1)
	{
		showMenu();
		char choice = '0';
		cin >> choice;
		switch (choice)
		{
		case '1':	Warehouse_inventory(Product_List);	break;//�ֿ��̵�
		case '2':	Inbound_products(Product_List);		break;//��Ʒ���
		case '3':	Outbound_products(Product_List);	break;//��Ʒ����
		case '0':   return 0;
		case 27:	choice = 0;		break;
		default:	cout << "ѡ���������ѡ��" << endl;	system("pause"); system("cls"); break;
		}
	}

	return 0;
}

void Warehouse_inventory(LinkList<Product>& d)
{

	if (d.IsEmpty())
	{
		cout << "�ֿ�Ϊ�գ�������Ʒ��" << endl;

	}
	else
	{
		d.Traverse(Print);
	}
	system("pause");
	system("cls");
}