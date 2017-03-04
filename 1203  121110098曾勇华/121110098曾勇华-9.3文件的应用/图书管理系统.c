# include<stdio.h>
# include"book.h"
void init()//��ʼ��
{
	int i;
	//��ʼ���鼮����
	books.count = 0;
	books.MaxSize = N;
	books.book = (BookDataType*)malloc(N*sizeof(BookDataType));

	//��ʼ�����������ߡ�������ιؼ�������
	for (i = 0; i < 3; i++)
	{
		otherkey[i].count = 0;
		otherkey[i].key = (OtherKey  *)malloc(N*sizeof(OtherKey));
		otherkey[i].MaxSize = N;
	}
	//��ʼ�����ؼ�������
	keys.count = 0;
	keys.key = (Key  *)malloc(sizeof(Key)*N);
	keys.MaxSize = N;
	//��ʼ����ʼ�����ؼ�����������
	readers.count = 0;
	readers.MaxSize = N;
	readers.reader = (ReaderType  *)malloc(N*sizeof(ReaderType));
	//��ʼ�����黹������
	renter.count = 0;
	renter.MaxSize = N;
	renter.rent = (BookRentType*)malloc(N*sizeof(BookRentType));
}
void Realloc(int i)//�ռ�����20��������iΪ���ͺţ�iΪ0-6�ֱ�Ϊ���������͡������͡��������͡�ͼ�����͡�����͡������͡��軹��ʷ�Ϳռ�
{
	switch (i)
	{
	case 0:
		otherkey[0].key = (OtherKey*)realloc(otherkey[0].key, (otherkey[0].MaxSize + addSize)*sizeof(OtherKey));//�ռ�����adSize��
		otherkey[0].MaxSize +=  addSize;
		break;
	case 1:
		otherkey[1].key = (OtherKey*)realloc(otherkey[1].key, (otherkey[1].MaxSize + addSize)*sizeof(OtherKey));//�ռ�����adSize��
		otherkey[1].MaxSize += addSize;
		break;
	case 2:
		otherkey[2].key = (OtherKey*)realloc(otherkey[2].key, (otherkey[2].MaxSize + addSize)*sizeof(OtherKey));//�ռ�����adSize��
		otherkey[2].MaxSize += addSize;
		break;
	case 3:
		books.book = (BookDataType*)realloc(books.book, (books.MaxSize + addSize)*sizeof(BookDataType));//�ռ�����adSize��
		books.MaxSize+= addSize;
		break;
	case 4:
		keys.key = (Key*)realloc(keys.key, (keys.MaxSize + addSize)*sizeof(Key));//�ռ�����adSize��
		keys.MaxSize+= addSize;
		break;
	case 5:
		readers.reader = (ReaderType*)realloc(readers.reader, (readers.MaxSize + addSize)*sizeof(ReaderType));//�ռ�����adSize��
		readers.MaxSize += addSize;
		break;
	case 6:
		renter.rent = (BookRentType*)realloc(renter.rent, (renter.MaxSize + addSize)*sizeof(BookRentType));//�ռ�����adSize��
		renter.MaxSize+= addSize;
		break;
	default:break;
	}
}
void readFile()
{
	int i,j;
	FILE *bookFile, *keyFile, *otherkeyFile[3], *readerFile, *renterFile;
	if ((bookFile = fopen("ͼ���������ļ�.txt", "r")) == NULL)//��ȡͼ���������ļ�.txt�ļ�
	{
		PR("���ܴ�ͼ���������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((keyFile = fopen("��������ļ�.txt", "r")) == NULL)//��ȡ��������ļ�.txt�ļ�
	{
		PR("���ܴ���������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((otherkeyFile[0] = fopen("���������ļ�.txt", "r")) == NULL)//��ȡ���������ļ�.txt�ļ�
	{
		PR("���ܴ����������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((otherkeyFile[1] = fopen("���������ļ�.txt", "r")) == NULL)//��ȡ���������ļ�.txt�ļ�
	{
		PR("���ܴ����������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((otherkeyFile[2] = fopen("�����������ļ�.txt", "r")) == NULL)//��ȡ�����������ļ�.txt�ļ�
	{
		PR("���ܴ򿪳����������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((readerFile = fopen("�����ļ�.txt", "r")) == NULL)//��ȡ�����ļ�.txt�ļ�
	{
		PR("���ܴ򿪶����ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((renterFile = fopen("���黹����ʷ.txt", "r")) == NULL)//��ȡ���黹����ʷ.txt�ļ�
	{
		PR("���ܴ򿪽��黹����ʷ.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	i = 0;
	while (!feof(bookFile))
	{
		if (i == books.MaxSize)//�ռ䲻��
		{
			Realloc(3);
		}
		fscanf(bookFile, D D S D S D S D D D D,& books.book[i].record, &books.book[i].id,
			books.book[i].name, &books.book[i].point[0], books.book[i].author,& books.book[i].point[1],
			books.book[i].publish, &books.book[i].point[2],& books.book[i].sort, &books.book[i].storenum,& books.book[i].len);
		i++;
	}
	books.count = i - 1;
	//��ȡ��������ļ���Ϣ
	i = 0;
	while (!feof(keyFile))
	{
		if (i == keys.MaxSize)//�ռ䲻��
		{
			Realloc(4);
		}
		fscanf(keyFile,D D,&keys.key[i].id,&keys.key[i].point);
		i++;
	}
	keys.count = i - 1;
	//��ȡ���������ߡ�������������Ϣ
	for (j = 0; j < 3; j++)
	{
		i = 0;
		while (!feof(otherkeyFile[j]))
		{
			if (i == otherkey[j].MaxSize)//�ռ䲻��
			{
				Realloc(j);
			}
			fscanf(otherkeyFile[j], S D D, otherkey[j].key[i].name,& otherkey[j].key[i].point,& otherkey[j].key[i].len);
			i++;
		}
		otherkey[j].count = i - 1;
	}
	//��ȡ�����ļ���Ϣ
	i = 0;
	while (!feof(readerFile))
	{
		if (i == readers.MaxSize)//�ռ䲻��
		{
			Realloc(5);
		}
		fscanf(readerFile, D S D D,&readers.reader[i].id,&readers.reader[i].name, &readers.reader[i].canrent, &readers.reader[i].rented);
		i++;
	}
	readers.count = i - 1;
	//��ȡ���黹����ʷ�ļ���Ϣ
	i = 0;
	while (!feof(renterFile))
	{
		if (i == renter.MaxSize)//�ռ䲻��
		{
			Realloc(6);
		}
		fscanf(renterFile, D D S S, &renter.rent[i].readerID, &renter.rent[i].bookID, renter.rent[i].rendDate, renter.rent[i].backDate);
		i++;
	}
	renter.count = i - 1;
	//�ر��ļ���
	fclose(bookFile);
	fclose(keyFile);
	fclose(otherkeyFile[0]);
	fclose(otherkeyFile[1]);
	fclose(otherkeyFile[2]);
	fclose(readerFile);
	fclose(renterFile);
}
void writeFile()
{
	int i, j;
	FILE *bookFile, *keyFile, *otherkeyFile[3], *readerFile, *renterFile;
	if ((bookFile = fopen("ͼ���������ļ�.txt", "w")) == NULL)//��ȡͼ���������ļ�.txt�ļ�
	{
		PR("���ܴ�ͼ���������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((keyFile = fopen("��������ļ�.txt", "w")) == NULL)//��ȡ��������ļ�.txt�ļ�
	{
		PR("���ܴ���������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((otherkeyFile[0] = fopen("���������ļ�.txt", "w")) == NULL)//��ȡ���������ļ�.txt�ļ�
	{
		PR("���ܴ����������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((otherkeyFile[1] = fopen("���������ļ�.txt", "w")) == NULL)//��ȡ���������ļ�.txt�ļ�
	{
		PR("���ܴ����������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((otherkeyFile[2] = fopen("�����������ļ�.txt", "w")) == NULL)//��ȡ�����������ļ�.txt�ļ�
	{
		PR("���ܴ򿪳����������ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((readerFile = fopen("�����ļ�.txt", "w")) == NULL)//��ȡ�����ļ�.txt�ļ�
	{
		PR("���ܴ򿪶����ļ�.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	if ((renterFile = fopen("���黹����ʷ.txt", "w")) == NULL)//��ȡ���黹����ʷ.txt�ļ�
	{
		PR("���ܴ򿪽��黹����ʷ.txt�ļ�!\n");
		exit(0);//��ֹ����
	}
	//д���鼮��Ϣ
	for (i = 0; i < books.count;i++)
		fprintf(bookFile, "%-10d%-10d%-15s%-10d%-15s%-10d%-15s%-10d%-10d%-10d%-10d%s", books.book[i].record, books.book[i].id,
			books.book[i].name,books.book[i].point[0], books.book[i].author,books.book[i].point[1],
			books.book[i].publish,books.book[i].point[2],books.book[i].sort,books.book[i].storenum,books.book[i].len,"\n");
	//д������ļ���Ϣ
	for (i = 0; i < keys.count;i++)
		fprintf(keyFile,"%-10d%-10d%s",keys.key[i].id,keys.key[i].point,"\n");

	//д�����������ߡ�������������Ϣ
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < otherkey[j].count;i++)
			fprintf(otherkeyFile[j],"%-10s%-10d%-10d%s", otherkey[j].key[i].name,otherkey[j].key[i].point,otherkey[j].key[i].len,"\n");
	}
	//д������ļ���Ϣ
	for (i = 0; i < readers.count;i++)
		fprintf(readerFile,"%-10d%-10s%-10d%-10d%s",readers.reader[i].id,readers.reader[i].name,readers.reader[i].canrent,readers.reader[i].rented,"\n");
	//д����黹����ʷ�ļ���Ϣ
	for (i = 0; i < renter.count;i++)
		fprintf(renterFile,"%-10d%-10d%-10s%-10s%s",renter.rent[i].readerID,renter.rent[i].bookID,renter.rent[i].rendDate, renter.rent[i].backDate,"\n");
	//�ر��ļ���
	fclose(bookFile);
	fclose(keyFile);
	fclose(otherkeyFile[0]);
	fclose(otherkeyFile[1]);
	fclose(otherkeyFile[2]);
	fclose(readerFile);
	fclose(renterFile);
}
void DispBook()//��������鼮��Ϣ
{
	int i;
	PR("��¼�����  ����      ָ��1 ����      ָ��2 ������    ָ��3 ����  �����������\n");
	for (i = 0; i < books.count; i++)
		PR("%-6d%-6d%-10s%-6d%-10s%-6d%-10s%-6d%-6d%-6d%-6d\n", books.book[i].record, books.book[i].id,
		books.book[i].name, books.book[i].point[0], books.book[i].author, books.book[i].point[1],
		books.book[i].publish, books.book[i].point[2], books.book[i].sort, books.book[i].storenum, books.book[i].len);
	PR("\n");
}
void DispBookID()//������������Ϣ
{
	int i;
	PR("���      ��¼��\n");
	for (i = 0; i < keys.count; i++)
		PR("%-10d%-3d\n", keys.key[i].id, keys.key[i].point);
	PR("\n");
}
void DispBookOtherKey(String name,int n)//����ιؼ���������Ϣ��0-2�ֱ�Ϊ������������Ϣ��������������������Ϣ
{
	int i;
	PR("%-10s��ͷָ��  ����\n",name);
	for (i = 0; i < otherkey[n].count; i++)
		PR("%-10s%-10d%-10d\n", otherkey[n].key[i].name, otherkey[n].key[i].point, otherkey[n].key[i].len);
	PR("\n");
}
void DispReader()//���������Ϣ
{
	int i;
	PR("���ߺ�    ������    �ɹ�����  �ѽ�����\n");
	for (i = 0; i < readers.count; i++)
		PR("%-10d%-10s%-10d%-10d\n", readers.reader[i].id, readers.reader[i].name , readers.reader[i].canrent, readers.reader[i].rented);
	PR("\n");
}
void DispBookRent()//����鼮���軹��ʷ��Ϣ
{
	int i;
	PR("���ߺ�    ���      ��������  ��������\n");
	for (i = 0; i < renter.count; i++)
		PR("%-10d%-10d%-10s%-10s\n", renter.rent[i].readerID, renter.rent[i].bookID, renter.rent[i].rendDate, renter.rent[i].backDate);
	PR("\n");
}
void search_boot()//��ѯ�˵�
{
	PR("       ��������������������������������������\n");
	PR("       ��   <0>--------��ѯ���            ��\n");
	PR("       ��   <1>--------����Ų�ѯ          ��\n");
	PR("       ��   <2>--------��������ѯ          ��\n");
	PR("       ��   <3>--------�����߲�ѯ          ��\n");
	PR("       ��   <4>--------���������ѯ        ��\n");
	PR("       ��������������������������������������\n");
}
int binSearch(int id)//���ֲ������
{
	int i, low, high,mid;
	if (keys.count<1)
	{
		return -1;
	}
	low = 0, high = keys.count - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (id==keys.key[mid].id)
		{
			i = keys.key[mid].point-1;
			return i;
		}
		else
			if (id> keys.key[mid].id)
				low = mid + 1;
			else
				high = mid - 1;
	}
	return -1;
}
int commonSearch(String name, int n)//���ιؼ���������ѯ��0-2�ֱ�Ϊ������������Ϣ��������������������Ϣ
{
	int i,k;	
	if (otherkey[n].count<1)
	{
		return -1;
	}
	for (i= 0; i < otherkey[n].count; i++)
	{
		if (strcmp(name, otherkey[n].key[i].name) == 0)
		{
			return i;
			break;
		}
	}
	return -1;
}
void showBookRecord(int i)//��ʾ�鼮��һ����¼��iΪ�ü�¼�����±�
{
	PR("%-10d%-10s%-10s%-10s%-10d%-10d\n", books.book[i].id,
		books.book[i].name, books.book[i].author, books.book[i].publish, books.book[i].sort, books.book[i].storenum - books.book[i].len);
}
void search()//��ѯ
{
	int num,id, flag = 1,i;
	String name;
	while (flag)
	{
		num = -1;//��ʼ��Ϊ-1
		search_boot();
		PR("�������ѡ��(0~4):");
		SC(D, &num);
		while (getchar() != '\n')//���˷����ֵ��ַ�
			;
		switch (num)
		{
		case 0:flag = 0; break;
		case 1:
			PR("����Ҫ��ѯ����ţ�");
			SC("%d", &id);
			i=binSearch(id);
			if (-1 == i)
				PR("û�����%d�ļ�¼\n", id);
			else
			{
				PR("���      ����      ����      ������    ����      �ɹ���\n");
				showBookRecord(i);		
			}
			break;////���ֲ������
		case 2:
			PR("����Ҫ��ѯ��������");
			SC("%s", name);
			i=commonSearch(name,0);
			if (i==-1)
				PR("û������%s�ļ�¼\n", name);
			else
			{
				PR("���      ����      ����      ������    ����      �ɹ���\n");
				for (i = otherkey[0].key[i].point; i != 0; i = books.book[i - 1].point[0])
					showBookRecord(i - 1);//�±�Ϊ��¼�ż�1
			}
			break;
		case 3:
			PR("����Ҫ��ѯ���������֣�");
			SC("%s", name);
			i = commonSearch(name, 1);
			if (i == -1)
				PR("û������%s�ļ�¼\n", name);
			else
			{
				PR("���      ����      ����      ������    ����      �ɹ���\n");
				for (i = otherkey[1].key[i].point; i != 0; i = books.book[i - 1].point[1])
					showBookRecord(i - 1);//�±�Ϊ��¼�ż�1
			}
			break;
		case 4:
			PR("����Ҫ��ѯ�ĳ��������֣�");
			SC("%s", name);
			i = commonSearch(name, 2);
			if (i == -1)
				PR("û�г�����%s�ļ�¼\n", name);
			else
			{
				PR("���      ����      ����      ������    ����      �ɹ���\n");
				for (i = otherkey[2].key[i].point; i != 0; i = books.book[i - 1].point[2])
					showBookRecord(i - 1);//�±�Ϊ��¼�ż�1
			}
			break;
		default:
			PR("�������!\n"); break;
		}
	}
}
void AdjustBookId()//������ż�¼
{
	int i,j,k;
	i = books.count-1;//�鼮�ļ�¼��
	j = keys.count-1;//������ż�¼��
	while (j >= 0)
	{
		if (books.book[i].id >= keys.key[j].id)
		{
			break;
		}
		j--;
	}
	k = j + 1;
	if (keys.count == keys.MaxSize)//�ռ�����
		Realloc(4);
	if (keys.count > 0)//��������
	{
		for (j = keys.count - 1; j >= k; j--)
			keys.key[j + 1] = keys.key[j];//��¼����
	}
	keys.key[k].id = books.book[i].id;//��¼����
	keys.key[k].point = books.count;
	keys.count++;//��ż�¼������1
}
void AdjustOtherKey(int n)//nΪ���ͺţ�0-2�ֱ����������¼�����߼�¼���������¼
{
	int i, j, k;
	int count;
	String name;
	count = books.count;
	switch (n)
	{
	case 0:
	    strcpy(name,books.book[count - 1].name);
		break;
	case 1:
		strcpy(name, books.book[count - 1].author);
		break;
	case 2:
		strcpy(name, books.book[count - 1].publish);
		break;
	}
	k = commonSearch(name, n);
	if (k != -1)
	{
		books.book[count - 1].point[n] = otherkey[n].key[k].point;
		otherkey[n].key[k].point = count;
		otherkey[n].key[k].len++;
	}
	else
	{
		k = otherkey[n].count;//�ιؼ��ּ�¼����
		if (otherkey[n].count == otherkey[n].MaxSize)
			Realloc(n);
		books.book[count - 1].point[n] = 0;
		otherkey[n].key[k].point = count;
		otherkey[n].key[k].len=1;
		strcpy(otherkey[n].key[k].name, name);
		otherkey[n].count++;//��¼������1
	}
}
void addBook()//�����鼮��¼
{
	int flag = 1, number, i;
	while (flag)
	{ 
		number = -1;
		i = books.count;//iΪ��ǰ�鼮���͵ĳ���
		if (books.count == books.MaxSize)//�ռ�����
			Realloc(3);
		books.count++;//��¼������1
		PR("������");
		PR("���      ����      ����      ������    ����      ������\n");
		SC(D S S S D D, &books.book[i].id, books.book[i].name, books.book[i].author, books.book[i].publish, &books.book[i].sort, &books.book[i].storenum);
		books.book[i].record = i + 1;
		books.book[i].len = 0;
		AdjustBookId();
		AdjustOtherKey(0);
		AdjustOtherKey(1);
		AdjustOtherKey(2);
		PR("�����������(����1����������������):");
		SC(D,&number);
		while (getchar() != NL)//���˷����ֵ��ַ�
			;
		if (number != 1)
			flag = 0;
	}
}
void boot()//���˵�
{
	PR("       ��������������������������������������������\n");
	PR("       ��   <0>------(�˳�)Exit                  ��\n");
	PR("       ��   <1>------(ͼ����Ϣ����)Input         ��\n");
	PR("       ��   <2>------(������Ϣ¼��)Add           ��\n");
	PR("       ��   <3>------(���鴦��)Rent              ��\n");
	PR("       ��   <4>------(���鴦��)Back              ��\n");
	PR("       ��   <5>------(ͼ���ѯ)Search            ��\n");
	PR("       ��   <6>------(��ʾ�ļ���Ϣ)Show          ��\n");
	PR("       ��������������������������������������������\n");
}
void show_boot()//��ʾ�˵�
{
	PR("       ����������������������������������������������������������\n");
	PR("       �� <0>------��ʾ���                                    ��\n");
	PR("       �� <1>------��ʾ�鼮�ļ���Ϣ                            ��\n");
	PR("       �� <2>------��ʾ��������ļ���Ϣ                        ��\n");
	PR("       �� <3>------��ʾ���������ļ���Ϣ                        ��\n");
	PR("       �� <4>------��ʾ���������ļ���Ϣ                        ��\n");
	PR("       �� <5>------��ʾ�����������ļ���Ϣ                      ��\n");
	PR("       �� <6>------��ʾ�����ļ���Ϣ                            ��\n");
	PR("       �� <7>------��ʾ���黹����ʷ�ļ���Ϣ                    ��\n");
	PR("       ����������������������������������������������������������\n");
}
void show()//��ʾ
{
	int flag = 1, i;
	int num;
	while (flag)
	{
		num = -1;//��ʼ��Ϊ-1
		show_boot();
		PR("�������ѡ��(0~7):");
		SC(D, &num);
		while (getchar() != NL)//���˷����ֵ��ַ�
			;
		switch (num)
		{
		case 0:flag = 0; break;
		case 1:DispBook(); break;//��ʾ�鼮�ļ���Ϣ
		case 2:DispBookID(); break;//��ʾ��������ļ���Ϣ
		case 3:DispBookOtherKey("����", 0); break;//��ʾ���������ļ���Ϣ 
		case 4:DispBookOtherKey("����", 1); break;//��ʾ���������ļ���Ϣ
		case 5:DispBookOtherKey("������", 2); break;//��ʾ�����������ļ���Ϣ
		case 6:DispReader(); break;//��ʾ�����ļ���Ϣ 
		case 7:DispBookRent(); break;//��ʾ���黹����ʷ�ļ���Ϣ 
		default:PR("�������\n"); break;
		}
	}
}
void BorrowBook()//����
{
	int readerID, bookID,k,i,j;
	int flag = 1, number;
	String date;
	while (flag)
	{
		number = -1;
		PR("������ߺ�  ���   ��������\n");
		SC(D D S, &readerID, &bookID, date);
		j = -1;
		for (i = 0; i < readers.count; i++)
		{
			if (readerID == readers.reader[i].id)
			{
				j = i;
				break;
			}
		}
		if (j == -1)
		{
			PR("�����������ߺ�%d,������ȷ�Ķ��ߺ�\n", readerID);
			return;
		}
		if (readers.reader[j].rented >= readers.reader[j].canrent)//��������
		{
			PR("��������%d,�뻹��һЩ���������\n", readers.reader[j].canrent);
			return;
		}
		k = binSearch(bookID);
		if (-1 == k)
		{
			PR("ͼ���û�����%d,��������ȷ�����\n", bookID);
			return;
		}
		if (books.book[k].len >= books.book[k].storenum)
		{
			PR("������ȫ�����\n");
			continue;
		}
		if (renter.count >= renter.MaxSize)//�����¼����
			Realloc(6);
		i = renter.count;////�����¼����
		renter.count++;//�����¼������1
		renter.rent[i].readerID = readerID;
		renter.rent[i].bookID = bookID;
		strcpy(renter.rent[i].rendDate, date);
		strcpy(renter.rent[i].backDate, "δ��");
		readers.reader[j].rented++;//���߽���������1
		books.book[k].len++;//������������1
		PR("�����������(����1����������������):");
		SC(D,&number);
		while (getchar() != NL)//���˷����ֵ��ַ�
			;
		if (number != 1)
			flag = 0;
	}
}
void BackBook()//����
{
	int readerID, bookID, k, i, j,m;
	int flag = 1, number;
	String date;
	while (flag)
	{
		number = -1;
		PR("������ߺ�  ���   ��������\n");
		SC(D D S, &readerID,& bookID,date);
		j = -1;
		for (i = 0; i < readers.count; i++)
		{
			if (readerID == readers.reader[i].id)
			{
				j = i;
				break;
			}
		}
		if (j == -1)
		{
			PR("�����������ߺ�%d,������ȷ�Ķ��ߺ�\n", readerID);
			return;
		}
		m = -1;
		for (i = 0; i < renter.count; i++)
		{
			if (bookID == renter.rent[i].bookID&&readerID==renter.rent[i].readerID)
			{
				m = i;
				break;
			}
		}
		if (m == -1)
		{
			PR("�����������ߺ�%d ���%d�Ľ����¼,������ȷ�����\n",readerID, bookID);
			return;
		}
		k = binSearch(bookID);
		if (-1 == k)
		{
			PR("ͼ���û�����%d,��������ȷ�����\n", bookID);
			return;
		}
		strcpy(renter.rent[m].backDate,date);
		readers.reader[j].rented--;//���߽�������-1
		books.book[k].len--;//����������-1
		PR("�����������(����1����������������):");
		SC(D, &number);
		while (getchar() != NL)//���˷����ֵ��ַ�
			;
		if (number != 1)
			flag = 0;
	}
}
void AddReader()
{
	int  i;
	int flag = 1, number;
	while (flag)
	{
		number = -1;
		if (readers.count == readers.MaxSize)
			Realloc(5);
		i = readers.count;
		readers.count++;
		PR("������ߺ�  ����\n");
		SC(D S , &readers.reader[i].id,readers.reader[i].name);
		readers.reader[i].canrent = 5;
		readers.reader[i].rented = 0;
		PR("�����������(����1����������������):");
		SC(D, &number);
		while (getchar() != NL)//���˷����ֵ��ַ�
			;
		if (number != 1)
			flag = 0;
	}
}
int main()
{
	int flag = 1, number, i;
	init();
	readFile();
	while(flag)
	{
		number=-1;//��ʼ��Ϊ-1
		boot();
		PR("�������ѡ��(0~6):");
		SC(D,&number);//������abc���󣬲��ܶ�ȡ,�򷵻�numberԭ��ַ����ֵ��������6abc��abc������
		while(getchar()!=NL)//���˷����ֵ��ַ�
			;
		switch(number)
		{
			case 0:
				{
				    writeFile();
					flag=0;
					break;
				}//�˳�
			case 1:
			{
				addBook();
				break;
			}
			case 2:
			{
				AddReader();
				break;
			}
			case 3:
			{
				BorrowBook();
				break;
			}
			case 4:
			{
				BackBook();
				break;
			}
			case 5:
				{
					search();
					break;
				}//����������������
			case 6:
				{
					show();
					break;
				}//����������������
            default:PR("���������������.\n");break;
		}
	}
	return 0;
}