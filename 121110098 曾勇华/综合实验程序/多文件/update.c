# include<stdio.h>
# include"student.h"
# include<string.h>
void update(int *count)//�޸ĸ�������
{
	char name[10],c;
	int i,flag,flag1,found,num;
	while(1)
	{
		found=0;
		flag1=1;
		PR("����Ҫ�������ݵ�ѧ��������");
		SC(S,name);
		for(i=0;i<*count;i++)
		{
			if(strcmp(name,stu[i].name)==0)
			{
				found=1;
				while(flag1)
				{
					update_boot();
					PR("�������ѡ��(0~5):");
					SC(D,&num);
					switch(num)
					{
						 case 0:
							 {
								 flag1=0;
								 break;
							 }
						 case 1:
							 {
								 PR("����ѧ��:");
								 SC(D,&stu[i].num);
								 PR("ѧ�����޸ģ����Լ����޸�������Ϣ.\n");
								 break;
							 }
						 case 2:
							 {
								 PR("�����ձ�:");
								 SC(S,stu[i].sex);
								 PR("�ձ����޸ģ����Լ����޸�������Ϣ.\n");
			                      break;
							 }
						 case 4:
							 {
								 PR("����ߵ���ѧ�ɼ�:");
								 SC(F,&stu[i].score[1]);
								 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
								 stu[i].score[4]=stu[i].score[3]/3;
								 PR("�óɼ����޸ģ����Լ����޸�������Ϣ.\n");
	                              break;
							 }
						 case 3:
							 {
								 PR("����C����:");
								 SC(F,&stu[i].score[0]);
								 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
								 stu[i].score[4]=stu[i].score[3]/3;	 
								 PR("�óɼ����޸ģ����Լ����޸�������Ϣ.\n");
                                 break;
							 }
						 case 5:
								 {
								 PR("����繤����:");
								 SC(F,&stu[i].score[2]);
								 stu[i].score[3]=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
								 stu[i].score[4]=stu[i].score[3]/3;
									 PR("�óɼ����޸ģ����Լ����޸�������Ϣ.\n");
							 break;

								 }
						 default:PR("�������!\n");break;
						 
					}
				}

			}
		}
		if(!found)
			PR("ѧ��%s����û���ҵ�������������������\n",name);
		if(found)
			show(count);
        PR("�������������ɾ��������1����:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//���˷������ַ�
				;
		if(flag==1)
			break;
	}


}