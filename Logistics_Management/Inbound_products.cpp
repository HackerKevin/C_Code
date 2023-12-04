#include "Product.h"
void NewProduct_inbound(LinkList<Product>& d), Increase_inventory(LinkList<Product>& d);
void Inbound_menu()
{
	cout << "\n产品入库"
		 << "\n请选择你要执行的操作：";
	cout << "\n1 --- 新品入库          "
		 << "\n2 --- 增加库存          "
		 << "\n0 --- 取消入库          "
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
		case '1':	NewProduct_inbound(d);		break;//新品入库
		case '2':	Increase_inventory(d);		break;//修改库存
		case '0':
		case 27:	choice = 0;		break;
		default:	cout << "选择错误，重新选择" << endl;	break;
		}
	} while (choice);
	system("pause");
	system("cls");
	return;
	
}

void NewProduct_inbound(LinkList<Product>& d)
{
	cout << "请输入产品信息（产品编号XXXX，产品名称，产品库存）：" << endl;
	Product NewProduct;
	cin >> NewProduct;
	if (d.Search(NewProduct) != NULL)
	{
		cout << "该产品编号已存在！" << endl;
		return;
	}
	else
	{
		if (NewProduct.num > 1000)
		{
			cout << "产品数量过多！" << endl;
			return;
		}
		if (NewProduct.num == 0||NewProduct.num < 0)
		{
			cout << "请输入合法的数量！" << endl;
			return;
		}
		else
		{
			d.InsertElem(NewProduct);
			cout << "入库成功！";
			return;
		}
	}
}

void Increase_inventory(LinkList<Product>& d)
{
	string _id;
	cout << "请输入待入库的产品编号（XXXX）：" << endl;
	cin >> _id;
	if (d.Search(_id) == NULL)
	{
		cout << "该产品不存在！" << endl;
		return;
	}
	else
	{
		Node<Product>* p = d.Search(_id);
		int n = 0, m = 0;
		cout << "请输入增加的库存量：" << endl;
		cin >> n;
		m = p->data.num + n;//增加后的库存量
		if (m > 1000)
		{
			cout << "库存过多！最大存量为：1000" << endl;
			return;
		}
		else
		{
			p->data.num += n;
			cout << "入库成功！" << p->data.name << "现在的库存量为：" << p->data.num << endl;
			return;
		}
	}
}
