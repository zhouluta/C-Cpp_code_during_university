#include<iostream>
using namespace std;

typedef struct {
	int data[10];
	int length;
}Sqlist;

void CreatList(Sqlist*& L, int a[], int n) {
	int i = 0, k = 0;
	L = (Sqlist*)malloc(sizeof(Sqlist));
	while (i < n)
	{
		L->data[i] = a[i];
		k++;
		i++;
	}
	L->length = k;
}
void Initlist(Sqlist*& L) {
	L = (Sqlist*)malloc(sizeof(Sqlist));
	L->length = 0;
}
void DestroyList(Sqlist*& L) {
	free(L);
}
bool ListEmpty(Sqlist* L) {
	return (L->length == 0);
}
int ListLength(Sqlist* L) {
	return(L->length);
}
void DispList(Sqlist* L) {
	if (ListEmpty(L))
		cout << "List is empty" << endl;
	else
	{
		for (int i = 0;i < L->length;i++) {
			cout << "第" << i << "个data:" << L->data[i] << endl;
		}
	}
	cout << endl;
}
bool GetElem(Sqlist* L, int i, int& e) {
	if (i<L->length || i>L->length)
		return false;
	e = L->data[i-1];
	return true;
}
int LocateElem(Sqlist* L, int e) {
	int i = 0;
	while (i < L->length && e != L->data[i])
		i++;
	if (i > L->length)
		return 0;
	else
		return i + 1;
}
bool ListInsert(Sqlist*& L, int i, int e) {
	int j;
	if (i<1 || i>L->length + 1)
		return false;
	i--;
	for (j = L->length;j > i;j--)
		L->data[j] = L->data[j-1];
	L->data[i] = e;
	L->length++;
	return true;
}
bool ListDelete(Sqlist*& L, int i, int& e) {
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (j = i;j < L->length - 1;j++)
		L->data[j] = L->data[j + 1];
	L->length++;
	cout<<"第 "<<i+1<<" 个元素 " << e << " has been deleted";
	return true;
}

void main() {
	Sqlist *L,*L1;
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	CreatList(L, a, 10);
	DispList(L);

	int b[10] = { NULL };
	CreatList(L1, b, 0);
	DispList(L1);
	
	int e;
	ListDelete(L, 5, e);
	
	
	
	
	cout << endl;
	system("pause");

}