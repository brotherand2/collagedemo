# include<stdio.h>
# include<malloc.h>
# include<string.h>
int Index(char *s,char  *t)//普通模式匹配
{
	int i=0,j,k;
	bool find=false;
	while(i<=strlen(s)-strlen(t))
	{
		k=i;
		j=0;
		while(j<strlen(t)&&s[k]==t[j])
		{
			k++;
			j++;
		}
		if(j==strlen(t))
		{
			find=true;
			break;
		}
		i++;
	}
	if(find)
		return i+1;
	else
		return 0;
}
void GetNext(char  *s,int *next)
{
	int i=1,j=0;
	if(strlen(s)>0)
	{
		next[0]=-1;//当第1个位置不相等时，进行初始化下标-1，这时要回到第1个位置比较j++，i++向下一位开始匹配
        if(strlen(s)>1)
		{
		    next[1]=0;//当第2个位置不相等时，只能回到第1个位置，下标为0
			while(i<strlen(s)-1)
			{
				if(j==-1||s[i]==s[j])//-1，这时要回到第1个位置比较j++
				{
					i++;//i++向下一位开始匹配
					j++;
					next[i]=j;
				}
				else
					j=next[j];
			}		
		}
	}
}
void GetNextval(char  *s,int *nextval)
{
	int i=1,j=0;
	if(strlen(s)>0)
	{
		nextval[0]=-1;//当第1个位置不相等时，进行初始化下标-1，这时要回到第1个位置比较j++，i++向下一位开始匹配
        if(strlen(s)>1)
		{
		    nextval[1]=0;//当第2个位置不相等时，只能回到第1个位置，下标为0
			while(i<strlen(s)-1)
			{
				if(j==-1||s[i]==s[j])//-1，这时要回到第1个位置比较j++
				{
					i++;//i++向下一位开始匹配
					j++;
					if(s[i]==s[j])
					  nextval[i]=nextval[j];
					else
						nextval[i]=j;
				}
				else
					j=nextval[j];
			}		
		}
	}
}
int KMP(char  *s,char  *t)//KMP普通模式匹配
{
	int i=0,j=0;
	int len1=strlen(s),len2=strlen(t);
	int *next=(int*)malloc(sizeof(int)*strlen(t));
	if(!strlen(s))
		return 0;
	GetNext(t,next);
	while(i<len1&&j<len2)
	{
		if(j==-1||s[i]==t[j])//如果j==-1是第进行匹配的串的第1个数不等，i向后移,j指向第一位
		{
			i++;
			j++;
		}
		else
			j=next[j];//j指针往左移
	}
	if(j==strlen(t))
		return i-j+1;
	else
		return 0;
}

int KMP1(char  *s,char  *t)//改良KMP普通模式匹配
{
	int i=0,j=0;
	int *nextval=(int*)malloc(sizeof(int)*strlen(t));
	int len1=strlen(s),len2=strlen(t);
	if(!strlen(s))
		return 0;
	GetNextval(t,nextval);
	while(i<len1&&j<len2)
	{
		if(j==-1||s[i]==t[j])//如果j==-1是第进行匹配的串的第1个数不等，i向后移,j指向第一位
		{
			i++;
			j++;
		}
		else
			j=nextval[j];//j指针往左移
	}
	if(j==strlen(t))
		return i-j+1;
	else
		return 0;
}
int HorSpool(char *s,char *t)
{
    int i,j;
	int d[128];//用于保存所有字符移动距离，ascii码中有128个字符
	int len2=strlen(t);//模式串长度
	int len1=strlen(s);//主串长度
	int pos=0;//当前下标
	for(i=0;i<128;i++)
		d[i]=len2;//所有字符距离初始化为len，非串t中的字符距离为len
	for(i=0;i<len2-1;i++)
        d[t[i]]=len2-1-i;//距离串t最后一个字符的距离
	while(pos+len2-1<=len1-1)
	{
		j=len2-1;//模式串最后一个字符的下标
		while(j>=0&&s[pos+j]==t[j])//最后一个开始往左配
			j--;
		if(j<0)//模式串第个字符都匹配
			return pos+1;
		else
		{
			if(j==len2-1)//最后一个就不配对
				pos=pos+d[s[pos+j]];
			else
			{
				pos=pos+j-(len2-1-d[s[pos+j]]);
			}
		}
	}
	return 0;
}
