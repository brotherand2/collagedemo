# include"student.h"
# include<stdio.h>
# include<stdlib.h>//Ϊʹ��exit()�����ṩԭ��
void myRealloc(int n)//����ռ䲻�������·����¿ռ�
{
	int i;
	if(n>addSize)//���ռ䲻������
		addSize=n*2;//����ռ����ӱ�
	stu=(student**)realloc(stu,addSize*sizeof(student*));
	printf("�ռ䲻�㣡��ǰ�ռ�Ϊ:%d,�������ٷ���ռ���...\n",studentSize);
	printf("�ռ������ɣ���ǰӵ�пռ���%d\n",addSize);
	for(i=studentSize;i<addSize;i++)//Ϊ���ӵ�ѧ��ָ�����ѧ���ռ�
		stu[i]=(student*)malloc(sizeof(student));
	studentSize=addSize;//����ǰ�ռ�����ΪaddSize
	addSize*=2;//��һ�����ռ䲻��������������
}