#include<iostream>
#include<string>
using namespace std;
//��һ��
//char* copy(char* p, char a[])//����ǰ��*
//{
//	p = a;//��ַ��ͬ
//	return p;//����p
//}
//int main()
//{
//	char a[5];
//	cout << "����5���ַ���ɵ��ַ�����";
//	for (int i = 0; i < 5; i++)
//	{
//		cin >> a[i];
//	}
//	cout << "�ַ���a[5]:";
//	for (int i = 0; i < 5; i++)
//	{
//		cout << a[i] << " ";
//	}
//	char* p = NULL;
//	p = copy(p, a);
//	cout << "\nͨ��ָ�뿽���������";
//	for (int i = 0; i < 5; i++)
//	{
//		cout << p[i] << " ";
//	}
//	system("pause");
//	return 0;
//}
//�ڶ���
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
//������
void sort(char* a[])
{
	int i, j;
	char* temp;
	for (i = 0; i < 4; i++)//ע����i<4,�ܹ�������ַ���������Ҫ+1
	{
		for (j = 0; j < 4; j++)//ע����j<4,�ܹ�������ַ���������Ҫ+1�ͺ�����Ǹ��ַ����Ƚ�
		{
			if (strcmp(a[j], a[j + 1]) > 0)//�ַ����Ƚ�:>0��ʾǰ����ַ����Ⱥ���Ĵ��򽻻�
			{//�����ַ���������������ַ���ȣ��� ASCII ֵ��С��Ƚϣ���ֱ�����ֲ�ͬ���ַ����� \0 Ϊֹ
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
	char* a[5];//�ַ�ָ������
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