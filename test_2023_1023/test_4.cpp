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
// 对Less类模板按照指针方式特化
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
	// 可以直接排序，结果是日期升序
	sort(v1.begin(), v1.end(), Less<Date>());
	vector<Date*> v2;
	v2.push_back(&d1);
	v2.push_back(&d2);
	v2.push_back(&d3);

	// 可以直接排序，结果错误日期还不是升序，而v2中放的地址是升序
	// 此处需要在排序过程中，让sort比较v2中存放地址指向的日期对象
	// 但是走Less模板，sort在排序时实际比较的是v2中指针的地址，因此无法达到预期
	sort(v2.begin(), v2.end(), Less<Date*>());
	return 0;
}

