#include<iostream>
#include<string.h>
using namespace std;

//��һ��
//void main()
//{
//    int nums[10] = { 1,2,3,5,7,9 }, n, i, flag = 0;
//    int* p = nums;
//    cout << "������һ������n:";
//    cin >> n;
//    for (i = 0;i < 6;i++)
//    {
//        if (p[i] == n)
//        {
//            flag = 1;
//            for (i = 0;i < 6;i++)
//                cout << " " << nums[i];
//            break;
//        }
//        else if (p[i] > n)
//        {
//            flag = 1;
//            for (int j = 6;j > i;j--)
//                p[j] = p[j - 1];
//            p[i] = n;
//            for (i = 0;i < 7;i++)
//                cout << " " << nums[i];
//            break;
//        }
//    }
//    if (flag == 0)
//    {
//        p[7] = n;
//
//        for (i = 0;i < 7;i++)
//            cout << " " << nums[i];
//    }
//}


//�ڶ���
//void main() {
//	char A[5] = { 'a','d','c','b','a' };
//	char* p1;
//	char* p2;
//	int flag;
//	int i = 0;
//	p1 = &A[i];
//	p2 = &A[4 - i];
//	while (i < (4 - i) && p1[i] == p2[4 - i])
//		i++;
//	if (i <= (4 - i))
//		cout << "���ַ������ǻ����ַ���" << endl;
//	else
//		cout << "���ַ����ǻ����ַ���" << endl;
//
//	system("pause");
//}

//������
//void main()
//{
//	char a[100];
//	int b[100], i, j, k, len, n;
//	gets_s(a);
//	len = strlen(a);
//	char* p1 = a;
//	int w = 0;
//
//
//	k = 0;n = 0;
//	for (i = j = 0;i <= len;i++)   //ע��i<=len����Ȼ���һ�������ͻᱻ©��
//		if (p1[i] >= '0' && p1[i] <= '9')
//			k = k * 10 + (p1[i] - '0');
//		else if (k == 0)
//			continue;
//		else
//		{
//			b[j] = k;
//			j++;
//			n++;
//			k = 0;
//		}
//	for (i = 0;i < n;i++)
//	{
//		cout<<b[i];
//		w += b[i];
//		if (i < (n - 1))
//			cout << "+";
//	}
//	cout << "=" << w;
//}

//������
int main()
{
    int str1[5] = { 1,4,5,8,12 };//���������ŷŵ�����
    int str2[5] = { 2,4,6,7,10 };
    int c[10];//���������������
    int i = 0, j = 0, k = 0;
    int* p1 = str1, * p2 = str2;
    while (i < 5 && j < 5)
    {
        if (str1[i] < str2[j]) //��str1��Ԫ��С��str2�ж�Ӧλ�õ�Ԫ�أ���str1�н�С��������c
        {
            c[k] = p1[i];
            i++;
            k++;
        }
        else //��str1��Ԫ�ش���str2��Ԫ�أ�jλ�ü�һ
        {
            c[k] = p2[j];
            j++;
            k++;
        }
    }

    if (i == 5)//i����5ʱ������str1��Ԫ��ȫ����Ž�c
        while (j < 5)
        {
            c[k] = p2[j];//���ڽ�str2��Ԫ�طŵ�c��
            k++;
            j++;
        }
    if (j == 5)//j����5ʱ������str2��Ԫ��ȫ����Ž�c�����ڰ�str1ʣ��Ԫ�طŽ�c
        while (i < 5)
        {
            c[k] = p1[i];
            k++;
            i++;
        }
    for (i = 0;i < 10;i++)
    {
        cout << c[i];
    }
    return;
}

