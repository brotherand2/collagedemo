# include<stdio.h>
# include"student.h"
void insertsort(student* a[], int n)//��������aΪҪ����ԭ���飬nΪҪ����ĸ���
{
	student *insertnode;//Ҫ�����ֵ��
	int i, j;
	for (i = 1; i<n; i++)//�����е�1��Ԫ�ز���ֱ𽫵�2�������һ������������
	{
		insertnode = a[i];//Ҫ�����ֵΪ�����±�i��Ӧ��ֵ
		j = i - 1;//jΪǰ������Ҫ�����ֵ��ǰa[j]Сʱ�������ƶ����� ��j��ǰ�ƣ������ֵ������ǰ��һ���Ƚ�
		while (j >= 0 && insertnode->score[3]>a[j]->score[3])//���ʵ���λ�ò���
		{
			a[j + 1] = a[j];//Ҫ�����ֵ��ǰa[j]��ʱ����j�±��ֵ����Ų
			j--;//j��ǰ�ƣ������ֵ������ǰ��һ���Ƚ�
		}
		a[j + 1] = insertnode;//��ʱ�˳���ѭ����j=-1,˵��Ҫ�����ֵ��ǰ���ֵ���󣬲��ڿ�ͷλ��
		//��j>=0,˵��insertnode>a[j],��ʱҪ�����ֵ��j�±��ֵС������j�±������ĸ�λ��
	}
}
void sort_total(int *count)//���ֵܷݼ������������
{
	int i,j;
	student *temp;
	insertsort(stu, *count);
}