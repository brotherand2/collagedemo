# include<stdio.h>
# include"student.h"
void sort_total(int *count)//°´×Ü·Öµİ¼õÅÅĞò
{
	int i,j;
	student temp;
	for(i=0;i<*count-1;i++)//Ã°ÅİÅÅĞò
	{
		for(j=0;j<*count-1-i;j++)
		{
			if(stu[j].score[3]<stu[j+1].score[3])
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}

		}
	}
}