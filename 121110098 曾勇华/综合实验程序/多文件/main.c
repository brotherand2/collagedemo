# include<stdio.h>
# include<stdlib.h>//为使用exit()函数提供原型
# include"student.h"//创建一个本地头文件student.h存放各种宏和函数原型
int count;
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
					input(&count);
					break;
				}//重新输入所有数据
			case 2:
				{
					readstu(&count);
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}
					update(&count);
					writefile(&count);
					break;
				}//修改个别数据
			case 3:
				{	
					insert(&count);
					break;
				}//插入
			case 4:
				{
					readstu(&count);
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}
					delet(&count);
					writefile(&count);
					break;					
				}//删除
			case 5:
				{
					readstu(&count);
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}
					search(&count);
					break;					
				}//查询
			case 6:
				{
					readstu(&count);
					if(0==count)
					{
						PR("没有学生数据！请输入1来输入数据。\n");
						continue;
					}
					show(&count);
					break;
				}//显示
			default:PR("输入错误！重新输入.\n");break;
		}
	}
	return 0;
}