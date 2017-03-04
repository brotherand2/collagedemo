# include<stdio.h>
# include"student.h"
void search_num(int *count)//按学号查询
{
	int i,j,num,found=0;
	PR("输入你要查询的学号:");
	SC(D,&num);
	while(getchar()!=NL)//过滤非数字的字符
	;

	for(i=0;i<*count;i++)
	{
		if(num==stu[i].num)
		{
			found=1;
			PR("姓名：%s\n",stu[i].name);
			PR("学号:%d\n",stu[i].num);
			PR("姓别：%s\n",stu[i].sex);
			PR("C语言     高等数学  电工基础  总分      平均分\n");
			for(j=0;j<5;j++)
    			PR("%-10.2f",stu[i].score[j]); 
			PR("\n");
		}
	}
	if(!found)
		PR("找不到该学号!\n");

}