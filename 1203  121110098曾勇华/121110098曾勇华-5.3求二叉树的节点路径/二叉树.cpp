/*
   ===============================================

   ===============================================
 */
# include<stdio.h>
# include"binarytree.h"
void boot()//���˵�
{
    printf("       ��������������������������������������������\n");
	printf("       ��   <0>------(�˳�)Exit                  ��\n");
	printf("       ��   <1>------(�ؽ�������)CREATE          ��\n");
	printf("       ��   <2>------(����������)TRAVEL          ��\n");
	printf("       ��   <3>------(������е�Ҷ�ӽڵ�·��)PATH��\n");
	printf("       ��   <4>------(���ҽڵ�)FIND              ��\n");
	printf("       ��   <5>------(��ʾ��������Ϣ)SHOW        ��\n");
	printf("       ��������������������������������������������\n");
}

void main()
{
    bool flag=true;//ѭ����־   
	int number;
	char str[100],ch;
	BTNode *b,*lp,*rp,*p;
	BTNode * path[MAX],*longpath[MAX];//����·��
	int max,i;
	printf("121110098   ���»�   ������\n");
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	while(flag)
	{
		boot();
		number=-1;//��ʼ��
		printf("�������ѡ��(0~6):");
		scanf("%d",&number);//������abc���󣬲��ܶ�ȡ,�򷵻�numberԭ��ַ����ֵ��������6abc��abc������
		while(getchar()!='\n')//���˷����ֵ��ַ�
			;
		switch(number)
		{
		case 0:
			flag=false;
			break;
		case 1:
			printf("�����ű�ʾ�����������:\n");
			gets(str);
			CreateBTNode(b,str);
			printf("�������������\n");
			break;
		case 2:
			printf("������:");
			DispBTNode(b);
			printf("\n�������:");
			PreOrder(b);
			printf("\n�������:");
			InOrder(b);
			printf("\n�������:");
			PostOrder(b);
			printf("\n��α���:");
			LevelOrder(b);
			printf("\n");
			break;
		case 3:
				AllPath(b,path,-1);
				LongPath(b,path,longpath,-1,max);
				printf("\n�·������Ϊ%d:\n",max+1);
				for(i=0;i<=max;i++)
					printf("%c",longpath[i]->data);
				printf("\n");
				break;
		case 4:
			    printf("����Ҫ���ҵ��ַ�:");
				ch=getchar();
				p=FindNode(b,ch);
				if(p)
				{
					printf("�ڵ���ҳɹ�%c\n",ch);
					NodePath(b,path,-1,ch);
					lp=LchildNode(p);
					if(lp)
						printf("����Ϊ%c",lp->data);
					rp=RchildNode(p);
					if(rp)
						printf("����Ϊ%c",rp->data);
				}
				else
				{
					printf("û�нڵ�%c\n",ch);
				}
				printf("\n");
				break;
		case 5:
				DispBTNode(b);
		 		printf("\n�����������:%d\n",BTNodeDepth(b));
				printf("�������Ŀ��:%d\n",BTNodeWidth(b));
				printf("�������Ľڵ����:%d\n",Nodes(b));
				printf("��������Ҷ�ӽڵ����:%d\n",LeafNodes(b));
				break;
		default:
			printf("������󣬲�������������ַ�������0~5������\n");
			break;
		}
	}
	DestroyBTNode(b);
}