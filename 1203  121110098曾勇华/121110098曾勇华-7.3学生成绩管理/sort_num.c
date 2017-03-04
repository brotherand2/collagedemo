# include<stdio.h>
# include"student.h"
void quicksort(student* a[],int left,int right)//快速排序，a为要排序的数组,left，right为要排序的起始、结束位置
{
	int i=left,j=right;//i为要排序的起始位置,j为要排序的结束位置
	student* t=a[left];//t为要排序的数组的起始位置,t为特殊数，数组中除第1个元素，每个元素要跟第1个数比较
	if(left<right)//如果起始位置小于结束位置则需要排序，否则表示只有1个元素或没有元素不需要排序
	{
		while(i<j)//i<j时继续将大的往数往左移，小的数往后移
		{
			while (a[j]->num <= t->num&&i<j)
			{//直到找到比第一个数大或i,j的下标相等才停止
				j--;//不比第一个数大向左移继续寻找
			}
			a[i]=a[j];//将寻找到的这个比t大的数放到i位置，实现大的数向左移
			while (a[i]->num>=t->num&&i<j)
			{//直到找到一个比第一个数小或i,j的下标相等才停止
				i++;//比第1个数小向右移继续寻找
			}
			a[j]=a[i];//将寻找到的这个比t小的数放到j位置，实现小的数向右移

		}

		//退出循环后i=j,因为内循环的两个循环一旦i,j相等就不再移动
		a[j]=t;//这时i=j,所以或者可以a[i]=t，将第1个数放到i,j位置,这时t放到了恰当的位置，因为j遇到大于t的数，往左抛，i遇到不大于t数往右抛，
		//这样，j右边的数都不大于t，i左边的数都比t大，i,j左边的数都比t大，i,j右边的数都不大于t，t的位置就是最后排序后的位置，不会变
		quicksort(a,left,j-1);//i,j位置前的数找的恰当的位置
		quicksort(a,j+1,right);//i,j位置后的数找的恰当的位置,就排好序了

	}
}
void sort_num(int *count)//按学号递减排序
{
	quicksort(stu,0,*count-1);
}

