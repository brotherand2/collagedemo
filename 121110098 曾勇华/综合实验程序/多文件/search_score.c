# include<stdio.h>
# include"student.h"
void search_score(int *count,int n)//按成绩查询
{
    char score_name[5][10]={"C语言","高等数学","电工基础","总分","平均分"};
	float score;
	int i,j,found=0;

	PR("输入你要查询的%s成绩：",score_name[n]);
	SC(F,&score);
	for(i=0;i<*count;i++)
	{
		if(score==stu[i].score[n])
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
		PR("找不到该%s成绩！!\n",score_name[n]);


}

