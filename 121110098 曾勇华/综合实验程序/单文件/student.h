# define SC scanf//使用宏
# define PR printf
# define D  "%d"
# define S  "%s"
# define F  "%f"
# define C  "%c"
# define SS "%.2f"
# define NL  '\n'
# define N  60
void boot();//主菜单
void input();//重新输入所有数据
void readstu();//用于读取文件时记学生个数
void update();//修改个别数据
void update_boot();//修改数据的菜单
void writefile();//将数据写入student.txt文件
void insert();//插入
void delet();//删除
void show();//显示
void show_boot();//显示菜单
void sort_total();//按总分递减排序
void sort_aver();//按平均分递减排序
void sort_num();//按学号递减排序
void sort_name();//按姓名递减排序
void search();//查询
void search_boot();//查询菜单
void search_num();//按学号查询
void search_name();//按姓名查询

void search_score(int n);//按成绩查询