#define _CRT_SECURE_NO_WARNINGS	1
template<class T>//һ�����浱ǰ�ڵ����ݵ���ģ��
struct list_node//���಻�Գ�Ա�ķ��ʽ������ƣ�����ʹ��struct
{
	list_node<T>* _next;//ָ����һ���ڵ��ַ��ָ��
	list_node<T>* _prev;//ָ����һ���ڵ��ַ��ָ��
	T _data;//��ǰ�ڵ������

	list_node(const T& x = T())//���캯��,ȱʡֵ��Ϊһ���������������������������Լ����͵�Ĭ�Ϲ���
							 //ע�⣺�˴�ȱʡֵ���ܸ�0����ΪT��һ����int����

		//ָ���������ʼ��Ϊ��ָ�룬�ڲ��뺯���вŽ���ָ��
		:_next(nullptr)
		, _prev(nullptr)

		, _data(x)//��_data��ʼ��Ϊx
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

//�ܽ᣺������Ҫô����ԭ��ָ�룬Ҫô�����Զ������Ͷ�ԭ��ָ��ķ�װ��ģ��ָ�����Ϊ

////����Ĵ���ʵ�����Ƕ���ģ�������ͨ�������е�ģ�����ֻ��class T����Ч������ʵ�������ע�͵�����Ӱ������
//template<class T>//һ������const����������ģ�壬�õ�����ָ������ݲ����޸�
//struct _list_const_iterator//���಻�Գ�Ա�ķ��ʽ������ƣ�����ʹ��struct
//{
//	typedef list_node<T> node;//��list_node<T>������Ϊnode
//	typedef _list_const_iterator<T> self;//��_list_const_iterator<T>������Ϊself
//	node* _node;//����һ���ڵ��ָ��

//	//�ýڵ��ָ�빹��һ��const������
//	_list_const_iterator(node* n)
//		:_node(n)
//	{}

//	const T& operator*()//��������ڵ�����ã�����ڵ�����ݲ��ܱ��޸�
//	{
//		return _node->_data;
//	}

//	self& operator++()//����ǰ��++���õ������ܹ����ʵ�ǰ�ڵ����һ���ڵ�
//	//ָ��++���صĻ���ָ�룬��ô�������һ�¾Ͳ�����������++���صľͻ��ǵ�����
//	{
//		_node = _node->_next;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
//		return *this;//���ص��øú����ĵ�����
//	}

//	self operator++(int)//���غ���++���õ������ܷ�����һ���ڵ�ǰ�ȷ��ص�ǰ�ڵ�
//	{
//		self tmp(*this);//����һ�ݵ�ǰ�ڵ�ĵ�ַ
//		_node = _node->_next;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
//		return tmp;//�����޸�ǰ�Ľڵ�
//	}

//	self& operator--()//����ǰ��--���õ������ܹ����ʵ�ǰ�ڵ����һ���ڵ�
//	{
//		_node = _node->_prev;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
//		return *this;//���ص��øú����ĵ�����
//	}

//	self operator--(int)//���غ���--���õ������ܷ�����һ���ڵ�ǰ�ȷ��ص�ǰ�ڵ�
//	{
//		self tmp(*this);//����һ�ݵ�ǰ�ڵ�ĵ�ַ
//		_node = _node->_prev;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
//		return tmp;//�����޸�ǰ�Ľڵ�
//	}

//	//�����������ж���������������������ܹ����бȽ�
//	bool operator!=(const self& s)//����!=
//	{
//		return _node != s._node;//��������ڵ�ĵ�ַ����ȣ�����true�����򷵻�false
//	}
//	bool operator==(const self& s)//����==

//	{
//		return _node == s._node;//��������ڵ�ĵ�ַ��ȣ�����true�����򷵻�false
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

	void empty_init()//�ճ�ʼ��,�����캯���͵��������乹�츴��
	{
		_head = new node;//����һ���ڵ㲢����ַ�����ڱ�λ

		//˫�������е�һ���ڵ�Ҳ�����ڱ�λ��_next��_prev��ָ���Լ�
		_head->_next = _head;
		_head->_prev = _head;
	}

	template <class Iterator>//һ���е��������乹�����ģ��
	list(Iterator first, Iterator last)
	{
		empty_init();

		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

	void swap(list<T>& tmp)//������
	{
		std::swap(_head, tmp._head);//������������ֱ��ʹ��std���е�swap����
	}

	list(const list<T>& lt)//��������
	{
		//�÷�Χfor������������push_back������
		//empty_init();
		//for (auto e : lt)
		//{
		//	push_back(e);
		//}

		empty_init();
		list<T> tmp(lt.begin(), lt.end());//���õ��������乹��
		swap(tmp);

	}

	list<T>& operator=(list<T> lt)//����=
	{
		swap(lt);
		return *this;
	}

	list()//���캯��
	{
		//����empty_init
		empty_init();
	}

	~list()//��������
		   //����������ʾ�����ײ��ã��������ﻹ��Ҫ���ڱ�λ�ͷŵ�
	{
		clear();
		delete _head;//�ͷ��ڱ�λ
		_head = nullptr;//���Ұָ��
	}

	void clear()//�����нڵ����
	{
		iterator it = begin();//��it��ȡͷ�ڵ�ĵ�ַ
		while (it != end())
		{
			it = erase(it);//erase���ص��ǵ�ǰ�ڵ����һ���ڵ㣬��������it++
			/*erase(it++);*/ //������д��
		}
	}

	void insert(iterator pos, const T& x)//�������ݺ������书��Ϊ��posλ��֮ǰ��������x
	{
		node* cur = pos._node;//��ȡpos�ڵ�ĵ�ַ
		node* prev = cur->_prev;//��ȡposǰһ���ڵ�ĵ�ַprev

		node* new_node = new node(x);//����һ���½ڵ㣬�����ڵ��д�ŵ����ݳ�ʼ��Ϊx

		prev->_next = new_node;//��prev��_nextָ���¿��ٵĽڵ�
		new_node->_prev = prev;//���¿��ٽڵ��_prevָ��prev
		new_node->_next = cur;//���¿��ٽڵ��_nextָ��curҲ����pos
		cur->_prev = new_node;//��pos�ڵ��_prevָ���¿��ٵĽڵ�

	}

	void push_back(const T& x)//β�����뺯��,���ʾ��Ƕ�insert���и���
	{
		////�����õ�д����
		////�����Ƕ�һ�����������Ѿ��нڵ������_head��_prevʼ��ָ��β��
		//node* tail = _head->_prev;//����һ��ָ��β�ڵ��ַ��ָ��_tail

		//node* new_node = new node(x);//����һ���½ڵ㣬�����ڵ��д�ŵ����ݳ�ʼ��Ϊx

		//tail->_next = new_node;//��ʾ���½ڵ�ĵ�ַ����β�ڵ��_next
		//new_node->_prev = tail;//��ʾ���½ڵ��_prevָ��β�ڵ�ĵ�ַ
		//new_node->_next = _head;//��ʾ���½ڵ��_nextָ��ͷ�ڵ�ĵ�ַ
		//_head->_prev = new_node;//��ʾ��ͷ�ڵ��_prevָ���½ڵ�ĵ�ַ

		//���õ�д����
		insert(end(), x);

	}

	void push_front(const T& x)//ͷ�����뺯��,���ʻ��Ƕ�insert���и���
	{
		insert(begin(), x);
	}

	iterator erase(iterator pos)//ɾ������������Ϊɾ��pos�ڵ�,�����ظýڵ����һ���ڵ�
	{
		assert(pos != end());//�ڱ�λ�ڵ㲻�ܱ�ɾ����������Խ����쳣����

		node* prev = pos._node->_prev;//�ҵ�pos�ڵ����һ���ڵ�prev
		node* next = pos._node->_next;//�ҵ�pos�ڵ����һ���ڵ�next

		//����������pos�ڵ�����������ӵĹ���
		prev->_next = next;//��prev�ڵ��е�_nextֱ��ָ��next�ڵ�
		next->_prev = prev;//��next�ڵ��е�_prevֱ��ָ��prev�ڵ�

		delete pos._node;//ɾ��pos�ڵ�

		return iterator(next);//����ԭ��pos����һ���ڵ�
	}

	void pop_back()//ɾ��β���ڵ�,ֱ�Ӹ���erase
	{
		erase(--end()); //�ڱ�λ--����ͷ�ڵ�
	}

	void pop_front()//ɾ��ͷ���ڵ�,ͬ������erase
	{
		erase(begin());
	}
private:

	node* _head;

};