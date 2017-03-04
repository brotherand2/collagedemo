/*
  ==========================================================
              程序：模式匹配
  与书上程序相比增加功能：
  1、与书上链表实现不同，采用动态数组保存字符，能保存任意大小的字符串，且不浪费空间
  2、增加了匹配算法KMP，改进后的KMP算法
  3、增加了计算算法运行时间功能
  4、采用文件读取功能，从文件中读取字符串
  ==========================================================
*/
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<malloc.h>
# include<sys/timeb.h>
# include "strpp.h"
int * position;//用于保存所有位置（位置为该位置对应的下标加1）
int locate,locate1;//查找到该字符串的位置（位置为该位置对应的下标加1）
int len1,len2,len;//分别是主字符串长度，模式串长度，当前字符串长度
void WriteFile(int count,char *s2,long int time)//将匹配信息写入文件
{
	FILE *fp;
	int i;
	if((fp=fopen("匹配结果.txt","a+"))==NULL)
	{
		printf("创建失败\n");
		exit(0);
	}
	fprintf(fp,"%s%ld%s%s%s%d%s","总用时",time,"毫秒\n字串",s2,"出现在主串中的次数:",count,"\n");
	fprintf(fp,"%d%s",count,"次匹配位置(相应位置下标+1)分别为:\n");
	for(i=0;i<count;i++)
		fprintf(fp,"%d  ",position[i]);
	fprintf(fp,"%s","\n\n\n\n\n");
	fclose(fp);
}
long int Time(char *s1,char *s2,int (*match)(char *,char*))//匹配模式，所花时间
{
	int count=0;//找到的位置个数
	long int time;//用于保存匹配过程经过的时间，单位毫秒
	timeb start,end;//timeb是定义在头文件 sys/timeb.h中的一个结构体，分别用于保存匹配开始前时间和结束后的时间
	/*
	定义为：
	struct timeb{
　　time_t time; // 为1970-01-01至今的秒数
　　unsigned short millitm; // 千分之一秒即毫秒 
　　short timezonel; //为目前时区和Greenwich相差的时间，单位为分钟
　　short dstflag; // 为日光节约时间的修正状态，如果为非0代表启用日光节约时间修正 
　　};
	*/
	ftime(&start);//匹配开始前，获得当前系统时间，函数定义：int ftime(struct timeb *tp);函数说明：ftime()将目前日期由tp所指的结构返回。
	locate=match(s1,s2);
	if(locate)
	{
		position[count]=locate;
		count++;//找到的位置个数加1 
        while(s1+locate<=s1+len1-len2)//s1+locate为当前找到的位置的下一个位置,必须满足（s1+locate）+len2-1<=s1+len1-1才能继续寻找，否则因为余下的字符个数少于len2，不可能匹配，寻找无意义
		{
			locate1=match(s1+locate,s2);//当前找到的位置的下一个位置继续寻找
			if(locate1)
			{
				position[count]=(locate+1)+(locate1-1);
				locate+=locate1;//跳过locate1个位置，即从locate+(locate1-1)的下一位置，继续寻找
				count++;//找到的位置个数加1 
			}
			else
				break;//没找到，退出循环
		}
	}
	ftime(&end);//匹配结束，获得当前系统时间
	time=(end.time-start.time)*1000+end.millitm-start.millitm;
	printf("匹配个数:%d\n",count);
	WriteFile(count,s2,time);
	return time;
}
long int StrstrTime(char *s1,char *s2)//普通匹配模式，所花时间
{
	int count=0;//找到的位置个数
	long int time;//用于保存匹配过程经过的时间，单位毫秒
	timeb start,end;//timeb是定义在头文件 sys/timeb.h中的一个结构体，分别用于保存匹配开始前时间和结束后的时间
	char *t;					/*
	定义为：
	struct timeb{
　　time_t time; // 为1970-01-01至今的秒数
　　unsigned short millitm; // 千分之一秒即毫秒 
　　short timezonel; //为目前时区和Greenwich相差的时间，单位为分钟
　　short dstflag; // 为日光节约时间的修正状态，如果为非0代表启用日光节约时间修正 
　　};
	*/
	ftime(&start);//匹配开始前，获得当前系统时间，函数定义：int ftime(struct timeb *tp);函数说明：ftime()将目前日期由tp所指的结构返回。
	t=strstr(s1,s2);
	if(t)
	{
		locate=t-s1+1;
		position[count]=locate;
		count++;//找到的位置个数加1 
        while(s1+locate<=s1+len1-len2)//s1+locate为当前找到的位置的下一个位置,必须满足（s1+locate）+len2-1<=s1+len1-1才能继续寻找，否则因为余下的字符个数少于len2，不可能匹配，寻找无意义
		{
			t=strstr(s1+locate,s2);
			if(t)
			{
				locate1=t-(s1+locate)+1;//当前找到的位置的下一个位置继续寻找
				position[count]=(locate+1)+(locate1-1);
				locate+=locate1;//跳过locate1个位置，即从locate+(locate1-1)的下一位置，继续寻找
				count++;//找到的位置个数加1 
			}
			else
				break;//没找到，退出循环
		}
	}
	ftime(&end);//匹配结束，获得当前系统时间
	time=(end.time-start.time)*1000+end.millitm-start.millitm;
	printf("匹配个数:%d\n",count);
	WriteFile(count,s2,time);
	return time;
}
int main()
{
	long int time;//用于保存匹配过程经过的时间，单位毫秒
	char *s1,*s2,*t;//分别指向主字符串，模式串，读取的每一行字符串
	FILE *fp1,*fp2;//文件指针，分别指向主字符串文件和模式串文件 
	printf("121110098   曾勇华   字符串处理(具体详细信息在 《匹配结果.txt中》)\n");
	if((fp1=fopen("主字符串.txt","rb"))==NULL)
	{
		printf("主字符串不存在，请在主字符串.txt输入主字符串\n");
		exit(0);
	}
	if((fp2=fopen("模式串.txt","rb"))==NULL)
	{
		printf("模式串不存在，请在模式串.txt输入模式串\n");
		exit(0);
	}
	fseek(fp1, 0,SEEK_END);//把fp指针退回到离文件结尾0字节处,即将文件的当前位置移到文件的末尾
	fseek(fp2, 0,SEEK_END);//把fp指针退回到离文件结尾0字节处,即将文件的当前位置移到文件的末尾
	len1=ftell(fp1); //获得当前位置相对于文件首的位移，该位移值等于文件所含字节数
	len2=ftell(fp2); //获得当前位置相对于文件首的位移，该位移值等于文件所含字节数
	rewind(fp1);//将文件指针重新指向一个流的开头 
	rewind(fp2);//将文件指针重新指向一个流的开头 
    s1=(char *)malloc(sizeof(char)*len1);//根据文件长度，动态分配相应的字符串空间
    t=(char *)malloc(sizeof(char)*len1);
    s2=(char *)malloc(sizeof(char)*len2);
	position=(int *)malloc(sizeof(int)*(len1-len2+1));//最极端的情况，每个位置开始都与模式串匹配，如主串aaaaaa,模式串aa,这时从主串第1个位置到倒数第2个位置都与模式串匹配，匹配个数达到最大为6-2+1=5
    if(len1<=len2)
	{
		printf("主字符串长度不能小于模式串长度\n");
		exit(0);
	}
	fgets(s1,len1+1,fp1);//读取一行字符串
	while(fgets(t,len1+1,fp1))//读取一行字符串，且不为空
	{
	    len=strlen(s1);//当前字符串长度
		s1[len-2]='\0';//如果进入了循环，说明文本中不止一行，这时因为第每读取一行后，如果该行有n个字符，则读取的字符串添加两个字符回车换行符\r\n,再添加一个'\0'字符，用strlen()测的字符长度要比真实字符长度加2，所以要将第n+1个字符(即len-2)设为'\0',去掉后两个字符\r\n
		strcat(s1,t);//将字符串接到s1串后
	}
    fgets(s2,len2+1,fp2);
	while(fgets(t,len2+1,fp2))//读取一行字符串，且不为空
	{
	    len=strlen(s2);//当前字符串长度
		s2[len-2]='\0';//如果进入了循环，说明文本中不止一行，这时因为第每读取一行后，如果该行有n个字符，则读取的字符串添加两个字符回车换行符\r\n,再添加一个'\0'字符，用strlen()测的字符长度要比真实字符长度加2，所以要将第n+1个字符(即len-2)设为'\0',去掉后两个字符\r\n
		strcat(s2,t);//将字符串接到s1串后
	}
	/*
	fgets(str,n,fp);
	str是存放在字符串的起始地址；n是一个int类型变量。
	函数的功能是从fp所指文件中读入n-1个字符放入str为起始地址的空间内；
	如果在未读满n-1个字符之时，已读到一个换行符或一个EOF（文件结束标志），
	则结束本次读操作，读入的字符串中最后包含读到的换行符。因此，确切地说，
	调用fgets函数时，最多只能读入n-1个字符。读入结束后，系统将自动在最后加'\0'，
	并以str作为函数值返回。
	*/
	len1=strlen(s1);//因为原字符串可能包括回车换行符，去年这些后，len1重新保存去掉回车换行符后的字符串长度
	len2=strlen(s2);//因为原字符串可能包括回车换行符，去年这些后，len2重新保存去掉回车换行符后的字符串长度
	printf("KMP算法：\n");
	time=Time(s1,s2,KMP);
	printf("总用时%ld毫秒\n",time);
	printf("改进后的KMP算法：\n");
    time=Time(s1,s2,KMP1);
	printf("总用时%ld毫秒\n",time);
	printf("C语言中strstr()函数：\n");
    time=StrstrTime(s1,s2);
	printf("总用时%ld毫秒   (函数库里的函数就是快)\n ",time);
	printf("普通模式算法：\n");
    time=Time(s1,s2,Index);
	printf("总用时%ld毫秒\n",time);
	printf("Horspool算法：\n");
    time=Time(s1,s2,HorSpool);
	printf("总用时%ld毫秒\n",time);
	fclose(fp1);
	fclose(fp2);
	return 0;
}