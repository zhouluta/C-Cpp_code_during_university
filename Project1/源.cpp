#include <stdio.h>  //��������Ŀ�
#include <stdlib.h>
#include <wchar.h>//���ַ����ú�����
#include <string.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#define N 10  //��ʼ�����ݵĸ���
int B = 9;  //����ȫ�ֱ���
int* p = &B;  //����������ָ�������
int C = 9;
int* q = &C;
int D = 9;
int* r = &D;
void inputlesson(struct Table_3 stu_lesson[], int n);  //��������
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
}stu[1000];  //����ṹ��
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
	int i, a, b, c, d, j, k, x, y, z, choice2, choice3, choice4;  //�����ʼ����
	int id;
	double time11, start, end;  //�������ʱ��ı���
	char fname[32];
	char sex[2] = { 'M','F' };  //MΪmale��FΪfemale
	char name2[20];
	wchar_t name[20];//�ÿ��ַ�����
	wchar_t xing[] = L"��Ǯ��������֣����½���������������ŻƳ�";  //���һЩ��
	wchar_t ming[] = L"���󿡲���˼־Ⱥ�����������ǿ·��������÷����������γ�������Ȼ�ľ��������";
	char name3[20];
	wchar_t firstname[] = L"��ɢ�ߴ�������ѧ�������Ļ�ѧ��ʷ����������ѧӢ������";
	wchar_t lastname[] = L"���󿡲���˼־Ⱥ�����������ǿ·��������÷����������γ�������Ȼ�ľ��������";
	char name4[20];
	wchar_t yuanxi1[] = L"�����������˹��Ľ������װ��ѧ���̼�����Ȼ�ľ��������";
	wchar_t yuanxi2[] = L"�����������˹��Ľ������װ��ѧ���̼�����Ȼ�ľ��������";
	srand((unsigned)time(NULL));  ////������������ĳ�ʼ������
	for (i = 0;i < N;i++)  //����N��ѧ������
	{
		a = rand() % 2;  //ʹ��rand���� % ��b - a + 1��+ a����[0,1]�������
		b = rand() % 6 + 17;  //ʹ��rand���� % ��b - a + 1��+ a����[17,22]�������
		stu[i].stu_id = i + 1;
		stu[i].sex = sex[a];  //���ѡȡsex�б��F��M
		stu[i].age = b;  //��b��������ɵ����䣩����stu[i].age

		c = rand() % 20;
		name[0] = xing[c];//���������������
		for (j = 1;j < 3;j++)//���������������
		{
			d = rand() % 35;
			name[j] = ming[d];
		}
		name[j] = '\0';
		wcharTochar(name, name2, sizeof(name2));
		setlocale(LC_ALL, "chs");//����Ϊ�������
		strcpy_s(stu[i].stu_name, name2);
		for (k = 0;k < 2;k++)
		{
			y = rand() % 18;
			name[k] = yuanxi1[y];
		}
		for (j = 2;j < 4;j++)//���������������
		{
			z = rand() % 18;
			name[j] = yuanxi2[z];
		}
		name[j] = '\0';
		wcharTochar(name, name4, sizeof(name4));
		setlocale(LC_ALL, "chs");//����Ϊ�������
		strcpy_s(stu[i].yuan_xi, name4);
	}
	PrintTable1(B);  //���ô�ӡ����������һ���ݴ�ӡ����
	for (i = 0;i < N;i++)  //����50��ѧ������
	{
		lesson[i].lesson_id = i + 1001;
		b = rand() % 3 + 2;  //ʹ��rand���� % ��b - a + 1��+ a����[2,4]�������
		lesson[i].credict = b;

		for (k = 0;k < 2;k++)
		{
			c = rand() % 18;
			name[k] = firstname[c];
		}
		for (j = 2;j < 4;j++)//���������������
		{
			d = rand() % 18;
			name[j] = lastname[d];
		}
		name[j] = '\0';
		wcharTochar(name, name3, sizeof(name3));
		setlocale(LC_ALL, "chs");//����Ϊ�������
		strcpy_s(lesson[i].lesson_name, name3);
		c = rand() % 18;
		name[0] = firstname[c];
		for (j = 1;j < 3;j++)//���������������
		{
			d = rand() % 18;
			name[j] = lastname[d];
		}
		name[j] = '\0';
		wcharTochar(name, name3, sizeof(name3));
		setlocale(LC_ALL, "chs");//����Ϊ�������
		strcpy_s(lesson[i].first_les_name, name3);
	}
	PrintTable2(C);  //���ô�ӡ��������������ݴ�ӡ����
	inputlesson(stu_lesson, N);  //���ú�����ʵ�ֱ�����ʼ��
	PrintTable3(D);  //���ô�ӡ���������������ݴ�ӡ����
	do
	{
	A:k = menu();  //���ú���������˵�����ȡ�û�ѡ��
		switch (k)  //��k����ʱ������switch-case������û�����
		{
		case 0:break;  //���kΪ0�����
		case 1:  //����û�ѡ��Ϊ1
			start = clock();	//��ʼ��ʱ
			do {
				x = menu1();
				switch (x)
				{
				case 0:goto W;  //����goto�����ɼ�ʱ
				case 1:
					plusM(p);  //�û��������ݣ����ú��������õ�ַ���ݣ��ı�pֵ
					printf("������������Ϣ��\n");  //��ӡ��ʾ��Ϣ
					printf("ѧ�ţ�");
					scanf_s("%d", &stu[B].stu_id);  //���û��������ݴ���
					rewind(stdin);  //������棬��\n�������ֹӰ����������
					printf("�Ա�(F or M)��");
					scanf_s("%c", &stu[B].sex);
					rewind(stdin);
					printf("���䣺");
					scanf_s("%d", &stu[B].age);
					rewind(stdin);
					printf("������");
					gets_s(stu[B].stu_name);
					printf("Ժϵ��");
					gets_s(stu[B].yuan_xi);
					paixu1(stu, B + 1);
					printf("��һ������ӳɹ���\n");  //��ӡ��ʾ��Ϣ
					break;
				case 2:
					plusM(q);  //�û��������ݣ����ú��������õ�ַ���ݣ��ı�qֵ
					printf("������������Ϣ��\n");  //��ӡ��ʾ��Ϣ
					printf("�γ̺ţ�");
					scanf_s("%d", &lesson[C].lesson_id);   //���û��������ݴ���
					rewind(stdin);  //������棬��\n�������ֹӰ����������
					printf("�γ�����");
					gets_s(lesson[C].lesson_name);
					printf("���пΣ�");
					gets_s(lesson[C].first_les_name);
					rewind(stdin);
					printf("ѧ�֣�");
					scanf_s("%d", &lesson[C].credict);
					paixu2(lesson, C + 1);
					printf("���������ӳɹ���\n");
					break;
				case 3:
					plusM(r);  //�û��������ݣ����ú��������õ�ַ���ݣ��ı�rֵ
					printf("������������Ϣ��\n");  //��ӡ��ʾ��Ϣ
					printf("ѧ�ţ�");
					scanf_s("%d", &stu_lesson[D].stu_id);  //���û��������ݴ���
					rewind(stdin);  //������棬��\n�������ֹӰ����������
					printf("�γ̺ţ�");
					scanf_s("%d", &stu_lesson[D].lesson);
					rewind(stdin);
					printf("�ɼ���");
					scanf_s("%d", &stu_lesson[D].score);
					rewind(stdin);
					paixu3(stu_lesson, D + 1);
					printf("����������ӳɹ���\n");
					break;
				case 4:
					system("cls");  //���ú����������Ļ
					break;
				case 5:
					PrintTable1(B);  //��ӡ��һ
					break;
				case 6:
					PrintTable2(C);  //��ӡ���
					break;
				case 7:
					PrintTable3(D);  //��ӡ����
					break;
				default:
					printf("û�����ѡ�\n");  //����Ƿ�����
				}
			} while (x);
		W:end = clock();	//��ʱ����
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;  //����ʱ��
			printf("�ò������������ʱ�䣺%lfms\n", time11);  //����û�ִ������������ʱ��
			goto A;  //����ѭ��
		case 2:
			start = clock();	//��ʼ��ʱ
			do {
				choice2 = menu1();  //��ӡ�˵�1���洢�û�ѡ��
				switch (choice2)
				{
				case 0:goto Y;
				case 1:
					int stu_id1;
					printf("����������ɾ����ѧ��ѧ�ţ�\n");  //��ӡ��ʾ��Ϣ
					scanf_s("%d", &stu_id1);
					rewind(stdin);  //�������
					for (i = 0;i <= B;i++)
					{
						if (stu_id1 == stu[i].stu_id)
						{
							delTable1(stu_id1);
							delTable3(stu_id1);
							goto AB;
						}
					}
					printf("û�и�ѧ�ţ������˳�ɾ����������ӣ�\n");
					break;
				AB:printf("��һ����ɾ���ɹ���\n");  //��ӡ��ʾ��Ϣ
					break;
				case 2:
					int lesson_id1;
					printf("����������ɾ���Ŀγ̺ţ�\n");
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
					if (i == C + 1) { printf("û�иÿγ̺ţ�\n"); goto AD; }
					subM(q);
					printf("�������ɾ���ɹ���\n");
				AD:break;
				case 3:
					int stu_id2;
					printf("����������ɾ����ѧ��ѧ�ţ�\n");
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
					printf("û�и�ѧ�ţ������˳�ɾ����������ӣ�\n");
					break;
				AC:printf("��һ����ɾ���ɹ���\n");  //��ӡ��ʾ��Ϣ
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
					printf("û�����ѡ�\n");
				}
			} while (choice2);
		Y:end = clock();	//��ʱ����
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;
			printf("�ò������������ʱ�䣺%lfms\n", time11);
			goto A;
		case 3:
			start = clock();	//��ʼ��ʱ
			do {
				choice3 = menu2();
				switch (choice3)
				{
				case 0:goto J;
				case 1:
					printf("�����������޸�ѧ����ѧ�ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("ѧ��Ϊ%d��ѧ���������ǣ�", id);
					gets_s(stu[id - 1].stu_name);
					printf("�޸ĳɹ���\n");
					break;
				case 2:
					printf("�����������޸�ѧ����ѧ�ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("ѧ��Ϊ%d��ѧ�����Ա��ǣ�F or M����", id);
					scanf_s("%c", &stu[id - 1].sex);
					printf("�޸ĳɹ���\n");
					break;
				case 3:
					int id;
					printf("�����������޸�ѧ����ѧ�ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("ѧ��Ϊ%d��ѧ���������ǣ�", id);
					scanf_s("%d", &stu[id - 1].age);
					rewind(stdin);
					printf("�޸ĳɹ���\n");
					break;
				case 4:
					printf("�����������޸�ѧ����ѧ�ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("ѧ��Ϊ%d��ѧ����Ժϵ�ǣ�", id);
					gets_s(stu[id - 1].yuan_xi);
					rewind(stdin);
					printf("�޸ĳɹ���\n");
					break;
				case 5:
					printf("�����������޸Ŀγ̵Ŀγ̺ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("�γ̺�Ϊ%d���¿γ����ǣ�", id);
					gets_s(lesson[id - 1].lesson_name);
					rewind(stdin);
					printf("�޸ĳɹ���\n");
					break;
				case 6:
					printf("�����������޸Ŀγ̵Ŀγ̺ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("�γ̺�Ϊ%d�������п����ǣ�", id);
					gets_s(lesson[id - 1].first_les_name);
					rewind(stdin);
					printf("�޸ĳɹ���\n");
					break;
				case 7:
					printf("�����������޸Ŀγ̵Ŀγ̺ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("�γ̺�Ϊ%d����ѧ���ǣ�", id);
					scanf_s("%d", &lesson[id - 1].credict);
					rewind(stdin);
					printf("�޸ĳɹ���\n");
					break;
				case 8:
					int id1, id2;
					printf("�����������޸�ѧ����ѧ�ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("������ԭ�γ̺ţ�");
					scanf_s("%d", &id1);
					rewind(stdin);
					printf("�������¿γ̺ţ�");
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
					printf("�޸ĳɹ���\n");
					break;
				case 9:
					printf("�����������޸�ѧ����ѧ�ţ�");
					scanf_s("%d", &id);
					rewind(stdin);
					printf("������ԭ�γ̺ţ�");
					scanf_s("%d", &id1);
					rewind(stdin);
					printf("�������³ɼ���");
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
					printf("�޸ĳɹ���\n");
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
					printf("û�����ѡ�\n");
				}
			} while (choice3);
		J:end = clock();	//��ʱ����
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;
			printf("�ò������������ʱ�䣺%lfms\n", time11);
			goto A;
		case 4:
			start = clock();	//��ʼ��ʱ
			int searchid;
			printf("�����������ѯѧ����ѧ�ţ�");
			scanf_s("%d", &searchid);
			rewind(stdin);
			for (i = 0;i <= B;i++)
			{
				if (stu[i].stu_id == searchid)
				{
					printf("**************************************************************\n");
					printf("ѧ��         �Ա�           ����          ����        Ժϵ\n");
					printf("**************************************************************\n");
					printf("%2d%13c%16d%16s%14s\n", stu[i].stu_id, stu[i].sex, stu[i].age, stu[i].stu_name, stu[i].yuan_xi);
					printf("************************************\n");
					printf("ѧ��         �γ̺�           �ɼ�     \n");
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
				printf("���޴��ˣ�\n");
			else
				printf("��ѯ��ϣ�\n");
			printf("��������Ҫ��ѯ��ѧ������������䣺\n");
			int firstage, lastage;
			printf("��ʼ���䣺");
			scanf_s("%d", &firstage);
			rewind(stdin);
			printf("��ֹ���䣺");
			scanf_s("%d", &lastage);
			rewind(stdin);
			printf("������%d��%d֮���ѧ�����£�\n", firstage, lastage);
			printf("**************************************************************\n");
			printf("ѧ��         �Ա�           ����          ����        Ժϵ\n");
			printf("**************************************************************\n");
			for (i = 0;i <= B;i++)
			{
				if (stu[i].age <= lastage && stu[i].age >= firstage)
				{
					printf("%2d%13c%16d%16s%14s\n", stu[i].stu_id, stu[i].sex, stu[i].age, stu[i].stu_name, stu[i].yuan_xi);
				}
				else continue;
			}
			end = clock();	//��ʱ����
			time11 = (double)((end - start) * 1000) / CLOCKS_PER_SEC;
			printf("�ò������������ʱ�䣺%lfms\n", time11);
			goto A;
		case 5:
			printf("������ı��ļ�����");  //��ӡ��ʾ��Ϣ
			scanf_s("%s", &fname, 50);  //���û���������ı����ִ���
			SaveToFile(fname, stu, lesson, stu_lesson, 6);   //���ú��������ļ�
			printf("����ɹ���\n");
			break;
		case 6:
			printf("����Ķ������ļ�����");  //��ӡ��ʾ��Ϣ
			scanf_s("%s", &fname, 50);  //���û�������Ķ������ļ����ִ���
			WriteToFile(fname, stu, lesson, stu_lesson);
			printf("����ɹ���\n");  //��ӡ��ʾ��Ϣ
			break;
		case 7:
			system("cls");  //�����Ļ
			break;
		default:
			printf("û�����ѡ�\n");  //����Ƿ�����
		}
	} while (k);
	return 0;
}
void inputlesson(struct Table_3 stu_lesson[], int n)  //�������ݳ�ʼ��
{
	srand((unsigned)time(NULL));  ////������������ĳ�ʼ������
	int i, j, a;
	for (i = 0;i < n;i++)
	{
		stu_lesson[i].stu_id = i + 1;
		int ii = 0;
		for (j = 0;j < 6;j++)
		{
			a = rand() % 101;  //ʹ��rand���� % ��b - a + 1��+ a����[0,100]�������
			stu_lesson[i].lesson[j] = 1001 + ii;
			stu_lesson[i].score[j] = a;
			ii += 1;
		}
	}
}
int menu()  //���˵�
{
	int n;
	printf("************\n");
	printf("MENU\n");
	printf("************\n");
	printf("1:��\n");
	printf("2:ɾ\n");
	printf("3:��\n");
	printf("4:��\n");
	printf("5:���������ı��ļ�����Ӳ��\n");
	printf("6:�������Զ������ļ�����Ӳ��\n");
	printf("7:����\n");
	printf("0:�˳�\n");
	printf("************\n");
	printf("��۶�Ӧ���֣�");
	scanf_s("%d", &n);
	rewind(stdin);
	return n;
}
int menu1()  //�˵�1
{
	int n = 0;
	printf("**************\n");
	printf("����MENU\n");
	printf("**************\n");
	printf("1:�Ա�һ����\n");
	printf("2:�Ա������\n");
	printf("3:�Ա�������\n");
	printf("4:����\n");
	printf("5:��ʾTable1\n");
	printf("6:��ʾTable2\n");
	printf("7:��ʾTable3\n");
	printf("0:�˳�����\n");
	printf("************\n");
	printf("��۶�Ӧ���֣�");
	scanf_s("%d", &n);
	rewind(stdin);
	return n;
}
int menu2()  //�˵�2
{
	int n = 0;
	printf("**************\n");
	printf("�Ĳ���MENU\n");
	printf("**************\n");
	printf("1:�޸ı�һ����\n");
	printf("2:�޸ı�һ�Ա�\n");
	printf("3:�޸ı�һ����\n");
	printf("4:�޸ı�һԺϵ\n");
	printf("5:�޸ı���γ���\n");
	printf("6:�޸ı�����п�\n");
	printf("7:�޸ı��ѧ��\n");
	printf("8:�޸ı����γ̺�\n");
	printf("9:�޸ı����ɼ�\n");
	printf("10:����\n");
	printf("11:��ʾTable1\n");
	printf("12:��ʾTable2\n");
	printf("13:��ʾTable3\n");
	printf("0:�˳��Ĳ���\n");
	printf("************\n");
	printf("��۶�Ӧ���֣�");
	scanf_s("%d", &n);
	rewind(stdin);
	return n;
}
void PrintTable1(int n)  //��ƺ�������չʾ��һ
{
	int i;
	n = B;
	printf("**************************************************************\n");
	printf("ѧ��         �Ա�           ����          ����        Ժϵ\n");
	printf("**************************************************************\n");
	for (i = 0;i <= B;i++)
	{
		printf("%2d%13c%16d%16s%14s\n", stu[i].stu_id, stu[i].sex, stu[i].age, stu[i].stu_name, stu[i].yuan_xi);
	}
}
void PrintTable2(int n)  //��ƺ�������չʾ���
{
	int i;
	n = C;
	printf("******************************************************\n");
	printf("�γ̺�         �γ���           ���п�          ѧ��      \n");
	printf("******************************************************\n");
	for (i = 0;i <= C;i++)
	{
		printf("%4d%18s%16s%13d\n", lesson[i].lesson_id, lesson[i].lesson_name, lesson[i].first_les_name, lesson[i].credict);
	}
}
void PrintTable3(int n)  //��ƺ�������չʾ����
{
	int i, j;
	n = D;
	printf("************************************\n");
	printf("ѧ��         �γ̺�           �ɼ�     \n");
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
int plusM(int* p)  //��*p��ֵ��һ
{
	*p = *p + 1;
	return *p;
}
int subM(int* p)  //��*p��ֵ��һ
{
	*p = *p - 1;
	return *p;
}
void paixu1(struct Table_1 stu[], int length)  //�Ա�һ�������򣨴�С����
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
void paixu2(struct Table_2 leeson[], int length)  //�Ա���������򣨴�С����
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
void paixu3(struct Table_3 stu_leeson[], int length)  //�Ա����������򣨴�С����
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
void delTable1(int stu_id1)  //ɾ����һ����
{
	int i;
	for (i = 0; i <= B; i++)
	{
		if (stu[i].stu_id == stu_id1)
		{
			for (;i <= B;i++)
			{
				stu[i] = stu[i + 1];  //�ú�һ���ǰһ���ɾ����Ч��
			}
			break;
		}
	}
	subM(p);
}
void delTable3(int stu_id2)  //ɾ����������
{
	int i;
	for (i = 0; i <= D; i++)
	{
		if (stu_lesson[i].stu_id == stu_id2)
		{
			for (;i <= D;i++)
			{
				stu_lesson[i] = stu_lesson[i + 1];  //�ú�һ���ǰһ���ɾ����Ч��
			}
			break;
		}
	}
	subM(r);
}
void SaveToFile(char* fname, struct Table_1 stu[], struct Table_2 lesson[], struct Table_3 stu_lesson[], int m)  //�����ݴ�Ϊ�ı��ļ�
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
void WriteToFile(char* fname, struct Table_1 stu[], struct Table_2 lesson[], struct Table_3 stu_lesson[])  //�����ݴ�Ϊ�������ļ�
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