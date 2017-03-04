# include<stdlib.h>//为使用exit()函数提供原型
# include<stdio.h>
# include"student.h"
void writefile(int *count)//将数据写入student.txt文件
{
	int i;
	FILE *fp;//文件指针
	if((fp=fopen("student.txt","w"))==NULL)//创建student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
	for(i=0;i<*count;i++)
	{
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			stu[i].num,' ',stu[i].name,' ',stu[i].sex,' ',stu[i].score[0],' ',
			stu[i].score[1],' ',stu[i].score[2],' ',stu[i].score[3],' ',stu[i].score[4],NL);

	}
	fclose(fp);

}