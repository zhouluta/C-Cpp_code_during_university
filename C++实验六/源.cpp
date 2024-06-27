#include<iostream>
#include<wchar.h>//宽字符调用函数库
#include<locale.h>//  设置本地语言
#include<string.h>
using namespace std;
#define LEN1 sizeof(struct Student)
#define LEN2 sizeof(struct Course)
struct Student //记录学生信息表一
{
	int ID;//学号
	char* Name;//姓名
	char* Course_name[10] = { NULL };//所选课程名称
	int C_ID[10];
	struct Student* next;
};
struct Course
{
	int C_ID;//课程号
	char* Course_name;//课程名称
	int Course_stu = 0;
	struct Course* next;
};
void Dispaly_course(struct Course* p) {
	struct Course* p1;
	p1 = p;
	if (p1->next != NULL)
	{
		cout << p1->Course_name << endl
			<< "选择该课程的学生有" << p1->Course_stu << "人"
			<< endl;
	}
}
void Dispaly_student(struct Student* p) {
	struct Student* p1;
	p1 = p;
	if (p1 != NULL)
	{
		cout << "学生的学号为:" << p1->ID << "\t"
			<< "该学生姓名为：" << p1->Name << endl;

		if (p1->Course_name[0] == NULL) {
			cout << "该学生还没有选择任何课程";
		}
		else
			cout << "已选择课程有：";
		for (int i = 0; p1->Course_name[i] != NULL; i++) {
			cout << p1->C_ID[i] << "、" << p1->Course_name[i] << "\t";
		}
		cout << endl;
	}
}

void Course_selection(struct Course* cour, Student* stu) {
	struct Course* cour1;
	cour1 = cour;
	Student* stu1;
	stu1 = stu;

	int ID_stu, ID_cour;
	int flag = 1;
	int i;

	cout << "请输入要选课的学生的学号:" << endl;
	cin >> ID_stu;
	for (i = ID_stu - 1; i > 0; i--) {
		stu1 = stu1->next;
	}
	cout << "该学生的选课信息如下" << endl;
	Dispaly_student(stu1);

	cout << "你现在有以下课程可选:" << endl;
	while (cour1->next != NULL)
	{
		cout << cour1->C_ID << "、" << cour1->Course_name << "\t";
		cour1 = cour1->next;
	}
	cour1 = cour;

	cout << endl << "请输入要选择课程的ID:";
	cin >> ID_cour;

	for (int j = 1; j < ID_cour; j++)
		cour1 = cour1->next;
	i = 0;
	for (i = 0; stu1->C_ID[i] != 0; i++) {
		if (ID_cour == stu1->C_ID[i]) {
			cout << "该课程已经在学生的选课列表中了，请不要重复选择" << endl;
			flag = 0;
			break;
		}
		else
			flag = 1;
	}
	if (flag)
	{
		stu1->C_ID[i] = cour1->C_ID;
		stu1->Course_name[i] = cour1->Course_name;
		cout << "已成功选择" << cour1->Course_name << endl;
		Dispaly_student(stu1);
	}

}
void Course_delete(Student* stu) {
	Student* stu1;
	stu1 = stu;

	int ID_stu, ID_cour;
	int i;
	int flag;
	cout << "请输入学生学号：";
	cin >> ID_stu;
	for (i = ID_stu - 1; i > 0; i--) {
		stu1 = stu1->next;
	}
	cout << "该学生的选课信息如下" << endl;
	Dispaly_student(stu1);

	if (stu1->C_ID[0] != 0) {
		cout << "请输入要删除的课程的ID：";
		cin >> ID_cour;
		for (i = 0; stu1->C_ID[i] != 0; i++) {
			if (ID_cour == stu1->C_ID[i]) {
				cout << stu1->Course_name[i] << "已删除" << endl;
				if (i < 9) {
					for (int j = i; j < 9; j++) {
						stu1->Course_name[j] = stu1->Course_name[j + 1];
						stu1->C_ID[j] = stu1->C_ID[j + 1];
					}
				}
				else
				{
					stu1->Course_name[i] = NULL;
					stu1->C_ID[i] = 0;
				}
				break;
			}
			if (stu1->C_ID[i + 1] == 0) {
				cout << "该学生没有选择该课程";
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "chs"); //设置为中文输出
	char* course[7] = { "高数", "线代", "大物", "大英", "离散","近代史","马原" };
	char* stu_name[5] = { "zlt","wzy","zyq","zq","zrx" };
	struct Course* c1, * c2;
	struct Student* stu1, * stu2;
	int flag = 1;

	stu1 = (struct Student*)malloc(LEN1);
	c1 = (struct Course*)malloc(LEN2);

	c2 = c1;
	stu2 = stu1;

	for (int i = 0; i < 7; i++) {
		c2->Course_name = course[i];
		c2->Course_stu = 0;
		c2->C_ID = i;
		c2->C_ID++;
		c2->next = (struct Course*)malloc(LEN2);
		c2 = c2->next;
	}

	for (int i = 0, j = 1; i < 5; i++) {
		stu2->Name = stu_name[i];
		stu2->ID = j++;

		for (int i = 0; i < 10; i++) {
			stu2->Course_name[i] = NULL;
			stu2->C_ID[i] = 0;
		}
		stu2->next = (struct Student*)malloc(LEN1);
		stu2 = stu2->next;
	}
	stu2->next = NULL;
	c2->next = NULL;

	stu2 = stu1;
	stu2->Course_name[0] = c1->Course_name;
	stu2->C_ID[0] = c1->C_ID;
	c2 = c1;
	while (c2->next != NULL)
	{
		Dispaly_course(c2);
		c2 = c2->next;
	}
	while (stu2->next != NULL)
	{
		Dispaly_student(stu2);
		stu2 = stu2->next;
	}
	cout << "——————欢迎来到学生选课系统——————" << endl;
	while (flag)
	{
		cout << "请选择你要使用的功能：1、选课\t2、退课\t3、退出系统" << endl;
		cin >> flag;
		switch (flag)
		{
		case 1: {
			Course_selection(c1, stu1);
			break;
		}

		case 2: {
			Course_delete(stu1);
			break;
		}
		case 3: {
			cout << "已退出系统";
			flag = 0;
			break;
		}
		default:cout << "输入有误，请重新输入";
			break;
		}
	}

	return 0;
}
