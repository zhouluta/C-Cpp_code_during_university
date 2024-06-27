#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//int main() {
//	srand((int)time(0));
//	int x = 0, y = 0;
//	for (;x <= 2;x++)
//	{
//		for (;y < 5;y++)
//		{
//			cout << rand() % 10 << endl;
//		}
//	}
//	return 0;
//
//}


//第四题
//void main() {
//
//	int n, temp;
//	cin >> n;
//	cout << "input n:" << endl;
//	for (int k=1;k <= n / 2;k++) {
//		if (2 * n % k == 0)
//		{
//			temp = 2 * n / k - k + 1;
//			if (temp % 2 == 0 && temp / 2 != 0)
//			{
//				int i = temp / 2;
//				for (int j = 0;j < k - 1;j++)
//					cout << i + j << "+";
//				cout << i + k - 1 << endl;
//			}
//		}
//	}
//}
//void func(int n)
//{
//    for (int i = 1;i <= n / 2 + 1;i++)
//    {
//        int m = 0, k = 0;
//        int sum = 0;
//        for (int j = i;j <= n / 2 + 1;j++)
//        {
//            sum += j;
//            if (sum == n)
//            {
//                m = j;
//                k = i;
//                break;
//            }
//            if (sum > n) break;
//        }
//        if (m > 0)
//        {
//            for (int i = k;i < m;i++)
//                cout << i << "+";
//            cout << m << "=" << n << endl;
//
//        }
//    }
//}
//void main() {
//    func(100);
//    system("pause");
//}

//第三题
int fun(int n) {

	if (n > 0 && n <= 2)
		return 1;
	if (n < 0)
		return 0;
	if (n > 2)
	{
		return fun(n-1)+fun(n-2);
	}
}
void main() {
	int n;
	cout << "input n4:";
	cin >> n;
	cout << endl;
	
	cout << "fabonacci=" << fun(n);

}