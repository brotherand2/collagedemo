/*
   ===============================================

   ===============================================
 */
# include<stdio.h>
# include"binarytree.h"
void boot()//主菜单
{
    printf("       ┏━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("       ┃   <0>------(退出)Exit                  ┃\n");
	printf("       ┃   <1>------(重建二叉树)CREATE          ┃\n");
	printf("       ┃   <2>------(二叉树遍历)TRAVEL          ┃\n");
	printf("       ┃   <3>------(输出所有到叶子节点路径)PATH┃\n");
	printf("       ┃   <4>------(查找节点)FIND              ┃\n");
	printf("       ┃   <5>------(显示二叉树信息)SHOW        ┃\n");
	printf("       ┗━━━━━━━━━━━━━━━━━━━━┛\n");
}

void main()
{
    bool flag=true;//循环标志   
	int number;
	char str[100],ch;
	BTNode *b,*lp,*rp,*p;
	BTNode * path[MAX],*longpath[MAX];//保存路径
	int max,i;
	printf("121110098   曾勇华   二叉树\n");
	CreateBTNode(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	while(flag)
	{
		boot();
		number=-1;//初始化
		printf("输入你的选择(0~6):");
		scanf("%d",&number);//若输入abc错误，不能读取,则返回number原地址垃圾值，若输入6abc则abc被过滤
		while(getchar()!='\n')//过滤非数字的字符
			;
		switch(number)
		{
		case 0:
			flag=false;
			break;
		case 1:
			printf("用括号表示法输入二叉树:\n");
			gets(str);
			CreateBTNode(b,str);
			printf("二叉树建立完成\n");
			break;
		case 2:
			printf("二叉树:");
			DispBTNode(b);
			printf("\n先序遍历:");
			PreOrder(b);
			printf("\n中序遍历:");
			InOrder(b);
			printf("\n后序遍历:");
			PostOrder(b);
			printf("\n层次遍历:");
			LevelOrder(b);
			printf("\n");
			break;
		case 3:
				AllPath(b,path,-1);
				LongPath(b,path,longpath,-1,max);
				printf("\n最长路径长度为%d:\n",max+1);
				for(i=0;i<=max;i++)
					printf("%c",longpath[i]->data);
				printf("\n");
				break;
		case 4:
			    printf("输入要查找的字符:");
				ch=getchar();
				p=FindNode(b,ch);
				if(p)
				{
					printf("节点查找成功%c\n",ch);
					NodePath(b,path,-1,ch);
					lp=LchildNode(p);
					if(lp)
						printf("左孩子为%c",lp->data);
					rp=RchildNode(p);
					if(rp)
						printf("左孩子为%c",rp->data);
				}
				else
				{
					printf("没有节点%c\n",ch);
				}
				printf("\n");
				break;
		case 5:
				DispBTNode(b);
		 		printf("\n二叉树的深度:%d\n",BTNodeDepth(b));
				printf("二叉树的宽度:%d\n",BTNodeWidth(b));
				printf("二叉树的节点个数:%d\n",Nodes(b));
				printf("二叉树的叶子节点个数:%d\n",LeafNodes(b));
				break;
		default:
			printf("输入错误，不能输入非数字字符，输入0~5！！！\n");
			break;
		}
	}
	DestroyBTNode(b);
}