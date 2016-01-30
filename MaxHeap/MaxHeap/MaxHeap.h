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
	bool remove(T data);	//�Ƴ�Ԫ��
private:
	int capacity;	//������Ҳ��������Ĵ�С
	int size;		//�Ѵ�С��Ҳ������������ЧԪ�صĸ���
	T * heap;		//�ײ������
private:
	void filterUp(int index); //��index���ڽڵ㣬�����ڵ������
	void filterDown(int begin ,int end ); //��begin���ڽڵ㿪ʼ����end���������
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
/*����Ԫ��ʱ��ʹ��*/
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

/*ɾ��Ԫ��*/
template<typename T>
bool MaxHeap<T>::remove(T data)
{
	if (size == 0) //������ǿյ�
		return false;
	int index;
	for (index = 0; index < size; index++)  //��ȡֵ�������е�����
	{
		if (phead[index] == date)
			break;
	}
	if (index == size)			//������û�и�ֵ
		return false;  
	
	heap[index] = heap[size - 1];
	filterDown(index,size--);   
	return true;
};
/*���ϵ��µ�����*/
/*ɾ��Ԫ��ʱ��ʹ��*/
template<typename T>
void MaxHeap<T>::filterDown(int begin,int end)
{
	int current = begin;	//��ǰ���

	int child = begin * 2 + 1; //��ǰ��������

	T value = heap[current];	//���浱ǰ����ֵ

	while (child <= end)
	{
		if (child < end&&heap[child] < heap[child+1])//ѡ�����������нϴ�ĺ���
			child++;
		if (value>heap[child])	//�����������������
			break;
		else
		{
			heap[current] = heap[child];	//���ӽڵ㸲�ǵ�ǰ���
			current = child;				//�����ƶ�
			child = child * 2 + 1;			
		}
	}
	heap[curren] = value;
};

# endif 