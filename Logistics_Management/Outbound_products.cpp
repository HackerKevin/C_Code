#include "Product.h"
void Product_clearance(LinkList<Product>& d), Decrease_inventory(LinkList<Product>& d);
void Outbound_menu()
{
	cout << "\n产品出库"
		 << "\n请选择你要执行的操作：";
	cout << "\n1 --- 产品清仓          "
		 << "\n2 --- 减少库存          "
		 << "\n0 --- 取消出库          "
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
		case '1':	Product_clearance(d);		break;//产品清仓
		case '2':	Decrease_inventory(d);		break;//减少库存
		case '0':
		case 27:	choice = 0;		break;
		default:	cout << "选择错误，重新选择" << endl;	break;
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
		cout << "仓库为空，无法操作！" << endl;
		return;
	}
	else
	{
		string _id;
		cout << "请输入待增加库存的产品编号（XXXX）：" << endl;
		cin >> _id;
		if (d.Search(_id) == NULL)
		{
			cout << "该产品不存在！" << endl;
			return;
		}
		else
		{
			int i = d.LocateElem(_id);
			Product e;//用来接收被清仓的产品
			d.DeleteElem(i, e);
			cout << "产品编号：" << setw(8)<< e.id << "\t产品名：" << e.name 
				 << "\t已清仓，" << "共出库：" << e.num << "件" << endl;	
		}
	}
}

void Decrease_inventory(LinkList<Product>& d)
{
	if (d.IsEmpty())
	{
		cout << "仓库为空，无法操作！" << endl;
		return;
	}
	else
	{
		string _id;
		cout << "请输入待出库的产品编号（XXXX）：" << endl;
		cin >> _id;
		if (d.Search(_id) == NULL)
		{
			cout << "该产品不存在！" << endl;
			return;
		}
		Node<Product>* p = d.Search(_id);
		int n = 0, m = 0;
		cout << "请输入减少的库存量：" << endl;
		cin >> n;
		m = p->data.num - n;//减少后的库存量
		if (m < 0)
		{
			cout << "产品库存不足！最大出库量" << p->data.num << "件" << endl;
			return;
		}
		else
		{
			p->data.num -= n;
			if (m == 0)//库存为0，则清仓
			{
				int i = d.LocateElem(_id);
				Product e;//用来接收被清仓的产品
				d.DeleteElem(i, e);
				cout << "出库成功！" << "\t产品编号：" << setw(8) << e.id << "\t产品名：" << e.name
					 << "\t已清仓!" << endl;
				return;
			}
			else
			{
				cout << "出库成功！" << p->data.name << "现在的库存量为：" << p->data.num << endl;
				return;
			}
			
		}
	}
}