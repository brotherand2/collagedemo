/*
  ==========================================================
              ����ģʽƥ��
  �����ϳ���������ӹ��ܣ�
  1������������ʵ�ֲ�ͬ�����ö�̬���鱣���ַ����ܱ��������С���ַ������Ҳ��˷ѿռ�
  2��������ƥ���㷨KMP���Ľ����KMP�㷨
  3�������˼����㷨����ʱ�书��
  4�������ļ���ȡ���ܣ����ļ��ж�ȡ�ַ���
  ==========================================================
*/
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<malloc.h>
# include<sys/timeb.h>
# include "strpp.h"
int * position;//���ڱ�������λ�ã�λ��Ϊ��λ�ö�Ӧ���±��1��
int locate,locate1;//���ҵ����ַ�����λ�ã�λ��Ϊ��λ�ö�Ӧ���±��1��
int len1,len2,len;//�ֱ������ַ������ȣ�ģʽ�����ȣ���ǰ�ַ�������
void WriteFile(int count,char *s2,long int time)//��ƥ����Ϣд���ļ�
{
	FILE *fp;
	int i;
	if((fp=fopen("ƥ����.txt","a+"))==NULL)
	{
		printf("����ʧ��\n");
		exit(0);
	}
	fprintf(fp,"%s%ld%s%s%s%d%s","����ʱ",time,"����\n�ִ�",s2,"�����������еĴ���:",count,"\n");
	fprintf(fp,"%d%s",count,"��ƥ��λ��(��Ӧλ���±�+1)�ֱ�Ϊ:\n");
	for(i=0;i<count;i++)
		fprintf(fp,"%d  ",position[i]);
	fprintf(fp,"%s","\n\n\n\n\n");
	fclose(fp);
}
long int Time(char *s1,char *s2,int (*match)(char *,char*))//ƥ��ģʽ������ʱ��
{
	int count=0;//�ҵ���λ�ø���
	long int time;//���ڱ���ƥ����̾�����ʱ�䣬��λ����
	timeb start,end;//timeb�Ƕ�����ͷ�ļ� sys/timeb.h�е�һ���ṹ�壬�ֱ����ڱ���ƥ�俪ʼǰʱ��ͽ������ʱ��
	/*
	����Ϊ��
	struct timeb{
����time_t time; // Ϊ1970-01-01���������
����unsigned short millitm; // ǧ��֮һ�뼴���� 
����short timezonel; //ΪĿǰʱ����Greenwich����ʱ�䣬��λΪ����
����short dstflag; // Ϊ�չ��Լʱ�������״̬�����Ϊ��0���������չ��Լʱ������ 
����};
	*/
	ftime(&start);//ƥ�俪ʼǰ����õ�ǰϵͳʱ�䣬�������壺int ftime(struct timeb *tp);����˵����ftime()��Ŀǰ������tp��ָ�Ľṹ���ء�
	locate=match(s1,s2);
	if(locate)
	{
		position[count]=locate;
		count++;//�ҵ���λ�ø�����1 
        while(s1+locate<=s1+len1-len2)//s1+locateΪ��ǰ�ҵ���λ�õ���һ��λ��,�������㣨s1+locate��+len2-1<=s1+len1-1���ܼ���Ѱ�ң�������Ϊ���µ��ַ���������len2��������ƥ�䣬Ѱ��������
		{
			locate1=match(s1+locate,s2);//��ǰ�ҵ���λ�õ���һ��λ�ü���Ѱ��
			if(locate1)
			{
				position[count]=(locate+1)+(locate1-1);
				locate+=locate1;//����locate1��λ�ã�����locate+(locate1-1)����һλ�ã�����Ѱ��
				count++;//�ҵ���λ�ø�����1 
			}
			else
				break;//û�ҵ����˳�ѭ��
		}
	}
	ftime(&end);//ƥ���������õ�ǰϵͳʱ��
	time=(end.time-start.time)*1000+end.millitm-start.millitm;
	printf("ƥ�����:%d\n",count);
	WriteFile(count,s2,time);
	return time;
}
long int StrstrTime(char *s1,char *s2)//��ͨƥ��ģʽ������ʱ��
{
	int count=0;//�ҵ���λ�ø���
	long int time;//���ڱ���ƥ����̾�����ʱ�䣬��λ����
	timeb start,end;//timeb�Ƕ�����ͷ�ļ� sys/timeb.h�е�һ���ṹ�壬�ֱ����ڱ���ƥ�俪ʼǰʱ��ͽ������ʱ��
	char *t;					/*
	����Ϊ��
	struct timeb{
����time_t time; // Ϊ1970-01-01���������
����unsigned short millitm; // ǧ��֮һ�뼴���� 
����short timezonel; //ΪĿǰʱ����Greenwich����ʱ�䣬��λΪ����
����short dstflag; // Ϊ�չ��Լʱ�������״̬�����Ϊ��0���������չ��Լʱ������ 
����};
	*/
	ftime(&start);//ƥ�俪ʼǰ����õ�ǰϵͳʱ�䣬�������壺int ftime(struct timeb *tp);����˵����ftime()��Ŀǰ������tp��ָ�Ľṹ���ء�
	t=strstr(s1,s2);
	if(t)
	{
		locate=t-s1+1;
		position[count]=locate;
		count++;//�ҵ���λ�ø�����1 
        while(s1+locate<=s1+len1-len2)//s1+locateΪ��ǰ�ҵ���λ�õ���һ��λ��,�������㣨s1+locate��+len2-1<=s1+len1-1���ܼ���Ѱ�ң�������Ϊ���µ��ַ���������len2��������ƥ�䣬Ѱ��������
		{
			t=strstr(s1+locate,s2);
			if(t)
			{
				locate1=t-(s1+locate)+1;//��ǰ�ҵ���λ�õ���һ��λ�ü���Ѱ��
				position[count]=(locate+1)+(locate1-1);
				locate+=locate1;//����locate1��λ�ã�����locate+(locate1-1)����һλ�ã�����Ѱ��
				count++;//�ҵ���λ�ø�����1 
			}
			else
				break;//û�ҵ����˳�ѭ��
		}
	}
	ftime(&end);//ƥ���������õ�ǰϵͳʱ��
	time=(end.time-start.time)*1000+end.millitm-start.millitm;
	printf("ƥ�����:%d\n",count);
	WriteFile(count,s2,time);
	return time;
}
int main()
{
	long int time;//���ڱ���ƥ����̾�����ʱ�䣬��λ����
	char *s1,*s2,*t;//�ֱ�ָ�����ַ�����ģʽ������ȡ��ÿһ���ַ���
	FILE *fp1,*fp2;//�ļ�ָ�룬�ֱ�ָ�����ַ����ļ���ģʽ���ļ� 
	printf("121110098   ���»�   �ַ�������(������ϸ��Ϣ�� ��ƥ����.txt�С�)\n");
	if((fp1=fopen("���ַ���.txt","rb"))==NULL)
	{
		printf("���ַ��������ڣ��������ַ���.txt�������ַ���\n");
		exit(0);
	}
	if((fp2=fopen("ģʽ��.txt","rb"))==NULL)
	{
		printf("ģʽ�������ڣ�����ģʽ��.txt����ģʽ��\n");
		exit(0);
	}
	fseek(fp1, 0,SEEK_END);//��fpָ���˻ص����ļ���β0�ֽڴ�,�����ļ��ĵ�ǰλ���Ƶ��ļ���ĩβ
	fseek(fp2, 0,SEEK_END);//��fpָ���˻ص����ļ���β0�ֽڴ�,�����ļ��ĵ�ǰλ���Ƶ��ļ���ĩβ
	len1=ftell(fp1); //��õ�ǰλ��������ļ��׵�λ�ƣ���λ��ֵ�����ļ������ֽ���
	len2=ftell(fp2); //��õ�ǰλ��������ļ��׵�λ�ƣ���λ��ֵ�����ļ������ֽ���
	rewind(fp1);//���ļ�ָ������ָ��һ�����Ŀ�ͷ 
	rewind(fp2);//���ļ�ָ������ָ��һ�����Ŀ�ͷ 
    s1=(char *)malloc(sizeof(char)*len1);//�����ļ����ȣ���̬������Ӧ���ַ����ռ�
    t=(char *)malloc(sizeof(char)*len1);
    s2=(char *)malloc(sizeof(char)*len2);
	position=(int *)malloc(sizeof(int)*(len1-len2+1));//��˵������ÿ��λ�ÿ�ʼ����ģʽ��ƥ�䣬������aaaaaa,ģʽ��aa,��ʱ��������1��λ�õ�������2��λ�ö���ģʽ��ƥ�䣬ƥ������ﵽ���Ϊ6-2+1=5
    if(len1<=len2)
	{
		printf("���ַ������Ȳ���С��ģʽ������\n");
		exit(0);
	}
	fgets(s1,len1+1,fp1);//��ȡһ���ַ���
	while(fgets(t,len1+1,fp1))//��ȡһ���ַ������Ҳ�Ϊ��
	{
	    len=strlen(s1);//��ǰ�ַ�������
		s1[len-2]='\0';//���������ѭ����˵���ı��в�ֹһ�У���ʱ��Ϊ��ÿ��ȡһ�к����������n���ַ������ȡ���ַ�����������ַ��س����з�\r\n,�����һ��'\0'�ַ�����strlen()����ַ�����Ҫ����ʵ�ַ����ȼ�2������Ҫ����n+1���ַ�(��len-2)��Ϊ'\0',ȥ���������ַ�\r\n
		strcat(s1,t);//���ַ����ӵ�s1����
	}
    fgets(s2,len2+1,fp2);
	while(fgets(t,len2+1,fp2))//��ȡһ���ַ������Ҳ�Ϊ��
	{
	    len=strlen(s2);//��ǰ�ַ�������
		s2[len-2]='\0';//���������ѭ����˵���ı��в�ֹһ�У���ʱ��Ϊ��ÿ��ȡһ�к����������n���ַ������ȡ���ַ�����������ַ��س����з�\r\n,�����һ��'\0'�ַ�����strlen()����ַ�����Ҫ����ʵ�ַ����ȼ�2������Ҫ����n+1���ַ�(��len-2)��Ϊ'\0',ȥ���������ַ�\r\n
		strcat(s2,t);//���ַ����ӵ�s1����
	}
	/*
	fgets(str,n,fp);
	str�Ǵ�����ַ�������ʼ��ַ��n��һ��int���ͱ�����
	�����Ĺ����Ǵ�fp��ָ�ļ��ж���n-1���ַ�����strΪ��ʼ��ַ�Ŀռ��ڣ�
	�����δ����n-1���ַ�֮ʱ���Ѷ���һ�����з���һ��EOF���ļ�������־����
	��������ζ�������������ַ����������������Ļ��з�����ˣ�ȷ�е�˵��
	����fgets����ʱ�����ֻ�ܶ���n-1���ַ������������ϵͳ���Զ�������'\0'��
	����str��Ϊ����ֵ���ء�
	*/
	len1=strlen(s1);//��Ϊԭ�ַ������ܰ����س����з���ȥ����Щ��len1���±���ȥ���س����з�����ַ�������
	len2=strlen(s2);//��Ϊԭ�ַ������ܰ����س����з���ȥ����Щ��len2���±���ȥ���س����з�����ַ�������
	printf("KMP�㷨��\n");
	time=Time(s1,s2,KMP);
	printf("����ʱ%ld����\n",time);
	printf("�Ľ����KMP�㷨��\n");
    time=Time(s1,s2,KMP1);
	printf("����ʱ%ld����\n",time);
	printf("C������strstr()������\n");
    time=StrstrTime(s1,s2);
	printf("����ʱ%ld����   (��������ĺ������ǿ�)\n ",time);
	printf("��ͨģʽ�㷨��\n");
    time=Time(s1,s2,Index);
	printf("����ʱ%ld����\n",time);
	printf("Horspool�㷨��\n");
    time=Time(s1,s2,HorSpool);
	printf("����ʱ%ld����\n",time);
	fclose(fp1);
	fclose(fp2);
	return 0;
}