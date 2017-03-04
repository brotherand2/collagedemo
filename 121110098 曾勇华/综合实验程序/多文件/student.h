# define SC scanf//使用宏
# define PR printf
# define D  "%d"
# define S  "%s"
# define F  "%f"
# define C  "%c"
# define SS "%.2f"
# define NL  '\n'
# define N  60
typedef struct STUDENT//用typedef声明新类型名
{
	int num;//学号
	char name[10],sex[5];//姓名、姓别
	float score[5];//高等数学，C语言，电工基础，总 分，平均分
	struct STUDENT *next;
}student;//student 等价于struct STUDENT 
student stu[60];//学生最多个数60  //全局变量

void boot();//主菜单
void input(int *count);//重新输入所有数据
void readstu(int *count);//用于读取文件时记学生个数
void update(int *count);//修改个别数据
void update_boot();//修改数据的菜单
void writefile(int *count);//将数据写入student.txt文件
void insert(int *count);//插入
void delet(int *count);//删除
void show(int *count);//显示
void show_boot();//显示菜单
void sort_total(int *count);//按总分递减排序
void sort_aver(int *count);//按平均分递减排序
void sort_num(int *count);//按学号递减排序
void sort_name(int *count);//按姓名递减排序
void search(int *count);//查询
void search_boot();//查询菜单
void search_num(int *count);//按学号查询
void search_name(int *count);//按姓名查询
void search_score(int *count,int n);//按成绩查询