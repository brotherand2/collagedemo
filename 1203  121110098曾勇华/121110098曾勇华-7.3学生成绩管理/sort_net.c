# include<stdio.h>
# include"student.h"
void ShellSort( int n)
{
	int i, j;
	student* temp;
	int gap = n / 2;
	while (gap)
	{
		for (i = gap; i<n; i++)
		{
			j = i - gap;
			temp = stu[i];
			while (j >= 0 && temp->score[2]>stu[j]->score[2])
			{
				stu[j + gap] = stu[j];
				j -= gap;
			}
			stu[j + gap] = temp;
		}
		gap /= 2;
	}
}
void sort_net(int *count)//°´ÍøÂç»ù´¡·ÖÊıµİ¼õÅÅĞòÏ£¶ûÅÅĞò
{
	ShellSort(*count);
}