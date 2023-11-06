#define _CRT_SECURE_NO_WARNINGS	1
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
		, _prev(nullptr)

		, _data(x)//将_data初始化为x
	{}
};

template<class T, class Ref, class Ptr>						
struct _list_iterator
{
	typedef list_node<T> node;
	typedef _list_iterator<T, Ref, Ptr> self;
	node* _node;

	_list_iterator(node* n)
		:_node(n)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()			  
	{
		return &_node->_data;
	}

	self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	self operator--(int)
	{
		self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;
	}

	bool operator==(const self& s)
	{
		return _node == s._node;
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

template<class T>
class list
{
	typedef list_node<T> node;
public:

	typedef _list_iterator<T, T&, T*> iterator;
	typedef _list_iterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		return iterator(_head->_next);							   
	}

	const_iterator begin() const			   
	{
		return const_iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator end() const
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
		erase(begin());
	}
private:

	node* _head;

};