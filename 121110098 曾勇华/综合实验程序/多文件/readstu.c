# include<stdio.h>
# include"student.h"
# include<stdlib.h>//Ϊʹ��exit()�����ṩԭ��
void readstu(int *count)//���ڶ�ȡ�ļ�ʱ��ѧ������
{	
	FILE *fp;//�ļ�ָ��
    student *p1,*p2;
    int i=0;
	*count=0;
	if((fp=fopen("student.txt","r"))==NULL)//��ȡstudent.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
    p2=p1=&stu[0];
	while(!feof(fp))//feof(fp)��ʾ�ļ�β
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
    *count=i-1;/*λ�ú����ݵ����кβ�ͬ�أ��ٸ��򵥵����ӣ���������˵�����ߵ��𳵵����һ�ڳ��䡱�����λ�á�
			  �����˵������һֱ����ߣ����������������������ݡ�Ҳ����˵���������жϻᡰ����һ�ڡ����������ȫ������
			  ��while(!feof(FP)){...}�������ļ�����ʱ��Ŀ���ĵ��ܻ��Դ�ĵ������һЩ����ԭ������countҪ��1*/

	fclose(fp);//�ر��ļ�ָ��
}