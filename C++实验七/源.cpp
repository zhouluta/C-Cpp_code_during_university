#include <iostream>
using namespace std;
typedef struct Student {
	string name;
	int num;
}stu;
typedef struct Course {
	string name;
}cou;
void main() {
	stu s1 = { "lily",20190001 };
	cou c1 = { "สýัง" };

	cout << s1.name << s1.num << endl;
	cout << c1.name << endl;
	system("pause");
}