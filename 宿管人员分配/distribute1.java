/*自己写的几个分配程序的目前最好*/
import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Date;
import java.text.SimpleDateFormat;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;
class Student//学生类
{
	int  classes;//班级
	String name;//姓名
	String sex;//姓别
	String institude;//学院
}
class myFont  implements MouseListener,ActionListener
{
	 JTextArea text[];//记事本编辑区
	 JDialog  dialog=new JDialog();//字体框架
	 String myFont=null;//字体
	 Font fontText=null;//记事本自身字体
	 int zip=0;//字型
	 int size=0;//字体大小
	String data1[]={"常规","斜体","粗体","粗斜体"};//字型
	String data2[]={"8","9","10","11","12","14","16","18","20","22","24","26",
		"28","36","48","72"};//字体大小
	String font[]=GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();//获得机子自己的所有字体名
	JLabel lab1=new JLabel("字体(F):");
	JLabel lab2=new JLabel("字型(Y):");
	JLabel lab3=new JLabel("大小(S):");
	final JLabel lab4=new JLabel("中1E502中文软件",JLabel.CENTER);//这个标签是检测字体改变后的样子、效果
	JLabel lab5=new JLabel("字符集(R):");
	JComboBox box=new JComboBox();//字符集下拉列表
	JPanel pan=new JPanel();//放字休效果的面板
	JList list1=new JList(font);//字体列表
	JList list2=new JList(data1);//字型列表
	JList list3=new JList(data2);//字体大小列表
	JTextField field1=new JTextField();//字体框
	JTextField field2=new JTextField();//字型框
	JTextField field3=new JTextField();//字体大小框
	JButton but1=new JButton("确定");
	JButton but2=new JButton("取消");
	public myFont(JTextArea text[])
	{
		this.text=text;
		fontText=this.text[0].getFont();//获得记事本自身字体
		Container con=dialog.getContentPane();//得到字体对话框面板
		con.setLayout(null);
		lab1.setBounds(10,10,60,20);//设置大小
		lab2.setBounds(200,10,60,20);
		lab3.setBounds(320,10,60,20);
		pan.setBounds(200,210,180,100);
		pan.add(lab4);
        dialog.setResizable(false);
		lab4.setBounds(10,20,160,70);
		lab5.setBounds(200,320,60,20);
		pan.setLayout(null);
		lab4.setBorder(BorderFactory.createLoweredBevelBorder());//创建一个具有凹入斜面边缘的边框
		pan.setBackground(Color.lightGray);
		TitledBorder bord=BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.white),"示例");//再创建一个有标题的边框，边框线条为白色
		bord.setTitleColor(Color.blue);//边框颜色为蓝色
		pan.setBorder(bord);//将此边框加到面板
		field1.setText(fontText.getFontName());//在字体框初始化从记事本获得的字体
		field1.selectAll();//对字体框进行全选
		list1.setSelectedValue((Object)field1.getText(),false);//从列表中选择指定的对象，如果所选对象存在，但列表需要滚动才能显示，则为 true；否则为 false
		field2.setText(data1[fontText.getStyle()]);//在字型框初始化从记事本获得的字型
		list2.setSelectedValue((Object)field2.getText(),false);//从列表中选择指定的对象，如果所选对象存在，但列表需要滚动才能显示，则为 true；否则为 false
		field3.setText(""+fontText.getSize());//在字体大小框初始化从记事本获得的字体大小不一 
		list3.setSelectedValue((Object)field3.getText(),false);//从列表中选择指定的对象，如果所选对象存在，但列表需要滚动才能显示，则为 true；否则为 false
		field1.setBounds(10,40,180,20);//设置大小
		field2.setBounds(200,40,110,20);
		field3.setBounds(320,40,60,20);
		box.addItem("西方");
		box.addItem("中文");
		box.setBounds(200,340,180,20);
		JScrollPane scro=new JScrollPane(list1);
		JScrollPane scro1=new JScrollPane(list3);		
		scro.setBounds(10,60,180,140);//设置大小
		list2.setBounds(200,60,110,140);
		scro1.setBounds(320,60,60,140);
		but1.setBounds(400,40,60,20);
		but2.setBounds(400,74,60,20);
		size=Integer.parseInt(field3.getText());//从字体大小框获得大小
		zip=Font.PLAIN;//从字型框获得字型
		myFont=field1.getText();//从字体框获得字体
		lab4.setFont(new Font(myFont,zip,size));//设置样式标签的字体
		con.setBackground(Color.lightGray);//设置字体框面板的背景色
		con.add(lab1);//将各组件加入面板
		con.add(lab2);
		con.add(lab3);
		con.add(pan);
		con.add(lab5);
		con.add(field1);
		con.add(field2);
		con.add(box);
		con.add(field3);
		con.add(scro);
		con.add(list2);
		con.add(scro1);
		con.add(but1);
		con.add(but2);
		dialog.setSize(480,440);//设置大小
		dialog.setTitle("字体");//设置字体对话框标题
		dialog.show();//显示		
		list1.addMouseListener(this);//加入鼠标监听器
		list2.addMouseListener(this);
		list3.addMouseListener(this);
		but1.addActionListener(this);//加入事件监听器
		but2.addActionListener(this);
	}	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==but1)
		{
			for(int i=0;i<text.length;i++)
		     text[i].setFont(new Font(myFont,zip,size));//按确定设定自己选择的字体，字型，字体大小
		}
		dialog.hide();//不管按确定还是消失，按了后字体框消失
	}
	public void mouseClicked(MouseEvent e)
	{
		if(e.getSource()==list1)
		{
			int temp=list1.locationToIndex(e.getPoint());//根据鼠标所点位置坐标获得列表中最近的索引
			list1.setSelectedIndex(temp);//在列表中选中指定的索引
			myFont=list1.getSelectedValue().toString();//获得从列表中选中的值)Object型），再将它转换成String
			field1.setText(myFont);//在字体框设置自己选择的字体
			field1.requestFocus();//在鼠标点击列表后框中会失去鼠标光标，要求重新获得光标
			field1.selectAll();//在框内的字体全选
		}
		if(e.getSource()==list2)
		{
			int temp=list2.locationToIndex(e.getPoint());//根据鼠标所点位置坐标获得列表中最近的索引
			list2.setSelectedIndex(temp);//在列表中选中指定的索引
			String str=list2.getSelectedValue().toString();//获得从列表中选中的值(Object型），再将它转换成String
			if(str.equals("常规"))//获得的字体字符串与四种字型字符串比较，得到字型(int)
			 zip=Font.PLAIN;
			if(str.equals("斜体"));
			zip=Font.ITALIC;
			if(str.equals("粗体"))
			zip=Font.BOLD;
			if(str.equals("粗斜体"))
			zip=Font.ITALIC+Font.BOLD;
			field2.setText(str);//在字型框设置体
			field2.requestFocus();//在鼠标点击列表后框中会失去鼠标光标，要求重新获得光标
			field2.selectAll();//在框内的字体全选
		}
		if(e.getSource()==list3)
		{
			int temp=list3.locationToIndex(e.getPoint());//根据鼠标所点位置坐标获得列表中最近的索引
			list3.setSelectedIndex(temp);//在列表中选中指定的索引
			String str=list3.getSelectedValue().toString();//获得从列表中选中的值)Object型），再将它转换成String
			size=Integer.parseInt(str);//将字体大小的字符串转换成整型
			field3.setText(str);//在字型大小框设置字体大小
			field3.selectAll();//在框内的字体全选
			field3.requestFocus();//在鼠标点击列表后框中会失去鼠标光标，要求重新获得光标
		}
		lab4.setFont(new Font(myFont,zip,size));//字体标签样式设置选定的字体，字型，字体大小
	}
	public void mouseEntered(MouseEvent e){};//实现了鼠标事件接口，要覆写全部方法
	public void mouseExited(MouseEvent e){};
	public void mousePressed(MouseEvent e){};
	public void mouseReleased(MouseEvent e){};
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
	JMenuItem fontBackgroundColor=new JMenuItem("设置字体背景颜色");//下拉菜单
	JMenuItem backgroundColor=new JMenuItem("设置面板背景颜色");//下拉菜单
	JMenuItem fontColor=new JMenuItem("设置字体颜色");//下拉菜单
	JMenuItem fontSize=new JMenuItem("设置字体大小");
	JMenu menu=new JMenu("设置颜色");//菜单项
	TitledBorder titleBord[]=new TitledBorder[13];//标题边框
	Border bord=BorderFactory.createEtchedBorder(EtchedBorder.RAISED,Color.blue,Color.red);//使用指定的突出显示颜色和阴影颜色创建一个具有“浮雕化”外观效果的边框 
	PrintStream print;//打印输出流
    FileInputStream input;//输入流
	JColorChooser colorSelect=new JColorChooser();//JColorChooser 提供一个用于允许用户操作和选择颜色的控制器窗格
    JFileChooser fileChoose=new JFileChooser();//JFileChooser 为用户选择文件提供了一种简单的机制
	Scanner scan,scan1=new Scanner(System.in);//输入 流
	int i,j;
	Institude college[]=new Institude[13];//13个学院
	Student stu[]=new Student[26];//26个学生
	boolean isSuccess;//当前学生是否已成功分配到某个学院检查
	boolean isSet;//设置标记，false表示未设置，true表示设置好了，设置的是某学院分配的学生姓别相等
	boolean isFormatCorrect=true;//格式标记初始化为true，判断读入的文件格式正不正确
	boolean isReadSuccess=true;//读取是否成功，初始化为成功
    boolean isTheFistDistribute=true;//是否第一次分配，初始化为是
	File file=new File("student.txt");//要读取的文件
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
	        titleBord[i]=BorderFactory.createTitledBorder(bord);//再创建一个有标题的边框,标题初始化为空
			text[i].setBorder(titleBord[i]);//设置边框
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
		if(count==26&&isFormatCorrect&&isReadSuccess)//学生有26人时并且有格式正确、读取成功
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
		fontBackgroundColor.addActionListener(this);
		backgroundColor.addActionListener(this);
		fontColor.addActionListener(this);
		fontSize.addActionListener(this);
		menu.add(fontSize);
		menu.add(fontBackgroundColor);
		menu.add(fontColor);
		menu.add(backgroundColor);
		bar.add(menu);
		setJMenuBar(bar);
		pan.add(but1);
		pan.add(but2);
		pan.setBackground(Color.pink);
		add(pan);
		setTitle("嘉应学院自律会早操安排表");
		setLocation(200,100);
		setSize(810,640);
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//使用 System exit 方法退出应用程序。仅在应用程序中使用
		show();
		isTheFistDistribute=false;//不管分配成功与否，执行到这里已经分配过一次，不是第一次分配
		if(!isReadSuccess)
			JOptionPane.showMessageDialog(this,"找不到student.txt文件，点击下面打开学生信息文件按钮查找student文件，或者选择其它文件","提示：",JOptionPane.INFORMATION_MESSAGE);
	    if(count<26)
			JOptionPane.showMessageDialog(this,"该文件宿管员的人员信息不足26个，无法为每个学院分配2名学生，请重新填写好宿管人信息，\n或选择另一文件的学生信息，使人人员数大于等于26","警告：",JOptionPane.WARNING_MESSAGE);
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
			text[i].setText("\n\n            暂未分配");
		    titleBord[i].setTitle(institude[i]);
			text[i].setBorder(titleBord[i]);
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
            scan=new Scanner(file);
		}
		catch (Exception e)
		{
			isReadSuccess=false;//读取不成功
			if(!isTheFistDistribute)//如果不是第一次分配
			JOptionPane.showMessageDialog(this,"找不到student.txt文件，点击下面打开学生信息文件按钮查找student文件，或者选择其它文件","提示：",JOptionPane.INFORMATION_MESSAGE);
			return;
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
				isFormatCorrect=false;//某些学生信息格式不正确
			    JOptionPane.showMessageDialog(this,"可能读取错了文件或student文件格式不正确，正确格式是每一行都显示：\n整数 字符串  字符串  字符串 ，如1203  张三 男  计算机学院\n请重新处理student.txt","提示：",JOptionPane.INFORMATION_MESSAGE);
		        return ;	
			}
			if(stu[i].classes<=0||(!(stu[i].sex).equals("男")&&!(stu[i].sex).equals("女")))//如果读到的数小于等于0，或性别不是男和女，则可能读取错了文件，或文件格式不正确
			{
				isFormatCorrect=false;//某些学生信息格式不正确
			    JOptionPane.showMessageDialog(this,"可能读取错了文件或者文件student文件格式不正确，正确格式是每一行都显示：\n整数 字符串  字符串  字符串 ，如1203  张三 男  计算机学院\n请重新处理student.txt","提示：",JOptionPane.INFORMATION_MESSAGE);
			    return;
			}
			i++;
		}
		count=i;//记录读取的人数
		if(count<26&&count>0)
		{
            isFormatCorrect=true;//格式正确
			if(!isTheFistDistribute)//如果不是第一次分配
			JOptionPane.showMessageDialog(this,"该文件宿管员的人员信息不足26个，无法为每个学院分配2名学生，请重新填写好宿管人信息，\n或选择另一文件的学生信息，使人人员数大于等于26","警告：",JOptionPane.WARNING_MESSAGE);
		}
		if(count<=0)//1个都学生信息都没读到，最大的可能性是读错文件，也有可能格式不正确
		{
			isFormatCorrect=false;//格式不正确
		    JOptionPane.showMessageDialog(this,"读取错了文件","提示：",JOptionPane.INFORMATION_MESSAGE);
		}
		if(count==26)
		{
			isFormatCorrect=true;//格式正确
			isReadSuccess=true;//读取成功
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
		while(!isSuccess&&isFormatCorrect)//如果格式正确分配不成功，一直生成到成功为止，才显示出来，把分配不成功的避掉，不显示
		{
			initData();//初始化数据
			if(count==26&&isFormatCorrect)//学生有26人时并且有格式正确
			{
				statistics();//统计 学生男女人生
				distrubute();//分配宿管人员
			}
		}
		for(i=0;i<13;i++)
		{
			str=college[i].stu[0].classes+"    "+college[i].stu[0].name+"    "
			+college[i].stu[0].sex+"    "+college[i].stu[0].institude+"\n"+
			college[i].stu[1].classes+"    "+college[i].stu[1].name+"    "+
			college[i].stu[1].sex+"    "+ college[i].stu[1].institude+"\n";
		    text[i].setText(str);
		}
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
		if(e.getSource()==but1)//如果命令是选择文件
		{
			fileChoose.setDialogTitle("打开文件");//设置打开文件对话框标题
			if(JFileChooser.APPROVE_OPTION==fileChoose.showOpenDialog(this))//showOpenDialog弹出一个 "Open File" 文件选择器对话框,APPROVE_OPTION是确定
			{
				file=fileChoose.getSelectedFile();
				initData();//初始化数据
				readStudent();//用于读取文件中学生信息
				if(count==26&&isFormatCorrect&&isReadSuccess)//学生有26人时并且有格式正确
				{
					statistics();//统计 学生男女人生
					distrubute();//分配宿管人员
					showDistribute();//显示分配结果
					writeDistribute();//将分配信息写入一个文件保存
				}
			}
		}		
		if(e.getSource()==but2)//如果命令是进行下一组分配
		{
				initData();//初始化数据
				readStudent();//用于读取文件中学生信息
				if(count==26&&isFormatCorrect&&isReadSuccess)//学生有26人时并且有格式正确
				{
					statistics();//统计 学生男女人生
					distrubute();//分配宿管人员
					showDistribute();//显示分配结果
					writeDistribute();//将分配信息写入一个文件保存
				}
		}
		if(e.getSource()==backgroundColor)//如果命令是设置面板背景颜色
		{
		  Color color=colorSelect.showDialog(this,"选择面板背景颜色",Color.pink);//示例颜色粉红色
		  if(color!=null)//如果选择了其中一种颜色
		  {
			  pan.setBackground(color);
		  }

		}
		if(e.getSource()==fontBackgroundColor)//如果命令是进行字体背景颜色改变
		{
		  Color color=colorSelect.showDialog(this,"选择字体背景颜色",Color.white);//示例颜色白色
		  if(color!=null)//如果选择了其中一种颜色
		  {
			  for(i=0;i<13;i++)
			  {
				  text[i].setBackground(color);
			  }
		  }
		}
		if(e.getSource()==fontColor)//如果命令是进行字体颜色改变
		{
		  Color color=colorSelect.showDialog(this,"选择字体颜色",Color.black);//示例颜色为黑色
		  if(color!=null)//如果选择了其中一种颜色
		  {
			  for(i=0;i<13;i++)
			  {
				  text[i].setForeground(color);
				  titleBord[i].setTitleColor(color);//调置标题颜色
			  }
		  }
		}
		if(e.getSource()==fontSize)//如果命令是进行字体大小改变
		{
			 new myFont(text);
		}
	}
}
class distribute1
{
	public static void main(String args[]) throws Exception
	{
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());//返回实现本机系统外观（如果有一个）的 LookAndFeel 类的名称,设置本机操作系统的外观的这个程序界面的外观
		new distribution();
	} 
}