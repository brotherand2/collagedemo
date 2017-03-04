# include<stdio.h>
# include"student.h"
# include<stdlib.h>//为使用exit()函数提供原型
void input()//重新输入所有数据
{
	int n,i;
	student *p1;
	FILE *fp;//文件指针
	if((fp=fopen("student.txt","w"))==NULL)//创建student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
    do{
		PR("你要输入多少个学生数据：");
		SC(D,&n);
		while(getchar()!=NL)//过滤非数字的字符
			;
		if(n<1)
		{
			PR("输入错误,学生个数应为正！重新输入!\n");
		}
	}while(n<1);
    if(n>studentSize)//若空间不够，扩大空间
       myRealloc(n);
    for(i=0;i<n;i++)//输入n个学生数据
	{
	     p1=(student *)malloc(sizeof(student));//动态内存分配空间

		if(p1==NULL)
		{
			PR("空间分配失败！\n");
			return ;
		}
		PR("输入第%d个学生信息：\n学号：",i+1);
		SC(D,&p1->num);
		getchar();//接收换行符
		PR("姓名：");
		gets(p1->name);
		PR("性别：");
		gets(p1->sex);
		PR("数据结构：");
		SC(F,&p1->score[0]);
		PR("汇编语言:");
		SC(F,&p1->score[1]);
		PR("网络基础:");
		SC(F,&p1->score[2]);
		p1->score[3]=p1->score[0]+p1->score[1]+p1->score[2];//总分
		p1->score[4]=p1->score[3]/3;//平均分
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			p1->num,' ',p1->name,' ',p1->sex,' ',p1->score[0],' ',
			p1->score[1],' ',p1->score[2],' ',p1->score[3],' ',p1->score[4],NL);
		//将第i+1个学生信息输出到文件student.txt

	}
		fclose(fp);//关闭文件指针
}