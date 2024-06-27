#include<stdio.h>//ͷ�ļ�����
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define Macro1 sizeof(struct Student)//�궨��
#define Macro2 sizeof(struct Course)
#define Macro3 sizeof(struct Score)


void Del_Student(struct Student* head, int Del_id);//����Ϊɾ��ѧ����Ϣ�ĺ���
void Del_Course(struct Course* head, int Del_id);//����Ϊɾ���γ���Ϣ�ĺ���
void Del_Score1(struct Score* head, int Del_id);//����Ϊɾ���ɼ���Ϣ�ĺ���
void Del_Score2(struct Score* head, int Del_id);//����Ϊɾ���ɼ���Ϣ�ĺ���



struct Student//�ṹ��1ѧ����Ϣ
{
	int studentID;
	char name1[5];
	char sex;
	int age;
	char college[5];
	struct Student* next;
};
struct Course//�ṹ��2�γ���Ϣ
{
	int lessonID;
	char name2[5];
	char first_class[5];
	int credits;
	struct Course* next;
};
struct Score//�ṹ��3ѧ��-�γ̻����Ϣ
{
	int studentID;
	int lessonID;
	int score;
	struct Score* next;
};
struct Student* Func1(void);//��ȡ��Ϣ����
struct Course* Func2(void);
struct Score* Func3(void);



void add()//����Ϊ�����Ϣ�ĺ���
{
	int n, i, size;
	printf("������ѡ��Ҫ������ݵ����:\n");
	printf("1.ѧ����Ϣ\n");
	printf("2.�γ���Ϣ\n");
	printf("3.ѧ��-�γ̳ɼ���Ϣ\n");
	printf("����ѡ����:");
	scanf("%d", &n);
	while (n < 1 || n>3)
	{
		printf("��������,����������:");
		scanf("%d", &n);
		fflush(stdin);
	}
	printf("\n");
	switch (n)//ʹ��switch��ѡ��ͬ���û�ʹ�����
	{
	case 1://���ѧ����Ϣ
	{
		struct Student* head, * p1, * p2;
		struct Student* stu;
		printf("�밴��ѧ�š��������Ա����䡢ѧԺ����ѧ����Ϣ:\n");
		stu = (struct Student*) malloc(sizeof(Macro1));
		while (!scanf("%d   %s   %c   %d    %s", &stu->id1, stu->name1, stu->sex, &stu->age, stu->college))
		{
			printf("�����������������:\n");
			fflush(stdin);
		}
		p1 = p2 = head = Func1();
		while (stu->id1 > p2->id1 && p1->next != NULL)       //�����ʺ�λ�õ�ǰһ��ѧ��    
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == p1)           //�����ѧ������Ϊ����ͷ�����    
		{
			if (stu->id1 < p2->id1)            //�����ڱ�ͷǰ    
			{
				head = stu;
				stu->next = p2;
			}
			else                            //�����ڱ�ͷ��    
			{
				p2->next = stu;
				stu->next = NULL;
			}
		}
		else                    //�����ѧ���������е����    
		{
			if (stu->id1 < p1->id1)            //���뵽p1ָ���ѧ��ǰ    
			{
				p2->next = stu;
				stu->next = p1;
			}
			else                            //���뵽p1ָ���ѧ����    
			{
				p1->next = stu;
				stu->next = NULL;
			}
		}
		break;
	}
	case 2://��ӿγ���Ϣ
	{
		struct Course* head, * p1, * p2;
		struct Course* cou;
		printf("����������γ̺š��γ��������пΡ�ѧ��4���γ���Ϣ:\n");
		cou = (struct Course*) malloc(sizeof(Macro2));
		while (!scanf("%d   %s   %s   %d", &cou->lessonID, cou->name2, cou->first_class, &cou->credits))
		{
			printf("�����������������:\n");
			fflush(stdin);
		}
		fflush(stdin);
		p1 = p2 = head = Func2();
		while (cou->lessonID > p2->lessonID && p1->next != NULL)       //�����ʺ�λ�õ�ǰһ�ſγ�   
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == p1)           //����Ŀγ�����Ϊ����ͷ�����    
		{
			if (cou->lessonID < p2->lessonID)            //�����ڱ�ͷǰ    
			{
				head = cou;
				cou->next = p2;
			}
			else                            //�����ڱ�ͷ��    
			{
				p2->next = cou;
				cou->next = NULL;
			}
		}
		else                    //����Ŀγ��������е����    
		{
			if (cou->lessonID < p1->lessonID)            //���뵽p1ָ��Ŀγ�ǰ    
			{
				p2->next = cou;
				cou->next = p1;
			}
			else                            //���뵽p1ָ��Ŀγ̺�    
			{
				p1->next = cou;
				cou->next = NULL;
			}
		}
		break;
	}
	case 3://���ѧ��-�γ̳ɼ���Ϣ
	{
		struct Score* head, * p1, * p2;
		struct Score* sco;
		printf("����������ѧ�š��γ̺š��ɼ�4����Ϣ:\n");
		sco = (struct Score*) malloc(sizeof(Macro3));
		while (!scanf("%d    %d   %d", &sco->studentID, &sco->id2, &sco->score))
		{
			printf("�����������������:\n");
			fflush(stdin);
		}
		fflush(stdin);
		p1 = p2 = head = Func3();
		while (sco->studentID > p2->studentID && p1->next != NULL)       //�����ʺ�λ�õ�ǰһ��ѧ���ɼ�  
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p2 == p1)           //����ĳɼ�����Ϊ����ͷ�����    
		{
			if (sco->studentID < p2->studentID)            //�����ڱ�ͷǰ    
			{
				head = sco;
				sco->next = p2;
			}
			else                            //�����ڱ�ͷ��    
			{
				p2->next = sco;
				sco->next = NULL;
			}
		}
		else                    //����ĳɼ��������е����    
		{
			if (sco->studentID < p1->studentID)            //���뵽p1ָ��ĳɼ�ǰ    
			{
				p2->next = sco;
				sco->next = p1;
			}
			else                            //���뵽p1ָ��ĳɼ���    
			{
				p1->next = sco;
				sco->next = NULL;
			}
		}
		break;
	}
	}
}
void del()//����Ϊɾ����Ϣ�ĺ���
{
	int n;
	printf("�������ӦҪɾ�����ݵ����:\n");
	printf("1.ѧ����Ϣ\n");
	printf("2.�γ���Ϣ\n");
	printf("����ѡ����\n:");
	scanf("%d", &n);
	while (n < 1 || n>2)
	{
		printf("��������,����������:");
		scanf("%d", &n);
		fflush(stdin);
	}
	printf("\n");
	switch (n)
	{
	case 1://ɾ��ѧ����Ϣ
	{
		int Del_id;
		struct Student* head1;
		struct Score* head2;
		head1 = Func1();
		head2 = Func3();
		printf("��������Ҫɾ����ѧ��ѧ��:");
		scanf_s("%d", &Del_id);
		fflush(stdin);
		Del_Student(head1, Del_id);//����ɾ��ѧ����Ϣ����
		Del_Score1(head2, Del_id);//����ɾ����Ӧѧ���ɼ���Ϣ�ĺ���
		break;
	}
	case 2://ɾ���γ���Ϣ
	{
		int Del_id;
		struct Course* head1;
		struct Score* head2;
		head1 = Func2();
		head2 = Func3();
		printf("������ɾ���Ŀγ̺�:");
		scanf_s("%d", &Del_id);
		fflush(stdin);
		Del_Course(head1, Del_id);//����ɾ���γ���Ϣ����
		Del_Score2(head2, Del_id);//����ɾ����Ӧ�γ̳ɼ���Ϣ�ĺ���
		break;
	}
	}
}
void change()//����Ϊ�޸���Ϣ�ĺ���
{
	int change_id, n;
	struct Student* p;
	p = Func1();
	printf("������ѧ��ѧ��:");
	scanf("%d", &change_id);
	fflush(stdin);
	while (change_id != p->id1 && p->next != NULL) //������Ҫ�޸�ѧ����λ��
		p = p->next;
	if (change_id == p->id1)
	{
		printf("ѡ���޸ĵ�����:\n");
		printf("1��ѧ������\n");
		printf("2��ѧ������\n");
		printf("3��ѧ���Ա�\n");
		printf("4��ѧ��Ժϵ\n");
		printf("���������ǣ� ");
		scanf("%d", &n);
		fflush(stdin);
		while (n < 1 || n>4)
		{
			printf("��������,����������:");
			scanf("%d", &n);
			fflush(stdin);
		}
		printf("\n");
		switch (n)//�޸���Ϣ������
		{
		case 1://�޸�ѧ������
			printf("�������޸ĺ��������");
			scanf_s("%s", p->name1, 5);
			getchar();
			printf("����ɸ���\n");
			break;
		case 2://�޸�ѧ������
			printf("�������޸ĺ�����䣺");
			scanf_s("%d", &p->age);
			getchar();
			printf("����ɸ���\n");
			break;
		case 3://�޸�ѧ���Ա�
			printf("�������޸ĺ���Ա�(F/M)��");
			scanf_s("%c", &p->sex);
			getchar();
			printf("����ɸ���\n");
			break;
		case 4://�޸�ѧ��Ժϵ
			printf("�������޸ĺ��Ժϵ��");
			scanf_s("%s", p->college, 5);
			getchar();
			printf("����ɸ���\n");
			break;
		}
	}
	else printf("error\n");
}
void search()//����Ϊ�鿴����������Ϣ�ĺ���
{
	int n;
	printf("ѡ����Ҫ��ѯ����Ϣ����:\n");
	printf("1��ѧ��������Ϣ\n");
	printf("2��ѧ���ɼ���Ϣ\n");
	printf("���������ǣ� ");
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
	case 1://�鿴ѧ��������Ϣ
	{
		struct Student* p;
		int Search_id;
		p = Func1();
		printf("��������Ҫ��ѯ������Ϣ��ѧ����ѧ��:");
		scanf("%d", &Search_id);
		fflush(stdin);
		while (Search_id != p->id1 && p->next != NULL)
			p = p->next;
		if (Search_id == p->id1)
		{
			printf("����ѧ������ϢΪ��\n");
			printf("ѧ��:%d   ����:%s   ����:%d   �Ա�:%c   Ժϵ:%s\n", p->id1, p->name1, p->age, p->sex, p->college);
		}
		break;
	}
	case 2://�鿴ѧ���ɼ���Ϣ
	{
		int Search_id;
		struct Score* p;
		struct Course* pt;
		p = Func3();
		pt = Func2();
		printf("��������Ҫ��ѯ�γ̳ɼ���Ϣ��ѧ����ѧ��:");
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
				printf("�γ̣�%s   �ɼ���%d  \n", pt->name2, p->score);
				pt = Func2();
				p = p->next;
			}
		}
		break;
	}
	}
}
struct Student* Func1() //����Ϊ��ѧ����Ϣ�ļ�ת��������ĺ���
{
	FILE* f1;
	int n;
	if ((f1 = fopen("message1.txt", "r")) == NULL)
	{
		printf("�ļ�����!");
		exit(0);
	}
	struct Student* head;
	struct Student* p1, * p2;
	n = 0;
	p1 = p2 = (struct Student*)malloc(Macro1);//����һ���µ�Ԫ
	fscanf(f1, "%d   %s   %c   %d    %s", &p1->id1, p1->name1, &p1->sex, &p1->age, p1->college);//�����һ��ѧ���ĳɼ�
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
		p1 = (struct Student*)malloc(Macro1);//���ٶ�̬�洢��������ʼ��ַ����p1
		fscanf(f1, "%d   %s   %c   %d    %s", &p1->id1, p1->name1, &p1->sex, &p1->age, p1->college);//��������ѧ������Ϣ
	}
	p2->next = NULL;
	return(head);
}
struct Course* Func2() //����Ϊ���γ���Ϣ�ļ�ת��������ĺ���
{
	int n;
	FILE* f2;
	if ((f2 = fopen("message2.txt", "r")) == NULL)
	{
		printf("�ļ�����!");
		exit(0);
	}
	struct Course* head;
	struct Course* p1, * p2;
	n = 0;
	p1 = p2 = (struct Course*)malloc(Macro2);//����һ���µ�Ԫ
	fscanf(f2, "%d   %s   %s   %d ", &p1->lessonID, p1->name2, p1->first_class, &p1->credits);//�����һ���γ���Ϣ
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
		p1 = (struct Course*)malloc(Macro2);//���ٶ�̬�洢��������ʼ��ַ����p1
		fscanf(f2, "%d   %s   %s   %d ", &p1->lessonID, p1->name2, p1->first_class, &p1->credits);//���������γ���Ϣ
	}
	p2->next = NULL;
	return(head);
}
struct Score* Func3() //����Ϊ���ɼ���Ϣ�ı��ļ�ת��������ĺ���
{
	int n;
	FILE* f3;
	if ((f3 = fopen("message3.txt", "r")) == NULL)
	{
		printf("�ļ�����!");
		exit(0);
	}
	struct Score* head;
	struct Score* p1, * p2;
	n = 0;
	p1 = p2 = (struct Score*)malloc(Macro3);//����һ���µ�Ԫ
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
		p1 = (struct Score*)malloc(Macro3);//���ٶ�̬�洢��������ʼ��ַ����p1
		fscanf(f3, "%d    %d   %d", &p1->studentID, &p1->id2, &p1->score);//����ѧ���ɼ�
	}
	p2->next = NULL;
	return(head);
}
void Del_Student(struct Student* head, int Del_id) //����Ϊɾ��ѧ����Ϣ�ĺ���
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
		printf("��ɾ��ѧ��Ϊ%d��ѧ������Ϣ\n", Del_id);
	}
	else
		printf("error");
}

void Del_Course(struct Course* head, int Del_id) {//����ɾ���γ���Ϣ�ĺ���
	struct Course* p1, * p2;
	p1 = p2 = head;
	while (Del_id != p1->lessonID && p1->next != NULL)//����ɾ���γ̺�
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
		printf("�����ɹ���\n", Del_id);
	}
	else
		printf("error");
}
void Del_Score1(struct Score* head, int Del_id) {//����Ϊ����ѧ��ѧ��Ȼ��ɾ����Ӧѧ���ɼ���Ϣ�ĺ���
	struct Score* p1, * p2;
	p1 = p2 = head;
	while (Del_id != p1->studentID && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->studentID == Del_id) {
		while (head->studentID == Del_id)//ɾ����һ��ѧ���ĳɼ�
			head = head->next;
		while (p1->studentID == Del_id) {
			p1 = p1->next;
			p2->next = p1->next;

		}
		printf("�����ɹ���\n", Del_id);
	}
}
void Del_Score2(struct Score* head, int Del_id) {//������ݿγ̺�ɾ��ѧ���ɼ���Ϣ�ĺ���
	struct Score* p1, * p2;
	p1 = p2 = head;
	while (Del_id != p1->id2 && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->id2 == Del_id) {
		while (head->id2 == Del_id)//ɾ����һ��ѧ���ĳɼ�
			head = head->next;
		while (p1->id2 == Del_id) {
			p1 = p1->next;
			p2->next = p1->next;

		}
		printf("�����ɹ���\n", Del_id);
	}
}


int main()
{
	int n;
	float start, finish;//��¼ʱ�䣬�Ա�õ�����ʹ�õ�ʱ��
	double time;

	printf("\n");
	printf("1.�����Ϣ\n");
	printf("2.ɾ����Ϣ\n");
	printf("3.�޸���Ϣ\n");
	printf("4.��ѯ��Ϣ\n");
	printf("5.��������\n");
	printf("\n");
	printf("�����������ɲ���:");             

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
	case 1://�����Ϣ
	{
		start = clock();
		add();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n����ʱ��Ϊ%f s\n", time);//���ʱ��
		break;
	}
	case 2://ɾ����Ϣ
	{
		start = clock();
		del();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n����ʱ��Ϊ%f s\n", time);
		break;
	}
	case 3://�޸���Ϣ
	{
		start = clock();
		change();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n����ʱ��Ϊ%f s\n", time);
		break;
	}
	case 4://�鿴��Ϣ
	{
		start = clock();
		search();
		finish = clock();
		time = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n����ʱ��Ϊ%f s\n", time);
		break;
	}
	case 5://��������
	{
		printf("Thanks for using!");
		break;
	}
	}
	return 0;
}