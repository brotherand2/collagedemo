# include<stdio.h>
# include"student.h"
void search(int *count)//��ѯ
{
	int num,flag=1;
	if(*count<1)
		{
			PR("�����ݣ�\n");
			return;
		}

	while(flag)
	{
		search_boot();
		PR("�������ѡ��(0~7):");
		SC(D,&num);
		while(getchar()!=NL)//���˷����ֵ��ַ�
			;

		switch(num)
		{
		   case 0:flag=0;break;
		   case 1:search_num(count);break;
		   case 2:search_name(count);break;
		   case 3:search_score(count,0);break;
		   case 4:search_score(count,1);break;
		   case 5:search_score(count,2);break;
		   case 6:search_score(count,3);break;
		   case 7:search_score(count,4);break;
		   default:PR("�������!\n");break;

		}

	}

}