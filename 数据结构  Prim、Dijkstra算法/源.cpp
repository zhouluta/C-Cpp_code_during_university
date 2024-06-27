#include <stdio.h>
#include <malloc.h>
#include "��ͷ.h"
//------------------------------------------------------------
//----�ڽӾ���Ļ��������㷨----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e) //����ͼ���ڽӾ���
{
	int i, j;
	g.n = n; g.e = e;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g)	//����ڽӾ���g
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != INF)
				printf("%4d", g.edges[i][j]);
			else
				printf("%4s", "��");
		printf("\n");
	}
}
//------------------------------------------------------------

//------------------------------------------------------------
//----�ڽӱ�Ļ��������㷨------------------------------------
//------------------------------------------------------------
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) //����ͼ���ڽӱ�
{
	int i, j;
	ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)								//���ڽӱ�������ͷ����ָ�����ó�ֵ
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++)								//����ڽӾ�����ÿ��Ԫ��
		for (j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)			//����һ����
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));	//����һ�����p
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;	//����ͷ�巨������p
				G->adjlist[i].firstarc = p;
			}
	G->n = n; G->e = n;
}
void DispAdj(AdjGraph* G)	//����ڽӱ�G
{
	int i;
	ArcNode* p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p != NULL)
		{
			printf("%3d[%d]��", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("��\n");
	}
}
void DestroyAdj(AdjGraph*& G)		//����ͼ���ڽӱ�
{
	int i;
	ArcNode* pre, * p;
	for (i = 0; i < G->n; i++)			//ɨ�����еĵ�����
	{
		pre = G->adjlist[i].firstarc;	//pָ���i����������׽��
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)			//�ͷŵ�i������������б߽��
			{
				free(pre);
				pre = p; p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//�ͷ�ͷ�������
}
//------------------------------------------------------------


//------------------------------------------------------------
//----prim�㷨------------------------------------------------
//------------------------------------------------------------
void Prim(MatGraph g, int v)
{
	int lowcost[MAXV];			//����i�Ƿ���U��
	int min;
	int closest[MAXV], i, j, k;
	for (i = 0; i < g.n; i++)          //��lowcost[]��closest[]�ó�ֵ
	{
		lowcost[i] = g.edges[v][i];//�洢Ȩֵ,��0�еĵ�i��
		closest[i] = v;			//�洢���,v=0����ʱ�洢��������������ֵ
		//printf("lowcost-%d-", lowcost[i]);
		//printf("��ʱ%d", closest[i]);
		//for (int i = 0; i < 6; i++) //���closest �鿴�������������
		//{
		//	printf("-%d-", closest[i]);//ֻ����6����ֵ
		//}
	}
	for (i = 1; i < g.n; i++)          //�ҳ�n-1������
	{
		min = INF;
		for (j = 0; j < g.n; j++)       //��(V-U)���ҳ���U����Ķ���k
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;			//k��¼�������ı��
				//printf("lowcost-%d-",lowcost[j]);
			}
		printf("closestΪ��");
		for (int i = 0; i < 6; i++) //���closest �鿴�������������
		{
			printf(" %d ", closest[i]);//ֻ����6����ֵ
		}
		printf("\n");
		printf(" ��(%d,%d)ȨΪ:%d\n\n", closest[k], k, min);



		lowcost[k] = 0;         	//���k�Ѿ�����U����0
		for (j = 0; j < g.n; j++)   	//�޸�����lowcost��closest
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])//������
			{
				lowcost[j] = g.edges[k][j];//��Ȩֵ����Ϊ��һ�е�Ȩֵ
				closest[j] = k; //�洢���, v = 5����ʱ�洢��������������ֵ
			}
	}
	printf("������С��������closestΪ��");
	for (int i = 0; i < 6; i++) //���closest �鿴�������������
	{
		printf(" %d ", closest[i]);//ֻ����6����ֵ
	}
	printf("\n");
}


//------------------------------------------------------------
//----Dijkstra�㷨--------------------------------------------
//------------------------------------------------------------
void Dispath(MatGraph g, int dist[], int path[], int S[], int v)
//����Ӷ���v�������������·��
{
	int i, j, k;
	int apath[MAXV], d;					//���һ�����·��(����)���䶥�����
	for (i = 0; i < g.n; i++)					//ѭ������Ӷ���v��i��·��
		if (S[i] == 1 && i != v)
		{
			printf("  �Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:", v, i, dist[i]);
			d = 0; apath[d] = i;			//���·���ϵ��յ�
			k = path[i];
			if (k == -1)					//û��·�������
				printf("��·��\n");
			else						//����·��ʱ�����·��
			{
				while (k != v)
				{
					d++; apath[d] = k;
					k = path[k];
				}
				d++; apath[d] = v;		//���·���ϵ����
				printf("%d", apath[d]);	//��������
				for (j = d - 1; j >= 0; j--)	//�������������
					printf(",%d", apath[j]);
				printf("\n");
			}
		}
}

void Dijkstra(MatGraph g, int v)	//Dijkstra�㷨
{
	int dist[MAXV], path[MAXV];
	int S[MAXV];				//S[i]=1��ʾ����i��S��, S[i]=0��ʾ����i��U��
	int Mindis, i, j, u;
	for (i = 0; i < g.n; i++)
	{
		dist[i] = g.edges[v][i];	//�����ʼ��
		S[i] = 0;					//S[]�ÿ�
		if (g.edges[v][i] < INF)	//·����ʼ��
			path[i] = v;			//����v������i�б�ʱ���ö���i��ǰһ������Ϊv
		else
			path[i] = -1;			//����v������iû��ʱ���ö���i��ǰһ������Ϊ-1
	}
	S[v] = 1; path[v] = 0;			//Դ����v����S��
	for (i = 0; i < g.n - 1; i++)		//ѭ��ֱ�����ж�������·�������
	{
		Mindis = INF;				//Mindis����󳤶ȳ�ֵ
		for (j = 0; j < g.n; j++)		//ѡȡ����S�У���U�У��Ҿ�����С���·�����ȵĶ���u
			if (S[j] == 0 && dist[j] < Mindis)
			{
				u = j;
				Mindis = dist[j];
			}
		S[u] = 1;					//����u����S��
		for (j = 0; j < g.n; j++)		//�޸Ĳ���S�У���U�У��Ķ�������·��
			if (S[j] == 0)
				if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
				{
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
	}
	Dispath(g, dist, path, S, v);	//������·��
}

//������----------------------------
int main()
{
	MatGraph g, g2;
	int A[MAXV][MAXV] = //ԭ�����ڽӾ���
	{
		{0,28,INF,INF,INF,10,INF},
		{28,0,16,INF,INF,INF,14},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,25,24},
		{10,INF,INF,INF,25,0,INF},
		{INF,14,INF,18,24,INF,0}
	};
	int n = 7, e = 9;

	int B[MAXV][MAXV] =//prim�㷨�ڽӾ���
	{
		//0 1  2  3  4  5 
		{0, 5, 8, 7, INF, 3},//0
		{5, 0, 4,INF,INF,INF},//1
		{8, 4, 0, 5, INF, 9},//2
		{7,INF,5, 0, 5 , 6},//3
		{INF,INF,INF,5,0,1},//4
		{3,INF,9, 6, 1, 0}//5

	};
	int n2 = 6, e2 = 10;

	int C[MAXV][MAXV] =//Dijkstra�㷨�ڽӾ���
	{
		//0  1  2  3  4  5 
		{0,5,INF,7,INF,INF},//0
		{INF,0,4,INF,INF,INF},//1
		{8,INF,0,INF,INF,9},//2
		{INF,INF,5,0,INF,6},//3
		{INF,INF,INF,5,0,INF},//4
		{3,INF,INF,INF,1,0},//5
	};
	int n3 = 6, e3 = 10;

	CreateMat(g, B, n2, e2);			//����prim�㷨���ڽӾ���
	printf("ͼG���ڽӾ���:\n");
	DispMat(g);					//����ڽӾ���
	int v = 0;

	printf("\n-----Prim�㷨����С������-----");
	printf("\nPrim�㷨���(��ʼ��Ϊ%d)\n", v);
	Prim(g, v);

	printf("\n-----Dijkstra�㷨�����·��-----");
	CreateMat(g2, C, n3, e3);//����Dijkstra���ڽӾ���
	printf("\n��%d������������·������:\n", v);
	Dijkstra(g2, v);
	return 1;

}