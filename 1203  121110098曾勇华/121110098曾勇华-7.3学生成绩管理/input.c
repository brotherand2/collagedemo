# include<stdio.h>
# include"student.h"
# include<stdlib.h>//Ϊʹ��exit()�����ṩԭ��
void input()//����������������
{
	int n,i;
	student *p1;
	FILE *fp;//�ļ�ָ��
	if((fp=fopen("student.txt","w"))==NULL)//����student.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
    do{
		PR("��Ҫ������ٸ�ѧ�����ݣ�");
		SC(D,&n);
		while(getchar()!=NL)//���˷����ֵ��ַ�
			;
		if(n<1)
		{
			PR("�������,ѧ������ӦΪ������������!\n");
		}
	}while(n<1);
    if(n>studentSize)//���ռ䲻��������ռ�
       myRealloc(n);
    for(i=0;i<n;i++)//����n��ѧ������
	{
	     p1=(student *)malloc(sizeof(student));//��̬�ڴ����ռ�

		if(p1==NULL)
		{
			PR("�ռ����ʧ�ܣ�\n");
			return ;
		}
		PR("�����%d��ѧ����Ϣ��\nѧ�ţ�",i+1);
		SC(D,&p1->num);
		getchar();//���ջ��з�
		PR("������");
		gets(p1->name);
		PR("�Ա�");
		gets(p1->sex);
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
		//����i+1��ѧ����Ϣ������ļ�student.txt

	}
		fclose(fp);//�ر��ļ�ָ��
}