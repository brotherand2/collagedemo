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
			PR("�������ѡ��(0~6):");
			SC(D,&num);
			while(getchar()!=NL)//���˷����ֵ��ַ�
			;

			switch(num)
			{
			   case 0:flag=0;break;
			   case 1:sort_total(count);break;
			   case 2:sort_aver(count);break;
			   case 3:sort_num(count);break;
			   case 4:sort_data_struct(count);break;
			   case 5:sort_assembly(count);break;
			   case 6:sort_net(count);break;
			   default:PR("�������\n");break;
			}
			writefile(count);
			readstu(count);
			if(num>=1&&num<=6)
			{
				PR("ѧ��      ����      �ձ�      ���ݽṹ  �������  �������  �ܷ�      ƽ����\n");

				for(i=0;i<*count;i++)
				{
					PR("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.f%-10.2f\n",
						stu[i]->num,stu[i]->name,stu[i]->sex,stu[i]->score[0],
						stu[i]->score[1],stu[i]->score[2],stu[i]->score[3],stu[i]->score[4]);
					
				}
			}
		}
}