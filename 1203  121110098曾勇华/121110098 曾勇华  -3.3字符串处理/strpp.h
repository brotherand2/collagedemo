# include<stdio.h>
# include<malloc.h>
# include<string.h>
int Index(char *s,char  *t)//��ͨģʽƥ��
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
		next[0]=-1;//����1��λ�ò����ʱ�����г�ʼ���±�-1����ʱҪ�ص���1��λ�ñȽ�j++��i++����һλ��ʼƥ��
        if(strlen(s)>1)
		{
		    next[1]=0;//����2��λ�ò����ʱ��ֻ�ܻص���1��λ�ã��±�Ϊ0
			while(i<strlen(s)-1)
			{
				if(j==-1||s[i]==s[j])//-1����ʱҪ�ص���1��λ�ñȽ�j++
				{
					i++;//i++����һλ��ʼƥ��
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
		nextval[0]=-1;//����1��λ�ò����ʱ�����г�ʼ���±�-1����ʱҪ�ص���1��λ�ñȽ�j++��i++����һλ��ʼƥ��
        if(strlen(s)>1)
		{
		    nextval[1]=0;//����2��λ�ò����ʱ��ֻ�ܻص���1��λ�ã��±�Ϊ0
			while(i<strlen(s)-1)
			{
				if(j==-1||s[i]==s[j])//-1����ʱҪ�ص���1��λ�ñȽ�j++
				{
					i++;//i++����һλ��ʼƥ��
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
int KMP(char  *s,char  *t)//KMP��ͨģʽƥ��
{
	int i=0,j=0;
	int len1=strlen(s),len2=strlen(t);
	int *next=(int*)malloc(sizeof(int)*strlen(t));
	if(!strlen(s))
		return 0;
	GetNext(t,next);
	while(i<len1&&j<len2)
	{
		if(j==-1||s[i]==t[j])//���j==-1�ǵڽ���ƥ��Ĵ��ĵ�1�������ȣ�i�����,jָ���һλ
		{
			i++;
			j++;
		}
		else
			j=next[j];//jָ��������
	}
	if(j==strlen(t))
		return i-j+1;
	else
		return 0;
}

int KMP1(char  *s,char  *t)//����KMP��ͨģʽƥ��
{
	int i=0,j=0;
	int *nextval=(int*)malloc(sizeof(int)*strlen(t));
	int len1=strlen(s),len2=strlen(t);
	if(!strlen(s))
		return 0;
	GetNextval(t,nextval);
	while(i<len1&&j<len2)
	{
		if(j==-1||s[i]==t[j])//���j==-1�ǵڽ���ƥ��Ĵ��ĵ�1�������ȣ�i�����,jָ���һλ
		{
			i++;
			j++;
		}
		else
			j=nextval[j];//jָ��������
	}
	if(j==strlen(t))
		return i-j+1;
	else
		return 0;
}
int HorSpool(char *s,char *t)
{
    int i,j;
	int d[128];//���ڱ��������ַ��ƶ����룬ascii������128���ַ�
	int len2=strlen(t);//ģʽ������
	int len1=strlen(s);//��������
	int pos=0;//��ǰ�±�
	for(i=0;i<128;i++)
		d[i]=len2;//�����ַ������ʼ��Ϊlen���Ǵ�t�е��ַ�����Ϊlen
	for(i=0;i<len2-1;i++)
        d[t[i]]=len2-1-i;//���봮t���һ���ַ��ľ���
	while(pos+len2-1<=len1-1)
	{
		j=len2-1;//ģʽ�����һ���ַ����±�
		while(j>=0&&s[pos+j]==t[j])//���һ����ʼ������
			j--;
		if(j<0)//ģʽ���ڸ��ַ���ƥ��
			return pos+1;
		else
		{
			if(j==len2-1)//���һ���Ͳ����
				pos=pos+d[s[pos+j]];
			else
			{
				pos=pos+j-(len2-1-d[s[pos+j]]);
			}
		}
	}
	return 0;
}
