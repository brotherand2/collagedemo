import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Date;
import java.text.SimpleDateFormat;

class Student//学生类
{
	int  classes;//班级
	String name;//姓名
	String sex;//姓别
	String institude;//学院
}

class Institude//学院类
{
	Student stu[]=new Student[2];//两名宿管员
	int count;//学院的人数
	String institude;//学院名字
	boolean isTheSameSex;//true表示姓别相同，flase表示不相同
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
	Institude college[]=new Institude[13];//13个学院
	Student stu[]=new Student[26];//26个学生
	boolean entry=true;//入口标志，true表示进入程序，false退出
	boolean isSuccess;//当前学生是否已成功分配到某个学院检查
	boolean isSet;//设置标记，false表示未设置，true表示设置好了，设置的是某学院分配的学生姓别相等
	int choice;
	int count;//读取学生的个数
	int male=0;//男同学人数
	int female=0;//女同学人数
	int isMaleBig;//是否男同学人数较多，1表示是，0表示相等，-1表示女同学较多
	int theSameSexCount;//同姓别的对数
	public distribution()
	{
		for(i=0;i<13;i++)
			college[i]=new Institude();
		for(i=0;i<26;i++)
			stu[i]=new Student();
		while(entry)
		{
			menu();
			choice=-1;//初始化为-1，不在中0-2中任何一个选择
			System.out.printf("请输入你的选择:");
			try
			{
				choice=scan1.nextInt();			
			}
			catch (Exception e)
			{
				String str=scan1.next();//将剩余的字符读取掉
				System.out.printf("请输入整数0-2，不要输入字符.\n");
			}
			switch(choice)
			{
			case 0:
				entry=false;//退出
				break;
			case 1:
				{
					initData();//初始化数据
					readStudent();//用于读取文件中学生信息
					statistics();//统计 学生男女人生
					distrubute();//分配宿管人员
					showDistribute();//显示分配结果
					writeDistribute();//将分配信息写入一个文件保存
				}break;
			case 2:
				 readStudent();//用于读取文件中学生信息
				 showStudent();//显示学生信息
				 break;
			default:
				System.out.printf("输入错误！重新输入.\n");
				break;
			}
		}
	}
	public void menu()//菜单
	{
		System.out.printf("       ┏━━━━━━━━━━━━━━━━━┓\n"); 
		System.out.printf("       ┃   <0>--------退出                ┃\n"); 
		System.out.printf("       ┃   <1>--------分配并显示分配结果  ┃\n"); 
		System.out.printf("       ┃   <2>--------显示学生信息        ┃\n"); 
		System.out.printf("       ┗━━━━━━━━━━━━━━━━━┛\n");
	}
	public void initData()//初始化数据
	{
		int i,j,k;
		Student temp=new Student();
		String institude[]={"土木工程学院","体育学院","美术学院","地理科学与旅游学院",
				   "物理与光信息科技学院","生命与科学学院","文学院","教育科学学院",
				   "电子信息工程学院","数学学院","政法学院","化学与环境学院",
				   "外国语学院","经管与管理学院","音乐学院","计算机学院"
		};//初始化16个学院的名字
		for(i=0;i<3;i++)//宿管员只到13个学院去检查，随机去掉3个学院
		{
			j=(int)((16-i)*Math.random());//randowm()函数生成0-1之间的随机浮点数，从剩下的16-i个学院中随机删除一个学院
			
			for(k=j;k<16-i-1;k++)
				institude[k]=institude[k+1];//将后面的字符串依次覆盖前面的字符串
		}
		for(i=0;i<13;i++)
		{
		    college[i].institude=institude[i];//为每个学院名字初始化
			college[i].isTheSameSex=false;//初始化为每个学院分配异姓别2个学生
			college[i].count=0;//安排好的人数初始化为0
			college[i].stu[0]=college[i].stu[1]=temp;
		}
		male=female=0;//男女生人数初始化为0
		isMaleBig=0;
		theSameSexCount=0;
	}
	public void readStudent()//用于读取文件中学生信息
	{
		int i=0;
		try
		{
            scan=new Scanner(new File("student.txt"));
		}
		catch (Exception e)
		{
			System.out.printf("找不到student.txt文件\n");
		}
        while(scan.hasNext()&&i<26)//还没读到文件尾并且人数少于26继续读取
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
				System.out.printf("student文件格式不正确，正确格式是每一行都显示：\n整数 字符串  字符串  字符串 ，如1203  张三 男  计算机学院\n请重新处理student.txt");
                System.exit(0);
			}
			i++;
		}
		count=i;//记录读取的人数
		if(count<26)
		{
			System.out.printf("宿管员的人员信息不足26个，无法为每个学院分配2名学生，请重新填写好宿管人信息，使人人员数大于等于26\n");
			System.exit(0);
		}
	}
    public void writeDistribute()//将分配信息定性写入文件
	{
	    SimpleDateFormat format=new SimpleDateFormat("日期时间:yyyy年MM月dd日  HH:mm:ss");
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
		print.println("当前分配结果:");
		for(i=0;i<13;i++)
		{
	     	print.println();
			print.println(college[i].institude);
			print.println(college[i].stu[0].classes+"     "+college[i].stu[0].name+"   "+college[i].stu[0].sex+"  "+college[i].stu[0].institude);
			print.println(college[i].stu[1].classes+"     "+college[i].stu[1].name+"   "+college[i].stu[1].sex+"  "+college[i].stu[1].institude);
		}
		if(!isSuccess)
		print.println("分配失败!!!!");
	}
	public void statistics()//统计学生男女人生
	{
		int i;
		for(i=0;i<26;i++)
		{
			if((stu[i].sex).equals("男"))//该同学是男性
				male++;//男同学人数加1
			else 
				female++;
		}
		if(male>female)
		{
			isMaleBig=1;//男生人数多
			theSameSexCount=(male-female)/2;
		}
		else
		{
			if(male<female)
			{
				isMaleBig=-1;//女生人数多
				theSameSexCount=(female-male)/2;
			}
			else
			{
				isMaleBig=0;//男女生人数相等
				theSameSexCount=0;//无同姓别学生被分到同一个学院
			}
		}
	}
	public void showStudent()//显示学生信息
	{
		int i;
		System.out.printf("班级      姓名      姓别      学院\n");
		for(i=0;i<count;i++)
		{
			System.out.printf("%-10d%-10s%-10s%-10s\n",stu[i].classes,stu[i].name,stu[i].sex,stu[i].institude);
		}
		System.out.printf("宿管人员一共有:%d\n",count);
		if(count<26)
		{
			System.out.printf("宿管员的人员信息不足26个，无法为每个学院分配2名学生，请重新填写好宿管人信息，使人人员数大于等于26\n");
			System.exit(0);
		}
	}
	public void showDistribute()//显示分配结果
	{
		int i;
		System.out.printf("\n\n分配结果如下:\n");
		for(i=0;i<13;i++)
		{
			System.out.printf("%s:\n",college[i].institude);
			System.out.printf("%-5d%-10s%-5s%-10s\n",college[i].stu[0].classes,college[i].stu[0].name,college[i].stu[0].sex,college[i].stu[0].institude);
			System.out.printf("%-5d%-10s%-5s%-10s\n\n",college[i].stu[1].classes,college[i].stu[1].name,college[i].stu[1].sex,college[i].stu[1].institude);	
		}
		if(!isSuccess)
			System.out.printf("分配不成功，请重新分配\n");
	}
	public void distrubute()//分配宿管人员
	{
		int i,j,n;
		int number;//产生随机数的次数
		System.out.printf("需要检查的学院有以下学院：\n");
		for(i=0;i<13;i++)
			System.out.printf("%s\n",college[i].institude);
		if(count<26)
		{
			System.out.printf("宿管员的人员信息不足26个，无法为每个学院分配2名学生，请重新填写好宿管人信息，使人人员数大于等于26\n");
			System.exit(0);
		}
		if(isMaleBig!=0)//男女生人数不相等,设置某些学院分配的学生姓别相同
		{
			j=0;
			while(j<theSameSexCount)
			{
				isSet=false;//初始化为未设置
				while(!isSet)
				{
					n=(int)(13*Math.random());//13个学院随机选一个设置为检查该学院宿舍的学生姓别相同
					if(!college[n].isTheSameSex)//如果该学院还未设置过分配的学生姓别相同
					{
						college[n].isTheSameSex=true;
						isSet=true;
					}
				}
				j++;//设置的个数加1
			}
		}
		isSuccess=true;
		for(i=0;i<26&&isSuccess;i++)//将26名学生随机分配到13个学院进行宿检
		{
			isSuccess=false;//一开始还未分配，初始化为false
			number=0;
			System.out.printf("%d、要分配的学生姓名:%s,%s,%s\n",i+1,stu[i].name,stu[i].sex,stu[i].institude);
			while(!isSuccess)//未分配好时，重新随机分配
			{
					n=(int)(13*Math.random());
					number++;//产生随机数的次数加1
					if(number>100000)//100000次还不成功，说明最后的一个学生还未分配是因为还未安排好的剩下一个学院就是这个学生的学院，无法分配
					{
						System.out.printf("分配失败,请重新分配\n");
						//scan1.next();//暂停一下，可看到错误信息
						break;
					}
					if(!(stu[i].institude).equals(college[n].institude))//如果该学生不是来自这个学院，则继续，否则不可以安排他管理自己的学院
					{
						if(college[n].count==0)//还未安排一个学生
						{
							if(!college[n].isTheSameSex)//如果未要求2名宿管人员姓别相同，满足以上条件，则可以安排他管理这个学院的宿舍
							{
								isSuccess=true;//该学生成功分配
							}
							else//要求2名宿管人员姓别相同
							{
								 if(isMaleBig==1)//男生人数较多,这个学院只能安排男同学
								 {
									 if((stu[i].sex).equals("男"))
										 isSuccess=true;
								 }
								 else
								 {
									 if((stu[i].sex).equals("女"))
										 isSuccess=true;
								 }
							}
							if(isSuccess)
							{
								college[n].count++;//安排的人数加1
								college[n].stu[0]=stu[i];//将该学生安排进该学院管理名单
							}
						}
						else
							if(college[n].count==1)//已安排好一个学生管理这个学院
							{
								if(!college[n].isTheSameSex)//要求2名宿管人员姓别不相同
								{
									if(!(stu[i].sex).equals(college[n].stu[0].sex))//如果该学生姓别不同于已安排好的那名同学，则可以安排他管理这个学院的宿舍
									isSuccess=true;//该学生成功分配
								}
								else//要求2名宿管人员姓别相同
								{
									if((stu[i].sex).equals(college[n].stu[0].sex))//如果该学生姓别和已安排好的那名同学相同，则可以安排他管理这个学院的宿舍
									isSuccess=true;//该学生成功分配	
								}
								if(isSuccess)
								{
									college[n].count++;//安排的人数加1
									college[n].stu[1]=stu[i];//将该学生安排进该学院管理名单
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