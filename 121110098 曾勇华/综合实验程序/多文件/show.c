# include<stdio.h>
# include"student.h"
void show(int *count)//��ʾ
{
	int flag=1,i;
		if(*count<1)
		{
			PR("�����ݣ�\n");
			return;
		}
		while(flag)
		{
			int num;
			show_boot();
			PR("�������ѡ��(0~4):");
			SC(D,&num);
			while(getchar()!=NL)//���˷����ֵ��ַ�
			;

			switch(num)
			{
			   case 0:flag=0;break;
			   case 1:sort_total(count);break;
			   case 2:sort_aver(count);break;
			   case 3:sort_num(count);break;
			   case 4:sort_name(count);break;
			   default:PR("�������\n");break;
			}
			writefile(count);
			readstu(count);
			if(num>=1&&num<=4)
			{

				

				PR("ѧ��      ����      �ձ�      C����     �ߵ���ѧ  �繤����  �ܷ�      ƽ����\n");

				for(i=0;i<*count;i++)
				{
					PR("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.f%-10.2f\n",
						stu[i].num,stu[i].name,stu[i].sex,stu[i].score[0],
						stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4]);
					
				}
			}
		}
}