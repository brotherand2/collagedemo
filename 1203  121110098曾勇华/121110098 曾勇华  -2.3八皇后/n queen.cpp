/*
    N�ʺ�����
	�����õݹ�ʵ�֣�����һ����ջ������·�����ҵ����Ҳ������л�˷�����ӹ��ܣ�
	1���ö�̬����ʵ�֣������������ʺ�����Ľ����
	2����Ϊ8�ʺ�֮�󣬺�����ֻ��ʾһ���֣�������ʾȫ�������������ļ����ܣ�
	˳�㽫���������ļ��������ļ��в鿴

*/
# include<stdio.h>
# include<math.h>
# include<malloc.h>
# include<string.h>
# include<stdlib.h>
# define MAX 100
int stack[MAX];
int count=0;
int **a;
int top=0;
char name[20];//���ٻʺ��������֡�8�ʺ�";
void DispQueen(int n)
{
   int i,j;
   for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		   a[i][j]=0;
	for(i=1;i<=n;i++)
		a[i-1][stack[i]-1]=1;
   for(i=0;i<n;i++)
   {
	   for(j=0;j<n;j++)
		   printf("%d ",a[i][j]);
	   printf("\n");
   }
}
void WriteFile(int n)
{
	int i,j;
	FILE *fp;
	itoa(n,name,10);//������nת����10���������ַ���
	strcat(name,"�ʺ�.txt");//�ʺ�.txt�ַ��������ַ���n����
	//printf("begin write file0\n");
	
	if((fp=fopen(name,"a+"))==NULL)
		return;
	//printf("begin write file1\n");

	fprintf(fp,"%s%d%s","��",count,"����\n");
	//printf("begin write file2\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fp,"%d  ",a[i][j]);
			/*if(a[i][j]!=0&&a[i][j]!=1)
			{
				printf("a[i][j]=%d",a[i][j]);
				getchar();
			}*/
		}
		fprintf(fp,"%s","\n");
	}
	fclose(fp);
}
bool place(int row,int col)//��row��col���Ƿ�ɷ���
{
	int n;
	int i,j;
	if(row==1)//��һ�п���������
		return true;
	for(n=1;n<=row-1;n++)//�жϴӵ�1�е�row-1�еĻʺ��Ƿ��ǵ�row���õĳ�ͻ
	{
        i=n;
		j=stack[n];
		if(col==j||abs(j-col)==abs(i-row))//�����ͬһ�У���Ϊ�Խ���
			return false;
	}
	return true;
}
void queen(int n)
{
	int j;
	bool find;
    top++;//��һ�н�ջ
	stack[top]=0;//���г�ʼ��Ϊ��0��
    while(top>0)
	{
		find=false;
		for(j=stack[top]+1;j<=n;j++)//����һ�п�ʼ�����һ�п��Ƿ�ɷ���
		{
			if(place(top,j))
			{
				stack[top]=j;
				find=true;
				break;
			}
		}
		if(!find)
			top--;
		else
		{
		    if(top==n)
			{
				count++;
				printf("��%d����:\n",count);
				DispQueen(n);
				WriteFile(n);
			}
			else
			{
				top++;
	            stack[top]=0;//���г�ʼ��Ϊ��0��
			}
		}
	}
}
void Destroy(int **a,int n)
{
	int i;
	for(i=0;i<n;i++)
		free(a[i]);
}
void main()
{
	int n,i,choice;
	bool flag=true;//�������
	printf("121110098   ���»�   N�ʺ�����\n");
	while(flag)
	{
		count=0;
		top=0;
		printf("��Ҫ����ٻʺ�����:");
		scanf("%d",&n);
		a=(int **)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			a[i]=(int *)malloc(sizeof(int)*n);//��д��n��һֱ�Ҳ�������
		queen(n);
		Destroy(a,n);
		printf("�������(����1����):");
		scanf("%d",&choice);
		if(choice!=1)
			flag=false;/**/
	}

}
/*
���н�����£�

��Ҫ����ٻʺ�����:4
��1����:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
��2����:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
�������(����1����):1
��Ҫ����ٻʺ�����:5
��1����:
1 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0
0 0 0 1 0
��2����:
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
��3����:
0 1 0 0 0
0 0 0 1 0
1 0 0 0 0
0 0 1 0 0
0 0 0 0 1
��4����:
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
��5����:
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
��6����:
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0
0 0 0 1 0
1 0 0 0 0
��7����:
0 0 0 1 0
1 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0
��8����:
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
1 0 0 0 0
��9����:
0 0 0 0 1
0 1 0 0 0
0 0 0 1 0
1 0 0 0 0
0 0 1 0 0
��10����:
0 0 0 0 1
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
�������(����1����):

*/