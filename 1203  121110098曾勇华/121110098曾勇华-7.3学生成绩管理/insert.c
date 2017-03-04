# include<stdio.h>
# include"student.h"
# include<stdlib.h>//为使用exit()函数提供原型
void insert(int *count)//插入
{
	    
		int flag;
	    student temp,*p1;//临时结构体变量
	while(1)
	{
		FILE *fp;//文件指针
		if((fp=fopen("student.txt","a"))==NULL)//向student.txt文件追加学生信息
		{
			PR("不能打开文件!\n");
			exit(0);//终止程序
		}
		p1=&temp;
	
		PR("学号:");
		SC(D,&p1->num);
		getchar();
		PR("姓名：");
		SC(S,p1->name);
		PR("性别：");
		SC(S,p1->sex);
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
		fclose(fp);
	    PR("插入成功！\n");
		readstu(count);
		show(count);
        PR("输入任意键继续，输入1结束:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//过滤非数字字符
				;
		if(flag==1)
			break;
	}
}