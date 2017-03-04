# include<stdio.h>
# include"student.h"
void show(int *count)//显示
{
	int flag=1,i;
		if(*count<1)
		{
			PR("无数据！\n");
			return;
		}
		while(flag)
		{
			int num;
			show_boot();
			PR("输入你的选择(0~6):");
			SC(D,&num);
			while(getchar()!=NL)//过滤非数字的字符
			;

			switch(num)
			{
			   case 0:flag=0;break;
			   case 1:sort_total(count);break;
			   case 2:sort_aver(count);break;
			   case 3:sort_num(count);break;
			   case 4:sort_data_struct(count);break;
			   case 5:sort_assembly(count);break;
			   case 6:sort_net(count);break;
			   default:PR("输入错误！\n");break;
			}
			writefile(count);
			readstu(count);
			if(num>=1&&num<=6)
			{
				PR("学号      姓名      姓别      数据结构  汇编语言  网络基础  总分      平均分\n");

				for(i=0;i<*count;i++)
				{
					PR("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.f%-10.2f\n",
						stu[i]->num,stu[i]->name,stu[i]->sex,stu[i]->score[0],
						stu[i]->score[1],stu[i]->score[2],stu[i]->score[3],stu[i]->score[4]);
					
				}
			}
		}
}