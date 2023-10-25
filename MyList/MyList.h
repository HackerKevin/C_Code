#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
//由于类模板不支持声明和定义分离，因此统一在头文件中实现
namespace MyList//为了防止污染，声明在自己的命名空间中
{
	template<class T>//一个保存当前节点数据的类模板
	struct list_node//该类不对成员的访问进行限制，所以使用struct
	{
		list_node<T>* _next;//指向上一个节点地址的指针
		list_node<T>* _prev;//指向下一个节点地址的指针
		T _data;//当前节点的内容

		list_node(const T& x = T())//构造函数,缺省值设为一个匿名对象，匿名对象会调用属于自己类型的默认构造
								 //注意：此处缺省值不能给0，因为T不一定是int类型
			
			//指针在这里初始化为空指针，在插入函数中才进行指向
			:_next(nullptr)
			,_prev(nullptr)

			,_data(x)//将_data初始化为x
		{}
	};

	//跟数组相比，数组的物理空间是连续的，可以用指针++的形式访问下一个对象
	//但是对于链表，其节点和节点之间是不连续的，所以不能用指针++的形式访问下一个对象
	//而且由于++的是一个指针，所以我们也不能通过重载++的形式让node*能访问下一个节点
	//在STL库中，是使用迭代器来实现的，下面我们来进行模拟

	template<class T, class Ref, class Ptr>//一个链表迭代器的类模板，相当于对节点指针的封装
							//Ref表示引用，用来区分普通引用和常引用
							//Ptr表示指针，用来区分自定义类型的普通指针和const指针
	struct _list_iterator//该类不对成员的访问进行限制，所以使用struct
	{
		typedef list_node<T> node;//将list_node<T>重命名为node
		typedef _list_iterator<T, Ref, Ptr> self;//将_list_iterator<T, Ref>重命名为self
		node* _node;//定义一个节点的指针

		//用节点的指针构造一个迭代器
		_list_iterator(node* n)
			:_node(n)
		{}

		//迭代器的核心功能：解引用
		Ref operator*()//返回这个节点的引用，就能对这个节点实现修改
					   //如果Ref为普通引用，则可以对节点进行修改，若为常引用则不能修改
		{
			return _node->_data;
		}

		
		Ptr operator->()//重载->，用来对自定义类型进行解引用
					   //如果Ptr为自定义类型的普通指针，则可以对节点进行修改，若为const指针则不能修改
		{
			return &_node->_data;
		}

		self& operator++()//重载前置++，让迭代器能够访问当前节点的下一个节点
		//指针++返回的还是指针，那么这里类比一下就不难理解迭代器++返回的就还是迭代器
		{
			_node = _node->_next;//将当前_node改为指向下一节点的地址
			return *this;//返回调用该函数的迭代器
		}

		self operator++(int)//重载后置++，让迭代器能访问下一个节点前先返回当前节点
		{
			self tmp(*this);//保存一份当前节点的地址
			_node = _node->_next;//将当前_node改为指向下一节点的地址
			return tmp;//返回修改前的节点
		}

		self& operator--()//重载前置--，让迭代器能够访问当前节点的上一个节点
		{
			_node = _node->_prev;//将当前_node改为指向上一节点的地址
			return *this;//返回调用该函数的迭代器
		}

		self operator--(int)//重载后置--，让迭代器能访问上一个节点前先返回当前节点
		{
			self tmp(*this);//保存一份当前节点的地址
			_node = _node->_prev;//将当前_node改为指向下一节点的地址
			return tmp;//返回修改前的节点
		}

		//下面是重载判断运算符，让两个迭代器能够进行比较
		bool operator!=(const self& s)//重载!=
		{
			return _node != s._node;//如果两个节点的地址不相等，返回true，否则返回false
		}
		bool operator==(const self& s)//重载==

		{
			return _node == s._node;//如果两个节点的地址相等，返回true，否则返回false
		}
	};
	//总结：迭代器要么就是原生指针，要么就是自定义类型对原生指针的封装，模拟指针的行为

	////下面的代码实际上是多余的，仅当普通迭代器中的模板参数只有class T才有效，所以实际上这段注释掉并不影响运行
	//template<class T>//一个链表const迭代器的类模板，该迭代器指向的内容不能修改
	//struct _list_const_iterator//该类不对成员的访问进行限制，所以使用struct
	//{
	//	typedef list_node<T> node;//将list_node<T>重命名为node
	//	typedef _list_const_iterator<T> self;//将_list_const_iterator<T>重命名为self
	//	node* _node;//定义一个节点的指针

	//	//用节点的指针构造一个const迭代器
	//	_list_const_iterator(node* n)
	//		:_node(n)
	//	{}

	//	const T& operator*()//返回这个节点的引用，这个节点的内容不能被修改
	//	{
	//		return _node->_data;
	//	}

	//	self& operator++()//重载前置++，让迭代器能够访问当前节点的下一个节点
	//	//指针++返回的还是指针，那么这里类比一下就不难理解迭代器++返回的就还是迭代器
	//	{
	//		_node = _node->_next;//将当前_node改为指向下一节点的地址
	//		return *this;//返回调用该函数的迭代器
	//	}

	//	self operator++(int)//重载后置++，让迭代器能访问下一个节点前先返回当前节点
	//	{
	//		self tmp(*this);//保存一份当前节点的地址
	//		_node = _node->_next;//将当前_node改为指向下一节点的地址
	//		return tmp;//返回修改前的节点
	//	}

	//	self& operator--()//重载前置--，让迭代器能够访问当前节点的上一个节点
	//	{
	//		_node = _node->_prev;//将当前_node改为指向上一节点的地址
	//		return *this;//返回调用该函数的迭代器
	//	}

	//	self operator--(int)//重载后置--，让迭代器能访问上一个节点前先返回当前节点
	//	{
	//		self tmp(*this);//保存一份当前节点的地址
	//		_node = _node->_prev;//将当前_node改为指向下一节点的地址
	//		return tmp;//返回修改前的节点
	//	}

	//	//下面是重载判断运算符，让两个迭代器能够进行比较
	//	bool operator!=(const self& s)//重载!=
	//	{
	//		return _node != s._node;//如果两个节点的地址不相等，返回true，否则返回false
	//	}
	//	bool operator==(const self& s)//重载==

	//	{
	//		return _node == s._node;//如果两个节点的地址相等，返回true，否则返回false
	//	}
	//};

	template<class T>//
	class list//一个链表的类模板
	{
		typedef list_node<T> node;//将list_node<T>重命名为node，方便定义
	public:
		
		typedef _list_iterator<T, T&, T*> iterator;//将迭代器_list_iterator<T, T&, T*>重命名为iterator,表示如果类型为<T, T&>就使用普通迭代器

		//由于C++规定所有容器里面的迭代器都叫iterator，所以为了统一也将_list_iterator<T>重命名为iterator
		//这里也可以用别的名字，但是这样就不支持范围for，因为范围for是傻瓜式的寻找iterator并进行替代

		typedef _list_iterator<T, const T&, const T*> const_iterator;//将迭代器_list_iterator<T, const T&, const T*>重命名为const_iterator,表示如果类型为<T, const T&, const T*>就使用const迭代器

		//_list_iterator有两个模板参数后下面的typedef可忽略
		//typedef _list_const_iterator<T> const_iterator;//将迭代器_list_const_iterator<T>重命名为const_iterator
		////注意：对于：typedef const iterator const_iterator;由于语法规定，该代码中的const修饰的实际上是iterator*，意思是迭代器的指向不能修改，不是表示迭代器指向的内容不能修改

		

		iterator begin()//定义一个指向链表头部的迭代器begin
		{
			//iterator it(_head->next);
			//return it;
			return iterator (_head->_next);//使用匿名对象返回哨兵位的_next也就是头节点
										   //使用匿名对象返回可以调用编译器的自动优化
		}

		
		const_iterator begin() const//定义一个指向链表头部的const迭代器begin
						       //这里的const修饰的是*this，也就是指向的内容，意思是list中的_head不能被改变
		{
			return const_iterator(_head->_next);
		}

		iterator end()//定义一个指向哨兵位的迭代器end
		{
			return iterator(_head);
		}

		const_iterator end() const//定义一个指向哨兵位的const迭代器end
		{
			return const_iterator(_head);
		}

		void empty_init()//空初始化,供构造函数和迭代器区间构造复用
		{
			_head = new node;//创建一个节点并将地址返回哨兵位

			//双向链表中第一个节点也就是哨兵位的_next和_prev均指向自己
			_head->_next = _head;
			_head->_prev = _head;
		} 

		template <class Iterator>//一个有迭代器区间构造的类模板
		list(Iterator first, Iterator last)
		{
			empty_init();

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void swap(list<T>& tmp)//链表交换
		{
			std::swap(_head, tmp._head);//对于内置类型直接使用std库中的swap函数
		}

		list(const list<T>& lt)//拷贝构造
		{
			//用范围for遍历新容器并push_back，更简单
			//empty_init();
			//for (auto e : lt)
			//{
			//	push_back(e);
			//}

			empty_init();
			list<T> tmp(lt.begin(), lt.end());//复用迭代器区间构造
			swap(tmp);

		}

		list<T>& operator=(list<T> lt)//重载=
		{
			swap(lt);
			return *this;
		}

		list()//构造函数
		{
			//复用empty_init
			empty_init();
		}

		~list()//析构函数
			   //由于析构表示链表彻底不用，所以这里还需要把哨兵位释放掉
		{
			clear();
			delete _head;//释放哨兵位
			_head = nullptr;//规避野指针
		}
		
		void clear()//把所有节点清除
		{
			iterator it = begin();//让it获取头节点的地址
			while (it != end())
			{
				it = erase(it);//erase返回的是当前节点的下一个节点，所以无需it++
				/*erase(it++);*/ //更简洁的写法
			}
		}

		void insert(iterator pos, const T& x)//插入数据函数，其功能为在pos位置之前插入数据x
		{
			node* cur = pos._node;//获取pos节点的地址
			node* prev = cur->_prev;//获取pos前一个节点的地址prev

			node* new_node = new node(x);//创建一个新节点，并将节点中存放的数据初始化为x

			prev->_next = new_node;//将prev的_next指向新开辟的节点
			new_node->_prev = prev;//将新开辟节点的_prev指向prev
			new_node->_next = cur;//将新开辟节点的_next指向cur也就是pos
			cur->_prev = new_node;//将pos节点的_prev指向新开辟的节点

		}

		void push_back(const T& x)//尾部插入函数,本质就是对insert进行复用
		{
			////不复用的写法：
			////无论是对一个空链表还是已经有节点的链表，_head的_prev始终指向尾部
			//node* tail = _head->_prev;//创建一个指向尾节点地址的指针_tail

			//node* new_node = new node(x);//创建一个新节点，并将节点中存放的数据初始化为x

			//tail->_next = new_node;//表示将新节点的地址赋给尾节点的_next
			//new_node->_prev = tail;//表示将新节点的_prev指向尾节点的地址
			//new_node->_next = _head;//表示将新节点的_next指向头节点的地址
			//_head->_prev = new_node;//表示将头节点的_prev指向新节点的地址

			//复用的写法：
			insert(end(), x);

		}

		void push_front(const T& x)//头部插入函数,本质还是对insert进行复用
		{
			insert(begin(), x);
		}

		iterator erase(iterator pos)//删除函数，功能为删除pos节点,并返回该节点的下一个节点
		{
			assert(pos != end());//哨兵位节点不能被删除，这里可以进行异常处理

			node* prev = pos._node->_prev;//找到pos节点的上一个节点prev
			node* next = pos._node->_next;//找到pos节点的下一个节点next

			//下面是跳过pos节点进行重新链接的过程
			prev->_next = next;//将prev节点中的_next直接指向next节点
			next->_prev = prev;//将next节点中的_prev直接指向prev节点

			delete pos._node;//删除pos节点
			
			return iterator(next);//返回原本pos的下一个节点
		}

		void pop_back()//删除尾部节点,直接复用erase
		{
			erase(--end()); //哨兵位--就是头节点
		}

		void pop_front()//删除头部节点,同样复用erase
		{
			erase(begin()); //哨兵位--就是头节点
		}
	private:

		node* _head;

	};

	//测试const迭代器
	void print_list(const list<int>& lt)
					//这里选择传引用，否则需要实现深拷贝，代价太大
	{//下面是一段test_list1中的代码，测试的话可以发现由于参数是const迭代器下面的代码编译后会报错
	 //核心原因在于这里相当于把迭代器的权限放大了，如果传给普通的迭代器那就意味着可以通过这个普通的迭代器进行修改，这是不允许的
	 
		/*list<int>::iterator it = lt.begin();
		list<int>::iterator end = lt.end();
		while (it != end)
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;*/
		//
		list<int>::const_iterator it = lt.begin();
		list<int>::const_iterator end = lt.end();
		while (it != end)
		{
			/*(*it) *= 2;*///这里可以作异常处理
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	//测试链表1
	void test_list1()
	{
		//测试尾插函数
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		//测试迭代器
		list<int>::iterator it = lt.begin();//调用默认的拷贝构造，浅拷贝
		//之前在string中，有些情况如果使用浅拷贝会出现因为指针指向的是同一块空间而在最后析构的时候报错
		//但这里由于迭代器类中没有写析构函数，所以没有出现报错。而之所以没有写析构函数是因为这里不需要释放节点，
		//而之所以不需要释放节点是因为这个节点的指针并不属于迭代器，迭代器的作用只是封装节点的指针以帮助实现遍历链表、修改链表等操作。
		//但是并不支持释放，释放应该由链表的析构函数来执行。
		//总结：迭代器有节点的使用权，但是没有归属权
		list<int>::iterator end = lt.end();
		while (it != end)
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		//用迭代器测试范围for
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		//测试const迭代器
		print_list(lt);
	}
	
	//测试链表2
	//结构体AA作为自定义类型的测试模型
	struct AA
	{
		int _a1;
		int _a2;

		AA(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}
	};
	void test_list2()
	{
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(2, 2));
		lt.push_back(AA(3, 3));
		lt.push_back(AA(4, 4));
		lt.push_back(AA(5, 5));

		list<AA>::iterator it = lt.begin();
		list<AA>::iterator end = lt.end();
		while (it != end)
		{
			/*cout << (*it)._a1 << " " << (*it)._a2 << " ";*/
			//上面的cout虽然能够输出AA中的内容但不如->实用
			cout << it->_a1 << " " << it->_a2 << " ";
			//本来应该是两个箭头，但是为了增强可读性，省略了一个，这是由编译器自己实现的
			++it;
		}
		cout << endl;
	}

	//测试链表3
	void test_list3()
	{
		//测试insert函数
		//先建立一个链表
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		//使用insert插入前的输入
		list<int>::iterator it = lt.begin();
		list<int>::iterator end = lt.end();
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		it = lt.begin();//将迭代器重置
		lt.insert(++it, 20);//使用insert在第二个节点的前面插入数据20

		//使用insert插入后的输入
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		//测试push_front函数
		lt.push_front(66);
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		//测试pop_front和pop_back
		lt.pop_front();
		lt.pop_back();
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	//测试链表4
	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		list<int>::iterator it = lt.begin();
		list<int>::iterator end = lt.end();
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		//测试clear函数
		lt.clear();
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << "已清空" << endl;;
	}

	//测试链表5
	void test_list5()
	{
		//测试拷贝构造
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2(lt);//拷贝构造
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		//测试=重载
		list<int> lt3;
		lt3 = lt;
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
