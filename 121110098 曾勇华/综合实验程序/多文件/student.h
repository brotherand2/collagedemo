# define SC scanf//ʹ�ú�
# define PR printf
# define D  "%d"
# define S  "%s"
# define F  "%f"
# define C  "%c"
# define SS "%.2f"
# define NL  '\n'
# define N  60
typedef struct STUDENT//��typedef������������
{
	int num;//ѧ��
	char name[10],sex[5];//�������ձ�
	float score[5];//�ߵ���ѧ��C���ԣ��繤�������� �֣�ƽ����
	struct STUDENT *next;
}student;//student �ȼ���struct STUDENT 
student stu[60];//ѧ��������60  //ȫ�ֱ���

void boot();//���˵�
void input(int *count);//����������������
void readstu(int *count);//���ڶ�ȡ�ļ�ʱ��ѧ������
void update(int *count);//�޸ĸ�������
void update_boot();//�޸����ݵĲ˵�
void writefile(int *count);//������д��student.txt�ļ�
void insert(int *count);//����
void delet(int *count);//ɾ��
void show(int *count);//��ʾ
void show_boot();//��ʾ�˵�
void sort_total(int *count);//���ֵܷݼ�����
void sort_aver(int *count);//��ƽ���ֵݼ�����
void sort_num(int *count);//��ѧ�ŵݼ�����
void sort_name(int *count);//�������ݼ�����
void search(int *count);//��ѯ
void search_boot();//��ѯ�˵�
void search_num(int *count);//��ѧ�Ų�ѯ
void search_name(int *count);//��������ѯ
void search_score(int *count,int n);//���ɼ���ѯ