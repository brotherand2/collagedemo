/*
    N皇后总题
	书上用递归实现，改了一下用栈来保存路径，找到或找不到进行回朔，增加功能：
	1、用动态数组实现，可以输出任意皇后问题的结果；
	2、因为8皇后之后，黑屏上只显示一部分，不能显示全部，所以增加文件功能，
	顺便将结果输出在文件，可在文件中查看

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
char name[20];//多少皇后，例如名字“8皇后";
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
	itoa(n,name,10);//将整数n转换成10进制数的字符串
	strcat(name,"皇后.txt");//皇后.txt字符串接在字符串n后面
	//printf("begin write file0\n");
	
	if((fp=fopen(name,"a+"))==NULL)
		return;
	//printf("begin write file1\n");

	fprintf(fp,"%s%d%s","第",count,"个解\n");
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
bool place(int row,int col)//第row行col列是否可放置
{
	int n;
	int i,j;
	if(row==1)//第一行可以随便放置
		return true;
	for(n=1;n<=row-1;n++)//判断从第1行到row-1行的皇后是否是第row放置的冲突
	{
        i=n;
		j=stack[n];
		if(col==j||abs(j-col)==abs(i-row))//如果在同一列，或互为对角线
			return false;
	}
	return true;
}
void queen(int n)
{
	int j;
	bool find;
    top++;//第一行进栈
	stack[top]=0;//进行初始化为第0列
    while(top>0)
	{
		find=false;
		for(j=stack[top]+1;j<=n;j++)//从下一列开始到最后一列看是否可放置
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
				printf("第%d个解:\n",count);
				DispQueen(n);
				WriteFile(n);
			}
			else
			{
				top++;
	            stack[top]=0;//进行初始化为第0列
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
	bool flag=true;//继续标记
	printf("121110098   曾勇华   N皇后问题\n");
	while(flag)
	{
		count=0;
		top=0;
		printf("你要求多少皇后问题:");
		scanf("%d",&n);
		a=(int **)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			a[i]=(int *)malloc(sizeof(int)*n);//忘写了n，一直找不到错误
		queen(n);
		Destroy(a,n);
		printf("继续与否(输入1继续):");
		scanf("%d",&choice);
		if(choice!=1)
			flag=false;/**/
	}

}
/*
运行结果如下：

你要求多少皇后问题:4
第1个解:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
第2个解:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
继续与否(输入1继续):1
你要求多少皇后问题:5
第1个解:
1 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0
0 0 0 1 0
第2个解:
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
第3个解:
0 1 0 0 0
0 0 0 1 0
1 0 0 0 0
0 0 1 0 0
0 0 0 0 1
第4个解:
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
第5个解:
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
第6个解:
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0
0 0 0 1 0
1 0 0 0 0
第7个解:
0 0 0 1 0
1 0 0 0 0
0 0 1 0 0
0 0 0 0 1
0 1 0 0 0
第8个解:
0 0 0 1 0
0 1 0 0 0
0 0 0 0 1
0 0 1 0 0
1 0 0 0 0
第9个解:
0 0 0 0 1
0 1 0 0 0
0 0 0 1 0
1 0 0 0 0
0 0 1 0 0
第10个解:
0 0 0 0 1
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 1 0 0 0
继续与否(输入1继续):

*/