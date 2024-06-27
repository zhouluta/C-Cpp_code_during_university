#include<stdio.h>
#include<iostream>

#include"Sqlist1.h"
int main() {
	SqList* H;
	int i;
	char f = 'f';
	ElemType a[2];
	int n = 2;
	printf("请输入两个元素：");
	for (i = 0; i < n; i++) {
		scanf_s("%c", &a[i]);
		getchar();
	}
	CreateList(H, a, n);//建立顺序表
	DispList(H);//输出线性表
	printf("该列表的长度为：%d\n", ListLength(H));
	printf("在第3个元素插入元素f\n");
	ListInsert(H, f);//插入元素
	DispList(H);//输出线性表
	printf("该列表的长度为：%d\n", ListLength(H));
	DestroyList(H);//释放内存
	system("pause");
	return 0;
}

