#pragma once
#include "LinkList.h"
//产品类
struct Product
{
	Product(const string& ID = "000",const string& Name = "UNkowm",const int& Num = -1)
	{
		id = ID;
		name = Name;
		num = Num;
	}
	friend ostream& operator<<(ostream& _cout, const Product& d)
	{
		_cout << "产品编号: " << setw(8) << d.id << "\t产品名称: " << setw(8) << d.name << setw(15) << "产品库存: " << d.num << endl;
		return _cout;
	}

	friend istream& operator>>(istream& _cin, Product& d)
	{
		_cin >> d.id >> d.name >> d.num;
		return _cin;
	}
	string id;
	string name;
	int num;


	bool operator==(const Product& d) const
	{
		return id == d.id;
	}
	bool operator==(const string& d) const
	{
		return id == d;
	}
	bool operator !=(const string& d) const
	{
		return id != d;
	}
	bool operator<(const Product& d) const
	{
		return id < d.id;
	}
	bool operator>(const Product& d) const
	{
		return id > d.id;
	}
	bool operator<=(const Product& d) const
	{
		return *this < d || *this == d;
	}
};

extern void Warehouse_inventory(LinkList<Product>& d), Inbound_products(LinkList<Product>& d), Outbound_products(LinkList<Product>& d);
