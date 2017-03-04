# include<stdio.h>
# include"graph.h"
void boot()//主菜单
{
    printf("       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("       ┃   <0>------(退出)Exit                                  ┃\n");
	printf("       ┃   <1>------(图遍历)TRAVEL                              ┃\n");
	printf("       ┃   <2>------(输出任意两个城市最短路径)PATH              ┃\n");
	printf("       ┃   <3>------(输出一个城市到所有城市的最短路径)PATH      ┃\n");
	printf("       ┃   <4>------(最小生成树)SHORTEST TREE                   ┃\n");
	printf("       ┃   <5>------(显示图信息)SHOW                            ┃\n");
	printf("       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
int main()
{
	ALGraph *G;
	MGraph g,g1;
	Edge E[MAX];
	int i,j;
    bool flag=true;//循环标志   
	int number;
	int start,end;///起点、终点
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
			printf("121110098   曾勇华   图\n");
				
	while(flag)
	{
		boot();
		number=-1;//初始化
		printf("输入你的选择(0~5):");
		scanf("%d",&number);//若输入abc错误，不能读取,则返回number原地址垃圾值，若输入6abc则abc被过滤
		while(getchar()!='\n')//过滤非数字的字符
			;
		switch(number)
		{
		case 0:
			flag=0;
			break;
		case 1:
			printf("输入起点:");
			scanf("%d",&start);
			MatToList1(g,G);
			printf("\n从%d开始的深度优先DFS(非递归算法):\n",start);
			DFS2(G,start);
			for(i=0;i<g.n;i++)
		    visit[i]=0;
			printf("\n从%d开始的深度优先DFS(递归算法):\n",start);
			DFS(G,start);
			printf("\n从%d开始的广度优先BFS:\n",start);
			BFS1(G,start);
			printf("\n");
			break;
		case 2:
             printf("\n输出任意两个城市最短路径：\n");
             floyd(g);//输出所有相邻顶点间的距离、路径
			 break;
		case 3:
			printf("输入起点:");
			scanf("%d",&start);
            Dijkstra(g,start);
			break;
		case 4:
			printf("普里姆算法求解结果:\n");
	        Prim(g,0);
		    printf("克鲁斯卡尔算法求解结果:\n");
			SortEdge(g,E);
	        Kruskal(E,g.n,g.e);
			printf("\n");
			break;
		case 5:
			printf("有向图的邻接矩阵:\n");
			DispMat1(g);
			printf("\n邻接矩阵转邻接表:\n");
			MatToList1(g,G);
			DispAdj1(G);
			break;
		default:
			printf("输入错误，不能输入非数字字符，输入0~5！！！\n");
			break;
		}
	}
	return 0;
}

