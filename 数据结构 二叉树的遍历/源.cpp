
//二叉树的基本运算算法
#include <stdio.h>
#include <malloc.h>
#include<iostream>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;			//数据元素
	struct node* lchild;	//指向左孩子节点
	struct node* rchild;	//指向右孩子节点
} BTNode;
void CreateBTree(BTNode*& b, char* str)	//创建二叉树
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0')  	//str未扫描完时循环
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//为左孩子节点
		case ')':top--; break;
		case ',':k = 2; break;                      		//为孩子节点右节点
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 	//*p为二叉树的根节点
				b = p;
			else  								//已建立二叉树根节点
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
	if (b == NULL) return(0); 				//空树的高度为0
	else
	{
		lchildh = BTHeight(b->lchild);	//求左子树的高度为lchildh
		rchildh = BTHeight(b->rchild);	//求右子树的高度为rchildh
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
			printf("(");						//有孩子节点时才输出(
			DispBTree(b->lchild);				//递归处理左子树
			if (b->rchild != NULL) printf(",");	//有右孩子节点时才输出,
			DispBTree(b->rchild);				//递归处理右子树
			printf(")");						//有孩子节点时才输出)
		}
	}
}
int Nodes(BTNode* b) {             //定义计算二叉树的节点数的函数
	if (b == NULL)
		return 0;
	else
		return Nodes(b->lchild) + Nodes(b->rchild) + 1;
}
int LeafNum(BTNode* b, int& num) {         //定义计算二叉树的叶子数的函数
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
int Level(BTNode* b, char x, int h) {      //定义寻找二叉树中指定字符并输出对应层次的函数
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
//以下主函数用做调试
void main()
{
	int num = 0, h = 1, l=1;
	char x;
	BTNode* b;
	CreateBTree(b, "A(B(D,E),C(,F))");//创建二叉树
	DispBTree(b);                     //打印二叉树
	printf("\n");

	Nodes(b);                         //计算二叉树结点数
	std::cout << "结点数：" << Nodes(b) << std::endl;   //输出二叉树的节点数

	LeafNum(b, num);                  //引用传叶子数
	std::cout << "叶子数：" << num << std::endl;        //输出二叉树的叶子数
	
	std::cout << "输入查找的结点：";
	std::cin >> x;
	h = Level(b, x, l);
	if (h == 0)
		std::cout << "b中不存在" << x << "结点" << " ";
	else
		std::cout << "在b中" << x << "的层次为" << h << std::endl;


	std::cout << std::endl;
	system("pause");
}
