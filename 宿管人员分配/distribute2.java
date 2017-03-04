import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Date;
import java.text.SimpleDateFormat;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
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
class distribution  extends JFrame implements ActionListener
{
	JPanel pan=new JPanel();//大面板，放三个小面板
	JTextArea text[]=new JTextArea[13];//13个标签，存放13个学院的信息
	JButton but1=new JButton("打开新的学生信息文件");//按钮
	JButton but2=new JButton("生成下一组分配结果");//按钮
	JMenuBar bar=new JMenuBar();//菜单条
	JMenuItem lineColor=new JMenuItem("设置边框颜色");//下拉菜单
	JMenuItem backgroundColor=new JMenuItem("设置背景颜色");//下拉菜单
	JMenuItem fontColor=new JMenuItem("设置字体颜色");//下拉菜单
	JMenu menu=new JMenu("设置颜色");//菜单项
	PrintStream print;//打印输出流
    FileInputStream input;//输入流
	Color linecolor=Color.green;//边框颜色
	Color fontcolor=Color.black;//字体颜色
	Color backgroundcolor=Color.pink;//背景颜色
	Scanner scan,scan1=new Scanner(System.in);//输入 流
	int i,j;
	Institude college[]=new Institude[13];//13个学院
	Student stu[]=new Student[26];//26个学生
	boolean isSuccess;//当前学生是否已成功分配到某个学院检查
	boolean isSet;//设置标记，false表示未设置，true表示设置好了，设置的是某学院分配的学生姓别相等
	boolean isFormatCorrect=true;//格式标记初始化为true，判断读入的文件格式正不正确
	int count;//读取学生的个数
	int flag;//标记哪个学生开始分配不了
	int male=0;//男同学人数
	int female=0;//女同学人数
	int isMaleBig;//是否男同学人数较多，1表示是，0表示相等，-1表示女同学较多
	int theSameSexCount;//同姓别的对数
	public distribution()
	{
		for(i=0;i<13;i++)
		{
			text[i]=new JTextArea();//为文本域类分配空间
			text[i].setEditable(false);//设置不可编辑
			text[i].setLineWrap(true);//设置满一行后自动换行
			text[i].setBorder(BorderFactory.createLineBorder(linecolor));//创建一个具有凹入斜面边缘的边框
			college[i]=new Institude();//为学院类分配空间
		}
		for(i=0;i<26;i++)
			stu[i]=new Student();//为学生类分配空间	
		pan.setLayout(null);
        for(i=0;i<4;i++)//4行
		{
			for(j=0;j<4;j++)//4列
			{
				if(i*4+j<13)//设置13个标签的位置
				{
					text[i*4+j].setBounds(j*200+10,i*150+5,180,130);
				    pan.add(text[i*4+j]);
				}
			}
		}
		initData();//初始化数据
		readStudent();//用于读取文件中学生信息
		if(count==26&&isFormatCorrect)//学生有26人时并且有格式正确
		{
			statistics();//统计 学生男女人生
			distrubute();//分配宿管人员
			showDistribute();//显示分配结果
			writeDistribute();//将分配信息写入一个文件保存
		}
		but1.setBounds(200+80,450+50,170,30);
		but2.setBounds(400+80,450+50,170,30);
		but1.addActionListener(this);
		but2.addActionListener(this);
		menu.add(lineColor);
		menu.add(backgroundColor);
		menu.add(fontColor);
		bar.add(menu);
		setJMenuBar(bar);
		pan.add(but1);
		pan.add(but2);
		pan.setBackground(backgroundcolor);
		add(pan);
		setLocation(200,100);
		setSize(810,640);
		setResizable(false);
		show();
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
			text[i].setText("              "+institude[i]+"\n\n            暂未分配");
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
			JOptionPane.showMessageDialog(this,"找不到student.txt文件，点击下面打开学生信息文件按钮查找student文件，或者选择其它文件","提示：",JOptionPane.INFORMATION_MESSAGE);
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
				isFormatCorrect=false;//格式不正确
			    JOptionPane.showMessageDialog(this,"student文件格式不正确，正确格式是每一行都显示：\n整数 字符串  字符串  字符串 ，如1203  张三 男  计算机学院\n请重新处理student.txt","提示：",JOptionPane.INFORMATION_MESSAGE);
			}
			i++;
		}
		count=i;//记录读取的人数
		if(count<26)
		{
			System.out.printf("\n");
			JOptionPane.showMessageDialog(this,"宿管员的人员信息不足26个，无法为每个学院分配2名学生，请重新填写好宿管人信息，使人人员数大于等于26","警告：",JOptionPane.WARNING_MESSAGE);
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
	public void showDistribute()//显示分配结果
	{
		int i;
		String str;
		for(i=0;i<13;i++)
		{
			str="             "+college[i].institude+"\n\n"+college[i].stu[0].classes+
				"    "+college[i].stu[0].name+"    "+college[i].stu[0].sex+"    "+
                college[i].stu[0].institude+"\n"+"\n"+college[i].stu[1].classes+
				"    "+college[i].stu[1].name+"    "+college[i].stu[1].sex+"    "+
                college[i].stu[1].institude+"\n";
		    text[i].setText(str);
		}
		if(!isSuccess)
			JOptionPane.showMessageDialog(this,"第"+(flag+1)+"个学生"+stu[flag].name+","+stu[flag].sex+","+stu[flag].institude+"无法分配到剩下的学院","提示：生成失败，点击下面生成下一组分配按钮请重新分配",JOptionPane.INFORMATION_MESSAGE);
	}
	public void distrubute()//分配宿管人员
	{
		int i,j,n;
		int number;//产生随机数的次数
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
			while(!isSuccess)//未分配好时，重新随机分配
			{
					n=(int)(13*Math.random());
					number++;//产生随机数的次数加1
					if(number>100000)//100000次还不成功，说明最后的一个学生还未分配是因为还未安排好的剩下一个学院就是这个学生的学院，无法分配
					{
						flag=i;//标记哪个学生开始分配不了
						System.out.printf("分配失败,请重新分配\n");
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
	public void actionPerformed(ActionEvent e)//覆写操作事件监听器的方法，这个函数在发生操作后会监听到并自动调用
	{
		if(e.getSource()==but2)//如果命令是进行下一组分配
		{
				initData();//初始化数据
				readStudent();//用于读取文件中学生信息
				if(count==26&&isFormatCorrect)//学生有26人时并且有格式正确
				{
					statistics();//统计 学生男女人生
					distrubute();//分配宿管人员
					showDistribute();//显示分配结果
					writeDistribute();//将分配信息写入一个文件保存
				}
		}
	}
}
class distribute2
{
	public static void main(String args[]) 
	{
		new distribution();
	} 
}