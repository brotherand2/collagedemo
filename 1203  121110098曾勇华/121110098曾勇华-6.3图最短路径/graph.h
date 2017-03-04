# include<malloc.h>
# define MAX 100
# define INF 32767
int visit[MAX];
typedef int InfoType;
typedef struct
{
	int no;
	InfoType info;
}VertexType;
typedef struct
{
	int i;
	int j;
	int weight;
}Edge;
typedef struct
{
	int edges[MAX][MAX];
	int n;
	int e;
	VertexType vexs[MAX];
}MGraph;
typedef struct ANode
{
	int adjvex;
	struct ANode *nextarc;
	InfoType info;
}ArcNode;
typedef struct
{
	int data;
	ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAX];
typedef struct
{
	AdjList adjlist;
	int n,e;
}ALGraph;
void DispMat1(MGraph g)
{
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			if(g.edges[i][j]!=INF)
				printf("%4d",g.edges[i][j]);
			else
				printf("%4s","∞");
		}
		printf("\n");
	}
}
void MatToList1(MGraph g,ALGraph *&G)
{
	int i,j;
	ArcNode *p;
	G=(ALGraph*)malloc(sizeof(ALGraph));
	G->n=g.n;
	G->e=g.e;
	for(i=0;i<g.n;i++)
	{
		G->adjlist[i].data=i;
		G->adjlist[i].firstarc=NULL;
	}
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
			{
				p=(ArcNode*)malloc(sizeof(ArcNode));
				p->info=g.edges[i][j];
				p->adjvex=j;
				p->nextarc=G->adjlist[i].firstarc;
				G->adjlist[i].firstarc=p;
			}
		}
	}
}
void DispAdj1(ALGraph *G)
{
	int i;
	ArcNode *p;
	for(i=0;i<G->n;i++)
	{
		p=G->adjlist[i].firstarc;
		printf("%-10d",G->adjlist[i].data);
		while(p)
		{
			printf("%d(%d)  ",p->adjvex,p->info);
			p=p->nextarc;
		}
		printf("\n");
	}
}
void ListToMat1(MGraph &g,ALGraph *G)
{
	int i,j;
	ArcNode *p;
	g.n=G->n;
	g.e=G->e;
	for(i=0;i<G->n;i++)
	{
		for(j=0;j<G->n;j++)
		{
			if(i!=j)
			g.edges[i][j]=INF;
			else
			g.edges[i][j]=0;
		}
		p=G->adjlist[i].firstarc;
		while(p)
		{
			g.edges[i][p->adjvex]=p->info;
			p=p->nextarc;
		}
	}
}
void DFS(ALGraph *G,int u)//(递归算法)深度优先
{
	ArcNode *p;
	p=G->adjlist[u].firstarc;
	visit[u]=1;
	printf("%4d",u);
	while(p)
	{
		if(visit[p->adjvex]==0)
		{
			DFS(G,p->adjvex);
		}
		p=p->nextarc;
	}
}
void DFSAll(ALGraph *G,int path[],int u,int d)//(递归算法)深度优先
{
	int i;
	ArcNode *p;
	p=G->adjlist[u].firstarc;
	visit[u]=1;
	path[d]=u;
	d++;
    if(d==G->n)
	{
		printf("结果:");
		for(i=0;i<d;i++)
			printf("%4d",path[i]);
		printf("\n");
	}
	while(p)
	{
		if(visit[p->adjvex]==0)
		{
			DFSAll(G,path,p->adjvex,d);
		}
		p=p->nextarc;
	}
	visit[u]=0;
}
void DFS1(ALGraph *G,int u)//(非递归算法)深度优先
{
	int i;
	int st[MAX];
	int top=-1;
	ArcNode *p;
	for(i=0;i<G->n;i++)
		visit[i]=0;
	visit[u]=1;
	top++;
	st[top]=u;
	printf("%4d",u);
	while(top>-1)
	{
		i=st[top];
	    p=G->adjlist[i].firstarc;
		while(p)
		{
			if(visit[p->adjvex]==0)
			{
				printf("%4d",p->adjvex);
				visit[p->adjvex]=1;
				top++;
				st[top]=p->adjvex;
				break;
			}
			p=p->nextarc;
		}
		if(!p)
            top--;
	}
}
void DFS2(ALGraph *G,int v)   //非递归深度优先算法
{
	ArcNode *p;
	ArcNode *St[MAX];
	int top=-1,w,i;
    for (i=0;i<G->n;i++) 
		visit[i]=0;		//顶点访问标志均置成0
	printf("%3d",v);        //访问顶点v
	visit[v]=1;
	top++;                  //将顶点v的第一个相邻顶点进栈
	St[top]=G->adjlist[v].firstarc;
	while (top>-1)          //栈不空循环
	{
		p=St[top];  //出栈一个顶点作为当前顶点
		while (p!=NULL)     //查找当前顶点的第一个未访问的顶点
		{
			w=p->adjvex;
			if (visit[w]==0)
			{
				printf("%3d",w); //访问w
				visit[w]=1;
				top++;           //将顶点w的第一个顶点进栈
				St[top]=G->adjlist[w].firstarc;
				break;           //退出循环
			}
			p=p->nextarc;        //找下一个相邻顶点
		}
		if(!p)
			top--;  
	}
	printf("\n");
}
void BFS1(ALGraph *G,int u)
{
	int i;
	int qu[MAX];
	int front,rear;
	ArcNode *p;
	front=rear=0;
	rear++;
	qu[rear]=u;
	for (i=0;i<G->n;i++) 
	visit[i]=0;		//顶点访问标志均置成0
    visit[u]=1;
	printf("%4d",u);
	while(front!=rear)
	{
		front++;
		i=qu[front];
		p=G->adjlist[i].firstarc;
		while(p)
		{
			if(visit[p->adjvex]==0)
			{
				rear++;
				qu[rear]=p->adjvex;
				visit[p->adjvex]=1;
				printf("%4d",p->adjvex);
			}
			p=p->nextarc;
		}
	}
}
void ppath(int path[][7],int i,int j)
{
	int k;
	k=path[i][j];
	if(k==-1)
		return;
	ppath(path,i,k);
	printf("%3d",k);
	ppath(path,k,j);
}
void DisPath(int A[][7],int path[][7],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				printf("%d到%d的距离为:%d   路径为: ",i,j,A[i][j]);
				printf("%3d",i);
				ppath(path,i,j);
				printf("%3d\n",j);
			}
		}
	}
}
void floyd(MGraph g)
{
	int i,j,k;
	int A[7][7],path[7][7];
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			A[i][j]=g.edges[i][j];
			path[i][j]=-1;
		}
	}
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			for(k=0;k<g.n;k++)
			{
				if(A[i][k]+A[k][j]<A[i][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	DisPath(A,path,g.n);
}
void DisPath(int dist[],int path[],int u,int n)
{
	int i,k;
	printf("path:\n");
	for(i=0;i<n;i++)
		printf("%3d",path[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(i!=u)
		{
			printf("%d到%d的最短距离为:%d    ",u,i,dist[i]);
			printf("路径为:");
			printf("%3d",i);
			k=path[i];
			while(k!=u)
			{
				printf("%3d",k);
				k=path[k];
			}
			printf("%3d\n",u);
		}
	}

}
void Dijkstra(MGraph g,int u)
{
	int dist[MAX],path[MAX];
	int i,j,min,k;
	for(i=0;i<g.n;i++)
	{
		dist[i]=g.edges[u][i];
		path[i]=u;
		visit[i]=0;
	}
	visit[u]=1;
	for(i=1;i<g.n;i++)
	{
		min=INF;
		for(j=0;j<g.n;j++)
		{
			if(visit[j]==0&&dist[j]<min)
			{
				min=dist[j];
				k=j;
			}
		}
		visit[k]=1;
		for(j=0;j<g.n;j++)
		{
			if(visit[j]==0&&min+g.edges[k][j]<dist[j])
			{
				dist[j]=min+g.edges[k][j];
				path[j]=k;
			}
		}
	}
	DisPath(dist,path,u,g.n);
}
void Prim(MGraph g,int v)
{
	int i,j,k,min;
	int lowcost[MAX],closet[MAX];
	for(i=0;i<g.n;i++)
	{
		lowcost[i]=g.edges[v][i];
		closet[i]=v;
	}
	for(i=1;i<g.n;i++)
	{
		min=INF;
		for(j=0;j<g.n;j++)
		{
			if(lowcost[j]!=0&&lowcost[j]!=INF)
			{
				if(lowcost[j]<min)
				{
					k=j;
					min=lowcost[j];
				}
			}
		}
		printf("边(%d,%d)的权值%d\n",closet[k],k,lowcost[k]);
		lowcost[k]=0;
		for(j=0;j<g.n;j++)
		{
			if(j!=k&&g.edges[k][j]<lowcost[j])
			{
				closet[j]=k;
				lowcost[j]=g.edges[k][j];
			}
		}
	}
}
void SortEdge(MGraph g,Edge E[])
{
	int i,j,k=0;
	Edge temp;
	for(i=0;i<g.n;i++)
	{
       for(j=0;j<g.n;j++)
	   {
		   if(g.edges[i][j]!=0&&g.edges[i][j]<INF)
		   {
			   E[k].i=i;
			   E[k].j=j;
			   E[k].weight=g.edges[i][j];
			   k++;
		   }
	   }
	}
	for(i=1;i<k;i++)
	{
       j=i-1;
	   temp=E[i];
	   while(j>=0&&E[j].weight>temp.weight)
	   {
		   E[j+1]=E[j];
		   j--;
	   }
	   E[j+1]=temp;
	}
}
void Kruskal(Edge E[],int n,int e)
{
	int i,k=1,j=0,sn1,sn2;
	int vset[MAX];
	for(i=0;i<n;i++)
		vset[i]=i;
	for(k=1;k<n;i++)
	{
		sn1=vset[E[j].i];
		sn2=vset[E[j].j];
		if(sn1!=sn2)
		{
			k++;
			printf("(%d,%d)  ",E[j].i,E[j].j);
			for(i=0;i<n;i++)
			{
				if(vset[i]==sn2)
					vset[i]=sn1;
			}
		}
		j++;
	}
}
