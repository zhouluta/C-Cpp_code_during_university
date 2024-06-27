#include<iostream>
#include<string.h>
using namespace std;

//第一题
//void main()
//{
//    int nums[10] = { 1,2,3,5,7,9 }, n, i, flag = 0;
//    int* p = nums;
//    cout << "请输入一个整数n:";
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


//第二题
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
//		cout << "该字符串不是回文字符串" << endl;
//	else
//		cout << "该字符串是回文字符串" << endl;
//
//	system("pause");
//}

//第三题
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
//	for (i = j = 0;i <= len;i++)   //注意i<=len，不然最后一个整数就会被漏掉
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

//第四题
int main()
{
    int str1[5] = { 1,4,5,8,12 };//两个升序排放的数组
    int str2[5] = { 2,4,6,7,10 };
    int c[10];//用来存放两个数组
    int i = 0, j = 0, k = 0;
    int* p1 = str1, * p2 = str2;
    while (i < 5 && j < 5)
    {
        if (str1[i] < str2[j]) //当str1中元素小于str2中对应位置的元素，将str1中较小的数放入c
        {
            c[k] = p1[i];
            i++;
            k++;
        }
        else //若str1中元素大于str2中元素，j位置加一
        {
            c[k] = p2[j];
            j++;
            k++;
        }
    }

    if (i == 5)//i等于5时，表明str1中元素全部存放进c
        while (j < 5)
        {
            c[k] = p2[j];//现在将str2中元素放到c中
            k++;
            j++;
        }
    if (j == 5)//j等于5时，表明str2中元素全部存放进c，现在把str1剩下元素放进c
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

