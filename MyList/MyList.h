#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
//������ģ�岻֧�������Ͷ�����룬���ͳһ��ͷ�ļ���ʵ��
namespace MyList//Ϊ�˷�ֹ��Ⱦ���������Լ��������ռ���
{
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
			,_prev(nullptr)

			,_data(x)//��_data��ʼ��Ϊx
		{}
	};

	//��������ȣ����������ռ��������ģ�������ָ��++����ʽ������һ������
	//���Ƕ���������ڵ�ͽڵ�֮���ǲ������ģ����Բ�����ָ��++����ʽ������һ������
	//��������++����һ��ָ�룬��������Ҳ����ͨ������++����ʽ��node*�ܷ�����һ���ڵ�
	//��STL���У���ʹ�õ�������ʵ�ֵģ���������������ģ��

	template<class T, class Ref, class Ptr>//һ���������������ģ�壬�൱�ڶԽڵ�ָ��ķ�װ
							//Ref��ʾ���ã�����������ͨ���úͳ�����
							//Ptr��ʾָ�룬���������Զ������͵���ָͨ���constָ��
	struct _list_iterator//���಻�Գ�Ա�ķ��ʽ������ƣ�����ʹ��struct
	{
		typedef list_node<T> node;//��list_node<T>������Ϊnode
		typedef _list_iterator<T, Ref, Ptr> self;//��_list_iterator<T, Ref>������Ϊself
		node* _node;//����һ���ڵ��ָ��

		//�ýڵ��ָ�빹��һ��������
		_list_iterator(node* n)
			:_node(n)
		{}

		//�������ĺ��Ĺ��ܣ�������
		Ref operator*()//��������ڵ�����ã����ܶ�����ڵ�ʵ���޸�
					   //���RefΪ��ͨ���ã�����ԶԽڵ�����޸ģ���Ϊ�����������޸�
		{
			return _node->_data;
		}

		
		Ptr operator->()//����->���������Զ������ͽ��н�����
					   //���PtrΪ�Զ������͵���ָͨ�룬����ԶԽڵ�����޸ģ���Ϊconstָ�������޸�
		{
			return &_node->_data;
		}

		self& operator++()//����ǰ��++���õ������ܹ����ʵ�ǰ�ڵ����һ���ڵ�
		//ָ��++���صĻ���ָ�룬��ô�������һ�¾Ͳ�����������++���صľͻ��ǵ�����
		{
			_node = _node->_next;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
			return *this;//���ص��øú����ĵ�����
		}

		self operator++(int)//���غ���++���õ������ܷ�����һ���ڵ�ǰ�ȷ��ص�ǰ�ڵ�
		{
			self tmp(*this);//����һ�ݵ�ǰ�ڵ�ĵ�ַ
			_node = _node->_next;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
			return tmp;//�����޸�ǰ�Ľڵ�
		}

		self& operator--()//����ǰ��--���õ������ܹ����ʵ�ǰ�ڵ����һ���ڵ�
		{
			_node = _node->_prev;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
			return *this;//���ص��øú����ĵ�����
		}

		self operator--(int)//���غ���--���õ������ܷ�����һ���ڵ�ǰ�ȷ��ص�ǰ�ڵ�
		{
			self tmp(*this);//����һ�ݵ�ǰ�ڵ�ĵ�ַ
			_node = _node->_prev;//����ǰ_node��Ϊָ����һ�ڵ�ĵ�ַ
			return tmp;//�����޸�ǰ�Ľڵ�
		}

		//�����������ж���������������������ܹ����бȽ�
		bool operator!=(const self& s)//����!=
		{
			return _node != s._node;//��������ڵ�ĵ�ַ����ȣ�����true�����򷵻�false
		}
		bool operator==(const self& s)//����==

		{
			return _node == s._node;//��������ڵ�ĵ�ַ��ȣ�����true�����򷵻�false
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

	template<class T>//
	class list//һ���������ģ��
	{
		typedef list_node<T> node;//��list_node<T>������Ϊnode�����㶨��
	public:
		
		typedef _list_iterator<T, T&, T*> iterator;//��������_list_iterator<T, T&, T*>������Ϊiterator,��ʾ�������Ϊ<T, T&>��ʹ����ͨ������

		//����C++�涨������������ĵ���������iterator������Ϊ��ͳһҲ��_list_iterator<T>������Ϊiterator
		//����Ҳ�����ñ�����֣����������Ͳ�֧�ַ�Χfor����Ϊ��Χfor��ɵ��ʽ��Ѱ��iterator���������

		typedef _list_iterator<T, const T&, const T*> const_iterator;//��������_list_iterator<T, const T&, const T*>������Ϊconst_iterator,��ʾ�������Ϊ<T, const T&, const T*>��ʹ��const������

		//_list_iterator������ģ������������typedef�ɺ���
		//typedef _list_const_iterator<T> const_iterator;//��������_list_const_iterator<T>������Ϊconst_iterator
		////ע�⣺���ڣ�typedef const iterator const_iterator;�����﷨�涨���ô����е�const���ε�ʵ������iterator*����˼�ǵ�������ָ�����޸ģ����Ǳ�ʾ������ָ������ݲ����޸�

		

		iterator begin()//����һ��ָ������ͷ���ĵ�����begin
		{
			//iterator it(_head->next);
			//return it;
			return iterator (_head->_next);//ʹ���������󷵻��ڱ�λ��_nextҲ����ͷ�ڵ�
										   //ʹ���������󷵻ؿ��Ե��ñ��������Զ��Ż�
		}

		
		const_iterator begin() const//����һ��ָ������ͷ����const������begin
						       //�����const���ε���*this��Ҳ����ָ������ݣ���˼��list�е�_head���ܱ��ı�
		{
			return const_iterator(_head->_next);
		}

		iterator end()//����һ��ָ���ڱ�λ�ĵ�����end
		{
			return iterator(_head);
		}

		const_iterator end() const//����һ��ָ���ڱ�λ��const������end
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
			erase(begin()); //�ڱ�λ--����ͷ�ڵ�
		}
	private:

		node* _head;

	};

	//����const������
	void print_list(const list<int>& lt)
					//����ѡ�����ã�������Ҫʵ�����������̫��
	{//������һ��test_list1�еĴ��룬���ԵĻ����Է������ڲ�����const����������Ĵ�������ᱨ��
	 //����ԭ�����������൱�ڰѵ�������Ȩ�޷Ŵ��ˣ����������ͨ�ĵ������Ǿ���ζ�ſ���ͨ�������ͨ�ĵ����������޸ģ����ǲ������
	 
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
			/*(*it) *= 2;*///����������쳣����
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	//��������1
	void test_list1()
	{
		//����β�庯��
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		//���Ե�����
		list<int>::iterator it = lt.begin();//����Ĭ�ϵĿ������죬ǳ����
		//֮ǰ��string�У���Щ������ʹ��ǳ�����������Ϊָ��ָ�����ͬһ��ռ�������������ʱ�򱨴�
		//���������ڵ���������û��д��������������û�г��ֱ�����֮����û��д������������Ϊ���ﲻ��Ҫ�ͷŽڵ㣬
		//��֮���Բ���Ҫ�ͷŽڵ�����Ϊ����ڵ��ָ�벢�����ڵ�������������������ֻ�Ƿ�װ�ڵ��ָ���԰���ʵ�ֱ��������޸�����Ȳ�����
		//���ǲ���֧���ͷţ��ͷ�Ӧ�������������������ִ�С�
		//�ܽ᣺�������нڵ��ʹ��Ȩ������û�й���Ȩ
		list<int>::iterator end = lt.end();
		while (it != end)
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		//�õ��������Է�Χfor
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		//����const������
		print_list(lt);
	}
	
	//��������2
	//�ṹ��AA��Ϊ�Զ������͵Ĳ���ģ��
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
			//�����cout��Ȼ�ܹ����AA�е����ݵ�����->ʵ��
			cout << it->_a1 << " " << it->_a2 << " ";
			//����Ӧ����������ͷ������Ϊ����ǿ�ɶ��ԣ�ʡ����һ���������ɱ������Լ�ʵ�ֵ�
			++it;
		}
		cout << endl;
	}

	//��������3
	void test_list3()
	{
		//����insert����
		//�Ƚ���һ������
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		//ʹ��insert����ǰ������
		list<int>::iterator it = lt.begin();
		list<int>::iterator end = lt.end();
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		it = lt.begin();//������������
		lt.insert(++it, 20);//ʹ��insert�ڵڶ����ڵ��ǰ���������20

		//ʹ��insert����������
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		//����push_front����
		lt.push_front(66);
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;

		//����pop_front��pop_back
		lt.pop_front();
		lt.pop_back();
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	//��������4
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

		//����clear����
		lt.clear();
		for (it = lt.begin(); it != end; ++it)
		{
			cout << *it << " ";
		}
		cout << "�����" << endl;;
	}

	//��������5
	void test_list5()
	{
		//���Կ�������
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

		list<int> lt2(lt);//��������
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		//����=����
		list<int> lt3;
		lt3 = lt;
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
