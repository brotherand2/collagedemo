# include<stdio.h>
# include"student.h"
# include<string.h>
void delet(int *count)//ɾ��
{
	
	char name[10];
	int flag,found,i,j;
	
	while(1)
	{
		if(*count<1)
		{
			PR("�������ݿ�ɾ��\n");
			return;
		}
		found=0;
		PR("����Ҫɾ�����ݵ�ѧ������:\n");
		SC(S,name);
		for(i=0;i<*count;i++)
		{
			if(strcmp(stu[i]->name,name)==0)
			{
				found=1;
				for(j=i;j<*count;j++)
					stu[j]=stu[j+1];
				(*count)--;
				i--;
					PR("%s��Ϣ��ɾ��!\n",name);

			}
		}
		if(!found)
			PR("�޸�ѧ����\n");
		show(count);
        PR("�������������ɾ��������1����:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//���˷������ַ�
				;
		if(flag==1)
			break;
	}
}