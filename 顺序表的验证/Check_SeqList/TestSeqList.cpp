#include "SeqList.h"	// 顺序表类
//int a[] = { 1,2,3,4,5,6,7,8,9 };
//int b[] = { 1,1,2,3,3,5,5,6,8,10 };
void Test_Max_And_Min()
{
    int a[] = { 1,2,3,4,5,6,7,8,9 };
    SeqList<int> A(a, 9);
    A.Traverse(Print);
    cout << A.Max() << endl;
    cout << A.Min() << endl;
}
void Test_InsertElem()
{
    SeqList<int> A;
    A.InsertElem(1);
    A.InsertElem(5);
    A.InsertElem(3);
    A.InsertElem(1);
    A.InsertElem(5);
    A.InsertElem(3);
    A.InsertElem(2);
    A.InsertElem(8);
    A.InsertElem(6);
    A.InsertElem(10);
    A.Traverse(Print);
}
void Test_deleteRange()
{
    int b[] = { 1,1,2,3,3,5,5,6,8,10 };
    SeqList<int> B(b, 10);
    cout << "初始链表：";
    B.Traverse(Print);
    B.deleteRange(5, 9);
    cout << "删除5~9范围内的数据后：";
    B.Traverse(Print);
}
void Test_merge()
{
    int a[] = { 1,2,3,4,5,6,7,8,9 };
    int b[] = { 1,1,2,3,3,5,5,6,8,10 };
    SeqList<int> A(a, 9);
    SeqList<int> B(b, 10);
    SeqList<int> C;
    cout << "合并前：" << endl;
    A.Traverse(Print);
    B.Traverse(Print);
    C = merge(A, B, C);
    cout << "合并后：";
    C.Traverse(Print);
}
int main(void)
{
   /* Test_Max_And_Min();*/
    /*Test_InsertElem();*/
    /*Test_deleteRange();*/
    Test_merge();
    return 0;               		// 返回操作系统
}



