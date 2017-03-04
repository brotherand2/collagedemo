# include<string.h>//为使用strcmp()字符串函数
# include<stdio.h>
# include"student.h"
void search_name(int *count)//按姓名查询
{
	int i,j,found=0;
	char name[10];
	PR("输入你要查询的姓名:");
	SC(S,name);
	for(i=0;i<*count;i++)
	{
		if(strcmp(name,stu[i]->name)==0)
		{
			found=1;
			PR("姓名：%s\n",stu[i]->name);
			PR("学号:%d\n",stu[i]->num);
			PR("姓别：%s\n",stu[i]->sex);
			PR("数据结构   汇编语言  网络基础  总分      平均分\n");
			for(j=0;j<5;j++)
    			PR("%-10.2f",stu[i]->score[j]);
			PR("\n");
		}
	}
	if(!found)
		PR("找不到该姓名！!\n");

}
