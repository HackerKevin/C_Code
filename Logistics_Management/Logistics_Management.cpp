#include "Product.h"

LinkList<Product> Product_List;//全局链表

void showMenu()
{
	cout << "=========物流管理系统=========" << endl;
	cout << "1 -------- 仓库盘点 ----------" << endl;
	cout << "2 -------- 产品入库 ----------" << endl;
	cout << "3 -------- 产品出库 ----------" << endl;
	cout << "0 -------- 退出系统 ----------" << endl;
	cout << "请按提示输入你的选择：";
}

void oldProduct()
{
	Product p1("1", "篮球", 200);
	Product p2("2", "羽毛球", 270);
	Product p3("3", "足球",220 );
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
		case '1':	Warehouse_inventory(Product_List);	break;//仓库盘点
		case '2':	Inbound_products(Product_List);		break;//产品入库
		case '3':	Outbound_products(Product_List);	break;//产品出库
		case '0':   return 0;
		case 27:	choice = 0;		break;
		default:	cout << "选择错误，重新选择" << endl;	system("pause"); system("cls"); break;
		}
	}

	return 0;
}

void Warehouse_inventory(LinkList<Product>& d)
{

	if (d.IsEmpty())
	{
		cout << "仓库为空，请入库产品！" << endl;

	}
	else
	{
		d.Traverse(Print);
	}
	system("pause");
	system("cls");
}