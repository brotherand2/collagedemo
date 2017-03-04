# include<stdio.h>
# include"student.h"
# include<string.h>
void update(int *count)//修改个别数据
{
	char name[10],c;
	int i,flag,flag1,found,num;
	while(1)
	{
		found=0;
		flag1=1;
		PR("输入要更改数据的学生姓名：");
		SC(S,name);
		for(i=0;i<*count;i++)
		{
			if(strcmp(name,stu[i].name)==0)
			{
				found=1;
				while(flag1)
				{
					update_boot();
					PR("输入你的选择(0~5):");
					SC(D,&num);
					switch(num)
					{
						 case 0:
							 {
								 flag1=0;
								 break;
							 }
						 case 1:
							 {
								 PR("输入学号:");
								 SC(D,&stu[i].num);
								 PR("学号已修改，可以继续修改其它信息.\n");
								 break;
							 }
						 case 2:
							 {
								 PR("输入姓别:");
								 SC(S,stu[i].sex);
								 PR("姓别已修改，可以继续修改其它信息.\n");
			                      break;
							 }
						 case 4:
							 {
								 PR("输入高等数学成绩:");
								 SC(F,&stu[i].score[1]);
								 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
								 stu[i].score[4]=stu[i].score[3]/3;
								 PR("该成绩已修改，可以继续修改其它信息.\n");
	                              break;
							 }
						 case 3:
							 {
								 PR("输入C语言:");
								 SC(F,&stu[i].score[0]);
								 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
								 stu[i].score[4]=stu[i].score[3]/3;	 
								 PR("该成绩已修改，可以继续修改其它信息.\n");
                                 break;
							 }
						 case 5:
								 {
								 PR("输入电工基础:");
								 SC(F,&stu[i].score[2]);
								 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
								 stu[i].score[4]=stu[i].score[3]/3;
									 PR("该成绩已修改，可以继续修改其它信息.\n");
							 break;

								 }
						 default:PR("输入错误!\n");break;
						 
					}
				}

			}
		}
		if(!found)
			PR("学生%s数据没有找到，请重新输入姓名。\n",name);
		if(found)
			show(count);
        PR("输入任意键继续删除，输入1结束:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//过滤非数字字符
				;
		if(flag==1)
			break;
	}


}