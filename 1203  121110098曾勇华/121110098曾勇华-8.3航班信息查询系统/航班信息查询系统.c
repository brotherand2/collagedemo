# include<stdio.h>
#include <ctype.h>
# include"plane.h"
void myRealloc(int n)//数组空间不够，重新分配新空间
{
	int i;
	if (n>addSize)//最大空间不够保存
		addSize = n * 2;//所需空间数加倍
	air = (InfoType**)realloc(air, addSize*sizeof(InfoType*));
	printf("空间不足！当前空间为:%d,现正在再分配空间中...\n", MaxSize);
	printf("空间分配完成，当前拥有空间有%d\n", addSize);
	for (i = MaxSize; i<addSize; i++)//为增加的指针分配空间
		air[i] = (InfoType*)malloc(sizeof(InfoType));
	MaxSize = addSize;//将当前空间扩大为addSize
	addSize *= 2;//下一次若空间不够，扩增后数量
}
int strCmp(String str1, String str2)//字符串比较
{
	int i;
	String a, b;
	strcpy(a, str1);//将str1复制到a，避免破坏str1
	strcpy(b, str2);//将str2复制到b，避免破坏str2
	for (i = 0; i < strlen(a); i++)
		if (isupper(a[i]))//如果是大写字母，转为小写字母来比较
			a[i] = tolower(a[i]);
	for (i = 0; i < strlen(b); i++)
		if (isupper(b[i]))//如果是大写字母，转为小写字母来比较
			b[i] = tolower(b[i]);
	return  strcmp(a, b);
}
void readFile()
{
	FILE *fp;//文件指针
	InfoType *p1, *p2;
	int i = 0;
	count = 0;
	if ((fp = fopen("航班信息输入.txt", "r")) == NULL)//读取student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
	p2 = p1 = air[0];
	while (!feof(fp))//feof(fp)表示文件尾
	{
		if (i == MaxSize)
		{
			myRealloc(i);
		}
		p1 = air[i];
		fscanf(fp, S S S S S S S S,
			air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
			air[i]->info[5], air[i]->info[6], air[i]->info[7]);
		if (i>0)
		{
			p2->next = p1;
			p2 = p1;
		}
		i++;
	}
	p1->next = NULL;
	count = i - 1;//   //总之最后一行按了一下换行符，所以多了一行，若不想-1，就要将换行符删掉
	/*位置和内容到底有何不同呢？举个简单的例子，比如有人说“你走到火车的最后一节车箱”这就是位置。
	而如果说“请你一直向后走，摸到铁轨结束”这就是内容。也就是说用内容来判断会“多走一节”。这就是完全依赖于
	“while(!feof(FP)){...}”进行文件复制时，目标文档总会比源文档“多出一些”的原因。所以count要减1*/
	fclose(fp);//关闭文件指针
}
void writeFile()
{
	FILE *fp;//文件指针
	int i = 0;
	if ((fp = fopen("航班信息输入.txt", "w")) == NULL)//写student.txt文件
	{
		PR("不能打开文件!\n");
		exit(0);//终止程序
	}
	for (i = 0; i < count; i++)
		fprintf(fp, " %-10s % -10s % -10s % -10s % -10s % -10s % -10s % -10s%s",
		air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
		air[i]->info[5], air[i]->info[6], air[i]->info[7], "\n");
	fclose(fp);//关闭文件指针
}
void show_boot()//显示菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃ <0>------显示完毕                                    ┃\n");
	PR("       ┃ <1>------按航班号排序                                ┃\n");
	PR("       ┃ <2>------按起飞时间排序                              ┃\n");
	PR("       ┃ <3>------按到达时间排序                              ┃\n");
	PR("       ┃ <4>------按机型排序                                  ┃\n");
	PR("       ┃ <5>------按票价排序                                  ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
void search_boot()//查询菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃   <0>--------查询完毕            ┃\n");
	PR("       ┃   <1>--------按航班号查询        ┃\n");
	PR("       ┃   <2>--------按起点站查询        ┃\n");
	PR("       ┃   <3>--------按终点站查询        ┃\n");
	PR("       ┃   <4>--------按航班期查询        ┃\n");
	PR("       ┃   <5>--------按起飞时间查询      ┃\n");
	PR("       ┃   <6>--------按到达时间查询      ┃\n");
	PR("       ┃   <7>--------按机型查询          ┃\n");
	PR("       ┃   <8>--------按票价查询          ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━┛\n");
}

void PreProcess(int n)//排序前预处理
{
	int i, j;
	for (i = 0; i<count; i++)
	{
		for (j = strlen(air[i]->info[n]); j<MaxLen; j++)
			air[i]->info[n][j] = ' ';//将剩余字符空间初始化为空字符，方便排序，空字符优先级为0
		air[i]->info[n][j] = '\0';//最后一个字符初始化为空字符
	}
}
void RadixSort(int n)//基数排序,n为排序种类，0-7别是分别是航班号、起点站、终点站、航班期、起飞时间、到达时间、机型、票价字符串
{
	int i, j, k;//k为优先级空字符优先级为0，数字0-9优先级为1-10，字母a-z或A-Z优先级为11-36
	InfoType **head, **tail, *p;//头指针数组名、尾指针数组名
	head = (InfoType **)malloc(sizeof(InfoType*) * 37);//37个头指针，分别指向其它字符，0-9，和a-z
	tail = (InfoType **)malloc(sizeof(InfoType*) * 37);
	PreProcess(n);//排序前预处理
	for (i = MaxLen - 1; i >= 0; i--)//除去最后一位'\0'，分别对每一位字符基数排序
	{
		for (j = 0; j<37; j++)
			head[j] = tail[j] = NULL;//初始为空
		for (j = 0; j<count; j++)//进行一趟下标为i的排序
		{
			if (air[j]->info[n][i] >= '0'&&air[j]->info[n][i] <= '9')
				k = air[j]->info[n][i] - '0' + 1;//数字0-9优先级为1-10
			else
			{
				if (air[j]->info[n][i] >= 'a'&&air[j]->info[n][i] <= 'z')
				{
					k = air[j]->info[n][i] - 'a' + 11;//a - z优先级为11 - 36
				}
				else if (air[j]->info[n][i] >= 'A'&&air[j]->info[n][i] <= 'Z')
				{
					k = air[j]->info[n][i] - 'A' + 11;//A - Z优先级为11 - 36
				}
				else
				{
					k = 0; //空字符或其它字符优先级为0
				}
			}
			if (!head[k])
			{
				head[k] = air[j];
			}
			else
				tail[k]->next = air[j];
			tail[k] = air[j];
			tail[k]->next = NULL;
		}
		k = 0;
		for (j = 0; j<37; j++)//进行收集
		{
			p = head[j];
			while (p)
			{
				air[k] = p;
				k++;
				p = p->next;
			}
		}
	}
}
void binSearch(int n, String str)//二分查询,n为种类，0-7别是分别是航班号、起点站、终点站、航班期、起飞时间、到达时间、机型、票价字符串
{
	int i, j, found = 0;
	int low, high, mid;
	String name;
	PR("输入你要查询的%s:", str);
	SC(S, name);
	for (j = strlen(name); j<MaxLen; j++)
		name[j] = ' ';//将剩余字符空间初始化为空字符，方便排序，空字符优先级为0
	name[j] = '\0';//最后一个字符初始化为空字符
	low = 0, high = count - 1;
	RadixSort(n);//查询前先排序
	writeFile();
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strCmp(air[mid]->info[n], name) == 0)
		{
			found = 1;
			break;
		}
		else if (strCmp(air[mid]->info[n], name) < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (!found)
		PR("找不到该%s！!\n", str);
	else
	{
		PR("航班号    起点站    终点站    航班期    起飞时间  到达时间  机型      票价\n");
		for (i = mid; i >= 0 && strcmp(air[i]->info[n], name) == 0; i--)//输出当前下标左边相等的记录
			PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
			air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
			air[i]->info[5], air[i]->info[6], air[i]->info[7]);

		for (i = mid + 1; i <count&&strcmp(air[i]->info[n], name) == 0; i++)//输出当前下标右边相等的记录
			PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
			air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
			air[i]->info[5], air[i]->info[6], air[i]->info[7]);
	}
}
void commonSearch(int n, String str)//普通查询,一个个查n为种类，查询文字，传入类型1-3，分别是起点站、终点站、航班期字符串
{
	int i, j, found = 0;
	String name;
	PR("输入你要查询的%s:", str);
	SC(S, name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(air[i]->info[n], name) == 0)
		{
			if (!found)
				PR("航班号    起点站    终点站    航班期    起飞时间  到达时间  机型      票价\n");
			found = 1;
			PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
				air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
				air[i]->info[5], air[i]->info[6], air[i]->info[7]);
		}
	}
	if (!found)
		PR("找不到该%s！!\n", str);
}
void search()//查询
{
	int num, flag = 1;
	if (count<1)
	{
		PR("无数据！\n");
		return;
	}
	while (flag)
	{
		search_boot();
		PR("输入你的选择(0~8):");
		SC(D, &num);
		while (getchar() != NL)//过滤非数字的字符
			;
		switch (num)
		{
		case 0:flag = 0; break;
		case 1:binSearch(0, "航班号"); break;
		case 2:commonSearch(1, "起点站"); break;
		case 3:commonSearch(2, "终点站"); break;
		case 4:commonSearch(3, "航班期"); break;
		case 5:binSearch(4, "起飞时间"); break;
		case 6:binSearch(5, "到达时间"); break;
		case 7:binSearch(6, "机型"); break;
		case 8:binSearch(7, "票价"); break;
		default:PR("输入错误!\n"); break;
		}
	}
}
void show()//显示
{
	int flag = 1, i;
	if (count<1)
	{
		PR("无数据！\n");
		return;
	}
	while (flag)
	{
		int num;
		show_boot();
		PR("输入你的选择(0~5):");
		SC(D, &num);
		while (getchar() != NL)//过滤非数字的字符
			;

		switch (num)
		{
		case 0:flag = 0; break;
		case 1:RadixSort(0); break;//按航班号排序
		case 2:RadixSort(4); break;//按起飞时间排序
		case 3:RadixSort(5); break;//按到达时间排序
		case 4:RadixSort(6); break;//按机型排序
		case 5:RadixSort(7); break;//按票价排序
		default:PR("输入错误！\n"); break;
		}
		writeFile();
		readFile();
		if (num >= 1 && num <= 5)
		{



			PR("航班号    起点站    终点站    航班期    起飞时间  到达时间  机型      票价\n");
			for (i = 0; i<count; i++)
			{
				PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
					air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
					air[i]->info[5], air[i]->info[6], air[i]->info[7]);
			}
		}
	}
}
void boot()
{
	PR("       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃ <0>------结束        (EXIT)                          ┃\n");
	PR("       ┃ <1>------查询航班   （SEARCH)                        ┃\n");
	PR("       ┃ <2>------显示所有航班(SHOW)                          ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
int main()
{
	int flag = 1, number, i;
	air = (InfoType **)malloc(N*sizeof(InfoType*));
	for (i = 0; i<N; i++)//默认给出N个学生空间
		air[i] = (InfoType*)malloc(sizeof(InfoType));
	MaxSize = N;///空间最大个数
	addSize = MaxSize * 2;//空间不够后扩增后的总个数
	PR("121110098 曾勇华   航班信息查询系统\n\n\n");
	readFile();
	while (flag)
	{
		boot();
		PR("输入你的选择(0~2):");
		SC(D, &number);//若输入abc错误，不能读取,则返回number原地址垃圾值，若输入6abc则abc被过滤
		while (getchar() != NL)//过滤非数字的字符
			;
		switch (number)
		{
		case 0:
		{
			flag = 0;
			break;
		}//退出
		case 1:
		{
			search();
			break;
		}//重新输入所有数据
		case 2:
		{
			show();
			break;
		}//重新输入所有数据
		default:PR("输入错误！重新输入.\n"); break;
		}
	}
	return 0;
}