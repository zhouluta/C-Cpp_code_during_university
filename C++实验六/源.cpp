#include<iostream>
#include<wchar.h>//���ַ����ú�����
#include<locale.h>//  ���ñ�������
#include<string.h>
using namespace std;
#define LEN1 sizeof(struct Student)
#define LEN2 sizeof(struct Course)
struct Student //��¼ѧ����Ϣ��һ
{
	int ID;//ѧ��
	char* Name;//����
	char* Course_name[10] = { NULL };//��ѡ�γ�����
	int C_ID[10];
	struct Student* next;
};
struct Course
{
	int C_ID;//�γ̺�
	char* Course_name;//�γ�����
	int Course_stu = 0;
	struct Course* next;
};
void Dispaly_course(struct Course* p) {
	struct Course* p1;
	p1 = p;
	if (p1->next != NULL)
	{
		cout << p1->Course_name << endl
			<< "ѡ��ÿγ̵�ѧ����" << p1->Course_stu << "��"
			<< endl;
	}
}
void Dispaly_student(struct Student* p) {
	struct Student* p1;
	p1 = p;
	if (p1 != NULL)
	{
		cout << "ѧ����ѧ��Ϊ:" << p1->ID << "\t"
			<< "��ѧ������Ϊ��" << p1->Name << endl;

		if (p1->Course_name[0] == NULL) {
			cout << "��ѧ����û��ѡ���κογ�";
		}
		else
			cout << "��ѡ��γ��У�";
		for (int i = 0; p1->Course_name[i] != NULL; i++) {
			cout << p1->C_ID[i] << "��" << p1->Course_name[i] << "\t";
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

	cout << "������Ҫѡ�ε�ѧ����ѧ��:" << endl;
	cin >> ID_stu;
	for (i = ID_stu - 1; i > 0; i--) {
		stu1 = stu1->next;
	}
	cout << "��ѧ����ѡ����Ϣ����" << endl;
	Dispaly_student(stu1);

	cout << "�����������¿γ̿�ѡ:" << endl;
	while (cour1->next != NULL)
	{
		cout << cour1->C_ID << "��" << cour1->Course_name << "\t";
		cour1 = cour1->next;
	}
	cour1 = cour;

	cout << endl << "������Ҫѡ��γ̵�ID:";
	cin >> ID_cour;

	for (int j = 1; j < ID_cour; j++)
		cour1 = cour1->next;
	i = 0;
	for (i = 0; stu1->C_ID[i] != 0; i++) {
		if (ID_cour == stu1->C_ID[i]) {
			cout << "�ÿγ��Ѿ���ѧ����ѡ���б����ˣ��벻Ҫ�ظ�ѡ��" << endl;
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
		cout << "�ѳɹ�ѡ��" << cour1->Course_name << endl;
		Dispaly_student(stu1);
	}

}
void Course_delete(Student* stu) {
	Student* stu1;
	stu1 = stu;

	int ID_stu, ID_cour;
	int i;
	int flag;
	cout << "������ѧ��ѧ�ţ�";
	cin >> ID_stu;
	for (i = ID_stu - 1; i > 0; i--) {
		stu1 = stu1->next;
	}
	cout << "��ѧ����ѡ����Ϣ����" << endl;
	Dispaly_student(stu1);

	if (stu1->C_ID[0] != 0) {
		cout << "������Ҫɾ���Ŀγ̵�ID��";
		cin >> ID_cour;
		for (i = 0; stu1->C_ID[i] != 0; i++) {
			if (ID_cour == stu1->C_ID[i]) {
				cout << stu1->Course_name[i] << "��ɾ��" << endl;
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
				cout << "��ѧ��û��ѡ��ÿγ�";
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "chs"); //����Ϊ�������
	char* course[7] = { "����", "�ߴ�", "����", "��Ӣ", "��ɢ","����ʷ","��ԭ" };
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
	cout << "��������������ӭ����ѧ��ѡ��ϵͳ������������" << endl;
	while (flag)
	{
		cout << "��ѡ����Ҫʹ�õĹ��ܣ�1��ѡ��\t2���˿�\t3���˳�ϵͳ" << endl;
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
			cout << "���˳�ϵͳ";
			flag = 0;
			break;
		}
		default:cout << "������������������";
			break;
		}
	}

	return 0;
}
