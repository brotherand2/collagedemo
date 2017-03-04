# include<stdio.h>
# include"graph.h"
void boot()//���˵�
{
    printf("       ������������������������������������������������������������\n");
	printf("       ��   <0>------(�˳�)Exit                                  ��\n");
	printf("       ��   <1>------(ͼ����)TRAVEL                              ��\n");
	printf("       ��   <2>------(������������������·��)PATH              ��\n");
	printf("       ��   <3>------(���һ�����е����г��е����·��)PATH      ��\n");
	printf("       ��   <4>------(��С������)SHORTEST TREE                   ��\n");
	printf("       ��   <5>------(��ʾͼ��Ϣ)SHOW                            ��\n");
	printf("       ������������������������������������������������������������\n");
}
int main()
{
	ALGraph *G;
	MGraph g,g1;
	Edge E[MAX];
	int i,j;
    bool flag=true;//ѭ����־   
	int number;
	int start,end;///��㡢�յ�
	int A[MAX][6]={
		{0,5,INF,7,INF,INF},
		{INF,0,4,INF,INF,INF},
		{8,INF,0,INF,INF,9},
		{INF,INF,5,0,INF,6},
		{INF,INF,INF,5,0,INF},
		{3,INF,INF,INF,1,0}};
		g.n=6;
		g.e=10;
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
			g.edges[i][j]=A[i][j];
			printf("121110098   ���»�   ͼ\n");
				
	while(flag)
	{
		boot();
		number=-1;//��ʼ��
		printf("�������ѡ��(0~5):");
		scanf("%d",&number);//������abc���󣬲��ܶ�ȡ,�򷵻�numberԭ��ַ����ֵ��������6abc��abc������
		while(getchar()!='\n')//���˷����ֵ��ַ�
			;
		switch(number)
		{
		case 0:
			flag=0;
			break;
		case 1:
			printf("�������:");
			scanf("%d",&start);
			MatToList1(g,G);
			printf("\n��%d��ʼ���������DFS(�ǵݹ��㷨):\n",start);
			DFS2(G,start);
			for(i=0;i<g.n;i++)
		    visit[i]=0;
			printf("\n��%d��ʼ���������DFS(�ݹ��㷨):\n",start);
			DFS(G,start);
			printf("\n��%d��ʼ�Ĺ������BFS:\n",start);
			BFS1(G,start);
			printf("\n");
			break;
		case 2:
             printf("\n������������������·����\n");
             floyd(g);//����������ڶ����ľ��롢·��
			 break;
		case 3:
			printf("�������:");
			scanf("%d",&start);
            Dijkstra(g,start);
			break;
		case 4:
			printf("����ķ�㷨�����:\n");
	        Prim(g,0);
		    printf("��³˹�����㷨�����:\n");
			SortEdge(g,E);
	        Kruskal(E,g.n,g.e);
			printf("\n");
			break;
		case 5:
			printf("����ͼ���ڽӾ���:\n");
			DispMat1(g);
			printf("\n�ڽӾ���ת�ڽӱ�:\n");
			MatToList1(g,G);
			DispAdj1(G);
			break;
		default:
			printf("������󣬲�������������ַ�������0~5������\n");
			break;
		}
	}
	return 0;
}

