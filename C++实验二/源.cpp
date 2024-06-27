#include<iostream>
using namespace std;
//第一题
//void main() {
//	int n,random;
//	random = rand() % 100 + 1;
//	cout << "input n(0<n<100):" << endl;
//	cout << "random："<<random << endl;
//	cin >> n;
//	while(n==random)
//	{
//		cout << "you're right" << endl;
//		break;
//	}
//	while(n != random)
//	{
//		cout << "please retry" << endl;
//		cin >> n;
//	}
//
//}

//第二题
//void main() {
//
//	char A[5] = { 'a','b','c','d','d' };
//	for (int i = 0;i < 5;i++)
//	{
//		if (A[i] == 100)
//			A[i] = NULL;
//
//	}
//	for (int i = 0;i < 5;i++)
//	{
//		cout << A[i] << "  ";
//	}
//
//}
//第三题
//void main() {
//	int a[5] = { 2,3,5,7,4 };
//	int max = a[0];
//	int second = a[1];
//	for (int i = 0;i < 5;i++)
//	{
//		if (a[i] > max)
//		{
//			second = max;
//			max = a[i];
//		}
//		if (a[i] > second && a[i] < max)
//			second = a[i];
//	}
//	cout << "第二大的数为:" << second << endl;
//}

//第四题

void main() {
	int b[5] = { 1,2,3,4,5 };
	int i = 0;
	int c[5];
	for(i = 0;i < 5;i++)
	{
		c[i] = b[4 - i];
		cout << c[i] << " ";

	}


}
