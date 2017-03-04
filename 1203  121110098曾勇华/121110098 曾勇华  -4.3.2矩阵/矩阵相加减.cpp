/*
   ===============================================
      矩阵相加减
	  增加功能：
	  1、菜单模式，可有选择多次查询；
	  2、用	while(getchar()!='\n')
			;
		来过滤非数字的字符，解决不小心输入字母列循环的问题
	 3、通过char ch 字符，判断ch是'+'还是'-'进行选择，将矩阵相加函数与矩阵相减函数合并
   ===============================================
 */
# include<stdio.h>
# define m 6
# define n 8
# define max 50
typedef struct
{
	int i;//横坐标
	int j;//纵坐标
	int d;//值
}TupNode;//三元组节点
typedef struct
{
	int row;//行
	int col;//列
	int num;//三元组的个数
	TupNode data[50];
}TSMatrix;
void CreateMat(TSMatrix &a,int b[][n])//创造矩阵的三元组
{
	int i,j,k=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i][j])
			{
				a.data[k].i=i;
				a.data[k].j=j;
				a.data[k].d=b[i][j];
				k++;
			}
		}
	}
	a.row=m;
	a.col=n;
	a.num=k;
}
void TranMat(TSMatrix a,TSMatrix &c)
{
	int i;
	for(i=0;i<a.num;i++)
	{
		c.data[i].i=a.data[i].j;
		c.data[i].j=a.data[i].i;
		c.data[i].d=a.data[i].d;                                  
	}
	c.num=a.num;
	c.col=a.row;
	c.row=a.col;
}
void DispMat(TSMatrix a)//输出三元组
{
	int i;
	printf("%4d%4d%4d\n",a.row,a.col,a.num);
    printf("----------------------\n");
	for(i=0;i<a.num;i++)
	{
		printf("%4d%4d%4d\n",a.data[i].i,a.data[i].j,a.data[i].d);
	}
}
void DispRect(TSMatrix a)//输出矩阵
{
	int i,j;
	int rect[m][n]={0};
	for(i=0;i<a.num;i++)
		rect[a.data[i].i][a.data[i].j]=a.data[i].d;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d   ",rect[i][j]);
		printf("\n");
	}
}
void AddOrSubMat(TSMatrix a,TSMatrix b,TSMatrix &c,char ch)//矩阵相加、相减
{
	int k=0,i=0,j=0,s;
	int sign;//符号
	switch(ch)
	{
	case '+':sign=1;break;
	case '-':sign=-1;break;
	default:printf("符号不正确\n");return;
	}
	while(i<a.num&&j<b.num)
	{
         if(a.data[i].i<b.data[j].i)
		 {
			 c.data[k].i=a.data[i].i;
			 c.data[k].j=a.data[i].j;
			 c.data[k].d=a.data[i].d;
			 k++;
			 i++;
		 }
		 else
		 {
			 if(a.data[i].i>b.data[j].i)
			 {
				 c.data[k].i=b.data[j].i;
				 c.data[k].j=b.data[j].j;
				 c.data[k].d=b.data[j].d*sign;
				 k++;
				 j++;
			 }
			 else
			 {
				 if(a.data[i].j<b.data[j].j)
				 {
					 c.data[k].i=a.data[i].i;
					 c.data[k].j=a.data[i].j;
					 c.data[k].d=a.data[i].d;
					 k++;
					 i++;
				 }
				 else
				 {
					 if(a.data[i].j>b.data[j].j)
					 {
						 c.data[k].i=b.data[j].i;
						 c.data[k].j=b.data[j].j;
						 c.data[k].d=b.data[j].d*sign;
						 k++;
						 j++;
					 }
					 else
					 {
						 if(ch=='+')
						 s=a.data[i].d+b.data[j].d;
						 else
							s=a.data[i].d-b.data[j].d;
						 if(s)
						 {
							 c.data[k].i=a.data[i].i;
							 c.data[k].j=a.data[i].j;
							 c.data[k].d=s;
							 k++;
						 }
							 i++;
							 j++;
					 }
				 }
			 }
		 }
	}
	while(i<a.num)
	{
		 c.data[k].i=a.data[i].i;
		 c.data[k].j=a.data[i].j;
		 c.data[k].d=a.data[i].d;
		 k++;
		 i++;
	}
	while(j<b.num)
	{
		 c.data[k].i=b.data[j].i;
		 c.data[k].j=b.data[j].j;
		 c.data[k].d=b.data[j].d*sign;
		 k++;
		 j++;
	}
	c.row=m;
	c.col=n;
	c.num=k;
}
void boot()//主菜单
{
    printf("       ┏━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("       ┃   <0>------(退出)Exit                  ┃\n");
	printf("       ┃   <1>------(创建稀疏矩阵)CREATE        ┃\n");
	printf("       ┃   <2>------(矩阵相加)ADD               ┃\n");
	printf("       ┃   <3>------(矩阵相减)SUB               ┃\n");
	printf("       ┃   <4>------(显示)SHOW                  ┃\n");
	printf("       ┗━━━━━━━━━━━━━━━━━━━━┛\n");
}
void main()
{
	TSMatrix a,b,c;//三元组
	bool isCreate=false;//是否创建稀疏矩阵
	bool flag=true;//循环标志
	int a1[m][n]={
		{0,0,3,0,0,0,0,0},
		{0,0,0,0,0,0,5,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,7,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,9,0,0,0,0,0,0}};
	int b1[m][n]={
		{0,2,0,0,0,0,0,0},
		{0,0,0,4,0,0,0,0},
		{0,0,0,0,0,6,0,0},
		{0,0,0,0,8,0,0,0},
		{0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0}};
	int number;
	printf("121110098   曾勇华   矩阵相加减\n");
	while(flag)
	{
		boot();
		number=-1;//初始化
		printf("输入你的选择(0~6):");
		scanf("%d",&number);//若输入abc错误，不能读取,则返回number原地址垃圾值，若输入6abc则abc被过滤
		while(getchar()!='\n')//过滤非数字的字符
			;
		switch(number)
		{
		case 0:
			flag=false;
			break;
		case 1:
				CreateMat(a,a1);
          	    CreateMat(b,b1);
                printf("稀疏矩阵创建成功\n");
				isCreate=true;
				break;
		case 2:
				AddOrSubMat(a,b,c,'+');
				printf("a的矩阵:\n");
				DispRect(a);
				printf("b的矩阵:\n");
				DispRect(b);
				printf("a+b的矩阵:\n");
	            DispRect(c);
				printf("a+b的三元组:\n");
	            DispMat(c);
                break;
		case 3:
				AddOrSubMat(a,b,c,'-');
				printf("a的矩阵:\n");
				DispRect(a);
				printf("b的矩阵:\n");
				DispRect(b);
				printf("a-b的矩阵:\n");
	            DispRect(c);
				printf("a-b的三元组:\n");
	            DispMat(c);
                break;
		case 4:
			if(isCreate)
			{
				printf("a的矩阵:\n");
				DispRect(a);
				printf("b的矩阵:\n");
				DispRect(b);
				printf("a的三元组:\n");
				DispMat(a);
				printf("b的三元组:\n");
				DispMat(b);
			}
			else
				printf("未创建稀疏矩阵，输入1创建稀疏矩阵\n");
			break;
		default:
			printf("输入错误，不能输入非数字字符，输入0~5！！！\n");
			break;
		}
	}
}
/*
   输出结果：
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):a
输入错误，不能输入非数字字符，输入0~5！！！
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):8
输入错误，不能输入非数字字符，输入0~5！！！
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):b6
输入错误，不能输入非数字字符，输入0~5！！！
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):76
输入错误，不能输入非数字字符，输入0~5！！！
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):4
未创建稀疏矩阵，输入1创建稀疏矩阵
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):4
未创建稀疏矩阵，输入1创建稀疏矩阵
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):1
稀疏矩阵创建成功
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):4
a的矩阵:
0   0   3   0   0   0   0   0
0   0   0   0   0   0   5   0
0   0   0   0   0   0   0   0
0   0   0   0   7   0   0   0
0   0   0   0   0   0   0   0
0   9   0   0   0   0   0   0
b的矩阵:
0   2   0   0   0   0   0   0
0   0   0   4   0   0   0   0
0   0   0   0   0   6   0   0
0   0   0   0   8   0   0   0
0   0   1   0   0   0   0   0
0   0   0   0   0   0   0   0
a的三元组:
   6   8   4
----------------------
   0   2   3
   1   6   5
   3   4   7
   5   1   9
b的三元组:
   6   8   5
----------------------
   0   1   2
   1   3   4
   2   5   6
   3   4   8
   4   2   1
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):2
a的矩阵:
0   0   3   0   0   0   0   0
0   0   0   0   0   0   5   0
0   0   0   0   0   0   0   0
0   0   0   0   7   0   0   0
0   0   0   0   0   0   0   0
0   9   0   0   0   0   0   0
b的矩阵:
0   2   0   0   0   0   0   0
0   0   0   4   0   0   0   0
0   0   0   0   0   6   0   0
0   0   0   0   8   0   0   0
0   0   1   0   0   0   0   0
0   0   0   0   0   0   0   0
a+b的矩阵:
0   2   3   0   0   0   0   0
0   0   0   4   0   0   5   0
0   0   0   0   0   6   0   0
0   0   0   0   15   0   0   0
0   0   1   0   0   0   0   0
0   9   0   0   0   0   0   0
a+b的三元组:
   6   8   8
----------------------
   0   1   2
   0   2   3
   1   3   4
   1   6   5
   2   5   6
   3   4  15
   4   2   1
   5   1   9
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):3
a的矩阵:
0   0   3   0   0   0   0   0
0   0   0   0   0   0   5   0
0   0   0   0   0   0   0   0
0   0   0   0   7   0   0   0
0   0   0   0   0   0   0   0
0   9   0   0   0   0   0   0
b的矩阵:
0   2   0   0   0   0   0   0
0   0   0   4   0   0   0   0
0   0   0   0   0   6   0   0
0   0   0   0   8   0   0   0
0   0   1   0   0   0   0   0
0   0   0   0   0   0   0   0
a-b的矩阵:
0   -2   3   0   0   0   0   0
0   0   0   -4   0   0   5   0
0   0   0   0   0   -6   0   0
0   0   0   0   -1   0   0   0
0   0   -1   0   0   0   0   0
0   9   0   0   0   0   0   0
a-b的三元组:
   6   8   8
----------------------
   0   1  -2
   0   2   3
   1   3  -4
   1   6   5
   2   5  -6
   3   4  -1
   4   2  -1
   5   1   9
       ┏━━━━━━━━━━━━━━━━━━━━┓
       ┃   <0>------(退出)Exit                  ┃
       ┃   <1>------(创建稀疏矩阵)CREATE        ┃
       ┃   <2>------(矩阵相加)ADD               ┃
       ┃   <3>------(矩阵相减)SUB               ┃
       ┃   <4>------(显示)SHOW                  ┃
       ┗━━━━━━━━━━━━━━━━━━━━┛
输入你的选择(0~6):0
Press any key to continue
  */