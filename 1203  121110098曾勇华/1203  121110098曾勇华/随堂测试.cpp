#include "linklist.cpp"

/*�õ������е�һ��Ԫ��ֵ�滻��������Ԫ��ֵ��[x,y]֮�������Ԫ�أ����絥����{1,2,8,9,6,3}��
��1�滻Ԫ��ֵ��[2,3]֮���Ԫ�غ�ĵ�������{1,1,8,9,6,1}������Ĵ����������ʽ�Լ���ơ�
����ڵ�2���¿�ǰ����QQ����562137315@qq.com���ʼ�����д����ѧ������������������ֱ��COPY����ʦ��
*/
void Replace(LinkList *&L,ElemType x,ElemType y )
{
//�������

		LinkList *p=L->next;
		int first;//��һ��Ԫ��ֵ
		if(p)
		{
			first=p->data;
			p=p->next;///�ӵڶ���Ԫ�ؿ�ʼ
			while(p)
			{				
				if(p->data<=y&&p->data>=x)
					p->data=first;
				p=p->next;
			}
		}
}

int main()
{
//�������
    LinkList *L;
	int a[]={1,2,8,9,6,3};
    CreateListR(L, a,6);
	printf("�滻ǰ��");
	DispList(L);
    Replace(L,2,3);
	printf("�滻��");
	DispList(L);
	DestroyList(L);
    return 0;
}
