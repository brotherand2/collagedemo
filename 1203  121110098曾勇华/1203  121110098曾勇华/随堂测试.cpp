#include "linklist.cpp"

/*用单链表中第一个元素值替换本链表中元素值在[x,y]之间的所有元素，比如单链表{1,2,8,9,6,3}，
用1替换元素值在[2,3]之间的元素后的单链表是{1,1,8,9,6,1}。链表的创建和输出形式自己设计。
最迟在第2节下课前发到QQ邮箱562137315@qq.com，邮件主题写明班学号姓名。不能上网的直接COPY给老师。
*/
void Replace(LinkList *&L,ElemType x,ElemType y )
{
//补充代码

		LinkList *p=L->next;
		int first;//第一个元素值
		if(p)
		{
			first=p->data;
			p=p->next;///从第二个元素开始
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
//补充代码
    LinkList *L;
	int a[]={1,2,8,9,6,3};
    CreateListR(L, a,6);
	printf("替换前：");
	DispList(L);
    Replace(L,2,3);
	printf("替换后：");
	DispList(L);
	DestroyList(L);
    return 0;
}
