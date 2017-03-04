# include<string.h>//为使用strcmp()字符串函数
# include<stdio.h>
# include"student.h"
void sort_name(int *count)//按姓名递减排序

{
	int i,j;
	student temp;
	for(i=0;i<*count-1;i++)//冒泡排序
	{
		for(j=0;j<*count-1-i;j++)
		{
			if(strcmp(stu[j].name,stu[j+1].name)<0)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}

		}
	}
}