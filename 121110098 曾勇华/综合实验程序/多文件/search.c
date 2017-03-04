# include<stdio.h>
# include"student.h"
void search(int *count)//查询
{
	int num,flag=1;
	if(*count<1)
		{
			PR("无数据！\n");
			return;
		}

	while(flag)
	{
		search_boot();
		PR("输入你的选择(0~7):");
		SC(D,&num);
		while(getchar()!=NL)//过滤非数字的字符
			;

		switch(num)
		{
		   case 0:flag=0;break;
		   case 1:search_num(count);break;
		   case 2:search_name(count);break;
		   case 3:search_score(count,0);break;
		   case 4:search_score(count,1);break;
		   case 5:search_score(count,2);break;
		   case 6:search_score(count,3);break;
		   case 7:search_score(count,4);break;
		   default:PR("输入错误!\n");break;

		}

	}

}