#include <stdio.h>  //调用所需的库
#include <stdlib.h>
#include <wchar.h>//宽字符调用函数库
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#define N 10  //初始化数据的个数
int B = 9;  //定义全局变量
int* p = &B;  //将变量存在指针变量中
int C = 9;
int* q = &C;
int D = 9;
int* r = &D;
void inputlesson(struct Table_3 stu_lesson[], int n);  //函数声明
void paixu1(struct Table_1 stu[], int length);
void paixu2(struct Table_2 leeson[], int length);
void paixu3(struct Table_3 stu_leeson[], int length);
int menu();
int menu1();
int menu2();
void PrintTable1(int n);
void PrintTable2(int n);
void PrintTable3(int n);
void delTable1(int stu_id1);
void delTable3(int stu_id2);
int plusM(int* p);
int subM(int* p);
void wcharTochar(const wchar_t* wchar, char* chr, int length);
void SaveToFile(char* fname, struct Table_1 stu[], struct Table_2 lesson[], struct Table_3 stu_lesson[], int m);
void WriteToFile(char* fname, struct Table_1 stu[], struct Table_2 lesson[], struct Table_3 stu_lesson[]);
struct Table_1
{
	int stu_id;
	char stu_name[30];
	char sex;
	int age;
	char yuan_xi[30];
}stu[1000];  //定义结构体
struct Table_2
{
	int lesson_id;
	char lesson_name[30];
	char first_les_name[30];
	int credict;
}lesson[50];
struct Table_3
{
	int stu_id;
	int lesson[N];
	int score[N];
}stu_lesson[10000];
int main()
{
	int i, a, b, c, d, j, k, x, y, z, choice2, choice3, choice4;  //定义初始变量
	int id;
	double time11, start, end;  //定义计算时间的变量
	char fname[32];
	char sex[2] = { 'M','F' };  //M为male；F为female
	char name2[20];
	wchar_t name[20];//用宽字符定义
	wchar_t xing[] = L"赵钱孙李周吴郑王冯陈蒋沈韩杨朱秦许何吕张黄陈";  //随机一些字
	wchar_t ming[] = L"浩泽俊博名思志群涵海雨玉杰震强路轩瑞嘉欣婷峰彦敏逸梓涛程龙华辉然文静豪家清楠";
	char name3[20];
	wchar_t firstname[] = L"离散线代高数大学物理语文化学历史地理政治数学英语生物";
	wchar_t lastname[] = L"浩泽俊博名思志群涵海雨玉杰震强路轩瑞嘉欣婷峰彦敏逸梓涛程龙华辉然文静豪家清楠";
	char name4[20];
	wchar_t yuanxi1[] = L"国商理工智能人工文金融务包装科学工程技术辉然文静豪家清楠";
	wchar_t yuanxi2[] = L"国商理工智能人工文金融务包装科学工程技术辉然文静豪家清楠";
	srand((unsigned)time(NULL));  ////随机数发生器的初始化函数
	for (i = 0;i < N;i++)  //生成N个学生数据
	{
		a = rand() % 2;  //使用rand（） % （b - a + 1）+ a生成[0,1]的随机数
		b = rand() % 6 + 17;  //使用rand（） % （b - a + 1）+ a生成[17,22]的随机数
		stu[i].stu_id = i + 1;
		stu[i].sex = sex[a];  //随机选取sex列表的F或M
		stu[i].age = b;  //将b（随机生成的年龄）存入stu[i].age

		c = rand() % 20;
		name[0] = xing[c];//随机产生常用姓氏
		for (j = 1;j < 3;j++)//随机产生常用名字
		{
			d = rand() % 35;
			name[j] = ming[d];
		}
		name[j] = '\0';
		wcharTochar(name, name2, sizeof(name2));
		setlocale(LC_ALL, "chs");//设置为中文输出
		strcpy_s(stu[i].stu_name, name2);
		for (k = 0;k < 2;k++)
		{
			y = rand() % 18;
			name[k] = yuanxi1[y];
		}
		for (j = 2;j < 4;j++)//随机产生常用名字
		{
			z = rand() % 18;
			name[j] = yuanxi2[z];
		}
		name[j] = '\0';
		wcharTochar(name, name4, sizeof(name4));
		setlocale(LC_ALL, "chs");//设置为中文输出
		strcpy_s(stu[i].yuan_xi, name4);
	}
	PrintTable1(B);  //调用打印函数，将表一数据打印出来
	for (i = 0;i < N;i++)  //生成50个学生数据
	{
		lesson[i].lesson_id = i + 1001;
		b = rand() % 3 + 2;  //使用rand（） % （b - a + 1）+ a生成[2,4]的随机数
		lesson[i].credict = b;

		for (k = 0;k < 2;k++)
		{
			c = rand() % 18;
			name[k] = firstname[c];
		}
		for (j = 2;j < 4;j++)//随机产生常用名字
		{
			d = rand() % 18;
			name[j] = lastname[d];
		}
		name[j] = '\0';
		wcharTochar(name, name3, sizeof(name3));
		setlocale(LC_ALL, "chs");//设置为中文输出
		strcpy_s(lesson[i].lesson_name, name3);
		c = rand() % 18;
		name[0] = firstname[c];
		for (j = 1;j < 3;j++)//随机产生常用名字
		{
			d = rand() % 18;
			name[j] = lastname[d];
		}
		name[j] = '\0';
		wcharTochar(name, name3, sizeof(name3));
		setlocale(LC_ALL, "chs");//设置为中文输出
		strcpy_s(lesson[i].first_les_name, name3);
	}
	PrintTable2(C);  //调用打印函数，将表二数据打印出来
	inputlesson(stu_lesson, N);  //调用函数，实现表三初始化
	PrintTable3(D);  //调用打印函数，将表三数据打印出来
	do
	{
	A:k = menu();  //调用函数，输出菜单，获取用户选择
		switch (k)  //当k非零时，利用switch-case来完成用户所需
		{
		case 0:break;  //如果k为0则结束
		case 1:  //如果用户选择为1
			start = clock();	//开始计时
			do {
				x = menu1();
				switch (x)
				{
				case 0:goto W;  //利用goto语句完成计时
				case 1:
					plusM(p);  //用户增加数据，调用函数，利用地址传递，改变p值
					printf("请输入以下信息：\n");  //打印提示信息
					printf("学号：");
					scanf_s("%d", &stu[B].stu_id);  //将用户所输数据存入
					rewind(stdin);  //清除缓存，将\n清除，防止影响后面的输入
					printf("性别(F or M)：");
					scanf_s("%c", &stu[B].sex);
					rewind(stdin);
					printf("年龄：");
					scanf_s("%d", &stu[B].age);
					rewind(stdin);
					printf("姓名：");
					gets_s(stu[B].stu_name);
					printf("院系：");
					gets_s(stu[B].yuan_xi);
					paixu1(stu, B + 1);
					printf("表一数据添加成功！\n");  //打印提示信息
					break;
				case 2:
					plusM(q);  //用户增加数据，调用函数，利用地址传递，改变q值
					printf("请输入以下信息：\n");  //打印提示信息
					printf("课程号：");
					scanf_s("%d", &lesson[C].lesson_id);   //将用户所输数据存入
					rewind(stdin);  //清除缓存，将\n清除，防止影响后面的输入
					printf("课程名：");
					gets_s(lesson[C].lesson_name);
					printf("先行课：");
					gets_s(lesson[C].first_les_name);
					rewind(stdin);
					printf("学分：");
					scanf_s("%d", &lesson[C].credict);
					paixu2(lesson, C + 1);
					printf("表二数据添加成功！\n");
					break;
				case 3:
					plusM(r);  //用户增加数据，调用函数，利用地址传递，改变r值
					printf("请输入以下信息：\n");  //打印提示信息
					printf("学号：");
					scanf_s("%d", &stu_lesson[D].stu_id);  //将用户所输数据存入
					rewind(stdin);  //清除缓存，将\n清除，防止影响后面的输入
					printf("课程号：");
					scanf_s("%d", &stu_lesson[D].lesson);
					rewind(stdin);
					printf("成绩：");
					scanf_s("%d", &stu_lesson[D].score);
					rewind(stdin);
					paixu3(stu_lesson, D + 1);
					printf("表三数据添加成功！\n");
					break;
				case 4:
					system("cls");  //调用函数，清除屏幕
					break;
				case 5:
					PrintTable1(B);  //打印表一
					break;
				case 6:
					PrintTable2(C);  //打印表二
					break;
				case 7:
					PrintTable3(D);  //打印表三
					break;
				default:
					printf("没有这个选项！\n");  //处理非法输入
				}
			} while (x);
		W:end = clock();	//计时结束
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;  //计算时间
			printf("该操作运行所需的时间：%lfms\n", time11);  //输出用户执行增操作所用时间
			goto A;  //控制循环
		case 2:
			start = clock();	//开始计时
			do {
				choice2 = menu1();  //打印菜单1，存储用户选择
				switch (choice2)
				{
				case 0:goto Y;
				case 1:
					int stu_id1;
					printf("请输入所需删除的学生学号：\n");  //打印提示信息
					scanf_s("%d", &stu_id1);
					rewind(stdin);  //清除缓存
					for (i = 0;i <= B;i++)
					{
						if (stu_id1 == stu[i].stu_id)
						{
							delTable1(stu_id1);
							delTable3(stu_id1);
							goto AB;
						}
					}
					printf("没有该学号！可以退出删操作进行添加！\n");
					break;
				AB:printf("表一数据删除成功！\n");  //打印提示信息
					break;
				case 2:
					int lesson_id1;
					printf("请输入所需删除的课程号：\n");
					scanf_s("%d", &lesson_id1);
					rewind(stdin);
					for (i = 0; i <= C; i++)
					{
						if (lesson[i].lesson_id == lesson_id1)
						{
							for (;i <= C;i++)
							{
								lesson[i] = lesson[i + 1];
							}
							break;
						}
					}
					if (i == C + 1) { printf("没有该课程号！\n"); goto AD; }
					subM(q);
					printf("表二数据删除成功！\n");
				AD:break;
				case 3:
					int stu_id2;
					printf("请输入所需删除的学生学号：\n");
					scanf_s("%d", &stu_id2);
					rewind(stdin);
					for (i = 0;i <= B;i++)
					{
						if (stu_id2 == stu_lesson[i].stu_id)
						{
							delTable3(stu_id2);
							delTable1(stu_id2);
							goto AC;
						}
					}
					printf("没有该学号！可以退出删操作进行添加！\n");
					break;
				AC:printf("表一数据删除成功！\n");  //打印提示信息
					break;
				case 4:
					system("cls");
					break;
				case 5:
					PrintTable1(B);
					break;
				case 6:
					PrintTable2(C);
					break;
				case 7:
					PrintTable3(D);
					break;
				default:
					printf("没有这个选项！\n");
				}
			} while (choice2);
		Y:end = clock();	//计时结束
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;
			printf("该操作运行所需的时间：%lfms\n", time11);
			goto A;
		case 3:
			start = clock();	//开始计时
			do {
				choice3 = menu2();
				switch (choice3)
				{
				case 0:goto J;
				case 1:
					printf("请输入所需修改学生的学号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("学号为%d的学生新名字是：", id);
					gets_s(stu[id - 1].stu_name);
					printf("修改成功！\n");
					break;
				case 2:
					printf("请输入所需修改学生的学号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("学号为%d的学生新性别是（F or M）：", id);
					scanf_s("%c", &stu[id - 1].sex);
					printf("修改成功！\n");
					break;
				case 3:
					int id;
					printf("请输入所需修改学生的学号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("学号为%d的学生新年龄是：", id);
					scanf_s("%d", &stu[id - 1].age);
					rewind(stdin);
					printf("修改成功！\n");
					break;
				case 4:
					printf("请输入所需修改学生的学号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("学号为%d的学生新院系是：", id);
					gets_s(stu[id - 1].yuan_xi);
					rewind(stdin);
					printf("修改成功！\n");
					break;
				case 5:
					printf("请输入所需修改课程的课程号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("课程号为%d的新课程名是：", id);
					gets_s(lesson[id - 1].lesson_name);
					rewind(stdin);
					printf("修改成功！\n");
					break;
				case 6:
					printf("请输入所需修改课程的课程号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("课程号为%d的新先行课名是：", id);
					gets_s(lesson[id - 1].first_les_name);
					rewind(stdin);
					printf("修改成功！\n");
					break;
				case 7:
					printf("请输入所需修改课程的课程号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("课程号为%d的新学分是：", id);
					scanf_s("%d", &lesson[id - 1].credict);
					rewind(stdin);
					printf("修改成功！\n");
					break;
				case 8:
					int id1, id2;
					printf("请输入所需修改学生的学号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("请输入原课程号：");
					scanf_s("%d", &id1);
					rewind(stdin);
					printf("请输入新课程号：");
					scanf_s("%d", &id2);
					rewind(stdin);
					for (j = 0;j < 6;j++)
					{
						if (stu_lesson[id - 1].lesson[j] == id1)
						{
							stu_lesson[id - 1].lesson[j] = id2;
							break;
						}
					}
					printf("修改成功！\n");
					break;
				case 9:
					printf("请输入所需修改学生的学号：");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("请输入原课程号：");
					scanf_s("%d", &id1);
					rewind(stdin);
					printf("请输入新成绩：");
					scanf_s("%d", &id2);
					rewind(stdin);
					for (j = 0;j < 6;j++)
					{
						if (stu_lesson[id - 1].lesson[j] == id1)
						{
							stu_lesson[id - 1].score[j] = id2;
							break;
						}
					}
					printf("修改成功！\n");
					break;
				case 10:
					system("cls");
					break;
				case 11:
					PrintTable1(B);
					break;
				case 12:
					PrintTable2(C);
					break;
				case 13:
					PrintTable3(D);
					break;
				default:
					printf("没有这个选项！\n");
				}
			} while (choice3);
		J:end = clock();	//计时结束
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;
			printf("该操作运行所需的时间：%lfms\n", time11);
			goto A;
		case 4:
			start = clock();	//开始计时
			int searchid;
			printf("请输入所需查询学生的学号：");
			scanf_s("%d", &searchid);
			rewind(stdin);
			for (i = 0;i <= B;i++)
			{
				if (stu[i].stu_id == searchid)
				{
					printf("**************************************************************\n");
					printf("学号         性别           年龄          姓名        院系\n");
					printf("**************************************************************\n");
					printf("%2d%13c%16d%16s%14s\n", stu[i].stu_id, stu[i].sex, stu[i].age, stu[i].stu_name, stu[i].yuan_xi);
					printf("************************************\n");
					printf("学号         课程号           成绩     \n");
					printf("************************************\n");
					for (j = 0;j < 6;j++)
					{
						if (stu_lesson[i].lesson[j] != 0)
							printf("%2d%16d%15d\n", stu_lesson[i].stu_id, stu_lesson[i].lesson[j], stu_lesson[i].score[j]);
						else
							continue;
					}
					break;
				}
			}
			if (i == B + 1)
				printf("查无此人！\n");
			else
				printf("查询完毕！\n");
			printf("请输入想要查询的学生的年龄闭区间：\n");
			int firstage, lastage;
			printf("起始年龄：");
			scanf_s("%d", &firstage);
			rewind(stdin);
			printf("终止年龄：");
			scanf_s("%d", &lastage);
			rewind(stdin);
			printf("年龄在%d至%d之间的学生如下：\n", firstage, lastage);
			printf("**************************************************************\n");
			printf("学号         性别           年龄          姓名        院系\n");
			printf("**************************************************************\n");
			for (i = 0;i <= B;i++)
			{
				if (stu[i].age <= lastage && stu[i].age >= firstage)
				{
					printf("%2d%13c%16d%16s%14s\n", stu[i].stu_id, stu[i].sex, stu[i].age, stu[i].stu_name, stu[i].yuan_xi);
				}
				else continue;
			}
			end = clock();	//计时结束
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;
			printf("该操作运行所需的时间：%lfms\n", time11);
			goto A;
		case 5:
			printf("保存的文本文件名：");  //打印提示信息
			scanf_s("%s", &fname, 50);  //将用户所输入的文本名字存入
			SaveToFile(fname, stu, lesson, stu_lesson, 6);   //调用函数生成文件
			printf("保存成功！\n");
			break;
		case 6:
			printf("保存的二进制文件名：");  //打印提示信息
			scanf_s("%s", &fname, 50);  //将用户所输入的二进制文件名字存入
			WriteToFile(fname, stu, lesson, stu_lesson);
			printf("保存成功！\n");  //打印提示信息
			break;
		case 7:
			system("cls");  //清除屏幕
			break;
		default:
			printf("没有这个选项！\n");  //处理非法输入
		}
	} while (k);
	return 0;
}
void inputlesson(struct Table_3 stu_lesson[], int n)  //表三数据初始化
{
	srand((unsigned)time(NULL));  ////随机数发生器的初始化函数
	int i, j, a;
	for (i = 0;i < n;i++)
	{
		stu_lesson[i].stu_id = i + 1;
		int ii = 0;
		for (j = 0;j < 6;j++)
		{
			a = rand() % 101;  //使用rand（） % （b - a + 1）+ a生成[0,100]的随机数
			stu_lesson[i].lesson[j] = 1001 + ii;
			stu_lesson[i].score[j] = a;
			ii += 1;
		}
	}
}
int menu()  //主菜单
{
	int n;
	printf("************\n");
	printf("MENU\n");
	printf("************\n");
	printf("1:增\n");
	printf("2:删\n");
	printf("3:改\n");
	printf("4:查\n");
	printf("5:将数据以文本文件存入硬盘\n");
	printf("6:将数据以二进制文件存入硬盘\n");
	printf("7:清屏\n");
	printf("0:退出\n");
	printf("************\n");
	printf("请扣对应数字：");
	scanf_s("%d", &n);
	rewind(stdin);
	return n;
}
int menu1()  //菜单1
{
	int n = 0;
	printf("**************\n");
	printf("操作MENU\n");
	printf("**************\n");
	printf("1:对表一操作\n");
	printf("2:对表二操作\n");
	printf("3:对表三操作\n");
	printf("4:清屏\n");
	printf("5:显示Table1\n");
	printf("6:显示Table2\n");
	printf("7:显示Table3\n");
	printf("0:退出操作\n");
	printf("************\n");
	printf("请扣对应数字：");
	scanf_s("%d", &n);
	rewind(stdin);
	return n;
}
int menu2()  //菜单2
{
	int n = 0;
	printf("**************\n");
	printf("改操作MENU\n");
	printf("**************\n");
	printf("1:修改表一姓名\n");
	printf("2:修改表一性别\n");
	printf("3:修改表一年龄\n");
	printf("4:修改表一院系\n");
	printf("5:修改表二课程名\n");
	printf("6:修改表二先行课\n");
	printf("7:修改表二学分\n");
	printf("8:修改表三课程号\n");
	printf("9:修改表三成绩\n");
	printf("10:清屏\n");
	printf("11:显示Table1\n");
	printf("12:显示Table2\n");
	printf("13:显示Table3\n");
	printf("0:退出改操作\n");
	printf("************\n");
	printf("请扣对应数字：");
	scanf_s("%d", &n);
	rewind(stdin);
	return n;
}
void PrintTable1(int n)  //设计合理的输出展示表一
{
	int i;
	n = B;
	printf("**************************************************************\n");
	printf("学号         性别           年龄          姓名        院系\n");
	printf("**************************************************************\n");
	for (i = 0;i <= B;i++)
	{
		printf("%2d%13c%16d%16s%14s\n", stu[i].stu_id, stu[i].sex, stu[i].age, stu[i].stu_name, stu[i].yuan_xi);
	}
}
void PrintTable2(int n)  //设计合理的输出展示表二
{
	int i;
	n = C;
	printf("******************************************************\n");
	printf("课程号         课程名           先行课          学分      \n");
	printf("******************************************************\n");
	for (i = 0;i <= C;i++)
	{
		printf("%4d%18s%16s%13d\n", lesson[i].lesson_id, lesson[i].lesson_name, lesson[i].first_les_name, lesson[i].credict);
	}
}
void PrintTable3(int n)  //设计合理的输出展示表三
{
	int i, j;
	n = D;
	printf("************************************\n");
	printf("学号         课程号           成绩     \n");
	printf("************************************\n");
	for (i = 0;i <= D;i++)
		for (j = 0;j < 6;j++)
		{
			if (stu_lesson[i].lesson[j] != 0)
				printf("%2d%16d%15d\n", stu_lesson[i].stu_id, stu_lesson[i].lesson[j], stu_lesson[i].score[j]);
			else
				continue;
		}
}
void wcharTochar(const wchar_t* wchar, char* chr, int length)
{
	WideCharToMultiByte(CP_ACP, 0, wchar, -1, chr, length, NULL, NULL);
}
int plusM(int* p)  //将*p的值加一
{
	*p = *p + 1;
	return *p;
}
int subM(int* p)  //将*p的值减一
{
	*p = *p - 1;
	return *p;
}
void paixu1(struct Table_1 stu[], int length)  //对表一进行排序（从小到大）
{
	struct Table_1 tmp1;
	int i, j;
	for (i = 0; i < length; i++) {
		for (j = 1; j < length - i; j++)
		{
			if (stu[j].stu_id < stu[j - 1].stu_id)
			{
				tmp1 = stu[j];
				stu[j] = stu[j - 1];
				stu[j - 1] = tmp1;
			}
		}
	}
}
void paixu2(struct Table_2 leeson[], int length)  //对表二进行排序（从小到大）
{
	struct Table_2 tmp2;
	int i, j;
	for (i = 0; i < length; i++) {
		for (j = 1; j < length - i; j++)
		{
			if (leeson[j].lesson_id < leeson[j - 1].lesson_id)
			{
				tmp2 = leeson[j];
				leeson[j] = leeson[j - 1];
				leeson[j - 1] = tmp2;
			}
		}
	}
}
void paixu3(struct Table_3 stu_leeson[], int length)  //对表三进行排序（从小到大）
{
	struct Table_3 tmp3;
	int i, j;
	for (i = 0; i < length; i++) {
		for (j = 1; j < length - i; j++)
		{
			if (stu_lesson[j].stu_id < stu_lesson[j - 1].stu_id)
			{
				tmp3 = stu_lesson[j];
				stu_lesson[j] = stu_lesson[j - 1];
				stu_lesson[j - 1] = tmp3;
			}
		}
	}
}
void delTable1(int stu_id1)  //删除表一数据
{
	int i;
	for (i = 0; i <= B; i++)
	{
		if (stu[i].stu_id == stu_id1)
		{
			for (;i <= B;i++)
			{
				stu[i] = stu[i + 1];  //用后一项覆盖前一项，起到删除的效果
			}
			break;
		}
	}
	subM(p);
}
void delTable3(int stu_id2)  //删除表三数据
{
	int i;
	for (i = 0; i <= D; i++)
	{
		if (stu_lesson[i].stu_id == stu_id2)
		{
			for (;i <= D;i++)
			{
				stu_lesson[i] = stu_lesson[i + 1];  //用后一项覆盖前一项，起到删除的效果
			}
			break;
		}
	}
	subM(r);
}
void SaveToFile(char* fname, struct Table_1 stu[], struct Table_2 lesson[], struct Table_3 stu_lesson[], int m)  //将数据存为文本文件
{
	FILE* fp;
	int i, j;
	if ((fp = fopen(fname, "w")) == NULL)
	{
		printf("Failure to open\n");
		exit(0);
	}
	fp = fopen(fname, "a");
	for (i = 0;i <= B;i++)
	{
		fprintf(fp, "%2d%13c%16d%16s%14s\n", stu[i].stu_id, stu[i].sex, stu[i].age, stu[i].stu_name, stu[i].yuan_xi);
	}
	for (i = 0;i <= C;i++)
	{
		fprintf(fp, "%4d%18s%16s%13d\n", lesson[i].lesson_id, lesson[i].lesson_name, lesson[i].first_les_name, lesson[i].credict);
	}
	for (i = 0;i <= D;i++)
	{
		fprintf(fp, "%2d", stu_lesson[i].stu_id);
		for (j = 0;j < m;j++)
		{
			if (stu_lesson[i].lesson[j] != 0)
				fprintf(fp, "%16d%15d\n", stu_lesson[i].lesson[j], stu_lesson[i].score[j]);
			else
				continue;
		}
	}
	fclose(fp);
}
void WriteToFile(char* fname, struct Table_1 stu[], struct Table_2 lesson[], struct Table_3 stu_lesson[])  //将数据存为二进制文件
{
	FILE* fp;
	if ((fp = fopen(fname, "wb")) == NULL)
	{
		printf("Failure to open\n");
		exit(0);
	}
	fp = fopen(fname, "a");
	fwrite(stu, sizeof(struct Table_1), B, fp);
	fwrite(lesson, sizeof(struct Table_2), C, fp);
	fwrite(stu_lesson, sizeof(struct Table_3), D, fp);
	fclose(fp);
}