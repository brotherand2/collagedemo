import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Date;
import java.text.SimpleDateFormat;

class Student//ѧ����
{
	int  classes;//�༶
	String name;//����
	String sex;//�ձ�
	String institude;//ѧԺ
}

class Institude//ѧԺ��
{
	Student stu[]=new Student[2];//�����޹�Ա
	int count;//ѧԺ������
	String institude;//ѧԺ����
	boolean isTheSameSex;//true��ʾ�ձ���ͬ��flase��ʾ����ͬ
	public Institude()
	{
		stu[0]=new Student();
		stu[1]=new Student();
	}
}
class distribution
{
	PrintStream print;
    FileInputStream input;
	Scanner scan,scan1=new Scanner(System.in);
	int i,j;
	Institude college[]=new Institude[13];//13��ѧԺ
	Student stu[]=new Student[26];//26��ѧ��
	boolean entry=true;//��ڱ�־��true��ʾ�������false�˳�
	boolean isSuccess;//��ǰѧ���Ƿ��ѳɹ����䵽ĳ��ѧԺ���
	boolean isSet;//���ñ�ǣ�false��ʾδ���ã�true��ʾ���ú��ˣ����õ���ĳѧԺ�����ѧ���ձ����
	int choice;
	int count;//��ȡѧ���ĸ���
	int male=0;//��ͬѧ����
	int female=0;//Ůͬѧ����
	int isMaleBig;//�Ƿ���ͬѧ�����϶࣬1��ʾ�ǣ�0��ʾ��ȣ�-1��ʾŮͬѧ�϶�
	int theSameSexCount;//ͬ�ձ�Ķ���
	public distribution()
	{
		for(i=0;i<13;i++)
			college[i]=new Institude();
		for(i=0;i<26;i++)
			stu[i]=new Student();
		while(entry)
		{
			menu();
			choice=-1;//��ʼ��Ϊ-1��������0-2���κ�һ��ѡ��
			System.out.printf("���������ѡ��:");
			try
			{
				choice=scan1.nextInt();			
			}
			catch (Exception e)
			{
				String str=scan1.next();//��ʣ����ַ���ȡ��
				System.out.printf("����������0-2����Ҫ�����ַ�.\n");
			}
			switch(choice)
			{
			case 0:
				entry=false;//�˳�
				break;
			case 1:
				{
					initData();//��ʼ������
					readStudent();//���ڶ�ȡ�ļ���ѧ����Ϣ
					statistics();//ͳ�� ѧ����Ů����
					distrubute();//�����޹���Ա
					showDistribute();//��ʾ������
					writeDistribute();//��������Ϣд��һ���ļ�����
				}break;
			case 2:
				 readStudent();//���ڶ�ȡ�ļ���ѧ����Ϣ
				 showStudent();//��ʾѧ����Ϣ
				 break;
			default:
				System.out.printf("���������������.\n");
				break;
			}
		}
	}
	public void menu()//�˵�
	{
		System.out.printf("       ��������������������������������������\n"); 
		System.out.printf("       ��   <0>--------�˳�                ��\n"); 
		System.out.printf("       ��   <1>--------���䲢��ʾ������  ��\n"); 
		System.out.printf("       ��   <2>--------��ʾѧ����Ϣ        ��\n"); 
		System.out.printf("       ��������������������������������������\n");
	}
	public void initData()//��ʼ������
	{
		int i,j,k;
		Student temp=new Student();
		String institude[]={"��ľ����ѧԺ","����ѧԺ","����ѧԺ","�����ѧ������ѧԺ",
				   "���������Ϣ�Ƽ�ѧԺ","�������ѧѧԺ","��ѧԺ","������ѧѧԺ",
				   "������Ϣ����ѧԺ","��ѧѧԺ","����ѧԺ","��ѧ�뻷��ѧԺ",
				   "�����ѧԺ","���������ѧԺ","����ѧԺ","�����ѧԺ"
		};//��ʼ��16��ѧԺ������
		for(i=0;i<3;i++)//�޹�Աֻ��13��ѧԺȥ��飬���ȥ��3��ѧԺ
		{
			j=(int)((16-i)*Math.random());//randowm()��������0-1֮����������������ʣ�µ�16-i��ѧԺ�����ɾ��һ��ѧԺ
			
			for(k=j;k<16-i-1;k++)
				institude[k]=institude[k+1];//��������ַ������θ���ǰ����ַ���
		}
		for(i=0;i<13;i++)
		{
		    college[i].institude=institude[i];//Ϊÿ��ѧԺ���ֳ�ʼ��
			college[i].isTheSameSex=false;//��ʼ��Ϊÿ��ѧԺ�������ձ�2��ѧ��
			college[i].count=0;//���źõ�������ʼ��Ϊ0
			college[i].stu[0]=college[i].stu[1]=temp;
		}
		male=female=0;//��Ů��������ʼ��Ϊ0
		isMaleBig=0;
		theSameSexCount=0;
	}
	public void readStudent()//���ڶ�ȡ�ļ���ѧ����Ϣ
	{
		int i=0;
		try
		{
            scan=new Scanner(new File("student.txt"));
		}
		catch (Exception e)
		{
			System.out.printf("�Ҳ���student.txt�ļ�\n");
		}
        while(scan.hasNext()&&i<26)//��û�����ļ�β������������26������ȡ
		{
			try
			{
				stu[i].classes=scan.nextInt();
				stu[i].name=scan.next();
				stu[i].sex=scan.next();
				stu[i].institude=scan.next();
				
			}
			catch (Exception e)
			{
				System.out.printf("student�ļ���ʽ����ȷ����ȷ��ʽ��ÿһ�ж���ʾ��\n���� �ַ���  �ַ���  �ַ��� ����1203  ���� ��  �����ѧԺ\n�����´���student.txt");
                System.exit(0);
			}
			i++;
		}
		count=i;//��¼��ȡ������
		if(count<26)
		{
			System.out.printf("�޹�Ա����Ա��Ϣ����26�����޷�Ϊÿ��ѧԺ����2��ѧ������������д���޹�����Ϣ��ʹ����Ա�����ڵ���26\n");
			System.exit(0);
		}
	}
    public void writeDistribute()//��������Ϣ����д���ļ�
	{
	    SimpleDateFormat format=new SimpleDateFormat("����ʱ��:yyyy��MM��dd��  HH:mm:ss");
	    Date date=new Date();
		String time=format.format(date);
		try
		{
			print=new PrintStream(new FileOutputStream(new File("distribute result.txt"),true));		
		}
		catch (Exception e)
		{
		}
		print.println();
		print.println(time);
		print.println("��ǰ������:");
		for(i=0;i<13;i++)
		{
	     	print.println();
			print.println(college[i].institude);
			print.println(college[i].stu[0].classes+"     "+college[i].stu[0].name+"   "+college[i].stu[0].sex+"  "+college[i].stu[0].institude);
			print.println(college[i].stu[1].classes+"     "+college[i].stu[1].name+"   "+college[i].stu[1].sex+"  "+college[i].stu[1].institude);
		}
		if(!isSuccess)
		print.println("����ʧ��!!!!");
	}
	public void statistics()//ͳ��ѧ����Ů����
	{
		int i;
		for(i=0;i<26;i++)
		{
			if((stu[i].sex).equals("��"))//��ͬѧ������
				male++;//��ͬѧ������1
			else 
				female++;
		}
		if(male>female)
		{
			isMaleBig=1;//����������
			theSameSexCount=(male-female)/2;
		}
		else
		{
			if(male<female)
			{
				isMaleBig=-1;//Ů��������
				theSameSexCount=(female-male)/2;
			}
			else
			{
				isMaleBig=0;//��Ů���������
				theSameSexCount=0;//��ͬ�ձ�ѧ�����ֵ�ͬһ��ѧԺ
			}
		}
	}
	public void showStudent()//��ʾѧ����Ϣ
	{
		int i;
		System.out.printf("�༶      ����      �ձ�      ѧԺ\n");
		for(i=0;i<count;i++)
		{
			System.out.printf("%-10d%-10s%-10s%-10s\n",stu[i].classes,stu[i].name,stu[i].sex,stu[i].institude);
		}
		System.out.printf("�޹���Աһ����:%d\n",count);
		if(count<26)
		{
			System.out.printf("�޹�Ա����Ա��Ϣ����26�����޷�Ϊÿ��ѧԺ����2��ѧ������������д���޹�����Ϣ��ʹ����Ա�����ڵ���26\n");
			System.exit(0);
		}
	}
	public void showDistribute()//��ʾ������
	{
		int i;
		System.out.printf("\n\n����������:\n");
		for(i=0;i<13;i++)
		{
			System.out.printf("%s:\n",college[i].institude);
			System.out.printf("%-5d%-10s%-5s%-10s\n",college[i].stu[0].classes,college[i].stu[0].name,college[i].stu[0].sex,college[i].stu[0].institude);
			System.out.printf("%-5d%-10s%-5s%-10s\n\n",college[i].stu[1].classes,college[i].stu[1].name,college[i].stu[1].sex,college[i].stu[1].institude);	
		}
		if(!isSuccess)
			System.out.printf("���䲻�ɹ��������·���\n");
	}
	public void distrubute()//�����޹���Ա
	{
		int i,j,n;
		int number;//����������Ĵ���
		System.out.printf("��Ҫ����ѧԺ������ѧԺ��\n");
		for(i=0;i<13;i++)
			System.out.printf("%s\n",college[i].institude);
		if(count<26)
		{
			System.out.printf("�޹�Ա����Ա��Ϣ����26�����޷�Ϊÿ��ѧԺ����2��ѧ������������д���޹�����Ϣ��ʹ����Ա�����ڵ���26\n");
			System.exit(0);
		}
		if(isMaleBig!=0)//��Ů�����������,����ĳЩѧԺ�����ѧ���ձ���ͬ
		{
			j=0;
			while(j<theSameSexCount)
			{
				isSet=false;//��ʼ��Ϊδ����
				while(!isSet)
				{
					n=(int)(13*Math.random());//13��ѧԺ���ѡһ������Ϊ����ѧԺ�����ѧ���ձ���ͬ
					if(!college[n].isTheSameSex)//�����ѧԺ��δ���ù������ѧ���ձ���ͬ
					{
						college[n].isTheSameSex=true;
						isSet=true;
					}
				}
				j++;//���õĸ�����1
			}
		}
		isSuccess=true;
		for(i=0;i<26&&isSuccess;i++)//��26��ѧ��������䵽13��ѧԺ�����޼�
		{
			isSuccess=false;//һ��ʼ��δ���䣬��ʼ��Ϊfalse
			number=0;
			System.out.printf("%d��Ҫ�����ѧ������:%s,%s,%s\n",i+1,stu[i].name,stu[i].sex,stu[i].institude);
			while(!isSuccess)//δ�����ʱ�������������
			{
					n=(int)(13*Math.random());
					number++;//����������Ĵ�����1
					if(number>100000)//100000�λ����ɹ���˵������һ��ѧ����δ��������Ϊ��δ���źõ�ʣ��һ��ѧԺ�������ѧ����ѧԺ���޷�����
					{
						System.out.printf("����ʧ��,�����·���\n");
						//scan1.next();//��ͣһ�£��ɿ���������Ϣ
						break;
					}
					if(!(stu[i].institude).equals(college[n].institude))//�����ѧ�������������ѧԺ������������򲻿��԰����������Լ���ѧԺ
					{
						if(college[n].count==0)//��δ����һ��ѧ��
						{
							if(!college[n].isTheSameSex)//���δҪ��2���޹���Ա�ձ���ͬ��������������������԰������������ѧԺ������
							{
								isSuccess=true;//��ѧ���ɹ�����
							}
							else//Ҫ��2���޹���Ա�ձ���ͬ
							{
								 if(isMaleBig==1)//���������϶�,���ѧԺֻ�ܰ�����ͬѧ
								 {
									 if((stu[i].sex).equals("��"))
										 isSuccess=true;
								 }
								 else
								 {
									 if((stu[i].sex).equals("Ů"))
										 isSuccess=true;
								 }
							}
							if(isSuccess)
							{
								college[n].count++;//���ŵ�������1
								college[n].stu[0]=stu[i];//����ѧ�����Ž���ѧԺ��������
							}
						}
						else
							if(college[n].count==1)//�Ѱ��ź�һ��ѧ���������ѧԺ
							{
								if(!college[n].isTheSameSex)//Ҫ��2���޹���Ա�ձ���ͬ
								{
									if(!(stu[i].sex).equals(college[n].stu[0].sex))//�����ѧ���ձ�ͬ���Ѱ��źõ�����ͬѧ������԰������������ѧԺ������
									isSuccess=true;//��ѧ���ɹ�����
								}
								else//Ҫ��2���޹���Ա�ձ���ͬ
								{
									if((stu[i].sex).equals(college[n].stu[0].sex))//�����ѧ���ձ���Ѱ��źõ�����ͬѧ��ͬ������԰������������ѧԺ������
									isSuccess=true;//��ѧ���ɹ�����	
								}
								if(isSuccess)
								{
									college[n].count++;//���ŵ�������1
									college[n].stu[1]=stu[i];//����ѧ�����Ž���ѧԺ��������
								}
							}
						}
			}
		}
	}
}
class distribute
{
	public static void main(String args[]) 
	{
		new distribution();
	} 
}