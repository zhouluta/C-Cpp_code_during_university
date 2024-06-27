
//�������Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
#include<iostream>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;			//����Ԫ��
	struct node* lchild;	//ָ�����ӽڵ�
	struct node* rchild;	//ָ���Һ��ӽڵ�
} BTNode;
void CreateBTree(BTNode*& b, char* str)	//����������
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0')  	//strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//Ϊ���ӽڵ�
		case ')':top--; break;
		case ',':k = 2; break;                      		//Ϊ���ӽڵ��ҽڵ�
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 	//*pΪ�������ĸ��ڵ�
				b = p;
			else  								//�ѽ������������ڵ�
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
void DestroyBTree(BTNode*& b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
BTNode* FindNode(BTNode* b, ElemType x)
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}
BTNode* LchildNode(BTNode* p)
{
	return p->lchild;
}
BTNode* RchildNode(BTNode* p)
{
	return p->rchild;
}
int BTHeight(BTNode* b)
{
	int lchildh, rchildh;
	if (b == NULL) return(0); 				//�����ĸ߶�Ϊ0
	else
	{
		lchildh = BTHeight(b->lchild);	//���������ĸ߶�Ϊlchildh
		rchildh = BTHeight(b->rchild);	//���������ĸ߶�Ϊrchildh
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}
void DispBTree(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");						//�к��ӽڵ�ʱ�����(
			DispBTree(b->lchild);				//�ݹ鴦��������
			if (b->rchild != NULL) printf(",");	//���Һ��ӽڵ�ʱ�����,
			DispBTree(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽڵ�ʱ�����)
		}
	}
}
int Nodes(BTNode* b) {             //�������������Ľڵ����ĺ���
	if (b == NULL)
		return 0;
	else
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
}
int LeafNum(BTNode* b, int& num) {         //��������������Ҷ�����ĺ���
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			num++;
			//std::cout << b->data;
		}
		num = LeafNum(b->lchild, num);
		num = LeafNum(b->rchild, num);
	}
	return num;
}
int Level(BTNode* b, char x, int h) {      //����Ѱ�Ҷ�������ָ���ַ��������Ӧ��εĺ���
	int l;
	if (b == NULL)
		return 0;
	else if (b->data == x)
		return h;
	else
	{
		l = Level(b->lchild, x, h + 1);
		if (l != 0)
			return l;
		else
			return Level(b->rchild, x, h + 1);
	}
}
//������������������
void main()
{
	int num = 0, h = 1, l=1;
	char x;
	BTNode* b;
	CreateBTree(b, "A(B(D,E),C(,F))");//����������
	DispBTree(b);                     //��ӡ������
	printf("\n");

	Nodes(b);                         //��������������
	std::cout << "�������" << Nodes(b) << std::endl;   //����������Ľڵ���

	LeafNum(b, num);                  //���ô�Ҷ����
	std::cout << "Ҷ������" << num << std::endl;        //�����������Ҷ����
	
	std::cout << "������ҵĽ�㣺";
	std::cin >> x;
	h = Level(b, x, l);
	if (h == 0)
		std::cout << "b�в�����" << x << "���" << " ";
	else
		std::cout << "��b��" << x << "�Ĳ��Ϊ" << h << std::endl;


	std::cout << std::endl;
	system("pause");
}
