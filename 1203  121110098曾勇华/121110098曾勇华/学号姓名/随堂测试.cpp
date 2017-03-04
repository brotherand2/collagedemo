# include "linklist.cpp"

//输出元素值在[x,y]之间的所有元素，包括输出元素值和它的位置，比如输出[3,6]之间的元素，3在单链表{1,2,8,9,6,3}第6个位置。

void Search(LinkList *&L,ElemType x,ElemType y )
{
//补充代码
	int i;
	int locate;//位置
	fori(i=x;<=y;i++)
	{
		locate=LocateElem(L,i);
		if(locate)
			printf("%d 在单链表中的位置为%d\n",i,locate);
	}

}

int main()
{
//补充代码
	ElemType a[]={1,2,8,9,6,3};
    LinkList *L;
    InitList(L);
    CreateListF(L,a,6);
	DispList(L);//
	Search(L,3,6);
	DestroyList(L);
    return 0;
}