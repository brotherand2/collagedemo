# include<stdio.h>
# include"student.h"
# include<stdlib.h>//为使用exit()函数提供原型
void readstu(int *count)//用于读取文件时记学生个数
{	
	FILE *fp;//文件指针
    student *p1,*p2;
    int i=0;
	*count=0;
	if((fp=fopen("student.txt","r"))==NULL)//读取student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
    p2=p1=&stu[0];
	while(!feof(fp))//feof(fp)表示文件尾
	{
		p1=&stu[i];
		
		fscanf(fp,D S S F F F F F,
			&stu[i].num,stu[i].name,stu[i].sex,&stu[i].score[0],
			&stu[i].score[1],&stu[i].score[2],&stu[i].score[3],&stu[i].score[4]); 
		if(i>0)
		{
		p2->next=p1;
		p2=p1;
		}
        i++;
	}
	p1->next=NULL;
    *count=i-1;/*位置和内容到底有何不同呢？举个简单的例子，比如有人说“你走到火车的最后一节车箱”这就是位置。
			  而如果说“请你一直向后走，摸到铁轨结束”这就是内容。也就是说用内容来判断会“多走一节”。这就是完全依赖于
			  “while(!feof(FP)){...}”进行文件复制时，目标文档总会比源文档“多出一些”的原因。所以count要减1*/

	fclose(fp);//关闭文件指针
}