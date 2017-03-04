# define SC scanf//使用宏
# define PR printf
# define D  "%d"
# define S  "%s"
# define F  "%f"
# define C  "%c"
# define SS "%.2f"
# define NL  '\n'
# define N  5//默认空间个数
# define MaxLen 10//字符串长度
int count=0;//当前航班记录数
int MaxSize ;///空间最大个数
int addSize;//空间不够后扩增后的总个数

typedef char String[MaxLen+1];
typedef struct InfoType
{
	String info[8];//字符串数组，info[0]-info[7]分别是航班号、起点站、终点站、航班期、起飞时间、到达时间、机型、票价字符串
	struct InfoType *next;
}InfoType;
InfoType **air;//全局变量,动态数组