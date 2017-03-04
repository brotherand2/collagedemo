# include<stdio.h>
# include"student.h"
void sort_num(int *count)//∞¥—ß∫≈µ›ºı≈≈–Ú
{
	int i,j;
	student temp;
	for(i=0;i<*count-1;i++)//√∞≈›≈≈–Ú
	{
		for(j=i+1;j<*count;j++)
		{
			if(stu[i].num<stu[j].num)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}

		}
	}
}