#ifndef _HUFFMAN_TREE_HPP_
#define _HUFFMAN_TREE_HPP_
template <typename T>
struct HuffmanNode
{
	HuffmanNode() = default;
	HuffmanNode(T key)
		:lchild(nullptr), rchild(nullptr), parent(nullptr){}
	~HuffmanNode();

	T key;
	HuffmanNode<T>* lchild;
	HuffmanNode<T>* rchild;
	HuffmanNode<T>* parent;

};

template <typename T>
class Huffman
{
public:
	Huffman();
	~Huffman();

	void preOrder();			  //ǰ�������������
	void inOrder();				  //���������������
	void postOrder();			  //���������������

	void creat(T a[], int size);  //������������
	void destory();				  //���ٹ�������
	void print();				  //��ӡ��������

private:
	void preOrder(HuffmanNode<T>* pnode);
	void inOrder(HuffmanNode<T>* pnode);
	void postOrder(HuffmanNode<T>*pnode);
	void print(HuffmanNode<T>*pnode);
	void destroy(HuffmanNode<T>*pnode);

private:
	HuffmanNode<T>* root;
};

/*Ĭ�Ϲ��캯��*/
template<typename T>
Huffman<T>::Huffman()
	:root(nullptr){};

/*������������*/
template<typename T>
void Huffman<T>::creat(T a[], int size)
{
	//����ÿ�ζ�Ҫ��ʣ�µĽڵ�����ѡ������С�ģ��ʺ���С����
};

#endif