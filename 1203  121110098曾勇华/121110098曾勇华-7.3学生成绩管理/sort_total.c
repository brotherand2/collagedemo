# include<stdio.h>
# include"student.h"
void insertsort(student* a[], int n)//插入排序，a为要排序原数组，n为要排序的个数
{
	student *insertnode;//要插入的值；
	int i, j;
	for (i = 1; i<n; i++)//数组中第1个元素不变分别将第2个到最后一个插入数组中
	{
		insertnode = a[i];//要插入的值为数组下标i对应的值
		j = i - 1;//j为前驱，当要插入的值比前a[j]小时，不用移动，或 则j往前移，插入的值继续跟前面一个比较
		while (j >= 0 && insertnode->score[3]>a[j]->score[3])//找适当的位置插入
		{
			a[j + 1] = a[j];//要插入的值比前a[j]大时，将j下标的值往后挪
			j--;//j往前移，插入的值继续跟前面一个比较
		}
		a[j + 1] = insertnode;//这时退出了循环若j=-1,说明要插入的值比前面的值都大，插在开头位置
		//若j>=0,说明insertnode>a[j],这时要插入的值比j下标的值小，插在j下标后面的哪个位置
	}
}
void sort_total(int *count)//按总分递减排序插入排序
{
	int i,j;
	student *temp;
	insertsort(stu, *count);
}