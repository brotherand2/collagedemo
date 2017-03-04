# include<stdio.h>
# include<string.h>//为使用strcmp()字符串函数
# include<stdlib.h>//为使用exit()函数提供原型
# include"student.h"//创建一个本地头文件student.h存放各种宏和函数原型
typedef struct STUDENT//用typedef声明新类型名
{
	int num;//学号
	char name[10],sex[5];//姓名、姓别
	float score[5];//高等数学，C语言，电工基础，总 分，平均分
	
	struct STUDENT *next;
}student;//student 等价于struct STUDENT 
student stu[60];//学生最多个数60
student *p1=NULL,*p2=NULL,*head=NULL,*p;//全局变量
int count;//用于读取文件时记学生个数
int main()
{
	int flag=1,number;
	while(flag)
	{
		boot();
		PR("输入你的选择(0~6):");
		SC(D,&number);//若输入abc错误，不能读取,则返回number原地址垃圾值，若输入6abc则abc被过滤
		while(getchar()!=NL)//过滤非数字的字符
			;

		switch(number)
		{
			case 0:
				{
					flag=0;
					break;
				}//退出
			case 1:
				{
					input();
					break;
				}//重新输入所有数据
			case 2:
				{
					readstu();
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}
					update();
					writefile();
				
					break;
				}//修改个别数据
			case 3:
				{
					
					insert();
					
					break;
					
				}//插入

			case 4:
				{
					readstu();
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}

					delet();
					writefile();
					break;
					
				}//删除
			case 5:
				{
					readstu();
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}

					search();
					break;
					
				}//查询
			case 6:
				{
					readstu();
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}

					show();
					break;
				}//显示
			default:PR("输入错误！重新输入.\n");break;

		}
	}

	return 0;
}
void boot()//主菜单
{
    PR("       ┏━━━━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃   <0>------(退出)Exit                  ┃\n");
	PR("       ┃   <1>------(重新输入所有数据)Input     ┃\n");
	PR("       ┃   <2>------(修改个别数据)Update        ┃\n");
	PR("       ┃   <3>------(插入)Insert                ┃\n");
	PR("       ┃   <4>------(删除)Delete                ┃\n");
	PR("       ┃   <5>------(查询)Search                ┃\n");
	PR("       ┃   <6>------(显示)Show                  ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━━━━┛\n");
	

}
void input()//重新输入所有数据
{
	int n,i;
	FILE *fp;//文件指针
	if((fp=fopen("student.txt","w"))==NULL)//创建student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
    do{
	PR("你要输入多少个学生数据：(1~60)");
	SC(D,&n);
	while(getchar()!=NL)//过滤非数字的字符
		;

	if(n<1||n>60)
		PR("输入错误！重新输入!\n");
	}while(n<1||n>60);

    for(i=0;i<n;i++)//输入n个学生数据
	{
	     p1=(student *)malloc(sizeof(student));//动态内存分配空间

		if(p1==NULL)
		{
			PR("空间分配失败！\n");
			return ;
		}
		PR("输入第%d个学生信息：\n学号：",i+1);
		SC(D,&p1->num);
		getchar();//接收换行符
		PR("姓名：");
		gets(p1->name);
		PR("性别：");
		gets(p1->sex);
		PR("C语言成绩：");
		SC(F,&p1->score[0]);
		PR("高等数学:");
		SC(F,&p1->score[1]);
		PR("电工基础:");
		SC(F,&p1->score[2]);
		p1->score[3]=p1->score[0]+p1->score[1]+p1->score[2];//总分
		p1->score[4]=p1->score[3]/3;//平均分
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			p1->num,' ',p1->name,' ',p1->sex,' ',p1->score[0],' ',
			p1->score[1],' ',p1->score[2],' ',p1->score[3],' ',p1->score[4],NL);
		//将第i+1个学生信息输出到文件student.txt



	}
		fclose(fp);//关闭文件指针

}
void readstu()//用于读取文件时记学生个数
{	
	FILE *fp;//文件指针

    int i=0;
	count=0;
	if((fp=fopen("student.txt","r"))==NULL)//读取student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
    head=p2=p1=&stu[0];
	while(!feof(fp))//feof(fp)表示文件尾
	{
		p1=&stu[i];
		
		fscanf(fp,D S S F F F F F,
			&stu[i].num,stu[i].name,stu[i].sex,&stu[i].score[0],
			&stu[i].score[1],&stu[i].score[2],&stu[i].score[3],&stu[i].score[4]);
		if(i>0)
		{
		p2->next=p1;
		p2=p1;
		}
        i++;
	}
	p1->next=NULL;
    count=i-1;/*位置和内容到底有何不同呢？举个简单的例子，比如有人说“你走到火车的最后一节车箱”这就是位置。
			  而如果说“请你一直向后走，摸到铁轨结束”这就是内容。也就是说用内容来判断会“多走一节”。这就是完全依赖于
			  “while(!feof(FP)){...}”进行文件复制时，目标文档总会比源文档“多出一些”的原因。所以count要减1*/

	fclose(fp);//关闭文件指针
}
void update()//修改个别数据
{
	char name[10],c;
	int i,flag=1,flag1,found,num;
	while(flag)
	{
		found=0;
		flag1=1;
		PR("输入要更改数据的学生姓名：");
		SC(S,name);
		for(i=0;i<count;i++)
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
			show();
		PR("是否继续输入姓名进行修改(y/n)?");
		getchar();//接收换行符
		c=getchar();
		if(c=='n'||c=='N')
			flag=0;
	}


}
void update_boot()//修改数据的菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━┓\n"); 
	PR("       ┃   <0>--------修改完毕            ┃\n"); 
	PR("       ┃   <1>--------修改学号            ┃\n");
	PR("       ┃   <2>--------修改姓别            ┃\n"); 
	PR("       ┃   <3>--------修改C语言成绩       ┃\n"); 
	PR("       ┃   <4>--------修改高等数学成绩    ┃\n");
	PR("       ┃   <5>--------修改电工基础成绩    ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━┛\n");


}
void writefile()//将数据写入student.txt文件
{
	int i;
	FILE *fp;//文件指针
	if((fp=fopen("student.txt","w"))==NULL)//创建student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
	for(i=0;i<count;i++)
	{
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			stu[i].num,' ',stu[i].name,' ',stu[i].sex,' ',stu[i].score[0],' ',
			stu[i].score[1],' ',stu[i].score[2],' ',stu[i].score[3],' ',stu[i].score[4],NL);

	}
	fclose(fp);

}
void insert()//插入
{
	    
		int flag;
	    student temp;//临时结构体变量
	while(1)
	{
		FILE *fp;//文件指针
		if((fp=fopen("student.txt","a"))==NULL)//向student.txt文件追加学生信息
		{
			PR("不能打开文件!\n");
			exit(0);//终止程序
		}
		p1=&temp;
	
		PR("学号:");
		SC(D,&p1->num);
		getchar();
		PR("姓名：");
		SC(S,p1->name);
		PR("性别：");
		SC(S,p1->sex);
		PR("C语言成绩：");
		SC(F,&p1->score[0]);
		PR("高等数学:");
		SC(F,&p1->score[1]);
		PR("电工基础:");
		SC(F,&p1->score[2]);
		p1->score[3]=p1->score[0]+p1->score[1]+p1->score[2];//总分
		p1->score[4]=p1->score[3]/3;//平均分
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			p1->num,' ',p1->name,' ',p1->sex,' ',p1->score[0],' ',
			p1->score[1],' ',p1->score[2],' ',p1->score[3],' ',p1->score[4],NL);
		fclose(fp);
	    PR("插入成功！\n");
		readstu();
		show();
        PR("输入任意键继续，输入1结束:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//过滤非数字字符
				;
		if(flag==1)
			break;
	}



}
void delet()//删除
{
	char c;
	char name[10];
	int flag=1,found,i,j;
	
	while(flag)
	{
		if(count<1)
		{
			PR("已无数据可删！\n");
			return;
		}
		found=0;
		PR("输入要删除数据的学生姓名:\n");
		SC(S,name);
		for(i=0;i<count;i++)
		{
			if(strcmp(stu[i].name,name)==0)
			{
				found=1;
				for(j=i;j<count;j++)
					stu[j]=stu[j+1];
				count--;
				i--;
					PR("%s信息已删除!\n",name);

			}
		}
		if(!found)
			PR("无该学生！\n");
		show();
		PR("继续删除与否？(y/n)");
		c=getchar();
		if(c=='n'||c=='N')
			flag=0;

	}


}
void show()//显示
{
	int flag=1,i;
		if(count<1)
		{
			PR("无数据！\n");
			return;
		}
		while(flag)
		{
			int num;
			show_boot();
			PR("输入你的选择(0~4):");
			SC(D,&num);
			while(getchar()!=NL)//过滤非数字的字符
			;

			switch(num)
			{
			   case 0:flag=0;break;
			   case 1:sort_total();break;
			   case 2:sort_aver();break;
			   case 3:sort_num();break;
			   case 4:sort_name();break;
			   default:PR("输入错误！\n");break;
			}
			writefile();
			readstu();
			if(num>=1&&num<=4)
			{

				

				PR("学号      姓名      姓别      C语言     高等数学  电工基础  总分      平均分\n");

				for(i=0;i<count;i++)
				{
					PR("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.f%-10.2f\n",
						stu[i].num,stu[i].name,stu[i].sex,stu[i].score[0],
						stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4]);
					
				}
			}
		}
}
void show_boot()//显示菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃ <0>------显示完毕                                    ┃\n");
	PR("       ┃ <1>------按总分递减排序显示学生信息和平均分数        ┃\n");
	PR("       ┃ <2>------按平均分递减排序显示学生信息和平均分数      ┃\n");
	PR("       ┃ <3>------按学号递减排序显示学生信息和平均分数        ┃\n");
	PR("       ┃ <4>------按姓名递减排序显示学生信息和平均分数        ┃\n");  
	PR("       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
void sort_total()//按总分递减排序
{
	int i,j;
	student temp;
	for(i=0;i<count-1;i++)//冒泡排序
	{
		for(j=0;j<count-1-i;j++)
		{
			if(stu[j].score[3]<stu[j+1].score[3])
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}

		}
	}
}
void sort_aver()//按平均分递减排序
{
	int i,j,k;
	float max;
	student temp;
	for(i=0;i<count-1;i++)//选择排序
	{
		k=i;
		
		for(j=i+1;j<count;j++)
		{
			max=stu[k].score[4];
			if(stu[j].score[4]>max)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=stu[i];
			stu[i]=stu[k];
			stu[k]=temp;
		}
	}

}
void sort_num()//按学号递减排序
{
	int i,j;
	student temp;
	for(i=0;i<count-1;i++)//冒泡排序
	{
		for(j=i+1;j<count;j++)
		{
			if(stu[i].num<stu[j].num)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}

		}
	}
}
void sort_name()//按姓名递减排序
{
	int i,j;
	student temp;
	for(i=0;i<count-1;i++)//冒泡排序
	{
		for(j=0;j<count-1-i;j++)
		{
			if(strcmp(stu[j].name,stu[j+1].name)<0)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}

		}
	}
}
void search()//查询
{
	int num,flag=1;
	if(count<1)
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
		   case 1:search_num();break;
		   case 2:search_name();break;
		   case 3:search_score(0);break;
		   case 4:search_score(1);break;
		   case 5:search_score(2);break;
		   case 6:search_score(3);break;
		   case 7:search_score(4);break;
		   default:PR("输入错误!\n");break;

		}

	}

}
void search_boot()//查询菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━┓\n"); 
	PR("       ┃   <0>--------查询完毕            ┃\n"); 
	PR("       ┃   <1>--------按学号查询          ┃\n");
	PR("       ┃   <2>--------按姓名查询          ┃\n"); 
	PR("       ┃   <3>--------按C语言成绩查询     ┃\n"); 
	PR("       ┃   <4>--------按高等数学成绩查询  ┃\n");
	PR("       ┃   <5>--------按电工基础成绩查询  ┃\n");
	PR("       ┃   <6>--------按总分查询          ┃\n");
	PR("       ┃   <7>--------按平均分查询        ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━┛\n");
}
void search_num()//按学号查询
{
	int i,j,num,found=0;
	PR("输入你要查询的学号:");
	SC(D,&num);
	while(getchar()!=NL)//过滤非数字的字符
	;

	for(i=0;i<count;i++)
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
void search_name()//按姓名查询
{
	int i,j,found=0;
	char name[10];
	PR("输入你要查询的姓名:");
	SC(S,name);
	for(i=0;i<count;i++)
	{
		if(strcmp(name,stu[i].name)==0)
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
		PR("找不到该姓名！!\n");

}


void search_score(int n)//按成绩查询
{
    char score_name[5][10]={"C语言","高等数学","电工基础","总分","平均分"};
	float score;
	int i,j,found=0;

	PR("输入你要查询的%s成绩：",score_name[n]);
	SC(F,&score);
	for(i=0;i<count;i++)
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

