# include<stdio.h>
# include<malloc.h>
void DeleteDeath(int *circle,int n,int k)
{
   int i,j,m;
   int total=n;//��ǰ������
   printf("����󺣵ı������:\n");
   j=0;//�ӵ�һ�������𣬵�1�����±�Ϊ0
   for(i=1;i<=n/2;i++)
   {
	   j=(j+k-1)%total;//����k-1���ˣ�����j��ʼ������һ������K�ˣ���ʱjŶҪɾ���ڵ���±�
	   printf("%4d",circle[j]);
	   for(m=j;m<total-1;m++)//ɾ���±�ΪJ�Ľڵ�
		   circle[m]=circle[m+1];
	   total--;
   }
}
void OutRing(int *circle,int n)
{
	int i;
	printf("\n�Ҵ��߱������:\n");
	for(i=0;i<n/2;i++)
		printf("%4d",circle[i]);
	printf("\n");
}
void main()
{
	int i,n,k;
	int *circle;//����ڵ�
	printf("121110098  ���»�    ��˳���ʵ��Լɪ��\n");
	printf("============================================\n");
    printf("�����������ͱ�������:");
	scanf("%d%d",&n,&k);
	circle=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		circle[i]=i+1;
	DeleteDeath(circle,n,k);
	OutRing(circle,n);
}