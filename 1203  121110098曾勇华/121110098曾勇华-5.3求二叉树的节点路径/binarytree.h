# include<stdio.h>
# include<malloc.h>
# define MAX 100
typedef char ElemType;
typedef struct BTNode
{
	ElemType data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

void CreateBTNode(BTNode *&b,char *s)
{
	BTNode *st[MAX],*p;
	int j=0,top=-1;
	int k;
	b=NULL;
	char ch=s[j];
	while(ch!='\0')
	{
		switch(ch)
		{
			case '(':top++;
				st[top]=p;
				k=1;
				break;
			case ')':top--;
				break;
			case ',':
				k=2;
				break;
			default:
				p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;
				p->lchild=NULL;
				p->rchild=NULL;
				if(!b)
					b=p;
				else
				{
					switch(k)
					{
					case 1:st[top]->lchild=p;break;
					case 2:st[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=s[j];
	}
}

void DispBTNode(BTNode *b)
{
	if(b)
	{
		printf("%c",b->data);
		if(b->lchild||b->rchild)
		{
			printf("(");
			DispBTNode(b->lchild);
			if(b->rchild)
			{
				printf(",");
				DispBTNode(b->rchild);
			}
			printf(")");
		}
	}
}
BTNode *FindNode(BTNode *b,ElemType e)
{
	BTNode *p;
    if(b)
	{
		if(b->data==e)
			return b;
		else
		{
			p=FindNode(b->lchild,e);
			if(p)
				return p;
			else
				return FindNode(b->rchild,e);
		}
	}
	else
		return NULL;
}
BTNode *LchildNode(BTNode *p)
{
	return p->lchild;
}
BTNode *RchildNode(BTNode *p)
{
	return p->rchild;
}
int BTNodeDepth(BTNode *b)
{
	int max1,max2;
	if(b)
	{
		max1=BTNodeDepth(b->lchild);
		max2=BTNodeDepth(b->rchild);
		return max1>max2?max1+1:max2+1;
	}
	else
		return 0;
}
int BTNodeWidth(BTNode *b)
{
	int i,max=0,n=0;
	BTNode *p;
	struct
	{
		int lno;
		struct BTNode *p;
	}Qu[MAX];
	int front,rear,level=1;
	front=rear=0;
	if(b)
	{
		rear++;
		Qu[rear].p=b;
		Qu[rear].lno=1;
		while(front!=rear)
		{
			front++;
			p=Qu[front].p;
			if(p->lchild)
			{
				rear++;
				Qu[rear].p=p->lchild;
				Qu[rear].lno=Qu[front].lno+1;
			}
			if(p->rchild)
			{
				rear++;
				Qu[rear].p=p->rchild;
				Qu[rear].lno=Qu[front].lno+1;
			}
		}
		i=1;
		while(i<=rear)
		{
			n=0;
			while(i<=rear&&Qu[i].lno==level)
			{
				i++;
				n++;
			}
			level=Qu[i].lno;
			if(n>max)
				max=n;
		}
		return max;
	}
	else
		return 0;
}
int Nodes(BTNode *b)
{
	if(b)
	{
		return Nodes(b->lchild)+Nodes(b->rchild)+1;
	}
	else
	return 0;
}
int LeafNodes(BTNode *b)
{
	if(b)
	{
		if(!b->lchild&&!b->rchild)
			return 1;
		else
			return LeafNodes(b->lchild)+LeafNodes(b->rchild);
	}
	else
		return 0;
}
void DestroyBTNode(BTNode *b)
{
	if(b)
	{
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}
void AllPath(BTNode *b,BTNode *path[],int n)
{
	int i;
	if(b)
	{
		n++;
		path[n]=b;
		if(!b->lchild&&!b->rchild)
		{
			printf("%c到跟节点的正路径:",b->data);
			for(i=0;i<=n;i++)
				printf("%c",path[i]->data);
			printf("\n");
		}
		AllPath(b->lchild,path,n);
		AllPath(b->rchild,path,n);
	}
}
void NodePath(BTNode *b,BTNode *path[],int n,char ch)
{
	int i;
	if(b)
	{
		n++;
		path[n]=b;
		if(b->data==ch)
		{
			printf("%c路径:",b->data);
			for(i=0;i<=n;i++)
				printf("%c",path[i]->data);
			printf("\n");
		}
		NodePath(b->lchild,path,n,ch);
		NodePath(b->rchild,path,n,ch);
	}
}
void LongPath(BTNode *b,BTNode *path[],BTNode *longpath[],int n,int &max)
{
	int i;
	if(b)
	{
		n++;
		path[n]=b;
		if(!b->lchild&&!b->rchild)
		{
            if(n>max)
				max=n;
			for(i=0;i<=n;i++)
				longpath[i]=path[i];
		}
		LongPath(b->lchild,path,longpath,n,max);
		LongPath(b->rchild,path,longpath,n,max);
	}
}
void InOrder(BTNode *b)
{
	BTNode *st[MAX],*p;
	int top=-1;
	if(b)
	{
		p=b;
		while(top>-1||p)
		{
			while(p)
			{
				top++;
				st[top]=p;
				p=p->lchild;
			}
			if(top>-1)
			{
			  p=st[top];
			  top--;
  			  printf("%c",p->data);
				p=p->rchild;
			  
			}
		}

	}
}
void PreOrder(BTNode *b)
{
	BTNode *st[MAX],*p;
	int top=-1;
	if(b)
	{
		p=b;
		while(top>-1||p)
		{
			while(p)
			{
				printf("%c",p->data);
				top++;
				st[top]=p;
				p=p->lchild;
			}
			if(top>-1)
            {
				p=st[top];
				top--;
				p=p->rchild;
			}
		}
	}
}
void PostOrder(BTNode *b)
{
	BTNode *st[MAX],*p=b,*q;
	int top=-1;
	int find;
	if(p)
	{
		do
		{
			while(p)
			{
				top++;
				st[top]=p;
				p=p->lchild;
			}
			q=NULL;
			find=1;
			while(top>-1&&find)
			{
				p=st[top];
				if(p->rchild==q)
				{
					printf("%c",p->data);
					q=p;
					top--;
				}
				else
				{
					p=p->rchild;
					find=0;
				}
					
			}
		}while(top>-1);
	}
}
void LevelOrder(BTNode *b)
{
	int front,rear;
	BTNode *qu[MAX],*p=b;
	front=rear=0;
	if(b)
	{
		rear++;
		qu[rear]=p;
		while(front!=rear)
		{
			front++;
			p=qu[front];
			printf("%c",p->data);
			if(p->lchild)
			{
				rear++;
				qu[rear]=p->lchild;
			}
			if(p->rchild)
			{
				rear++;
				qu[rear]=p->rchild;
			}
		}
	}
}