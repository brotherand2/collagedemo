# include<stdio.h>
# include<stdlib.h>//Ϊʹ��exit()�����ṩԭ��
# include"student.h"//����һ������ͷ�ļ�student.h��Ÿ��ֺ�ͺ���ԭ��
int count;
int main()
{
	int flag=1,number,i;
	stu=(student **)malloc(N*sizeof(sizeof(student*)));
	for(i=0;i<N;i++)//Ĭ�ϸ���N��ѧ���ռ�
		stu[i]=(student*)malloc(sizeof(student));
	studentSize=N;///ѧ���ռ�������
    addSize=studentSize*2;//�ռ䲻������������ܸ���
	printf("121110098   ���»�   ѧ���ɼ�����\n");
	while(flag)
	{
		boot();
		PR("�������ѡ��(0~6):");
		SC(D,&number);//������abc���󣬲��ܶ�ȡ,�򷵻�numberԭ��ַ����ֵ��������6abc��abc������
		while(getchar()!=NL)//���˷����ֵ��ַ�
			;
		switch(number)
		{
			case 0:
				{
					flag=0;
					break;
				}//�˳�
			case 1:
				{
					input(&count);
					break;
				}//����������������
			case 2:
				{
					readstu(&count);
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}
					update(&count);
					writefile(&count);
					break;
				}//�޸ĸ�������
			case 3:
				{	
					insert(&count);
					break;
				}//����
			case 4:
				{
					readstu(&count);
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}
					delet(&count);
					writefile(&count);
					break;					
				}//ɾ��
			case 5:
				{
					readstu(&count);
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}
					search(&count);
					break;					
				}//��ѯ
			case 6:
				{
					readstu(&count);
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}
					show(&count);
					break;
				}//��ʾ
			default:PR("���������������.\n");break;
		}
	}
	destroy();
	return 0;
}
void destroy()//��������
{
	int i;
	for (i = 0; i < studentSize; i++)
		free(stu[i]);
	free(stu);
}