# include<stdio.h>
# include"student.h"
void search_num(int *count)//��ѧ�Ų�ѯ
{
	int i,j,num,found=0;
	PR("������Ҫ��ѯ��ѧ��:");
	SC(D,&num);
	while(getchar()!=NL)//���˷����ֵ��ַ�
	;

	for(i=0;i<*count;i++)
	{
		if(num==stu[i].num)
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
		PR("�Ҳ�����ѧ��!\n");

}