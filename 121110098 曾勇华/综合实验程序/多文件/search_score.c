# include<stdio.h>
# include"student.h"
void search_score(int *count,int n)//���ɼ���ѯ
{
    char score_name[5][10]={"C����","�ߵ���ѧ","�繤����","�ܷ�","ƽ����"};
	float score;
	int i,j,found=0;

	PR("������Ҫ��ѯ��%s�ɼ���",score_name[n]);
	SC(F,&score);
	for(i=0;i<*count;i++)
	{
		if(score==stu[i].score[n])
		{
			found=1;
			PR("������%s\n",stu[i].name);
			PR("ѧ��:%d\n",stu[i].num);
			PR("�ձ�%s\n",stu[i].sex);
			PR("C����     �ߵ���ѧ  �繤����  �ܷ�      ƽ����\n");
			for(j=0;j<5;j++)
    			PR("%-10.2f",stu[i].score[j]);
			PR("\n");
		}
	}
	if(!found)
		PR("�Ҳ�����%s�ɼ���!\n",score_name[n]);


}

