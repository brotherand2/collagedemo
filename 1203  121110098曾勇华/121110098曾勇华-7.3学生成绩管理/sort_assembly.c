# include<stdio.h>
# include"student.h"
student *temp;
void createheap( int i, int n)//i为父节点下标，n为进行建小顶堆的元素个数
{
	int j = i * 2;//j为你节点的左孩子
	if (j<n&&stu[j-1]->score[1]>stu[(j-1)+1]->score[1])//或j<n说明有右孩子，j==n说明只有左孩子，不用进行孩子之间的小小比较
		j++;//如果右孩子比左孩子小，将j置于右孩子
	if (stu[i-1]->score[1]>stu[j-1]->score[1])//如果父节点比最小孩子大
	{
		temp = stu[i-1];//父节点与孩子节点交换，将孩子节点中最小数往上移
		stu[i-1] = stu[j-1];
		stu[j-1] = temp;
	}
}
void heapsort(int n)
{
	int i, j;
	for (j = n; j >= 2; j--)//依次从n个元素到2个元素建小顶堆
	{//每进行一次小顶堆排序，将最后一个元素（最小值）抛出去，剩下的元素再进行小顶堆排序，总元素个数少1个，所以j--
		for (i = j / 2; i >= 1; i--)//建小顶堆
			//数据往上推，最小数被推到树的根节点，最小点，j/2为最后一个节点的父节点
			createheap(i, j);//从最后一个父亲节点到第一个父节点（即根节点）与两个孩子比较
		//孩子若小于父节点就会被往上推，相当于冒泡排序，根节点最后成为最小的值
		temp = stu[0];//根节点为最小值与最后一个元素交换
		stu[0] = stu[j-1];
		stu[j-1] = temp;//stu[0]作为交换介质
	}
}
void sort_assembly(int *count)//按汇编语言递减排序堆排序
{
	heapsort(*count);
}