# include<stdio.h>
# include<string.h>//Ϊʹ��strcmp()�ַ�������
# include<stdlib.h>//Ϊʹ��exit()�����ṩԭ��
# include"student.h"//����һ������ͷ�ļ�student.h��Ÿ��ֺ�ͺ���ԭ��
typedef struct STUDENT//��typedef������������
{
	int num;//ѧ��
	char name[10],sex[5];//�������ձ�
	float score[5];//�ߵ���ѧ��C���ԣ��繤�������� �֣�ƽ����
	
	struct STUDENT *next;
}student;//student �ȼ���struct STUDENT 
student stu[60];//ѧ��������60
student *p1=NULL,*p2=NULL,*head=NULL,*p;//ȫ�ֱ���
int count;//���ڶ�ȡ�ļ�ʱ��ѧ������
int main()
{
	int flag=1,number;
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
					input();
					break;
				}//����������������
			case 2:
				{
					readstu();
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}
					update();
					writefile();
				
					break;
				}//�޸ĸ�������
			case 3:
				{
					
					insert();
					
					break;
					
				}//����

			case 4:
				{
					readstu();
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}

					delet();
					writefile();
					break;
					
				}//ɾ��
			case 5:
				{
					readstu();
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}

					search();
					break;
					
				}//��ѯ
			case 6:
				{
					readstu();
					if(0==count)
					{
						PR("û��ѧ�����ݣ�������1���������ݡ�\n");
						continue;
					}

					show();
					break;
				}//��ʾ
			default:PR("���������������.\n");break;

		}
	}

	return 0;
}
void boot()//���˵�
{
    PR("       ��������������������������������������������\n");
	PR("       ��   <0>------(�˳�)Exit                  ��\n");
	PR("       ��   <1>------(����������������)Input     ��\n");
	PR("       ��   <2>------(�޸ĸ�������)Update        ��\n");
	PR("       ��   <3>------(����)Insert                ��\n");
	PR("       ��   <4>------(ɾ��)Delete                ��\n");
	PR("       ��   <5>------(��ѯ)Search                ��\n");
	PR("       ��   <6>------(��ʾ)Show                  ��\n");
	PR("       ��������������������������������������������\n");
	

}
void input()//����������������
{
	int n,i;
	FILE *fp;//�ļ�ָ��
	if((fp=fopen("student.txt","w"))==NULL)//����student.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
    do{
	PR("��Ҫ������ٸ�ѧ�����ݣ�(1~60)");
	SC(D,&n);
	while(getchar()!=NL)//���˷����ֵ��ַ�
		;

	if(n<1||n>60)
		PR("���������������!\n");
	}while(n<1||n>60);

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
		PR("C���Գɼ���");
		SC(F,&p1->score[0]);
		PR("�ߵ���ѧ:");
		SC(F,&p1->score[1]);
		PR("�繤����:");
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
void readstu()//���ڶ�ȡ�ļ�ʱ��ѧ������
{	
	FILE *fp;//�ļ�ָ��

    int i=0;
	count=0;
	if((fp=fopen("student.txt","r"))==NULL)//��ȡstudent.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
    head=p2=p1=&stu[0];
	while(!feof(fp))//feof(fp)��ʾ�ļ�β
	{
		p1=&stu[i];
		
		fscanf(fp,D S S F F F F F,
			&stu[i].num,stu[i].name,stu[i].sex,&stu[i].score[0],
			&stu[i].score[1],&stu[i].score[2],&stu[i].score[3],&stu[i].score[4]);
		if(i>0)
		{
		p2->next=p1;
		p2=p1;
		}
        i++;
	}
	p1->next=NULL;
    count=i-1;/*λ�ú����ݵ����кβ�ͬ�أ��ٸ��򵥵����ӣ���������˵�����ߵ��𳵵����һ�ڳ��䡱�����λ�á�
			  �����˵������һֱ����ߣ����������������������ݡ�Ҳ����˵���������жϻᡰ����һ�ڡ����������ȫ������
			  ��while(!feof(FP)){...}�������ļ�����ʱ��Ŀ���ĵ��ܻ��Դ�ĵ������һЩ����ԭ������countҪ��1*/

	fclose(fp);//�ر��ļ�ָ��
}
void update()//�޸ĸ�������
{
	char name[10],c;
	int i,flag=1,flag1,found,num;
	while(flag)
	{
		found=0;
		flag1=1;
		PR("����Ҫ�������ݵ�ѧ��������");
		SC(S,name);
		for(i=0;i<count;i++)
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
			show();
		PR("�Ƿ�����������������޸�(y/n)?");
		getchar();//���ջ��з�
		c=getchar();
		if(c=='n'||c=='N')
			flag=0;
	}


}
void update_boot()//�޸����ݵĲ˵�
{
	PR("       ��������������������������������������\n"); 
	PR("       ��   <0>--------�޸����            ��\n"); 
	PR("       ��   <1>--------�޸�ѧ��            ��\n");
	PR("       ��   <2>--------�޸��ձ�            ��\n"); 
	PR("       ��   <3>--------�޸�C���Գɼ�       ��\n"); 
	PR("       ��   <4>--------�޸ĸߵ���ѧ�ɼ�    ��\n");
	PR("       ��   <5>--------�޸ĵ繤�����ɼ�    ��\n");
	PR("       ��������������������������������������\n");


}
void writefile()//������д��student.txt�ļ�
{
	int i;
	FILE *fp;//�ļ�ָ��
	if((fp=fopen("student.txt","w"))==NULL)//����student.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
	for(i=0;i<count;i++)
	{
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			stu[i].num,' ',stu[i].name,' ',stu[i].sex,' ',stu[i].score[0],' ',
			stu[i].score[1],' ',stu[i].score[2],' ',stu[i].score[3],' ',stu[i].score[4],NL);

	}
	fclose(fp);

}
void insert()//����
{
	    
		int flag;
	    student temp;//��ʱ�ṹ�����
	while(1)
	{
		FILE *fp;//�ļ�ָ��
		if((fp=fopen("student.txt","a"))==NULL)//��student.txt�ļ�׷��ѧ����Ϣ
		{
			PR("���ܴ��ļ�!\n");
			exit(0);//��ֹ����
		}
		p1=&temp;
	
		PR("ѧ��:");
		SC(D,&p1->num);
		getchar();
		PR("������");
		SC(S,p1->name);
		PR("�Ա�");
		SC(S,p1->sex);
		PR("C���Գɼ���");
		SC(F,&p1->score[0]);
		PR("�ߵ���ѧ:");
		SC(F,&p1->score[1]);
		PR("�繤����:");
		SC(F,&p1->score[2]);
		p1->score[3]=p1->score[0]+p1->score[1]+p1->score[2];//�ܷ�
		p1->score[4]=p1->score[3]/3;//ƽ����
		fprintf(fp,"%d%c%s%c%s%c%.2f%c%.2f%c%.2f%c%.2f%c%.2f%c",
			p1->num,' ',p1->name,' ',p1->sex,' ',p1->score[0],' ',
			p1->score[1],' ',p1->score[2],' ',p1->score[3],' ',p1->score[4],NL);
		fclose(fp);
	    PR("����ɹ���\n");
		readstu();
		show();
        PR("�������������������1����:");
		if((SC(D,&flag))!=1)
			while(getchar()!='\n')//���˷������ַ�
				;
		if(flag==1)
			break;
	}



}
void delet()//ɾ��
{
	char c;
	char name[10];
	int flag=1,found,i,j;
	
	while(flag)
	{
		if(count<1)
		{
			PR("�������ݿ�ɾ��\n");
			return;
		}
		found=0;
		PR("����Ҫɾ�����ݵ�ѧ������:\n");
		SC(S,name);
		for(i=0;i<count;i++)
		{
			if(strcmp(stu[i].name,name)==0)
			{
				found=1;
				for(j=i;j<count;j++)
					stu[j]=stu[j+1];
				count--;
				i--;
					PR("%s��Ϣ��ɾ��!\n",name);

			}
		}
		if(!found)
			PR("�޸�ѧ����\n");
		show();
		PR("����ɾ�����(y/n)");
		c=getchar();
		if(c=='n'||c=='N')
			flag=0;

	}


}
void show()//��ʾ
{
	int flag=1,i;
		if(count<1)
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
			   case 1:sort_total();break;
			   case 2:sort_aver();break;
			   case 3:sort_num();break;
			   case 4:sort_name();break;
			   default:PR("�������\n");break;
			}
			writefile();
			readstu();
			if(num>=1&&num<=4)
			{

				

				PR("ѧ��      ����      �ձ�      C����     �ߵ���ѧ  �繤����  �ܷ�      ƽ����\n");

				for(i=0;i<count;i++)
				{
					PR("%-10d%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.f%-10.2f\n",
						stu[i].num,stu[i].name,stu[i].sex,stu[i].score[0],
						stu[i].score[1],stu[i].score[2],stu[i].score[3],stu[i].score[4]);
					
				}
			}
		}
}
void show_boot()//��ʾ�˵�
{
	PR("       ����������������������������������������������������������\n");
	PR("       �� <0>------��ʾ���                                    ��\n");
	PR("       �� <1>------���ֵܷݼ�������ʾѧ����Ϣ��ƽ������        ��\n");
	PR("       �� <2>------��ƽ���ֵݼ�������ʾѧ����Ϣ��ƽ������      ��\n");
	PR("       �� <3>------��ѧ�ŵݼ�������ʾѧ����Ϣ��ƽ������        ��\n");
	PR("       �� <4>------�������ݼ�������ʾѧ����Ϣ��ƽ������        ��\n");  
	PR("       ����������������������������������������������������������\n");
}
void sort_total()//���ֵܷݼ�����
{
	int i,j;
	student temp;
	for(i=0;i<count-1;i++)//ð������
	{
		for(j=0;j<count-1-i;j++)
		{
			if(stu[j].score[3]<stu[j+1].score[3])
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}

		}
	}
}
void sort_aver()//��ƽ���ֵݼ�����
{
	int i,j,k;
	float max;
	student temp;
	for(i=0;i<count-1;i++)//ѡ������
	{
		k=i;
		
		for(j=i+1;j<count;j++)
		{
			max=stu[k].score[4];
			if(stu[j].score[4]>max)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			temp=stu[i];
			stu[i]=stu[k];
			stu[k]=temp;
		}
	}

}
void sort_num()//��ѧ�ŵݼ�����
{
	int i,j;
	student temp;
	for(i=0;i<count-1;i++)//ð������
	{
		for(j=i+1;j<count;j++)
		{
			if(stu[i].num<stu[j].num)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}

		}
	}
}
void sort_name()//�������ݼ�����
{
	int i,j;
	student temp;
	for(i=0;i<count-1;i++)//ð������
	{
		for(j=0;j<count-1-i;j++)
		{
			if(strcmp(stu[j].name,stu[j+1].name)<0)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}

		}
	}
}
void search()//��ѯ
{
	int num,flag=1;
	if(count<1)
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
		   case 1:search_num();break;
		   case 2:search_name();break;
		   case 3:search_score(0);break;
		   case 4:search_score(1);break;
		   case 5:search_score(2);break;
		   case 6:search_score(3);break;
		   case 7:search_score(4);break;
		   default:PR("�������!\n");break;

		}

	}

}
void search_boot()//��ѯ�˵�
{
	PR("       ��������������������������������������\n"); 
	PR("       ��   <0>--------��ѯ���            ��\n"); 
	PR("       ��   <1>--------��ѧ�Ų�ѯ          ��\n");
	PR("       ��   <2>--------��������ѯ          ��\n"); 
	PR("       ��   <3>--------��C���Գɼ���ѯ     ��\n"); 
	PR("       ��   <4>--------���ߵ���ѧ�ɼ���ѯ  ��\n");
	PR("       ��   <5>--------���繤�����ɼ���ѯ  ��\n");
	PR("       ��   <6>--------���ֲܷ�ѯ          ��\n");
	PR("       ��   <7>--------��ƽ���ֲ�ѯ        ��\n");
	PR("       ��������������������������������������\n");
}
void search_num()//��ѧ�Ų�ѯ
{
	int i,j,num,found=0;
	PR("������Ҫ��ѯ��ѧ��:");
	SC(D,&num);
	while(getchar()!=NL)//���˷����ֵ��ַ�
	;

	for(i=0;i<count;i++)
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
void search_name()//��������ѯ
{
	int i,j,found=0;
	char name[10];
	PR("������Ҫ��ѯ������:");
	SC(S,name);
	for(i=0;i<count;i++)
	{
		if(strcmp(name,stu[i].name)==0)
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
		PR("�Ҳ�����������!\n");

}


void search_score(int n)//���ɼ���ѯ
{
    char score_name[5][10]={"C����","�ߵ���ѧ","�繤����","�ܷ�","ƽ����"};
	float score;
	int i,j,found=0;

	PR("������Ҫ��ѯ��%s�ɼ���",score_name[n]);
	SC(F,&score);
	for(i=0;i<count;i++)
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

