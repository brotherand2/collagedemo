# include<stdio.h>
# include"book.h"
void init()//初始化
{
	int i;
	//初始化书籍类型
	books.count = 0;
	books.MaxSize = N;
	books.book = (BookDataType*)malloc(N*sizeof(BookDataType));

	//初始化书名、作者、出版社次关键字类型
	for (i = 0; i < 3; i++)
	{
		otherkey[i].count = 0;
		otherkey[i].key = (OtherKey  *)malloc(N*sizeof(OtherKey));
		otherkey[i].MaxSize = N;
	}
	//初始化主关键字类型
	keys.count = 0;
	keys.key = (Key  *)malloc(sizeof(Key)*N);
	keys.MaxSize = N;
	//初始化初始化主关键字类型类型
	readers.count = 0;
	readers.MaxSize = N;
	readers.reader = (ReaderType  *)malloc(N*sizeof(ReaderType));
	//初始化借书还书类型
	renter.count = 0;
	renter.MaxSize = N;
	renter.rent = (BookRentType*)malloc(N*sizeof(BookRentType));
}
void Realloc(int i)//空间扩大20个数量，i为类型号，i为0-6分别为扩冲书名型、作者型、出版社型、图书类型、书号型、读者型、借还历史型空间
{
	switch (i)
	{
	case 0:
		otherkey[0].key = (OtherKey*)realloc(otherkey[0].key, (otherkey[0].MaxSize + addSize)*sizeof(OtherKey));//空间扩大adSize个
		otherkey[0].MaxSize +=  addSize;
		break;
	case 1:
		otherkey[1].key = (OtherKey*)realloc(otherkey[1].key, (otherkey[1].MaxSize + addSize)*sizeof(OtherKey));//空间扩大adSize个
		otherkey[1].MaxSize += addSize;
		break;
	case 2:
		otherkey[2].key = (OtherKey*)realloc(otherkey[2].key, (otherkey[2].MaxSize + addSize)*sizeof(OtherKey));//空间扩大adSize个
		otherkey[2].MaxSize += addSize;
		break;
	case 3:
		books.book = (BookDataType*)realloc(books.book, (books.MaxSize + addSize)*sizeof(BookDataType));//空间扩大adSize个
		books.MaxSize+= addSize;
		break;
	case 4:
		keys.key = (Key*)realloc(keys.key, (keys.MaxSize + addSize)*sizeof(Key));//空间扩大adSize个
		keys.MaxSize+= addSize;
		break;
	case 5:
		readers.reader = (ReaderType*)realloc(readers.reader, (readers.MaxSize + addSize)*sizeof(ReaderType));//空间扩大adSize个
		readers.MaxSize += addSize;
		break;
	case 6:
		renter.rent = (BookRentType*)realloc(renter.rent, (renter.MaxSize + addSize)*sizeof(BookRentType));//空间扩大adSize个
		renter.MaxSize+= addSize;
		break;
	default:break;
	}
}
void readFile()
{
	int i,j;
	FILE *bookFile, *keyFile, *otherkeyFile[3], *readerFile, *renterFile;
	if ((bookFile = fopen("图书主索引文件.txt", "r")) == NULL)//读取图书主索引文件.txt文件
	{
		PR("不能打开图书主索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((keyFile = fopen("书号索引文件.txt", "r")) == NULL)//读取书号索引文件.txt文件
	{
		PR("不能打开书号索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((otherkeyFile[0] = fopen("书名索引文件.txt", "r")) == NULL)//读取书名索引文件.txt文件
	{
		PR("不能打开书名索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((otherkeyFile[1] = fopen("作者索引文件.txt", "r")) == NULL)//读取作者索引文件.txt文件
	{
		PR("不能打开作者索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((otherkeyFile[2] = fopen("出版社索引文件.txt", "r")) == NULL)//读取出版社索引文件.txt文件
	{
		PR("不能打开出版社索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((readerFile = fopen("读者文件.txt", "r")) == NULL)//读取读者文件.txt文件
	{
		PR("不能打开读者文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((renterFile = fopen("借书还书历史.txt", "r")) == NULL)//读取借书还书历史.txt文件
	{
		PR("不能打开借书还书历史.txt文件!\n");
		exit(0);//终止程序
	}
	i = 0;
	while (!feof(bookFile))
	{
		if (i == books.MaxSize)//空间不够
		{
			Realloc(3);
		}
		fscanf(bookFile, D D S D S D S D D D D,& books.book[i].record, &books.book[i].id,
			books.book[i].name, &books.book[i].point[0], books.book[i].author,& books.book[i].point[1],
			books.book[i].publish, &books.book[i].point[2],& books.book[i].sort, &books.book[i].storenum,& books.book[i].len);
		i++;
	}
	books.count = i - 1;
	//读取书号索引文件信息
	i = 0;
	while (!feof(keyFile))
	{
		if (i == keys.MaxSize)//空间不够
		{
			Realloc(4);
		}
		fscanf(keyFile,D D,&keys.key[i].id,&keys.key[i].point);
		i++;
	}
	keys.count = i - 1;
	//读取书名、作者、出版社索引信息
	for (j = 0; j < 3; j++)
	{
		i = 0;
		while (!feof(otherkeyFile[j]))
		{
			if (i == otherkey[j].MaxSize)//空间不够
			{
				Realloc(j);
			}
			fscanf(otherkeyFile[j], S D D, otherkey[j].key[i].name,& otherkey[j].key[i].point,& otherkey[j].key[i].len);
			i++;
		}
		otherkey[j].count = i - 1;
	}
	//读取读者文件信息
	i = 0;
	while (!feof(readerFile))
	{
		if (i == readers.MaxSize)//空间不够
		{
			Realloc(5);
		}
		fscanf(readerFile, D S D D,&readers.reader[i].id,&readers.reader[i].name, &readers.reader[i].canrent, &readers.reader[i].rented);
		i++;
	}
	readers.count = i - 1;
	//读取借书还书历史文件信息
	i = 0;
	while (!feof(renterFile))
	{
		if (i == renter.MaxSize)//空间不够
		{
			Realloc(6);
		}
		fscanf(renterFile, D D S S, &renter.rent[i].readerID, &renter.rent[i].bookID, renter.rent[i].rendDate, renter.rent[i].backDate);
		i++;
	}
	renter.count = i - 1;
	//关闭文件流
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
	if ((bookFile = fopen("图书主索引文件.txt", "w")) == NULL)//读取图书主索引文件.txt文件
	{
		PR("不能打开图书主索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((keyFile = fopen("书号索引文件.txt", "w")) == NULL)//读取书号索引文件.txt文件
	{
		PR("不能打开书号索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((otherkeyFile[0] = fopen("书名索引文件.txt", "w")) == NULL)//读取书名索引文件.txt文件
	{
		PR("不能打开书名索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((otherkeyFile[1] = fopen("作者索引文件.txt", "w")) == NULL)//读取作者索引文件.txt文件
	{
		PR("不能打开作者索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((otherkeyFile[2] = fopen("出版社索引文件.txt", "w")) == NULL)//读取出版社索引文件.txt文件
	{
		PR("不能打开出版社索引文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((readerFile = fopen("读者文件.txt", "w")) == NULL)//读取读者文件.txt文件
	{
		PR("不能打开读者文件.txt文件!\n");
		exit(0);//终止程序
	}
	if ((renterFile = fopen("借书还书历史.txt", "w")) == NULL)//读取借书还书历史.txt文件
	{
		PR("不能打开借书还书历史.txt文件!\n");
		exit(0);//终止程序
	}
	//写入书籍信息
	for (i = 0; i < books.count;i++)
		fprintf(bookFile, "%-10d%-10d%-15s%-10d%-15s%-10d%-15s%-10d%-10d%-10d%-10d%s", books.book[i].record, books.book[i].id,
			books.book[i].name,books.book[i].point[0], books.book[i].author,books.book[i].point[1],
			books.book[i].publish,books.book[i].point[2],books.book[i].sort,books.book[i].storenum,books.book[i].len,"\n");
	//写入书号文件信息
	for (i = 0; i < keys.count;i++)
		fprintf(keyFile,"%-10d%-10d%s",keys.key[i].id,keys.key[i].point,"\n");

	//写入书名、作者、出版社索引信息
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < otherkey[j].count;i++)
			fprintf(otherkeyFile[j],"%-10s%-10d%-10d%s", otherkey[j].key[i].name,otherkey[j].key[i].point,otherkey[j].key[i].len,"\n");
	}
	//写入读者文件信息
	for (i = 0; i < readers.count;i++)
		fprintf(readerFile,"%-10d%-10s%-10d%-10d%s",readers.reader[i].id,readers.reader[i].name,readers.reader[i].canrent,readers.reader[i].rented,"\n");
	//写入借书还书历史文件信息
	for (i = 0; i < renter.count;i++)
		fprintf(renterFile,"%-10d%-10d%-10s%-10s%s",renter.rent[i].readerID,renter.rent[i].bookID,renter.rent[i].rendDate, renter.rent[i].backDate,"\n");
	//关闭文件流
	fclose(bookFile);
	fclose(keyFile);
	fclose(otherkeyFile[0]);
	fclose(otherkeyFile[1]);
	fclose(otherkeyFile[2]);
	fclose(readerFile);
	fclose(renterFile);
}
void DispBook()//输出所有书籍信息
{
	int i;
	PR("记录号书号  书名      指针1 作者      指针2 出版社    指针3 分类  藏书量借出数\n");
	for (i = 0; i < books.count; i++)
		PR("%-6d%-6d%-10s%-6d%-10s%-6d%-10s%-6d%-6d%-6d%-6d\n", books.book[i].record, books.book[i].id,
		books.book[i].name, books.book[i].point[0], books.book[i].author, books.book[i].point[1],
		books.book[i].publish, books.book[i].point[2], books.book[i].sort, books.book[i].storenum, books.book[i].len);
	PR("\n");
}
void DispBookID()//输出书号索引信息
{
	int i;
	PR("书号      记录号\n");
	for (i = 0; i < keys.count; i++)
		PR("%-10d%-3d\n", keys.key[i].id, keys.key[i].point);
	PR("\n");
}
void DispBookOtherKey(String name,int n)//输出次关键字索引信息，0-2分别为书作者索引信息，书名，出版社索引信息
{
	int i;
	PR("%-10s链头指针  长度\n",name);
	for (i = 0; i < otherkey[n].count; i++)
		PR("%-10s%-10d%-10d\n", otherkey[n].key[i].name, otherkey[n].key[i].point, otherkey[n].key[i].len);
	PR("\n");
}
void DispReader()//输出读者信息
{
	int i;
	PR("读者号    读者名    可供书数  已借书数\n");
	for (i = 0; i < readers.count; i++)
		PR("%-10d%-10s%-10d%-10d\n", readers.reader[i].id, readers.reader[i].name , readers.reader[i].canrent, readers.reader[i].rented);
	PR("\n");
}
void DispBookRent()//输出书籍被借还历史信息
{
	int i;
	PR("读者号    书号      借书日期  还书日期\n");
	for (i = 0; i < renter.count; i++)
		PR("%-10d%-10d%-10s%-10s\n", renter.rent[i].readerID, renter.rent[i].bookID, renter.rent[i].rendDate, renter.rent[i].backDate);
	PR("\n");
}
void search_boot()//查询菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃   <0>--------查询完毕            ┃\n");
	PR("       ┃   <1>--------按书号查询          ┃\n");
	PR("       ┃   <2>--------按书名查询          ┃\n");
	PR("       ┃   <3>--------按作者查询          ┃\n");
	PR("       ┃   <4>--------按出版社查询        ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━┛\n");
}
int binSearch(int id)//二分查找书号
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
int commonSearch(String name, int n)//按次关键字索引查询，0-2分别为书作者索引信息，书名，出版社索引信息
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
void showBookRecord(int i)//显示书籍的一条记录，i为该记录数组下标
{
	PR("%-10d%-10s%-10s%-10s%-10d%-10d\n", books.book[i].id,
		books.book[i].name, books.book[i].author, books.book[i].publish, books.book[i].sort, books.book[i].storenum - books.book[i].len);
}
void search()//查询
{
	int num,id, flag = 1,i;
	String name;
	while (flag)
	{
		num = -1;//初始化为-1
		search_boot();
		PR("输入你的选择(0~4):");
		SC(D, &num);
		while (getchar() != '\n')//过滤非数字的字符
			;
		switch (num)
		{
		case 0:flag = 0; break;
		case 1:
			PR("输入要查询的书号：");
			SC("%d", &id);
			i=binSearch(id);
			if (-1 == i)
				PR("没有书号%d的记录\n", id);
			else
			{
				PR("书号      书名      作者      出版社    分类      可供数\n");
				showBookRecord(i);		
			}
			break;////二分查找书号
		case 2:
			PR("输入要查询的书名：");
			SC("%s", name);
			i=commonSearch(name,0);
			if (i==-1)
				PR("没有书名%s的记录\n", name);
			else
			{
				PR("书号      书名      作者      出版社    分类      可供数\n");
				for (i = otherkey[0].key[i].point; i != 0; i = books.book[i - 1].point[0])
					showBookRecord(i - 1);//下标为记录号减1
			}
			break;
		case 3:
			PR("输入要查询的作者名字：");
			SC("%s", name);
			i = commonSearch(name, 1);
			if (i == -1)
				PR("没有作者%s的记录\n", name);
			else
			{
				PR("书号      书名      作者      出版社    分类      可供数\n");
				for (i = otherkey[1].key[i].point; i != 0; i = books.book[i - 1].point[1])
					showBookRecord(i - 1);//下标为记录号减1
			}
			break;
		case 4:
			PR("输入要查询的出版社名字：");
			SC("%s", name);
			i = commonSearch(name, 2);
			if (i == -1)
				PR("没有出版社%s的记录\n", name);
			else
			{
				PR("书号      书名      作者      出版社    分类      可供数\n");
				for (i = otherkey[2].key[i].point; i != 0; i = books.book[i - 1].point[2])
					showBookRecord(i - 1);//下标为记录号减1
			}
			break;
		default:
			PR("输入错误!\n"); break;
		}
	}
}
void AdjustBookId()//调整书号记录
{
	int i,j,k;
	i = books.count-1;//书籍的记录数
	j = keys.count-1;//主键书号记录数
	while (j >= 0)
	{
		if (books.book[i].id >= keys.key[j].id)
		{
			break;
		}
		j--;
	}
	k = j + 1;
	if (keys.count == keys.MaxSize)//空间满了
		Realloc(4);
	if (keys.count > 0)//有序表调整
	{
		for (j = keys.count - 1; j >= k; j--)
			keys.key[j + 1] = keys.key[j];//记录后移
	}
	keys.key[k].id = books.book[i].id;//记录插入
	keys.key[k].point = books.count;
	keys.count++;//书号记录个数加1
}
void AdjustOtherKey(int n)//n为类型号，0-2分别调整书名记录、作者记录、出版社记录
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
		k = otherkey[n].count;//次关键字记录个数
		if (otherkey[n].count == otherkey[n].MaxSize)
			Realloc(n);
		books.book[count - 1].point[n] = 0;
		otherkey[n].key[k].point = count;
		otherkey[n].key[k].len=1;
		strcpy(otherkey[n].key[k].name, name);
		otherkey[n].count++;//记录个数加1
	}
}
void addBook()//增加书籍记录
{
	int flag = 1, number, i;
	while (flag)
	{ 
		number = -1;
		i = books.count;//i为当前书籍类型的长度
		if (books.count == books.MaxSize)//空间已满
			Realloc(3);
		books.count++;//记录个数加1
		PR("请输入");
		PR("书号      书名      作者      出版社    分类      藏书量\n");
		SC(D S S S D D, &books.book[i].id, books.book[i].name, books.book[i].author, books.book[i].publish, &books.book[i].sort, &books.book[i].storenum);
		books.book[i].record = i + 1;
		books.book[i].len = 0;
		AdjustBookId();
		AdjustOtherKey(0);
		AdjustOtherKey(1);
		AdjustOtherKey(2);
		PR("继续输入与否？(输入1继续，其它键结束):");
		SC(D,&number);
		while (getchar() != NL)//过滤非数字的字符
			;
		if (number != 1)
			flag = 0;
	}
}
void boot()//主菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃   <0>------(退出)Exit                  ┃\n");
	PR("       ┃   <1>------(图书信息输入)Input         ┃\n");
	PR("       ┃   <2>------(读者信息录入)Add           ┃\n");
	PR("       ┃   <3>------(借书处理)Rent              ┃\n");
	PR("       ┃   <4>------(还书处理)Back              ┃\n");
	PR("       ┃   <5>------(图书查询)Search            ┃\n");
	PR("       ┃   <6>------(显示文件作息)Show          ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━━━━┛\n");
}
void show_boot()//显示菜单
{
	PR("       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	PR("       ┃ <0>------显示完毕                                    ┃\n");
	PR("       ┃ <1>------显示书籍文件信息                            ┃\n");
	PR("       ┃ <2>------显示书号索引文件信息                        ┃\n");
	PR("       ┃ <3>------显示书名索引文件信息                        ┃\n");
	PR("       ┃ <4>------显示作者索引文件信息                        ┃\n");
	PR("       ┃ <5>------显示出版社索引文件信息                      ┃\n");
	PR("       ┃ <6>------显示读者文件信息                            ┃\n");
	PR("       ┃ <7>------显示借书还书历史文件信息                    ┃\n");
	PR("       ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
void show()//显示
{
	int flag = 1, i;
	int num;
	while (flag)
	{
		num = -1;//初始化为-1
		show_boot();
		PR("输入你的选择(0~7):");
		SC(D, &num);
		while (getchar() != NL)//过滤非数字的字符
			;
		switch (num)
		{
		case 0:flag = 0; break;
		case 1:DispBook(); break;//显示书籍文件信息
		case 2:DispBookID(); break;//显示书号索引文件信息
		case 3:DispBookOtherKey("书名", 0); break;//显示书名索引文件信息 
		case 4:DispBookOtherKey("作者", 1); break;//显示作者索引文件信息
		case 5:DispBookOtherKey("出版社", 2); break;//显示出版社索引文件信息
		case 6:DispReader(); break;//显示读者文件信息 
		case 7:DispBookRent(); break;//显示借书还书历史文件信息 
		default:PR("输入错误！\n"); break;
		}
	}
}
void BorrowBook()//借书
{
	int readerID, bookID,k,i,j;
	int flag = 1, number;
	String date;
	while (flag)
	{
		number = -1;
		PR("输入读者号  书号   借阅日期\n");
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
			PR("搜索不到读者号%d,输入正确的读者号\n", readerID);
			return;
		}
		if (readers.reader[j].rented >= readers.reader[j].canrent)//借书已满
		{
			PR("借书已满%d,请还回一些书后再来借\n", readers.reader[j].canrent);
			return;
		}
		k = binSearch(bookID);
		if (-1 == k)
		{
			PR("图书馆没有书号%d,请输入正确的书号\n", bookID);
			return;
		}
		if (books.book[k].len >= books.book[k].storenum)
		{
			PR("该书已全部借出\n");
			continue;
		}
		if (renter.count >= renter.MaxSize)//借书记录已满
			Realloc(6);
		i = renter.count;////借书记录个数
		renter.count++;//借书记录个数加1
		renter.rent[i].readerID = readerID;
		renter.rent[i].bookID = bookID;
		strcpy(renter.rent[i].rendDate, date);
		strcpy(renter.rent[i].backDate, "未还");
		readers.reader[j].rented++;//读者借书数量加1
		books.book[k].len++;//该书借出数量加1
		PR("继续输入与否？(输入1继续，其它键结束):");
		SC(D,&number);
		while (getchar() != NL)//过滤非数字的字符
			;
		if (number != 1)
			flag = 0;
	}
}
void BackBook()//还书
{
	int readerID, bookID, k, i, j,m;
	int flag = 1, number;
	String date;
	while (flag)
	{
		number = -1;
		PR("输入读者号  书号   还书日期\n");
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
			PR("搜索不到读者号%d,输入正确的读者号\n", readerID);
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
			PR("搜索不到读者号%d 书号%d的借书记录,输入正确的书号\n",readerID, bookID);
			return;
		}
		k = binSearch(bookID);
		if (-1 == k)
		{
			PR("图书馆没有书号%d,请输入正确的书号\n", bookID);
			return;
		}
		strcpy(renter.rent[m].backDate,date);
		readers.reader[j].rented--;//读者借书数量-1
		books.book[k].len--;//该书借出数量-1
		PR("继续输入与否？(输入1继续，其它键结束):");
		SC(D, &number);
		while (getchar() != NL)//过滤非数字的字符
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
		PR("输入读者号  姓名\n");
		SC(D S , &readers.reader[i].id,readers.reader[i].name);
		readers.reader[i].canrent = 5;
		readers.reader[i].rented = 0;
		PR("继续输入与否？(输入1继续，其它键结束):");
		SC(D, &number);
		while (getchar() != NL)//过滤非数字的字符
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
		number=-1;//初始化为-1
		boot();
		PR("输入你的选择(0~6):");
		SC(D,&number);//若输入abc错误，不能读取,则返回number原地址垃圾值，若输入6abc则abc被过滤
		while(getchar()!=NL)//过滤非数字的字符
			;
		switch(number)
		{
			case 0:
				{
				    writeFile();
					flag=0;
					break;
				}//退出
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
				}//重新输入所有数据
			case 6:
				{
					show();
					break;
				}//重新输入所有数据
            default:PR("输入错误！重新输入.\n");break;
		}
	}
	return 0;
}