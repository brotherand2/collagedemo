# include<stdio.h>
# include"student.h"
# include<stdlib.h>//Ϊʹ��exit()�����ṩԭ��
void insert(int *count)//����
{
	    
		int flag;
	    student temp,*p1;//��ʱ�ṹ�����
	while(1)
	{
		FILE *fp;//�ļ�ָ��
		if((fp=fopen("student.txt","a"))==NULL)//��student.txt�ļ�׷��ѧ����Ϣ
		{
			PR("���ܴ��ļ�!\n");
			exit(0);//��ֹ����
		}
		p1=&temp;
	
		PR("ѧ��:");
		SC(D,&p1->num);
		getchar();
		PR("������");
		SC(S,p1->name);
		PR("�Ա�");
		SC(S,p1->sex);
		PR("���ݽṹ��");
		SC(F,&p1->score[0]);
		PR("�������:");
		SC(F,&p1->score[1]);
		PR("�������:");
		SC(F,&p1->score[2]);
		p1->score[3]=p1->score[0]+p1->score[1]+p1->score[2];//�ܷ�
		p1->score[4]=p1->score[3]/3;//ƽ����
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			p1->num,' ',p1->name,' ',p1->sex,' ',p1->score[0],' ',
			p1->score[1],' ',p1->score[2],' ',p1->score[3],' ',p1->score[4],NL);
		fclose(fp);
	    PR("����ɹ���\n");
		readstu(count);
		show(count);
        PR("�������������������1����:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//���˷������ַ�
				;
		if(flag==1)
			break;
	}
}