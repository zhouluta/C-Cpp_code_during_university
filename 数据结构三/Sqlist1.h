#pragma once
//˳�����������㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType* data;		//���˳���Ԫ��
	int length;					//���˳���ĳ���
} SqList;						//˳��������
void CreateList(SqList*& L, ElemType a[], int n)
//����˳���
{
	L = (SqList*)malloc(sizeof(SqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * 2);
	for (int i = 0; i < n; i++)
		if (L->data[i] != '\0')
			L->data[i] = a[i];
	L->length = n;
}
bool ListInsert(SqList*& L, ElemType e)//����Ԫ��
{
	int j, i = 3;
	if (i<1 || i>L->length + 1)//�ж������ڴ�ռ��Ƿ��㹻
		L->data = (ElemType*)realloc(L->data, sizeof(ElemType) * (L->length + 1));//�����ڴ�����һ����λ
	i--;						//��˳���λ��ת��Ϊelem�±�
	for (j = L->length; j > i; j--) 	//��data[i]������Ԫ�غ���һ��λ��
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;				//˳�������1
	return true;
}
void DispList(SqList* L)//������Ա�
{
	for (int i = 0; i < L->length; i++)
		printf("%c ", L->data[i]);
	printf("\n");
}
int ListLength(SqList* L)//�����Ա�ĳ���
{
	return(L->length);
}
void DestroyList(SqList*& L)//�ͷ��ڴ�
{
	free(L);
}