# include"student.h"
# include<stdio.h>
# include<stdlib.h>//为使用exit()函数提供原型
void myRealloc(int n)//数组空间不够，重新分配新空间
{
	int i;
	if(n>addSize)//最大空间不够保存
		addSize=n*2;//所需空间数加倍
	stu=(student**)realloc(stu,addSize*sizeof(student*));
	printf("空间不足！当前空间为:%d,现正在再分配空间中...\n",studentSize);
	printf("空间分配完成，当前拥有空间有%d\n",addSize);
	for(i=studentSize;i<addSize;i++)//为增加的学生指针分配学生空间
		stu[i]=(student*)malloc(sizeof(student));
	studentSize=addSize;//将当前空间扩大为addSize
	addSize*=2;//下一次若空间不够，扩增后数量
}