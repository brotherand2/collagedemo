# include<string.h>//Ϊʹ��strcmp()�ַ�������
# include<stdio.h>
# include"student.h"
void sort_name(int *count)//�������ݼ�����

{
	int i,j;
	student temp;
	for(i=0;i<*count-1;i++)//ð������
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