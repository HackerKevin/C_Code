#define _CRT_SECURE_NO_WARNINGS	1
#include <vector>
#include "Date.h"
#include <algorithm>
template<class T>
struct Less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};
// ��Less��ģ�尴��ָ�뷽ʽ�ػ�
template<>
struct Less<Date*>
{
	bool operator()(Date* x, Date* y) const
	{
		return *x < *y;
	}
};
int main()
{
	Date d1(2022, 7, 7);
	Date d2(2022, 7, 6);
	Date d3(2022, 7, 8);
	vector<Date> v1;
	v1.push_back(d1);
	v1.push_back(d2);
	v1.push_back(d3);
	// ����ֱ�����򣬽������������
	sort(v1.begin(), v1.end(), Less<Date>());
	vector<Date*> v2;
	v2.push_back(&d1);
	v2.push_back(&d2);
	v2.push_back(&d3);

	// ����ֱ�����򣬽���������ڻ��������򣬶�v2�зŵĵ�ַ������
	// �˴���Ҫ����������У���sort�Ƚ�v2�д�ŵ�ַָ������ڶ���
	// ������Lessģ�壬sort������ʱʵ�ʱȽϵ���v2��ָ��ĵ�ַ������޷��ﵽԤ��
	sort(v2.begin(), v2.end(), Less<Date*>());
	return 0;
}

