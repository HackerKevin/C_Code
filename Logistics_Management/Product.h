#pragma once
#include "LinkList.h"
//��Ʒ��
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
		_cout << "��Ʒ���: " << setw(8) << d.id << "\t��Ʒ����: " << setw(8) << d.name << setw(15) << "��Ʒ���: " << d.num << endl;
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
