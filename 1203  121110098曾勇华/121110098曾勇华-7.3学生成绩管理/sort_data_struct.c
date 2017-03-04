# include<stdio.h>
# include"student.h"
void sort_data_struct(int *count)//按数据结构递减排序
{
	int i,j;
	student *temp;
	int flag=1,n=*count;
	for(i=0;i<n-1&&flag;i++)//冒泡排序
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(stu[j]->score[0]<stu[j+1]->score[0])
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
				flag=1;
			}
		}
	}
}