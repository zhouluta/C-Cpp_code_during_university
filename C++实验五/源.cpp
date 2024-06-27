#include<iostream>
#include<string>
using namespace std;
//第一题
//char* copy(char* p, char a[])//函数前加*
//{
//	p = a;//地址相同
//	return p;//返回p
//}
//int main()
//{
//	char a[5];
//	cout << "输入5个字符组成的字符串：";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> a[i];
//	}
//	cout << "字符串a[5]:";
//	for (int i = 0; i < 5; i++)
//	{
//		cout << a[i] << " ";
//	}
//	char* p = NULL;
//	p = copy(p, a);
//	cout << "\n通过指针拷贝后输出：";
//	for (int i = 0; i < 5; i++)
//	{
//		cout << p[i] << " ";
//	}
//	system("pause");
//	return 0;
//}
//第二题
//void main() {
//	int a[3][3];
//	int b[3][3];
//	int c[3][3];
//	for (int i = 0;i < 3;i++) {
//		for (int j = 0;j < 3;j++) {
//			cin >> a[i][j];
//		}
//	}
//	for (int i = 0;i < 3;i++) {
//		for (int j = 0;j < 3;j++) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = 0;i < 3;i++) {
//		for (int j = 0;j < 3;j++) {
//			cin >> b[i][j];
//		}
//	}
//	for (int i = 0;i < 3;i++) {
//		for (int j = 0;j < 3;j++) {
//			cout << b[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = 0;i < 3;++i) {
//		for (int j = 0;j < 3;++j) {
//			c[i][j] = 0;
//			for (int k = 0;k < 3;++k)
//				c[i][j] += a[i][k] * b[k][j];
//		}
//	}
//	for (int i = 0;i < 3;i++) {
//		for (int j = 0;j < 3;j++) {
//			cout << c[i][j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}
//第三题
void sort(char* a[])
{
	int i, j;
	char* temp;
	for (i = 0; i < 4; i++)//注意是i<4,总共有五个字符串而后面要+1
	{
		for (j = 0; j < 4; j++)//注意是j<4,总共有五个字符串而下面要+1和后面的那个字符串比较
		{
			if (strcmp(a[j], a[j + 1]) > 0)//字符串比较:>0表示前面的字符串比后面的大则交换
			{//两个字符串自左向右逐个字符相比（按 ASCII 值大小相比较），直到出现不同的字符或遇 \0 为止
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void print(char* a[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
}
int main()
{
	char* a[5];//字符指针数组
	char a1[] = "abc", a2[] = "aacd", a3[] = "aac", a4[] = "bcd", a5[] = "bcdef";
	a[0] = a1;
	a[1] = a2;
	a[2] = a3;
	a[3] = a4;
	a[4] = a5;
	cout << "Before sort:";
	print(a);
	sort(a);
	cout << "\nAfter sort:";
	print(a);
	cout << endl;
	system("pause");
	return 0;
}