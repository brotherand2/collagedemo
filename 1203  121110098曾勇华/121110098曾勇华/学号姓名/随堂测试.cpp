# include "linklist.cpp"

//���Ԫ��ֵ��[x,y]֮�������Ԫ�أ��������Ԫ��ֵ������λ�ã��������[3,6]֮���Ԫ�أ�3�ڵ�����{1,2,8,9,6,3}��6��λ�á�

void Search(LinkList *&L,ElemType x,ElemType y )
{
//�������
	int i;
	int locate;//λ��
	fori(i=x;<=y;i++)
	{
		locate=LocateElem(L,i);
		if(locate)
			printf("%d �ڵ������е�λ��Ϊ%d\n",i,locate);
	}

}

int main()
{
//�������
	ElemType a[]={1,2,8,9,6,3};
    LinkList *L;
    InitList(L);
    CreateListF(L,a,6);
	DispList(L);//
	Search(L,3,6);
	DestroyList(L);
    return 0;
}