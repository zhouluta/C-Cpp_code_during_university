#include<stdio.h>
#include<iostream>

#include"Sqlist1.h"
int main() {
	SqList* H;
	int i;
	char f = 'f';
	ElemType a[2];
	int n = 2;
	printf("����������Ԫ�أ�");
	for (i = 0; i < n; i++) {
		scanf_s("%c", &a[i]);
		getchar();
	}
	CreateList(H, a, n);//����˳���
	DispList(H);//������Ա�
	printf("���б�ĳ���Ϊ��%d\n", ListLength(H));
	printf("�ڵ�3��Ԫ�ز���Ԫ��f\n");
	ListInsert(H, f);//����Ԫ��
	DispList(H);//������Ա�
	printf("���б�ĳ���Ϊ��%d\n", ListLength(H));
	DestroyList(H);//�ͷ��ڴ�
	system("pause");
	return 0;
}

