# include<stdlib.h>//Ϊʹ��exit()�����ṩԭ��
# include<stdio.h>
# include"student.h"
void writefile(int *count)//������д��student.txt�ļ�
{
	int i;
	FILE *fp;//�ļ�ָ��
	if((fp=fopen("student.txt","w"))==NULL)//����student.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
	for(i=0;i<*count;i++)
	{
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			stu[i].num,' ',stu[i].name,' ',stu[i].sex,' ',stu[i].score[0],' ',
			stu[i].score[1],' ',stu[i].score[2],' ',stu[i].score[3],' ',stu[i].score[4],NL);

	}
	fclose(fp);

}