#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int DataType;
class Stack
{
public:
	void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (NULL == _array)
		{
			perror("malloc…Í«Îø’º‰ ß∞‹!!!");
			return;
		}
		_capacity = 3;
		_size = 0;
	}
	void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}
	DataType Top() { return _array[_size - 1]; }
	int Empty() { return 0 == _size; }
	int Size() { return _size; }
	void Destroy()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp = (DataType*)realloc(_array, newcapacity *
				sizeof(DataType));
			if (temp == NULL)
			{
				perror("realloc…Í«Îø’º‰ ß∞‹!!!");
				return;
			}
			_array = temp;
			_capacity = newcapacity;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
int main()
{
	Stack s;
	s.Init();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Pop();
	s.Pop();
	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Destroy();
	return 0;
}
