# define SC scanf//ʹ�ú�
# define PR printf
# define D  "%d"
# define S  "%s"
# define F  "%f"
# define C  "%c"
# define SS "%.2f"
# define NL  '\n'
# define N  5//Ĭ�Ͽռ����
# define MaxLen 10//�ַ�������
int count=0;//��ǰ�����¼��
int MaxSize ;///�ռ�������
int addSize;//�ռ䲻������������ܸ���

typedef char String[MaxLen+1];
typedef struct InfoType
{
	String info[8];//�ַ������飬info[0]-info[7]�ֱ��Ǻ���š����վ���յ�վ�������ڡ����ʱ�䡢����ʱ�䡢���͡�Ʊ���ַ���
	struct InfoType *next;
}InfoType;
InfoType **air;//ȫ�ֱ���,��̬����