#pragma once
//顺序表基本运算算法
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType* data;		//存放顺序表元素
	int length;					//存放顺序表的长度
} SqList;						//顺序表的类型
void CreateList(SqList*& L, ElemType a[], int n)
//建立顺序表
{
	L = (SqList*)malloc(sizeof(SqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * 2);
	for (int i = 0; i < n; i++)
		if (L->data[i] != '\0')
			L->data[i] = a[i];
	L->length = n;
}
bool ListInsert(SqList*& L, ElemType e)//插入元素
{
	int j, i = 3;
	if (i<1 || i>L->length + 1)//判断数组内存空间是否足够
		L->data = (ElemType*)realloc(L->data, sizeof(ElemType) * (L->length + 1));//数组内存增加一个单位
	i--;						//将顺序表位序转化为elem下标
	for (j = L->length; j > i; j--) 	//将data[i]及后面元素后移一个位置
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;				//顺序表长度增1
	return true;
}
void DispList(SqList* L)//输出线性表
{
	for (int i = 0; i < L->length; i++)
		printf("%c ", L->data[i]);
	printf("\n");
}
int ListLength(SqList* L)//求线性表的长度
{
	return(L->length);
}
void DestroyList(SqList*& L)//释放内存
{
	free(L);
}