# include<string.h>//Ϊʹ��strcmp()�ַ�������
# include<stdio.h>
# include"student.h"
void search_name(int *count)//��������ѯ
{
	int i,j,found=0;
	char name[10];
	PR("������Ҫ��ѯ������:");
	SC(S,name);
	for(i=0;i<*count;i++)
	{
		if(strcmp(name,stu[i]->name)==0)
		{
			found=1;
			PR("������%s\n",stu[i]->name);
			PR("ѧ��:%d\n",stu[i]->num);
			PR("�ձ�%s\n",stu[i]->sex);
			PR("���ݽṹ   �������  �������  �ܷ�      ƽ����\n");
			for(j=0;j<5;j++)
    			PR("%-10.2f",stu[i]->score[j]);
			PR("\n");
		}
	}
	if(!found)
		PR("�Ҳ�����������!\n");

}
