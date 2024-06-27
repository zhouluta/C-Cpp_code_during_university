#include<stdio.h>//头文件声明
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define Macro1 sizeof(struct Student)//宏定义
#define Macro2 sizeof(struct Course)
#define Macro3 sizeof(struct Score)


void Del_Student(struct Student* head, int Del_id);//功能为删除学生信息的函数
void Del_Course(struct Course* head, int Del_id);//功能为删除课程信息的函数
void Del_Score1(struct Score* head, int Del_id);//功能为删除成绩信息的函数
void Del_Score2(struct Score* head, int Del_id);//功能为删除成绩信息的函数



struct Student//结构体1学生信息
{
	int studentID;
	char name1[5];
	char sex;
	int age;
	char college[5];
	struct Student* next;
};
struct Course//结构体2课程信息
{
	int lessonID;
	char name2[5];
	char first_class[5];
	int credits;
	struct Course* next;
};
struct Score//结构体3学生-课程混合信息
{
	int studentID;
	int lessonID;
	int score;
	struct Score* next;
};
struct Student* Func1(void);//读取信息函数
struct Course* Func2(void);
struct Score* Func3(void);



void add()//功能为添加信息的函数
{
	int n, i, size;
	printf("请输入选择要添加数据的序号:\n");
	printf("1.学生信息\n");
	printf("2.课程信息\n");
	printf("3.学生-课程成绩信息\n");
	printf("您的选择是:");
	scanf("%d", &n);
	while (n < 1 || n>3)
	{
		printf("输入有误,请重新输入:");
		scanf("%d", &n);
		fflush(stdin);
	}
	printf("\n");
	switch (n)//使用switch来选择不同的用户使用情况
	{
	case 1://添加学生信息
	{
		struct Student* head, * p1, * p2;
		struct Student* stu;
		printf("请按照学号、姓名、性别、年龄、学院输入学生信息:\n");
		stu = (struct Student*) malloc(sizeof(Macro1));
		while (!scanf("%d   %s   %c   %d    %s", &stu->id1, stu->name1, stu->sex, &stu->age, stu->college))
		{
			printf("输入错误，请重新输入:\n");
			fflush(stdin);
		}
		p1 = p2 = head = Func1();
		while (stu->id1 > p2->id1 && p1->next != NULL)       //查找适合位置的前一个学生    
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == p1)           //插入的学生正好为链表头的情况    
		{
			if (stu->id1 < p2->id1)            //插入在表头前    
			{
				head = stu;
				stu->next = p2;
			}
			else                            //插入在表头后    
			{
				p2->next = stu;
				stu->next = NULL;
			}
		}
		else                    //插入的学生在链表中的情况    
		{
			if (stu->id1 < p1->id1)            //插入到p1指向的学生前    
			{
				p2->next = stu;
				stu->next = p1;
			}
			else                            //插入到p1指向的学生后    
			{
				p1->next = stu;
				stu->next = NULL;
			}
		}
		break;
	}
	case 2://添加课程信息
	{
		struct Course* head, * p1, * p2;
		struct Course* cou;
		printf("请依次输入课程号、课程名、先行课、学分4个课程信息:\n");
		cou = (struct Course*) malloc(sizeof(Macro2));
		while (!scanf("%d   %s   %s   %d", &cou->lessonID, cou->name2, cou->first_class, &cou->credits))
		{
			printf("输入错误，请重新输入:\n");
			fflush(stdin);
		}
		fflush(stdin);
		p1 = p2 = head = Func2();
		while (cou->lessonID > p2->lessonID && p1->next != NULL)       //查找适合位置的前一门课程   
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == p1)           //插入的课程正好为链表头的情况    
		{
			if (cou->lessonID < p2->lessonID)            //插入在表头前    
			{
				head = cou;
				cou->next = p2;
			}
			else                            //插入在表头后    
			{
				p2->next = cou;
				cou->next = NULL;
			}
		}
		else                    //插入的课程在链表中的情况    
		{
			if (cou->lessonID < p1->lessonID)            //插入到p1指向的课程前    
			{
				p2->next = cou;
				cou->next = p1;
			}
			else                            //插入到p1指向的课程后    
			{
				p1->next = cou;
				cou->next = NULL;
			}
		}
		break;
	}
	case 3://添加学生-课程成绩信息
	{
		struct Score* head, * p1, * p2;
		struct Score* sco;
		printf("请依次输入学号、课程号、成绩4个信息:\n");
		sco = (struct Score*) malloc(sizeof(Macro3));
		while (!scanf("%d    %d   %d", &sco->studentID, &sco->id2, &sco->score))
		{
			printf("输入错误，请重新输入:\n");
			fflush(stdin);
		}
		fflush(stdin);
		p1 = p2 = head = Func3();
		while (sco->studentID > p2->studentID && p1->next != NULL)       //查找适合位置的前一个学生成绩  
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == p1)           //插入的成绩正好为链表头的情况    
		{
			if (sco->studentID < p2->studentID)            //插入在表头前    
			{
				head = sco;
				sco->next = p2;
			}
			else                            //插入在表头后    
			{
				p2->next = sco;
				sco->next = NULL;
			}
		}
		else                    //插入的成绩在链表中的情况    
		{
			if (sco->studentID < p1->studentID)            //插入到p1指向的成绩前    
			{
				p2->next = sco;
				sco->next = p1;
			}
			else                            //插入到p1指向的成绩后    
			{
				p1->next = sco;
				sco->next = NULL;
			}
		}
		break;
	}
	}
}
void del()//功能为删除信息的函数
{
	int n;
	printf("请输入对应要删除数据的序号:\n");
	printf("1.学生信息\n");
	printf("2.课程信息\n");
	printf("您的选择是\n:");
	scanf("%d", &n);
	while (n < 1 || n>2)
	{
		printf("输入有误,请重新输入:");
		scanf("%d", &n);
		fflush(stdin);
	}
	printf("\n");
	switch (n)
	{
	case 1://删除学生信息
	{
		int Del_id;
		struct Student* head1;
		struct Score* head2;
		head1 = Func1();
		head2 = Func3();
		printf("请输入需要删除的学生学号:");
		scanf_s("%d", &Del_id);
		fflush(stdin);
		Del_Student(head1, Del_id);//调用删除学生信息函数
		Del_Score1(head2, Del_id);//调用删除对应学生成绩信息的函数
		break;
	}
	case 2://删除课程信息
	{
		int Del_id;
		struct Course* head1;
		struct Score* head2;
		head1 = Func2();
		head2 = Func3();
		printf("请输入删除的课程号:");
		scanf_s("%d", &Del_id);
		fflush(stdin);
		Del_Course(head1, Del_id);//调用删除课程信息函数
		Del_Score2(head2, Del_id);//调用删除对应课程成绩信息的函数
		break;
	}
	}
}
void change()//功能为修改信息的函数
{
	int change_id, n;
	struct Student* p;
	p = Func1();
	printf("请输入学生学号:");
	scanf("%d", &change_id);
	fflush(stdin);
	while (change_id != p->id1 && p->next != NULL) //查找需要修改学生的位置
		p = p->next;
	if (change_id == p->id1)
	{
		printf("选择修改的内容:\n");
		printf("1、学生姓名\n");
		printf("2、学生年龄\n");
		printf("3、学生性别\n");
		printf("4、学生院系\n");
		printf("您的输入是： ");
		scanf("%d", &n);
		fflush(stdin);
		while (n < 1 || n>4)
		{
			printf("输入有误,请重新输入:");
			scanf("%d", &n);
			fflush(stdin);
		}
		printf("\n");
		switch (n)//修改信息的类型
		{
		case 1://修改学生姓名
			printf("请输入修改后的姓名：");
			scanf_s("%s", p->name1, 5);
			getchar();
			printf("已完成更改\n");
			break;
		case 2://修改学生年龄
			printf("请输入修改后的年龄：");
			scanf_s("%d", &p->age);
			getchar();
			printf("已完成更改\n");
			break;
		case 3://修改学生性别
			printf("请输入修改后的性别(F/M)：");
			scanf_s("%c", &p->sex);
			getchar();
			printf("已完成更改\n");
			break;
		case 4://修改学生院系
			printf("请输入修改后的院系：");
			scanf_s("%s", p->college, 5);
			getchar();
			printf("已完成更改\n");
			break;
		}
	}
	else printf("error\n");
}
void search()//功能为查看（搜索）信息的函数
{
	int n;
	printf("选择需要查询的信息类型:\n");
	printf("1、学生基本信息\n");
	printf("2、学生成绩信息\n");
	printf("您的输入是： ");
	scanf("%d", &n);
	fflush(stdin);
	while (n < 1 || n>2)
	{
		printf("error:");
		scanf("%d", &n);
		fflush(stdin);
	}
	printf("\n");
	switch (n)
	{
	case 1://查看学生基本信息
	{
		struct Student* p;
		int Search_id;
		p = Func1();
		printf("请输入需要查询基本信息的学生的学号:");
		scanf("%d", &Search_id);
		fflush(stdin);
		while (Search_id != p->id1 && p->next != NULL)
			p = p->next;
		if (Search_id == p->id1)
		{
			printf("查找学生的信息为：\n");
			printf("学号:%d   姓名:%s   年龄:%d   性别:%c   院系:%s\n", p->id1, p->name1, p->age, p->sex, p->college);
		}
		break;
	}
	case 2://查看学生成绩信息
	{
		int Search_id;
		struct Score* p;
		struct Course* pt;
		p = Func3();
		pt = Func2();
		printf("请输入需要查询课程成绩信息的学生的学号:");
		scanf("%d", &Search_id);
		fflush(stdin);
		while (Search_id != p->studentID && p->next != NULL)
			p = p->next;
		for (int i = 0; i < 6; i++)
		{
			if (Search_id == p->studentID && p->next != NULL)
			{
				while (p->lessonID != pt->lessonID)
					pt = pt->next;
				printf("课程：%s   成绩：%d  \n", pt->name2, p->score);
				pt = Func2();
				p = p->next;
			}
		}
		break;
	}
	}
}
struct Student* Func1() //功能为将学生信息文件转换成链表的函数
{
	FILE* f1;
	int n;
	if ((f1 = fopen("message1.txt", "r")) == NULL)
	{
		printf("文件错误!");
		exit(0);
	}
	struct Student* head;
	struct Student* p1, * p2;
	n = 0;
	p1 = p2 = (struct Student*)malloc(Macro1);//开辟一个新单元
	fscanf(f1, "%d   %s   %c   %d    %s", &p1->id1, p1->name1, &p1->sex, &p1->age, p1->college);//读入第一个学生的成绩
	head = NULL;
	while (!feof(f1))
	{
		n++;
		if (n == 1) {
			head = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct Student*)malloc(Macro1);//开辟动态存储区，把起始地址赋给p1
		fscanf(f1, "%d   %s   %c   %d    %s", &p1->id1, p1->name1, &p1->sex, &p1->age, p1->college);//读入其他学生的信息
	}
	p2->next = NULL;
	return(head);
}
struct Course* Func2() //功能为将课程信息文件转换成链表的函数
{
	int n;
	FILE* f2;
	if ((f2 = fopen("message2.txt", "r")) == NULL)
	{
		printf("文件错误!");
		exit(0);
	}
	struct Course* head;
	struct Course* p1, * p2;
	n = 0;
	p1 = p2 = (struct Course*)malloc(Macro2);//开辟一个新单元
	fscanf(f2, "%d   %s   %s   %d ", &p1->lessonID, p1->name2, p1->first_class, &p1->credits);//读入第一个课程信息
	head = NULL;
	while (!feof(f2))
	{
		n++;
		if (n == 1) {
			head = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct Course*)malloc(Macro2);//开辟动态存储区，把起始地址赋给p1
		fscanf(f2, "%d   %s   %s   %d ", &p1->lessonID, p1->name2, p1->first_class, &p1->credits);//读入其他课程信息
	}
	p2->next = NULL;
	return(head);
}
struct Score* Func3() //功能为将成绩信息文本文件转换成链表的函数
{
	int n;
	FILE* f3;
	if ((f3 = fopen("message3.txt", "r")) == NULL)
	{
		printf("文件错误!");
		exit(0);
	}
	struct Score* head;
	struct Score* p1, * p2;
	n = 0;
	p1 = p2 = (struct Score*)malloc(Macro3);//开辟一个新单元
	fscanf(f3, "%d    %d   %d", &p1->studentID, &p1->id2, &p1->score);
	head = NULL;
	while (!feof(f3))
	{
		n++;
		if (n == 1) {
			head = p1;
		}
		else {
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct Score*)malloc(Macro3);//开辟动态存储区，把起始地址赋给p1
		fscanf(f3, "%d    %d   %d", &p1->studentID, &p1->id2, &p1->score);//读入学生成绩
	}
	p2->next = NULL;
	return(head);
}
void Del_Student(struct Student* head, int Del_id) //功能为删除学生信息的函数
{
	struct Student* p1, * p2;
	p1 = p2 = head;
	while (Del_id != p1->id1 && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->id1 == Del_id)
	{
		if (Del_id == head->id1)
			head = head->next;
		else
			p2->next = p1->next;
		printf("已删除学号为%d的学生的信息\n", Del_id);
	}
	else
		printf("error");
}

void Del_Course(struct Course* head, int Del_id) {//定义删除课程信息的函数
	struct Course* p1, * p2;
	p1 = p2 = head;
	while (Del_id != p1->lessonID && p1->next != NULL)//查找删除课程号
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->lessonID == Del_id)
	{
		if (Del_id == head->lessonID)
			head = head->next;
		else
			p2->next = p1->next;
		printf("操作成功！\n", Del_id);
	}
	else
		printf("error");
}
void Del_Score1(struct Score* head, int Del_id) {//功能为输入学生学号然后删除对应学生成绩信息的函数
	struct Score* p1, * p2;
	p1 = p2 = head;
	while (Del_id != p1->studentID && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->studentID == Del_id) {
		while (head->studentID == Del_id)//删除第一个学生的成绩
			head = head->next;
		while (p1->studentID == Del_id) {
			p1 = p1->next;
			p2->next = p1->next;

		}
		printf("操作成功！\n", Del_id);
	}
}
void Del_Score2(struct Score* head, int Del_id) {//定义根据课程号删除学生成绩信息的函数
	struct Score* p1, * p2;
	p1 = p2 = head;
	while (Del_id != p1->id2 && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->id2 == Del_id) {
		while (head->id2 == Del_id)//删除第一个学生的成绩
			head = head->next;
		while (p1->id2 == Del_id) {
			p1 = p1->next;
			p2->next = p1->next;

		}
		printf("操作成功！\n", Del_id);
	}
}


int main()
{
	int n;
	float start, finish;//记录时间，以便得到函数使用的时间
	double time;

	printf("\n");
	printf("1.添加信息\n");
	printf("2.删除信息\n");
	printf("3.修改信息\n");
	printf("4.查询信息\n");
	printf("5.结束操作\n");
	printf("\n");
	printf("请输入序号完成操作:");             

	scanf("%d", &n);
	while ((n < 1 || n > 5))
	{
		printf("error:");
		scanf("%d", &n);
		fflush(stdin);
	}
	printf("\n");
	switch (n)
	{
	case 1://添加信息
	{
		start = clock();
		add();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n所用时间为%f s\n", time);//输出时间
		break;
	}
	case 2://删除信息
	{
		start = clock();
		del();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n所用时间为%f s\n", time);
		break;
	}
	case 3://修改信息
	{
		start = clock();
		change();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n所用时间为%f s\n", time);
		break;
	}
	case 4://查看信息
	{
		start = clock();
		search();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n所用时间为%f s\n", time);
		break;
	}
	case 5://结束操作
	{
		printf("Thanks for using!");
		break;
	}
	}
	return 0;
}