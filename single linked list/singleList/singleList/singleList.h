/*
* ����C++templateʵ�ֵĵ�������
* ���ߣ�huanzheWu
* ʱ�䣺2016/1/24
*/

# ifndef SINGLE_LIST_HXX
# define SINGLE_LIST_HXX
#include<iostream>

//�ڵ�ṹ
template <typename T>
class Node
{
public :
	T _value;
	Node* _next;
public:
	Node() = default;
	Node(T value, Node * next)
		: _value(value), _next(next){}
};

//������
template <typename T>
class SingleLink
{
public:
	typedef Node<T>*  pointer;

	SingleLink();
	~SingleLink();
	//��ȡ����
	int size();
	//�п�
	bool isEmpty();
	//�������
	Node<T>* insert_after(int index, T t);
	Node<T>* insert_head(T t);
	Node<T>* insert_last(T t);
	//ɾ������
	Node<T>*  del(int index);
	Node<T>*  delete_head();
	Node<T>*  delete_last();
	//��ȡԪ��
	T get(int index);
	T get_head();
	T get_last();
private :
	int count;
	Node<T> * phead;
	Node<T> * getNode(int index);
};

//Ĭ�Ϲ��캯��
template <typename T>
SingleLink<T>::SingleLink()
:count(0), phead(nullptr)
{
	//����ͷ�ڵ�
	phead = new Node<T>();
	phead->_next = nullptr;
};

/*
����ָ��������ǰһ��λ�ýڵ㣬������Ϊ�գ��򷵻�ͷ�ڵ�
*/

template <typename T>
Node<T>* SingleLink<T>::getNode(int index)
{
	if (index > count||index < 0 )
		return nullptr;
	int temp = 0;
	Node<T>* ptr = phead;
	while (temp < index)
	{
		temp++;
		ptr = ptr->_next;
	}
	return ptr;
}
/*
��������
*/
template <typename T>
SingleLink<T>::~SingleLink()
{
	while (!isEmpty())
	{
		del(0);
	}
	//��������
};

//��������Ĵ�С
template <typename T>
int SingleLink<T>::size()
{
	return count;
};
//�����п�
template <typename T>
bool SingleLink<T>::isEmpty()
{
	return count==0;
};
//��ָ��λ�ò����½ڵ�
template <typename T>
Node<T>* SingleLink<T>::insert_after(int index, T t)
{
	Node<T> * ptrNode = getNode(index);
	if (ptrNode)
	{
		Node<T> *newNode = new Node<T>(t,ptrNode->_next);
		ptrNode->_next = newNode;
		count++;
		return newNode;
	}
	return nullptr;
};
/*
��ͷ������
*/
template <typename T>
Node<T>* SingleLink<T>::insert_head(T t)
{
	return insert_after(0, t);
};
/*
��β�����в���
*/
template <typename T>
Node<T>* SingleLink<T>::insert_last(T t)
{
	return insert_after(count, t);
};
/*
ɾ������ָ��λ��Ԫ��
*/
template <typename T>
Node<T>* SingleLink<T>::del(int index)
{
	if (isEmpty())
		return nullptr;
	Node<T>* ptrNode = getNode(index);
	Node<T>* delNode = ptrNode->_next;
	ptrNode->_next = delNode->_next;
	count--;
	delete delNode;
	return ptrNode->_next;
};
/*
ɾ��ͷ�ڵ�
*/
template<typename T>
Node<T>* SingleLink<T>::delete_head()
{
	return del(0);
};
/*
ɾ��β�ڵ�
*/
template<typename T>
Node<T>*SingleLink<T>::delete_last()
{
	return del(count);
};



# endif