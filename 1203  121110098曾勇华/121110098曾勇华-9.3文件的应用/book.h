# define SC scanf//ʹ�ú�
# define PR printf
# define D  "%d"
# define S  "%s"
# define F  "%f"
# define C  "%c"
# define SS "%.2f"
# define NL  '\n'
# define N  2//Ĭ�Ͽռ����
# define MaxLen 20//�ַ�������
int addSize=20;//�ռ䲻����������20����
typedef char String[MaxLen + 1];
typedef struct
{
	int record;//��¼
	int id;//���
	String name;//����
	int point[3];//ָ��1,2,3
	String author;//����
	String publish;//������
	int sort;//����
	int storenum;//������
	int len;//�����
}BookDataType;//ͼ������
typedef struct
{
	BookDataType *book;//�鼮����
	int count;//��ǰ����
	int MaxSize;///�ռ����ĸ���

}BookData;
BookData books;
typedef struct OtherKey
{
	String name;//����
	int point;//ָ��
	int len;//����
}OtherKey;//�����ιؼ�������
typedef struct
{
	OtherKey  *key;//�����ؼ�������
	int count;//��ǰ����
	int MaxSize;///�ռ����ĸ���
}OtherKeys;
OtherKeys otherkey[3];//0-2�ֱ������������ߡ�����������
typedef struct Key
{
	int id;//���
	int point;//ָ��
}Key;//���ؼ�������
typedef struct
{
	Key  *key;//���ؼ�������
	int count;//��ǰ����
	int MaxSize;///�ռ����ĸ���
}Keys;
Keys keys;//�������
typedef struct ReaderType
{
	String name;//��������
	int id;//���ߺ�
	int canrent;//�ɽ��鼮��
	int rented;//�ѽ��鼮
}ReaderType;//��������
typedef struct
{
	ReaderType  *reader;//��������
	int count;//��ǰ����
	int MaxSize;///�ռ����ĸ���
}Reader;//
Reader readers;
typedef struct BookRentType
{
	int readerID;//����ID
	int bookID;//���ID
	String rendDate;//��������
	String backDate;//��������
}BookRentType;//���黹������
typedef struct
{
	BookRentType  *rent;//��������ʷ����
	int count;//��ǰ����
	int MaxSize;///�ռ����ĸ���
}BookRent;
BookRent renter;