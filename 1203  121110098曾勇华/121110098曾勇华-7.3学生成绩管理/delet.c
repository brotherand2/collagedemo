# include<stdio.h>
# include"student.h"
# include<string.h>
void delet(int *count)//删除
{
	
	char name[10];
	int flag,found,i,j;
	
	while(1)
	{
		if(*count<1)
		{
			PR("已无数据可删！\n");
			return;
		}
		found=0;
		PR("输入要删除数据的学生姓名:\n");
		SC(S,name);
		for(i=0;i<*count;i++)
		{
			if(strcmp(stu[i]->name,name)==0)
			{
				found=1;
				for(j=i;j<*count;j++)
					stu[j]=stu[j+1];
				(*count)--;
				i--;
					PR("%s信息已删除!\n",name);

			}
		}
		if(!found)
			PR("无该学生！\n");
		show(count);
        PR("输入任意键继续删除，输入1结束:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//过滤非数字字符
				;
		if(flag==1)
			break;
	}
}