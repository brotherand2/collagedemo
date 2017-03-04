# include<stdio.h>
# include<malloc.h>
void DeleteDeath(int *circle,int n,int k)
{
   int i,j,m;
   int total=n;//当前总人数
   printf("抛入大海的编号如下:\n");
   j=0;//从第一个人数起，第1个人下标为0
   for(i=1;i<=n/2;i++)
   {
	   j=(j+k-1)%total;//跳过k-1个人，包括j开始计数，一共数了K人，这时j哦要删除节点的下标
	   printf("%4d",circle[j]);
	   for(m=j;m<total-1;m++)//删除下标为J的节点
		   circle[m]=circle[m+1];
	   total--;
   }
}
void OutRing(int *circle,int n)
{
	int i;
	printf("\n幸存者编号如下:\n");
	for(i=0;i<n/2;i++)
		printf("%4d",circle[i]);
	printf("\n");
}
void main()
{
	int i,n,k;
	int *circle;//保存节点
	printf("121110098  曾勇华    用顺序表实现约瑟夫环\n");
	printf("============================================\n");
    printf("输入总人数和报数上限:");
	scanf("%d%d",&n,&k);
	circle=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		circle[i]=i+1;
	DeleteDeath(circle,n,k);
	OutRing(circle,n);
}