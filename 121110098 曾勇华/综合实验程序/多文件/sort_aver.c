# include<stdio.h>
# include"student.h"
void sort_aver(int *count)//��ƽ���ֵݼ�����
{
	int i,j,k;
	float max;
	student temp;
	for(i=0;i<*count-1;i++)//ѡ������
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