#include <iostream>
#include<math.h>
#include<ctime>
#include<string>
#include<vector> 
#include<fstream>
using namespace std;
//void main() {
//	//int a = 0, i;
//	//for (i = 0;i < 3;++i) {
//	//	a += i;
//	//	cout << "a=" << a << endl;
//	//}
//	//for (i = 0;i < 3;i++) {
// //       a += i;
//	//	cout << "a=" << a << endl;
//	//}
//	int a[4] = { 0 };
//	////int b(5);
//	//cout << a << endl;
//	//cout << b << endl;
//	cout << a[5] << endl;

//}

//AAAAA
//int add(int a, int b) {
//	return a + b;
//}

//typedef struct Teacher {
//	string name;
//	char gender;
//	int age;
//}Teach;
//typedef struct Student {
//	string name;
//	int age;
//	char gender;
//}Stu;
//
//void fun1(Stu s) {
//	s.age = 25;
//}
//void fun2(Stu* s) {
//	s->age = 25;
//}
//void main() {
	//int a = 1;
	//int* p = &a;
	//cout << p << endl;
	//cout << *p << endl;

	//int a = 1;
	//int* p1 = &a;
	//int* p2 = NULL;
	//p2 = p1;
	//int** p3 = &p2;
	//cout << p2 << endl;
	//cout << &p2 << endl;
	//cout << p3 << endl;
	//cout << **p3 << endl;
	//cout << *p3 << endl;

	//int b[4] = { 0,1,2,3 };
	//int* p4 = b;
	//cout << b << endl;
	//cout << b[2] << endl;
	//cout << p4 << endl;
	//cout << *p4 << endl;
	//cout << *(b + 2) << endl;
	//cout << *(++p4) << endl;
	//cout << *(p4++) << endl;
	//cout << *(p4 - 2) << endl;

	//int c[][2] = { 1,2,3,4,5,6 };
	//int(*p6)[2] = c;

	//int* p5[3] = { c[0],c[1],c[2] };
	//int** p7 = p5;

	//AAAAA
	//int(*f)(int, int);
	//f = add;
	//cout << f(2, 3);
	//int a = rand() % 5;
	//a += 5;
	//cout << a << endl;
//
//	Teach t1;
//	t1.age = 25;
//	t1.gender = 'M';
//	t1.name = "yuan";
//	cout << t1.name << "   "<<t1.age <<"    "<< t1.gender << endl;
//
//	Teach* t2;
//
//	Stu s1 = { "Lily",18,'M' };
//
//	fun1(s1);
//	fun2(&s1);
//	cout << s1.age << endl;
//	cout << s1.age << endl;
//	Stu* p;
//	p = &s1;
//	cout << p->age  << endl;
//	cout << sizeof(p->age);
//	system("pause");

//
//
//
//}


//类
//class time {
//	public:
//		void Set(int , int , int );
//		void Show();
//	private:
//		int hour;
//		int minute;
//		int second;
//
//
//};
//void time::Set(int h, int m, int s) {
//	hour = h;
//	minute = m;
//	second = s;
//}
//void time::Show() {
//	cout<<"现在的时间为："<<
//	cout << hour << " :" << minute << " :" << second << endl;
//}
//class time t1;
//
//void main() {
//	t1.Set(3, 5, 29);
//	t1.Show();
//}



//int fun(int x[]) {
//
//	x[0] += 2;
//
//	return *x;
//
//}
//void main() {
//	int d = 1, e = 0;
//
//	e = fun(&d);
//	cout << d << endl << e;
//}

//int* fun(int x) {
//	x += 2;
//	int* p = &x;
//
//	return p;
//
//}
//void main() {
//	int d = 1, * f = NULL;
//
//	f = fun(d);
//	cout << d << endl << *f;
//}



//void main() {
//
//	//int a[3] = { 1, 2, 3 };
//	//int* b = a;
//	//int c = 0;
//	//c = (*b)++;
//
//	int a[3] = { 1, 2, 3 };
//	int* b = a;
//	int c = 0;
//	c = *(b++);
//	cout << a[0] << endl << a[1] << endl << a[2] << endl;
//	cout << *b << endl << c;
//}

//void main() {
//	time_t now = time(0);
//	cout << now;
//}

//void main() {
//	//int a = 10;
//	//int* p = &a;
//	//cout << a << endl;
//	//cout << p << endl;
//	//cout << *p;
//}
//void getSeconds(unsigned long* par);
//
//int main()
//{
//	unsigned long sec;
//
//
//	getSeconds(&sec);
//
//	// 输出实际值
//	cout << "Number of seconds :" << sec << endl;
//
//	return 0;
//}
//
//void getSeconds(unsigned long* par)
//{
//	// 获取当前的秒数
//	*par = time(NULL);
//	return;
//}
//double sqrt(double);

//void main() {
//	//std::cout << "NBA I am coming!" << std::endl;
//	//std::cout << "Star a new line \n";
//	//std::cout << "WZY just so so";
//	//char a ='A';
//	//std::cout << int(a);
//	int flag = 1;
//	int x;
//	x = rand() % 10 + 1;
//	cout << x;
//	int n;
//	cin >> n;
//
//	while (flag) {
//		if (n != x) {
//			cout << "fault";
//			cin >> n;
//		}
//
//		if (n == x) {
//			cout << "right";
//			break;
//		}
//
//	}
//	
//}
//struct student {
//	char name[10];
//	int id;
//	float score;
//};
//
//void main() {
//	//struct student stu1,stu2;
//	//stu1 = { "bob",1001,98.0 };
//	//stu2 = { "lily",1002,99.0 };
//	//struct student* p = new student;
//	//p = &stu1;
//	//cout << sizeof stu2;
//	//cout << p->id << endl;
//	char name[10];
//	cout << sizeof(name) << " " << sizeof(int) << " " << sizeof(float) << endl;
//	cout << sizeof student;
//}

//class person {
//public:
//	int eyes;
//	int hands;
//	friend void private1();
//private:
//	int ages=18;
//protected:
//	int password=10086;
//};
//void private1() {
//	cout << person.ages << endl;
//}
//void main() {
//	person p1;
//	p1.eyes = 2;
//	p1.hands = 2;
//	cout << p1.eyes << endl;
//	private1();
//}
//void main() {
		//char data[100];

		//// 以写模式打开文件
		//ofstream outfile;
		//outfile.open("TEXT.txt");

		//cout << "Writing to the file" << endl;
		//cout << "Enter your name: ";
		//cin.getline(data, 100);

		//// 向文件写入用户输入的数据
		//outfile << data << endl;

		//cout << "Enter your age: ";
		//cin >> data;
		//cin.ignore();

		//// 再次向文件写入用户输入的数据
		//outfile << data << endl;

		//// 关闭打开的文件
		//outfile.close();

		//// 以读模式打开文件
		//ifstream infile;
		//infile.open("TEXT.txt");

		//cout << "Reading from the file" << endl;
		//infile >> data;

		//// 在屏幕上写入数据
		//cout << data << endl;

		//// 再次从文件读取数据，并显示它
		//infile >> data;
		//cout << data << endl;

		//// 关闭打开的文件
		//infile.close();
	//ofstream fout;
	//fout.open("TEXT.txt");
	//fout << "哈哈哈";
	//fout.close();
//}





//class Animal {

//public:
//
//	virtual void shout() {
//
//		cout << "Shout ";
//
//	}
//
//};
//
//
//
//class Cat : public Animal {
//
//public:
//
//	void shout() {
//
//		cout << "Meow ";
//
//	}
//
//};
//
//
//
//class Dog : public Animal {
//
//public:
//
//	void shout() {
//
//		cout << "Woof ";
//
//	}
//
//};
//
//
//
//void test(Animal a) {
//
//	a.shout();
//
//}
//
//
//
//void main() {
//
//	Cat c;
//
//	Dog d;
//
//
//
//	test(c);
//
//	test(d);
//
//}

//float max() {
//	float a = 3.5;
//	cout << "a=" << a << endl;
//	return a;
//}
//void main() {
//	int  a = 2, * p = &a;
//	*p = 2;
//	cout << p << " " << *p;
//
//}


/*                                                       线性表运算
struct SqList {
	int data[50];
	int length;
};

void CreateList(SqList*& L, int a[], int n) {
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[i] = a[i];
		i++;
		k++;

	}
	L-> length = k;
}

void InitList(SqList*&L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

bool ListEmpty(SqList* L) {
	return(L->length == 0);
}

void DispList(SqList* L) {
	if (!ListEmpty)
		cout << "L is a empty List" << endl;
	else
	{
		for (int i = 0;i < L->length;i++)
			cout << L->data[i] << "  ";
	}
}

int ListLength(SqList* L) {
	return L->length;
}

void main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	SqList* L;
	InitList(L);
	CreateList(L, a, 10);
	cout << "L's length=" << ListLength(L) << endl;
	ListEmpty(L);
	DispList(L);

}
                                                                线性表运算
*/

//                                                              单链表运算
/*
struct LNode {
	int data;
	LNode* next;
};

//头插法创建单链表
void CreateListF(LNode*& L, int a[], int n) {
	LNode* s;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = 0;i < n;i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data;
		s->next = L->next;
		L->next = s;
	}

}

//尾插法创建单链表
void CreateListR(LNode*& L, int a[], int n) {
	LNode* s, * r;
	L = (LNode*)malloc(sizeof(LNode));
	r = L;
	for (int i = 0;i < n;i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;;
	}
	r->next = NULL;
}

void InitList(LNode*& L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
}

void DestroyList(LNode*& L) {
	LNode* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
}

bool ListEmpty(LNode* L) {
	return (L->next == NULL);
}

int ListLength(LNode* L) {
	int n = 0;
	LNode* p = L;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

void DispList(LNode* L) {
	LNode* p = L->next;
	while (p != NULL) {
		cout << p->data << "  ";
	}
	cout << endl;
}

bool ListDelete(LNode*& L, int i, int &e) {
	int j = 0;
	LNode* p = L, * q;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}

void main() {
	int a[] = { 1,2,3,4,5 };
	int length, e;
	LNode* L;
	InitList(L);
	CreateListF(L, a, 5);
	ListEmpty(L);
	length = ListLength(L);
	cout << "ListLength=" << length << endl;
	DispList(L);
	ListDelete(L, 3, e);
	cout << "Has Deleted" << e << endl;
	DispList(L);
	DestroyList(L);
}
                                                               单链表运算
*/
//
//class animal {
//friend void dis(animal a);
//private:
//	int id=1;
//};
//void dis(animal a) {
//	cout << a.id;
//}
//class cat :public animal {
//public:
//
//};
//void main() {
//	animal a;
//	dis(a);
//	
//}

int* fun() {
	int x = 1;
	return &x;
}
void main() {
	int* p = fun();
	cout << *p;
}