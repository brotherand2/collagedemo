# include<stdio.h>
#include <ctype.h>
# include"plane.h"
void myRealloc(int n)//����ռ䲻�������·����¿ռ�
{
	int i;
	if (n>addSize)//���ռ䲻������
		addSize = n * 2;//����ռ����ӱ�
	air = (InfoType**)realloc(air, addSize*sizeof(InfoType*));
	printf("�ռ䲻�㣡��ǰ�ռ�Ϊ:%d,�������ٷ���ռ���...\n", MaxSize);
	printf("�ռ������ɣ���ǰӵ�пռ���%d\n", addSize);
	for (i = MaxSize; i<addSize; i++)//Ϊ���ӵ�ָ�����ռ�
		air[i] = (InfoType*)malloc(sizeof(InfoType));
	MaxSize = addSize;//����ǰ�ռ�����ΪaddSize
	addSize *= 2;//��һ�����ռ䲻��������������
}
int strCmp(String str1, String str2)//�ַ����Ƚ�
{
	int i;
	String a, b;
	strcpy(a, str1);//��str1���Ƶ�a�������ƻ�str1
	strcpy(b, str2);//��str2���Ƶ�b�������ƻ�str2
	for (i = 0; i < strlen(a); i++)
		if (isupper(a[i]))//����Ǵ�д��ĸ��תΪСд��ĸ���Ƚ�
			a[i] = tolower(a[i]);
	for (i = 0; i < strlen(b); i++)
		if (isupper(b[i]))//����Ǵ�д��ĸ��תΪСд��ĸ���Ƚ�
			b[i] = tolower(b[i]);
	return  strcmp(a, b);
}
void readFile()
{
	FILE *fp;//�ļ�ָ��
	InfoType *p1, *p2;
	int i = 0;
	count = 0;
	if ((fp = fopen("������Ϣ����.txt", "r")) == NULL)//��ȡstudent.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
	p2 = p1 = air[0];
	while (!feof(fp))//feof(fp)��ʾ�ļ�β
	{
		if (i == MaxSize)
		{
			myRealloc(i);
		}
		p1 = air[i];
		fscanf(fp, S S S S S S S S,
			air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
			air[i]->info[5], air[i]->info[6], air[i]->info[7]);
		if (i>0)
		{
			p2->next = p1;
			p2 = p1;
		}
		i++;
	}
	p1->next = NULL;
	count = i - 1;//   //��֮���һ�а���һ�»��з������Զ���һ�У�������-1����Ҫ�����з�ɾ��
	/*λ�ú����ݵ����кβ�ͬ�أ��ٸ��򵥵����ӣ���������˵�����ߵ��𳵵����һ�ڳ��䡱�����λ�á�
	�����˵������һֱ����ߣ����������������������ݡ�Ҳ����˵���������жϻᡰ����һ�ڡ����������ȫ������
	��while(!feof(FP)){...}�������ļ�����ʱ��Ŀ���ĵ��ܻ��Դ�ĵ������һЩ����ԭ������countҪ��1*/
	fclose(fp);//�ر��ļ�ָ��
}
void writeFile()
{
	FILE *fp;//�ļ�ָ��
	int i = 0;
	if ((fp = fopen("������Ϣ����.txt", "w")) == NULL)//дstudent.txt�ļ�
	{
		PR("���ܴ��ļ�!\n");
		exit(0);//��ֹ����
	}
	for (i = 0; i < count; i++)
		fprintf(fp, " %-10s % -10s % -10s % -10s % -10s % -10s % -10s % -10s%s",
		air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
		air[i]->info[5], air[i]->info[6], air[i]->info[7], "\n");
	fclose(fp);//�ر��ļ�ָ��
}
void show_boot()//��ʾ�˵�
{
	PR("       ����������������������������������������������������������\n");
	PR("       �� <0>------��ʾ���                                    ��\n");
	PR("       �� <1>------�����������                                ��\n");
	PR("       �� <2>------�����ʱ������                              ��\n");
	PR("       �� <3>------������ʱ������                              ��\n");
	PR("       �� <4>------����������                                  ��\n");
	PR("       �� <5>------��Ʊ������                                  ��\n");
	PR("       ����������������������������������������������������������\n");
}
void search_boot()//��ѯ�˵�
{
	PR("       ��������������������������������������\n");
	PR("       ��   <0>--------��ѯ���            ��\n");
	PR("       ��   <1>--------������Ų�ѯ        ��\n");
	PR("       ��   <2>--------�����վ��ѯ        ��\n");
	PR("       ��   <3>--------���յ�վ��ѯ        ��\n");
	PR("       ��   <4>--------�������ڲ�ѯ        ��\n");
	PR("       ��   <5>--------�����ʱ���ѯ      ��\n");
	PR("       ��   <6>--------������ʱ���ѯ      ��\n");
	PR("       ��   <7>--------�����Ͳ�ѯ          ��\n");
	PR("       ��   <8>--------��Ʊ�۲�ѯ          ��\n");
	PR("       ��������������������������������������\n");
}

void PreProcess(int n)//����ǰԤ����
{
	int i, j;
	for (i = 0; i<count; i++)
	{
		for (j = strlen(air[i]->info[n]); j<MaxLen; j++)
			air[i]->info[n][j] = ' ';//��ʣ���ַ��ռ��ʼ��Ϊ���ַ����������򣬿��ַ����ȼ�Ϊ0
		air[i]->info[n][j] = '\0';//���һ���ַ���ʼ��Ϊ���ַ�
	}
}
void RadixSort(int n)//��������,nΪ�������࣬0-7���Ƿֱ��Ǻ���š����վ���յ�վ�������ڡ����ʱ�䡢����ʱ�䡢���͡�Ʊ���ַ���
{
	int i, j, k;//kΪ���ȼ����ַ����ȼ�Ϊ0������0-9���ȼ�Ϊ1-10����ĸa-z��A-Z���ȼ�Ϊ11-36
	InfoType **head, **tail, *p;//ͷָ����������βָ��������
	head = (InfoType **)malloc(sizeof(InfoType*) * 37);//37��ͷָ�룬�ֱ�ָ�������ַ���0-9����a-z
	tail = (InfoType **)malloc(sizeof(InfoType*) * 37);
	PreProcess(n);//����ǰԤ����
	for (i = MaxLen - 1; i >= 0; i--)//��ȥ���һλ'\0'���ֱ��ÿһλ�ַ���������
	{
		for (j = 0; j<37; j++)
			head[j] = tail[j] = NULL;//��ʼΪ��
		for (j = 0; j<count; j++)//����һ���±�Ϊi������
		{
			if (air[j]->info[n][i] >= '0'&&air[j]->info[n][i] <= '9')
				k = air[j]->info[n][i] - '0' + 1;//����0-9���ȼ�Ϊ1-10
			else
			{
				if (air[j]->info[n][i] >= 'a'&&air[j]->info[n][i] <= 'z')
				{
					k = air[j]->info[n][i] - 'a' + 11;//a - z���ȼ�Ϊ11 - 36
				}
				else if (air[j]->info[n][i] >= 'A'&&air[j]->info[n][i] <= 'Z')
				{
					k = air[j]->info[n][i] - 'A' + 11;//A - Z���ȼ�Ϊ11 - 36
				}
				else
				{
					k = 0; //���ַ��������ַ����ȼ�Ϊ0
				}
			}
			if (!head[k])
			{
				head[k] = air[j];
			}
			else
				tail[k]->next = air[j];
			tail[k] = air[j];
			tail[k]->next = NULL;
		}
		k = 0;
		for (j = 0; j<37; j++)//�����ռ�
		{
			p = head[j];
			while (p)
			{
				air[k] = p;
				k++;
				p = p->next;
			}
		}
	}
}
void binSearch(int n, String str)//���ֲ�ѯ,nΪ���࣬0-7���Ƿֱ��Ǻ���š����վ���յ�վ�������ڡ����ʱ�䡢����ʱ�䡢���͡�Ʊ���ַ���
{
	int i, j, found = 0;
	int low, high, mid;
	String name;
	PR("������Ҫ��ѯ��%s:", str);
	SC(S, name);
	for (j = strlen(name); j<MaxLen; j++)
		name[j] = ' ';//��ʣ���ַ��ռ��ʼ��Ϊ���ַ����������򣬿��ַ����ȼ�Ϊ0
	name[j] = '\0';//���һ���ַ���ʼ��Ϊ���ַ�
	low = 0, high = count - 1;
	RadixSort(n);//��ѯǰ������
	writeFile();
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strCmp(air[mid]->info[n], name) == 0)
		{
			found = 1;
			break;
		}
		else if (strCmp(air[mid]->info[n], name) < 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (!found)
		PR("�Ҳ�����%s��!\n", str);
	else
	{
		PR("�����    ���վ    �յ�վ    ������    ���ʱ��  ����ʱ��  ����      Ʊ��\n");
		for (i = mid; i >= 0 && strcmp(air[i]->info[n], name) == 0; i--)//�����ǰ�±������ȵļ�¼
			PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
			air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
			air[i]->info[5], air[i]->info[6], air[i]->info[7]);

		for (i = mid + 1; i <count&&strcmp(air[i]->info[n], name) == 0; i++)//�����ǰ�±��ұ���ȵļ�¼
			PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
			air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
			air[i]->info[5], air[i]->info[6], air[i]->info[7]);
	}
}
void commonSearch(int n, String str)//��ͨ��ѯ,һ������nΪ���࣬��ѯ���֣���������1-3���ֱ������վ���յ�վ���������ַ���
{
	int i, j, found = 0;
	String name;
	PR("������Ҫ��ѯ��%s:", str);
	SC(S, name);
	for (i = 0; i < count; i++)
	{
		if (strcmp(air[i]->info[n], name) == 0)
		{
			if (!found)
				PR("�����    ���վ    �յ�վ    ������    ���ʱ��  ����ʱ��  ����      Ʊ��\n");
			found = 1;
			PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
				air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
				air[i]->info[5], air[i]->info[6], air[i]->info[7]);
		}
	}
	if (!found)
		PR("�Ҳ�����%s��!\n", str);
}
void search()//��ѯ
{
	int num, flag = 1;
	if (count<1)
	{
		PR("�����ݣ�\n");
		return;
	}
	while (flag)
	{
		search_boot();
		PR("�������ѡ��(0~8):");
		SC(D, &num);
		while (getchar() != NL)//���˷����ֵ��ַ�
			;
		switch (num)
		{
		case 0:flag = 0; break;
		case 1:binSearch(0, "�����"); break;
		case 2:commonSearch(1, "���վ"); break;
		case 3:commonSearch(2, "�յ�վ"); break;
		case 4:commonSearch(3, "������"); break;
		case 5:binSearch(4, "���ʱ��"); break;
		case 6:binSearch(5, "����ʱ��"); break;
		case 7:binSearch(6, "����"); break;
		case 8:binSearch(7, "Ʊ��"); break;
		default:PR("�������!\n"); break;
		}
	}
}
void show()//��ʾ
{
	int flag = 1, i;
	if (count<1)
	{
		PR("�����ݣ�\n");
		return;
	}
	while (flag)
	{
		int num;
		show_boot();
		PR("�������ѡ��(0~5):");
		SC(D, &num);
		while (getchar() != NL)//���˷����ֵ��ַ�
			;

		switch (num)
		{
		case 0:flag = 0; break;
		case 1:RadixSort(0); break;//�����������
		case 2:RadixSort(4); break;//�����ʱ������
		case 3:RadixSort(5); break;//������ʱ������
		case 4:RadixSort(6); break;//����������
		case 5:RadixSort(7); break;//��Ʊ������
		default:PR("�������\n"); break;
		}
		writeFile();
		readFile();
		if (num >= 1 && num <= 5)
		{



			PR("�����    ���վ    �յ�վ    ������    ���ʱ��  ����ʱ��  ����      Ʊ��\n");
			for (i = 0; i<count; i++)
			{
				PR("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
					air[i]->info[0], air[i]->info[1], air[i]->info[2], air[i]->info[3], air[i]->info[4],
					air[i]->info[5], air[i]->info[6], air[i]->info[7]);
			}
		}
	}
}
void boot()
{
	PR("       ����������������������������������������������������������\n");
	PR("       �� <0>------����        (EXIT)                          ��\n");
	PR("       �� <1>------��ѯ����   ��SEARCH)                        ��\n");
	PR("       �� <2>------��ʾ���к���(SHOW)                          ��\n");
	PR("       ����������������������������������������������������������\n");
}
int main()
{
	int flag = 1, number, i;
	air = (InfoType **)malloc(N*sizeof(InfoType*));
	for (i = 0; i<N; i++)//Ĭ�ϸ���N��ѧ���ռ�
		air[i] = (InfoType*)malloc(sizeof(InfoType));
	MaxSize = N;///�ռ�������
	addSize = MaxSize * 2;//�ռ䲻������������ܸ���
	PR("121110098 ���»�   ������Ϣ��ѯϵͳ\n\n\n");
	readFile();
	while (flag)
	{
		boot();
		PR("�������ѡ��(0~2):");
		SC(D, &number);//������abc���󣬲��ܶ�ȡ,�򷵻�numberԭ��ַ����ֵ��������6abc��abc������
		while (getchar() != NL)//���˷����ֵ��ַ�
			;
		switch (number)
		{
		case 0:
		{
			flag = 0;
			break;
		}//�˳�
		case 1:
		{
			search();
			break;
		}//����������������
		case 2:
		{
			show();
			break;
		}//����������������
		default:PR("���������������.\n"); break;
		}
	}
	return 0;
}