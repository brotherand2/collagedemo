# define SC scanf//使用宏
# define PR printf
# define D  "%d"
# define S  "%s"
# define F  "%f"
# define C  "%c"
# define SS "%.2f"
# define NL  '\n'
# define N  2//默认空间个数
# define MaxLen 20//字符串长度
int addSize=20;//空间不够后扩增后20个数
typedef char String[MaxLen + 1];
typedef struct
{
	int record;//记录
	int id;//书号
	String name;//书名
	int point[3];//指针1,2,3
	String author;//作者
	String publish;//出版社
	int sort;//分类
	int storenum;//藏书量
	int len;//借出数
}BookDataType;//图书类型
typedef struct
{
	BookDataType *book;//书籍数组
	int count;//当前个数
	int MaxSize;///空间分配的个数

}BookData;
BookData books;
typedef struct OtherKey
{
	String name;//名字
	int point;//指针
	int len;//长度
}OtherKey;//其它次关键字类型
typedef struct
{
	OtherKey  *key;//其它关键字数组
	int count;//当前个数
	int MaxSize;///空间分配的个数
}OtherKeys;
OtherKeys otherkey[3];//0-2分别是书名、作者、出版社类型
typedef struct Key
{
	int id;//书号
	int point;//指针
}Key;//主关键字类型
typedef struct
{
	Key  *key;//主关键字数组
	int count;//当前个数
	int MaxSize;///空间分配的个数
}Keys;
Keys keys;//书号类型
typedef struct ReaderType
{
	String name;//读者名字
	int id;//读者号
	int canrent;//可借书籍数
	int rented;//已借书籍
}ReaderType;//读者类型
typedef struct
{
	ReaderType  *reader;//读者数组
	int count;//当前个数
	int MaxSize;///空间分配的个数
}Reader;//
Reader readers;
typedef struct BookRentType
{
	int readerID;//读者ID
	int bookID;//书号ID
	String rendDate;//借书日期
	String backDate;//还书日期
}BookRentType;//借书还书类型
typedef struct
{
	BookRentType  *rent;//还借书历史数组
	int count;//当前个数
	int MaxSize;///空间分配的个数
}BookRent;
BookRent renter;