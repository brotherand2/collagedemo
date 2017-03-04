# include<stdio.h>
# include"student.h"
void sort_aver(int *count)//按平均分递减排序
{
	int i,j,k;
	float max;
	student temp;
	for(i=0;i<*count-1;i++)//选择排序
	{
		k=i;
		
		for(j=i+1;j<*count;j++)
		{
			max=stu[k].score[4];
			if(stu[j].score[4]>max)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=stu[i];
			stu[i]=stu[k];
			stu[k]=temp;
		}
	}

}