/*
conetent : �󶥶�
author :huanzheWu
date:2016/1/30
*/

# ifndef _MAX_HEAP_HCC_
# define _MAX_HEAP_HCC_
/*�󶥶��ඨ��*/
template <typename T>
class MaxHeap
{
public:
	MaxHeap(int cap = 10);
	~MaxHeap(){};
public:
	bool insert(T val);	//��������в���Ԫ��
	bool remove();	//�Ƴ�Ԫ��
private:
	int capacity;	//������Ҳ��������Ĵ�С
	int size;		//�Ѵ�С��Ҳ������������ЧԪ�صĸ���
	T * heap;		//�ײ������
private:
	void filterUp(int index); //��index���ڽڵ㣬�����ڵ������
};
/*Ĭ�Ϲ��캯��*/
template <typename T>
MaxHeap<T>::MaxHeap(int cap = 10) //Ĭ�ϵ������СΪ10
:capacity(cap), size(0), heap(nullptr)
{
	heap = new T[capacity];
};

/*����Ԫ��*/
template <typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity) //��������������򷵻�false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
};
/*���µ��ϵ�����*/
template <typename T>
void MaxHeap<T>::filterUp(int index)
{
	while (index > 0) //�����δ������ڵ㣬��������
	{
		int indexParent = index / 2;  //����˫�׽ڵ�
		if (heap[index] > heap[indexParent])
		{
			T temp = heap[index];
			heap[index] = heap[indexParent];
			heap[indexParent] = temp;
		}
		index = indexParent;
	}
};

# endif 