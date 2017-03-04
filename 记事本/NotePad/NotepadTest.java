import java.io.File;
import java.net.URLClassLoader;
import java.net.URL;
import java.lang.InterruptedException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.text.SimpleDateFormat;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.ImageIcon;
import javax.swing.JScrollPane;
import javax.swing.JToolBar;
import javax.swing.JMenuItem;
import javax.swing.KeyStroke;
import javax.swing.JPopupMenu;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JFileChooser;
import javax.swing.JColorChooser;
import javax.swing.JDialog;
import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.JList;
import javax.swing.JComboBox;
import javax.swing.UIManager;
import javax.swing.JRadioButton;
import javax.swing.JToggleButton;
import javax.swing.ButtonGroup;
import javax.swing.TransferHandler;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import javax.swing.text.Document;
import javax.swing.undo.UndoManager;
import javax.swing.undo.UndoableEdit;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;
import javax.swing.event.DocumentListener;
import javax.swing.event.DocumentEvent;
import javax.swing.JComponent;
import java.awt.Font;
import java.awt.Window;
import java.awt.Event;
import java.awt.MediaTracker;
import java.awt.Color;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Container;
import java.awt.Toolkit;
import java.awt.Image;
import java.awt.GraphicsEnvironment;
import java.awt.datatransfer.*;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.Transferable;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.event.KeyEvent; 
import java.awt.event.KeyListener;
import java.awt.event.KeyAdapter;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.ActionEvent;
class MyTransferHandler extends TransferHandler
{
	JTextArea text=null;
	public MyTransferHandler(JTextArea text)
	{
		this.text=text;
	}
			public boolean canImport(JComponent c, DataFlavor[] flavors)//在拖放操作期间重复调用此方法,判断是否可以输入
			{
				for (int i = 0; i < flavors.length; i++)
				{
					if (DataFlavor.javaFileListFlavor.equals(flavors[i]))
					{
						return true;
					}
				}
				return false;
			}
			public boolean importData(JComponent com,Transferable t)
			{
					try
					{
						List list=(List)t.getTransferData(DataFlavor.javaFileListFlavor);//返回一个对象，该对象表示将要被传输的数据
						Iterator iter=list.iterator();
						while(iter.hasNext())
						{
						   File file=(File)iter.next();
						   text.setText("");
						   Scanner scan=new Scanner(new FileInputStream(file));
						   scan.useDelimiter("\n");//将此扫描器的分隔模式设置为换行符
						   while(scan.hasNext())//如果此扫描器的输入中有另一个标记
							{
								text.append(scan.next()+"\n");
							}
						}
						return true;		
					}
					catch (Exception e)
					{
					}									  
				return false;
			}		

}
class Goto extends JDialog implements ActionListener
{
	JTextArea text=null;
	JButton but1=new JButton("确定");
	JButton but2=new JButton("取消");
	JLabel lab=new JLabel("行数(L):");
	JTextField field=new JTextField();//行数框
	int row=0;//记事本行数
	int location=0;//当前的位置
	int currentline=0;//当前所在的行
	int line[];
	public Goto(JTextArea text)
	{

		this.text=text;
		setTitle("转到下列行");//设置标题
		setLayout(null);//设置布局管理器null
		lab.setBounds(10,10,50,20);//设置大小，位置
		field.setBounds(70,10,100,20);
		but1.setBounds(10,40,60,20);
		but2.setBounds(110,40,60,20);
		row=text.getLineCount();//返回 TextArea 中的行数
		line=new int[row];//分配空间
		location=text.getCaretPosition();//得到当前位置
        line[0]=text.getText().indexOf('\12',0);//'\12'是换行符,返回换行符字符在此字符串中第一次出现处的索引
		for(int i=1;i<line.length;i++)
			line[i]=text.getText().indexOf('\12',line[i-1]+1);//从找到的位置加1继续找
		for(int i=0;i<line.length;i++)
		{
			if(location<=line[i])//找到当前行，退出循环
			{
				currentline=i+1;
				break;
			}
		}
		if(currentline==0)//不在文字中，光标在文字的最下面
		{
			currentline=row;
		}
		field.setText(currentline+"");//在行数框设置当前行数
		field.selectAll();
		add(lab);
		add(field);
		add(but1);
		add(but2);
		but1.addActionListener(this);
		but2.addActionListener(this);
		setSize(200,100);//设置大小
		setResizable(false);//窗口不可拖拉变大变小
		setLocation(400,400);//设置位置
		show();//显示转到框
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==but1)//确定
		{
			String str=field.getText();//从行数得到行数的字符串
			try
			{
  			    int cnt=Integer.parseInt(str);//转换成字符串
				if(cnt<1||cnt>row)//行数超过范围
				{
                   JOptionPane.showMessageDialog(null,"行数超过范围。","提示...",JOptionPane.WARNING_MESSAGE);
				}
				else
				{
					if(cnt==1)//行数为1时，鼠标光标设在开头
						text.setCaretPosition(0);
					else
					{
						currentline=line[cnt-2]+1;
						text.setCaretPosition(currentline);//lin[cnt-1]是cnt-1行的换行符位置，+1后是第cnt行开头的位置
					}
						hide();//转到对话框消失		
				}
			}
			catch (NumberFormatException e1)
			{
                JOptionPane.showMessageDialog(null,"只能输入数字，不能输入数字以外的字母，符号等。","提示...",JOptionPane.WARNING_MESSAGE);
			}			
		}
		if(e.getSource()==but2)//取消
		{
			hide();//转到对话框消失
		}
	}
}
class MyTime extends Thread//我的时间线程
{
	JLabel lab=null;
	public MyTime(JLabel lab)
	{
		this.lab=lab;
	}
	public void run()//重写run方法
	{
		while(true)
		{
			try
			{
				this.sleep(1000);//每隔1000毫秒，即1秒显示
			    SimpleDateFormat format=new SimpleDateFormat("yyyy年MM月dd日 HH时mm分ss秒");
			    this.lab.setText("              现在时间:"+format.format(new Date()));
			}
			catch (Exception e)
			{
			}
		}
	}
}
class search implements ActionListener
{
	JDialog dialog=new JDialog();//创建一个寻找对话框
	JTextArea text=null;//文本框
	JPanel pan=new JPanel();
	JLabel lab=new JLabel("查找内容(N):");
	JCheckBox box=new JCheckBox("区分大小写(C)",true);//是一个可以被选定和取消复选框，初始化为选择
	JTextField field=new JTextField();//在这里输入要寻找的字符串
	ButtonGroup group=new ButtonGroup();//单选组，将单选按钮加到组，就能实现单选
	JRadioButton up=new JRadioButton("向上(U)");//单选按钮
	JRadioButton down=new JRadioButton("向下(D)",true);//单选按钮，初始化为选择
	JButton searchNext=new JButton("查找下一个(F)");
	JButton cancel=new JButton("取消");
	String getText=null;//从记事本中获得内容
	String getField=null;//从查找文本框获得内容
	public search(JTextArea text)
	{
		this.text=text;
		dialog.setTitle("查找");//设置对话框标题
		searchNext.setEnabled(false);//寻找按钮初始化为不弹起
		lab.setBounds(10,10,80,20);//以下几行为设置组件大小
		field.setBounds(100,10,210,20);
		searchNext.setBounds(320,10,120,20);
		box.setBounds(5,80,120,20);
		pan.setBounds(130,40,180,60);
		cancel.setBounds(320,40,120,20);
		dialog.setLayout(null);//不设置布局管理器
		field.addKeyListener(new KeyAdapter(){//加入键盘监听器
		public void keyReleased(KeyEvent e)//当键盘按键松开时
			{
				if(field.getText().length()!=0)//寻找文本框为空时，寻找按钮设置为不弹起
					searchNext.setEnabled(true);
				else
					searchNext.setEnabled(false);//寻找文本框非空时，寻找按钮设置为弹起

			}
		});
		searchNext.addActionListener(this);//加入操作事件的侦听器
		cancel.addActionListener(this);//加入操作事件的侦听器
		dialog.add(lab);//将各组件加入寻找对话框
		dialog.add(field);
		dialog.add(searchNext);
		dialog.add(box);
		pan.add(up);//将单选按钮加入面板
		pan.add(down);//将单选按钮加入面板
		pan.setBorder(BorderFactory.createTitledBorder("方向"));//面板加入边界并设置标题
		group.add(up);//两个单选按钮加到一个按钮组才能实现二选一
		group.add(down);
		dialog.add(pan);
		dialog.add(cancel);
		dialog.setResizable(false);//窗口不可拖拉变大变小
		dialog.setSize(455,150);//设置大小
		dialog.show();//显示对话框

    }
	public void actionPerformed(ActionEvent e)
	{
			getText=text.getText();//getText,getField放在事件监听器中不断监听二个编辑框有无改变，
			getField=field.getText();  //    若在构造方法中赋值则在编辑框改变也不会重新查找          
			int a=0;//判断是否找到
			
			int position=text.getCaretPosition();//获得鼠标光标位置

		if(e.getSource()==searchNext)//寻找按钮触发监听
		{
			if(box.isSelected()==false)//不勾选，即不区分大小写
			{
				getText=getText.toLowerCase();//将两个文本获得的字符串转换成小写字母
				getField=getField.toLowerCase();
			}
			if(down.isSelected())//向下查找
			{
				if(text.getSelectedText()==null)//还未查找到第一个，记事本中未选中文字
				a=getText.indexOf(getField,position);//从记事本中找到要寻找的第一个索引
				else//已查到一个以上
				a=getText.indexOf(getField,position+1-getField.length());//从查到的索引的位置加1开始查找下一个，查到的索引位置与鼠标光标位置的差距即为选定字符串的长度
			}
			else//向上查找
			{
				if(text.getSelectedText()==null)//还未查找到第一个，记事本中未选中文字
					a=getText.lastIndexOf(getField,position-1);//在记事本中指定位置从后向前找到要寻找的第一个索引
				else//已查到一个以上
					a=getText.lastIndexOf(getField,position-1-getField.length());//从查到的索引的位置减1开始查找下一个，查到的索引位置与鼠标光标位置的差距即为选定字符串的长度
			}
			if(a>-1)//查到了指定的字符串
			{             
				this.text.select(a,a+getField.length());
			}
			else//查不到，弹出查不到的信息对话框
				JOptionPane.showMessageDialog(dialog,"找不到:"+getField,"记事本",JOptionPane.QUESTION_MESSAGE);
                   
		}
		if(e.getSource()==cancel)//取消按钮触发监听
			dialog.hide();//对话框消失
	}
}
class replace implements ActionListener,KeyListener
{
	JDialog dialog=new JDialog();//创建一个替换对话框
	JTextArea text=null;//文本框
	JLabel lab1=new JLabel("查找内容(N):");
	JLabel lab2=new JLabel("替换为(P):");
	JCheckBox box=new JCheckBox("区分大小写(C)",true);//是一个可以被选定和取消复选框，初始化为选择
	JTextField field1=new JTextField();//在这里输入要寻找的字符串
	JTextField field2=new JTextField();//在这里输入要替换的字符串
	JButton replace=new JButton("替换(R)");
	JButton replaceAll=new JButton("全部替换(A)");
	JButton searchNext=new JButton("查找下一个(F)");
	JButton cancel=new JButton("取消");
	String getText=null;//从记事本中获得内容
	String getSearch=null;//从查找文本框获得内容
	String getReplace=null;//从替换广本框获得内容
	public replace(JTextArea text)
	{
		this.text=text;
  		dialog.setTitle("替换");//设置对话框标题
		dialog.setLayout(null);
		replace.setEnabled(false);//替换按钮初始化为不弹起
		replaceAll.setEnabled(false);//全部替换按钮初始化为不弹起
		searchNext.setEnabled(false);//查找按钮初始化为不弹起
		lab1.setBounds(10,10,80,20);//以下几行为设置组件大小
		field1.setBounds(100,10,180,20);
		searchNext.setBounds(300,10,120,20);
		lab2.setBounds(10,40,80,20);
		field2.setBounds(100,40,180,20);
		replace.setBounds(300,40,120,20);
		replaceAll.setBounds(300,70,120,20);
        box.setBounds(10,100,120,20);
		cancel.setBounds(300,100,120,20);
		field1.addKeyListener(this);//查找，替换，全部替换，取消按钮加入操作事件的侦听器
		searchNext.addActionListener(this);
		replace.addActionListener(this);
		replaceAll.addActionListener(this);
		cancel.addActionListener(this);
		dialog.add(lab1);//将各组件加入寻找对话框
		dialog.add(lab2);
		dialog.add(field1);
		dialog.add(field2);
		dialog.add(box);
		dialog.add(searchNext);
		dialog.add(replace);
		dialog.add(replaceAll);
		dialog.add(cancel);
		dialog.setSize(430,180);//设置大小
		dialog.show();//显示对话框
		dialog.setResizable(false);//窗口不可拖拉变大变小
	}
	public void keyReleased(KeyEvent e)//加入键盘监听器
	{
			text.setCaretPosition(0);//每当寻找文本框内容改变时，将鼠标光标置于记事本开头
			if(field1.getText().length()!=0)//寻找文本框为空时，寻找,替换，全部替换按钮设置为不弹起
			 {
				searchNext.setEnabled(true);
				replace.setEnabled(true);
				replaceAll.setEnabled(true);
			 }
			else//寻找文本框非空时，寻找,替换，全部替换按钮设置为不弹起
			   {
				searchNext.setEnabled(false);
				replace.setEnabled(false);
				replaceAll.setEnabled(false);
			   }
	} 
	public void keyPressed(KeyEvent e){}//实现键盘监听器接口要覆写全部方法
	public void keyTyped(KeyEvent e){}

	public void actionPerformed(ActionEvent e)
	{
		getText=text.getText();//getText,getSearch,getReplace放在事件监听器中不断监听三个编辑框有无改变，若在构造方法中赋值则在编辑框改变也不会重新查找，替换
		getSearch=field1.getText();
		getReplace=field2.getText();
		int a=0;//判断是否找到
		if(box.isSelected()==false)//不勾选，即不区分大小写		
		{
			getText=getText.toLowerCase();//将两个文本获得的字符串转换成小写字母
			getSearch=getSearch.toLowerCase();
		}
			
		int position=text.getCaretPosition();//获得鼠标光标位置
        if(e.getSource()==searchNext)//寻找按钮触发监听
		{  
			if(text.getSelectedText()==null)//还未查找到第一个，记事本中未选中文字			
				a=getText.indexOf(getSearch,position);	//从记事本中找到要寻找的第一个索引		
			else//已查到一个以上
//从查到的索引的位置加1开始查找下一个，查到的索引位置与鼠标光标位置的差距即为选定字符串的长度
				a=getText.indexOf(getSearch,position-getSearch.length()+1);
			if(a>-1)//查到了指定的字符串
				text.select(a,a+getSearch.length());//从索引开始选择要寻找字符串的长度
			else//查不到，弹出查不到的信息对话框
				JOptionPane.showMessageDialog(dialog,"找不到:"+field1.getText(),"记事本",JOptionPane.QUESTION_MESSAGE);
       
		}
		if(e.getSource()==replace)//替换按钮触发监听
		{
			if(text.getSelectedText()!=null)//记事本中已选定内容
			{
					text.replaceSelection(getReplace);//将寻找框的字符串替换选定的内容
			}
			else//记事本中未选定内容
				JOptionPane.showMessageDialog(dialog,"你没有选好要替换的内容.\n请输入要替换的内容并按下一步.","温馨提示:",JOptionPane.INFORMATION_MESSAGE);
		}
		if(e.getSource()==replaceAll)//全部替换按钮触发监听
		{
			int count=0;//记录替换的个数
			a=getText.indexOf(getSearch);//从记事本中找到要寻找的第一个索引		
			if(a==-1)//未找到，弹出找不到对话框
				JOptionPane.showMessageDialog(dialog,"找不到:"+field1.getText(),"记事本",JOptionPane.QUESTION_MESSAGE);

			while(a!=-1)//还未到结尾
			{
				count++;//找到一个后计数器加1
				a=getText.indexOf(getSearch,a+1);//继续寻找
			}
			if(count!=0)//已成功替换
			{
				String str=getText.replaceAll(getSearch,getReplace);//调String中的替换全部函数，将字符串全部替换
				text.setText(str);//将替换后的字符串，重新写入记事本
				JOptionPane.showMessageDialog(dialog,"找到并已替换:"+count+"个"+field1.getText(),"记事本",JOptionPane.QUESTION_MESSAGE);
                   //弹出对话框，显示替换的个数
			}


		}
		if(e.getSource()==cancel)//取消按钮触发监听
			dialog.hide();//对话框消失
	}

}
class myFont  implements MouseListener,ActionListener
{
	 JTextArea text=null;//记事本编辑区
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

	public myFont(JTextArea text)
	{
		this.text=text;
		fontText=this.text.getFont();//获得记事本自身字体
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
		 text.setFont(new Font(myFont,zip,size));//按确定设定自己选择的字体，字型，字体大小
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

class Notepad  implements ActionListener,DocumentListener,UndoableEditListener
{
	JFrame frame=new JFrame("无标题");//主标题
    JTextField field=new JTextField();/*用于JTextArea设置的TransferHandler将剪贴板被改变后,
	快捷键不可用,JTextArea可获得JTextField的TransferHandler,JTextField的TransferHandler是系统的，未改变*/
	JTextArea text=new JTextArea();//文本编辑区域
	JMenu menu[];//菜单项
	Font defaultFont=new Font("宋体",Font.PLAIN,20);//默认字体
	JFileChooser jFileChooser=new JFileChooser();//弹出一个针对用户主目录的文件选择器
	boolean isTextChange=false;//JTextArea内容是否改变
	File file=null;//选中的文件
	String path=null;//选中的文件绝对路径
	boolean flag=true;//状态栏是否可见，初始化设置状态栏可见
	boolean canUse=true;//判断是否可将文件内容拖进记事本
	JMenuBar bar=new JMenuBar();//菜单条
	JColorChooser jColor=new JColorChooser();//颜色选择器
    String menuLab[]={"文件(F)","编辑(E)","格式(O)","查看(V)","帮助(H)"};
	String menuItemLab[][]={{"新建(N)","打开(O)...","保存(S)","另存为(A)","页面设置(U)","打印(P)...","退出(X)"},
	{"撤销(U)","恢复(K)","剪切(T)","复制(C)","粘贴(P)","删除(L)","查找(F)...","查找下一个(N)","替换(R)...","转到(G)...","全选(A)","时间/日期(D)"},
		{"字体(F)"},{""},{"帮助主题(H)","关于记事本(A)"}};
	String keyItemLab[]={"撤销(U)","恢复(K)","剪切(T)","复制(C)","粘贴(P)","删除(L)","全选(A)"};
	String colorLab[]={"字体颜色","背景颜色"};//颜色菜单项目内容
	String buttonLab[]={"新建","打开","保存","另存为","打印",
		"撤销","恢复","剪切","复制","粘贴","删除","查找",
		"日期","字体","粗体","斜体","字体颜色","背景颜色","帮助"};//按钮提示消息
	JMenuItem colorItem[]=new JMenuItem[2];//颜色菜单项目
	JMenu colorMenu=new JMenu("颜色");//颜色菜单
	JMenuItem item[][]=new JMenuItem[menuItemLab.length][];//下拉菜单
    JToolBar tool=new JToolBar();//工具条，可拖动
	JButton but[]=new JButton[19];//工具条按钮
	JPanel pan=new JPanel();//下边状态栏面板
    SimpleDateFormat format=new SimpleDateFormat("yyyy年MM月dd日 HH时mm分ss秒");
	JLabel lab1=new JLabel("新建文件");//用于显示文件地址
	JLabel lab2=new JLabel("              现在时间:"+format.format(new Date()));//用于显示时间
	JLabel lab3=new JLabel("              当前光标所在的行数:"+getLineNumber());//用于行数
	JCheckBoxMenuItem check=new JCheckBoxMenuItem("自动换行(W)",true);/*
	可以被选定或取消选定的菜单项。如果被选定，菜单项的旁边通常会出现一个复选标记。如果未被选定或被取消选定，
	菜单项的旁边就没有复选标记*/
	JCheckBoxMenuItem status=new JCheckBoxMenuItem("状态栏",true);
	Container con=frame.getContentPane();//获得面板
	JPopupMenu pop=new JPopupMenu();//弹出右键
	JScrollPane scro=new JScrollPane(text);//滚动条;
	JMenuItem keyItem[]=new JMenuItem[7];//右键菜单
	Toolkit toolkit=Toolkit.getDefaultToolkit();//获取默认工具包
	Clipboard clip=toolkit.getSystemClipboard();//获得系统剪贴板

	 StringSelection s=null;/*void setContents(Transferable contents, ClipboardOwner owner) 
          将剪贴板的当前内容设置到指定的 transferable 对象，并将指定的剪贴板所有者作为新内容的所有者注册 
	      Transferable，ClipboardOwner实现了StringSelection接口，用于设置剪贴板内容需要StringSelection接口*/
	Document docu=text.getDocument();//文本容器。此接口的目标是为了满足不同的文档处理需要
	UndoManager undo=new UndoManager();//管理 UndoableEdit 列表，提供撤消或恢复适当编辑的方法
	public Notepad()
	{
        text.setFont(defaultFont);//设置默认字体
		frame.setIconImage(getImage("notepad.png"));//设置要作为此窗口图标显示的图像。
		frame.setLayout(new BorderLayout());//设置布局管理器
		menu=new JMenu[menuLab.length];//菜单项
		for(int i=0;i<menuItemLab.length;i++)
		{
            menu[i]=new JMenu(menuLab[i]);
			bar.add(menu[i]);//	将菜单加到菜单条上
            item[i]=new JMenuItem[menuItemLab[i].length];
			for(int j=0;j<menuItemLab[i].length;j++)
			{
				 item[i][j]=new JMenuItem(menuItemLab[i][j]);
				 if(i==2&&j==0)//在第2个格式菜单第一个项目之前
				 {
					 menu[i].add(check);//加入自动换行项
					 check.addActionListener(this);//加入监听器	
					 colorItem[0]=new JMenuItem(colorLab[0]);					 
					 colorMenu.add(colorItem[0]);//加入监听器
					 colorItem[0].addActionListener(this);//加入监听器
					 colorItem[1]=new JMenuItem(colorLab[1]);
					 colorMenu.add(colorItem[1]);
					 colorItem[1].addActionListener(this);//加入监听器
					 menu[i].add(colorMenu);//加入一个颜色菜单，颜色菜单里有背景颜色，字体颜色丙项
					 

				 }
	              if(j!=0&&j%3==0)//每学3个菜单项加一个分隔符
					  menu[i].addSeparator();
				  if(i!=3)//依次在每个菜单加入菜单项
					{
					menu[i].add(item[i][j]);
					item[i][j].addActionListener(this);//加入监听器
					}
				  else//在第4个查看菜单加入状态栏项
				    {
					menu[i].add(status);
					status.addActionListener(this);//加入监听器
					}
			}
		}
		for(int i=0;i<keyItemLab.length;i++)
		{
			keyItem[i]=new JMenuItem(keyItemLab[i]);
			if(i==2||i==6)//加一个分隔符
				pop.addSeparator();
			pop.add(keyItem[i]);//将菜单项加入右键菜单
			keyItem[i].addActionListener(this);//加入监听器
		}
		 for(int i=0;i<buttonLab.length;i++)
		 {
			 but[i]=new JButton();
			 tool.add(but[i]);//将按钮加入工具条
			 but[i].addActionListener(this);//加入事件监听器
			 but[i].setToolTipText(buttonLab[i]);
		 }

		this.text.setSelectedTextColor(Color.blue);//设置选择文本框中被选择的字体颜色
        this.setKeyBoardShortCuts();//设置快捷键
		this.setIcon();//设置图标
		this.reset();//重置，初始化
        this.text.setLineWrap(true);//设置自动换行
		text.add(pop);
		text.addMouseListener(new MouseAdapter(){     //在文本框加入鼠标事件         
			public void mouseReleased(MouseEvent e)//鼠标松开时
			{
		       checkOperate();//操作检测，是否可复制，删除，粘贴，剪切
	           lab3.setText("              当前光标所在的行数:"+getLineNumber());//用于行数

				if(e.isPopupTrigger())   //右键是否弹出    
					pop.show(e.getComponent(),e.getX(),e.getY());//getComponent返回事件的始发者,弹在相对于始发者地址
			}	
			public void mouseExited(MouseEvent e)//鼠标离开时，可能是将其它文件拖进记事本，所以设置记事本可拖其它文件
			{//获得改变系统属性剪贴板，ctrl+c,ctrl+v,ctrl+x快捷键不可用
				text.setTransferHandler(new MyTransferHandler(text));//设置用于处理,管理往返于记事本的 Transferable 的传输
			}
		});
		text.addKeyListener(new KeyAdapter(){
		public void keyReleased(KeyEvent e)
			{
			   isTextChange=true;//在文本框加入键盘监听器，当键盘在文本框输入时，文本改变为true
			   checkOperate();//操作检测，是否可复制，删除，粘贴，剪切
	           lab3.setText("              当前光标所在的行数:"+getLineNumber());//用于行数
			}
		public void keyPressed(KeyEvent e)//键盘按下时检测是否是与复制，粘贴，剪切快捷键，这些键要用到剪贴板
			{
			   String key=KeyEvent.getKeyText(e.getKeyCode());
               if(key.equals("X")||key.equals("C")||key.equals("V")||key.equals("Ctrl"))/*是这些快捷键，释放TransferHandler占用的剪贴板，
			   获得系统属性剪贴板，ctrl+c,ctrl+v,ctrl+x快捷键可用*/
				text.setTransferHandler(field.getTransferHandler());
			}
		});
		docu.addDocumentListener(this);//观察者使用该接口注册以接收文本文档的更改通知
		docu.addUndoableEditListener(this);//对接收有关可撤消操作,在文本插入、移除、属性更改时为可撤销
        checkOperate();//操作检测，是否可复制，删除，粘贴，剪切
		frame.add(tool,BorderLayout.NORTH);//工具条加在上面
		frame.add(scro,BorderLayout.CENTER);//在中间加入带滚动条的文本框
		pan.add(lab1);
		pan.add(lab2);
		pan.add(lab3);
		pan.setLayout(new FlowLayout(FlowLayout.LEFT));
		frame.add(pan,BorderLayout.SOUTH);//状态栏加在下面
		new MyTime(lab2).start();//时间线程开启
		frame.setJMenuBar(bar);//设置菜单条
		menu[1].addActionListener(this);
	    text.requestFocus();//请求此 text获取输入焦点,此时光标在最后，若无此句，则不能设置光标，下语句无效
		text.setTransferHandler(new MyTransferHandler(text));//设置用于处理,管理往返于记事本的 Transferable 的传输	
		frame.addWindowListener(new WindowAdapter(){
		public void windowClosing(WindowEvent e)
			{
			  checkText();//主窗口关闭时，询问是否保存，或取消关闭
			}
		});//加入接收窗口事件的侦听器
		text.setDragEnabled(true);//开启自动拖动处理
		frame.setSize(1000,800);//设置大小
		frame.setLocation(100,100);//设置位置
		frame.setVisible(true);//设置可见
		frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);//设置默认关闭方式不执行任何操作
	}
	public void setKeyBoardShortCuts()//设置快捷键
	{
		item[0][0].setAccelerator(KeyStroke.getKeyStroke('N',Event.CTRL_MASK));
		item[0][1].setAccelerator(KeyStroke.getKeyStroke('O',Event.CTRL_MASK));
		item[0][2].setAccelerator(KeyStroke.getKeyStroke('S',Event.CTRL_MASK));
		item[0][3].setAccelerator(KeyStroke.getKeyStroke('F',Event.CTRL_MASK));		
		item[0][5].setAccelerator(KeyStroke.getKeyStroke('P',Event.CTRL_MASK));
		item[1][0].setAccelerator(KeyStroke.getKeyStroke('Z',Event.CTRL_MASK));
		item[1][1].setAccelerator(KeyStroke.getKeyStroke('Z',Event.ALT_MASK));
		item[1][2].setAccelerator(KeyStroke.getKeyStroke('X',Event.ALT_MASK));
		item[1][3].setAccelerator(KeyStroke.getKeyStroke('C',Event.ALT_MASK));
		item[1][4].setAccelerator(KeyStroke.getKeyStroke('V',Event.ALT_MASK));
		item[1][5].setAccelerator(KeyStroke.getKeyStroke("DELETE"));
		item[1][6].setAccelerator(KeyStroke.getKeyStroke('F',Event.CTRL_MASK));
		item[1][7].setAccelerator(KeyStroke.getKeyStroke("F3"));
		item[1][8].setAccelerator(KeyStroke.getKeyStroke('H',Event.CTRL_MASK));
		item[1][9].setAccelerator(KeyStroke.getKeyStroke('G',Event.CTRL_MASK));
		item[1][10].setAccelerator(KeyStroke.getKeyStroke('A',Event.CTRL_MASK));
		item[1][11].setAccelerator(KeyStroke.getKeyStroke("F5"));
		item[0][0].setMnemonic(KeyEvent.VK_N);
		item[0][1].setMnemonic(KeyEvent.VK_O);
		item[0][2].setMnemonic(KeyEvent.VK_S);
		item[0][3].setMnemonic(KeyEvent.VK_A);
		item[0][6].setMnemonic(KeyEvent.VK_X);
		item[1][0].setMnemonic(KeyEvent.VK_U);
		item[1][1].setMnemonic(KeyEvent.VK_K);
		item[1][2].setMnemonic(KeyEvent.VK_T);
		item[1][3].setMnemonic(KeyEvent.VK_C);
		item[1][4].setMnemonic(KeyEvent.VK_P);
		item[1][5].setMnemonic(KeyEvent.VK_L);
		item[1][6].setMnemonic(KeyEvent.VK_F);
		item[1][7].setMnemonic(KeyEvent.VK_N);
		item[1][8].setMnemonic(KeyEvent.VK_R);
		item[1][9].setMnemonic(KeyEvent.VK_G);
		item[1][10].setMnemonic(KeyEvent.VK_A);
		item[1][11].setMnemonic(KeyEvent.VK_D);
	}
	public void setIcon()//设置图标
	{//如果没有这些图标,请下载相应的图标文件，下齐setIcon()里面的图片，原后按setIcon
     //里面的命名,可从百度上搜索图标下载，输入图标英文搜索,可用图片软件进行裁剪大小
        try//这里需要捕捉异常，否则会出现NullPointerException而终止
        {
			but[0].setIcon(new ImageIcon(getImage("new.png")));//以下几行设置按钮可用时图标
			but[1].setIcon(new ImageIcon(getImage("open.gif")));
			but[2].setIcon(new ImageIcon(getImage("save.png")));
			but[3].setIcon(new ImageIcon(getImage("saveas.gif")));
			but[4].setIcon(new ImageIcon(getImage("print.png")));
			but[5].setIcon(new ImageIcon(getImage("undo.png")));
			but[6].setIcon(new ImageIcon(getImage("redo.png")));
			but[7].setIcon(new ImageIcon(getImage("cut.png")));
			but[8].setIcon(new ImageIcon(getImage("copy.png")));
			but[9].setIcon(new ImageIcon(getImage("paste.png")));
			but[10].setIcon(new ImageIcon(getImage("delete.png")));
			but[11].setIcon(new ImageIcon(getImage("search.png")));
			but[12].setIcon(new ImageIcon(getImage("date.png")));
			but[13].setIcon(new ImageIcon(getImage("font.png")));
			but[14].setIcon(new ImageIcon(getImage("bold.png")));
			but[15].setIcon(new ImageIcon(getImage("italic.png")));
			but[16].setIcon(new ImageIcon(getImage("fontcolor.png")));
			but[17].setIcon(new ImageIcon(getImage("backgroundcolor.png")));
			but[18].setIcon(new ImageIcon(getImage("help.png")));
			menu[0].setIcon(new ImageIcon(getImage("file.gif")));//以下几行设置菜单图标
			menu[1].setIcon(new ImageIcon(getImage("edit.png")));
			menu[2].setIcon(new ImageIcon(getImage("format.png")));
			menu[3].setIcon(new ImageIcon(getImage("show.png")));
			menu[4].setIcon(new ImageIcon(getImage("help.png")));
			item[0][0].setIcon(new ImageIcon(getImage("new.png")));//以下几行设置项目可用图标
			item[0][1].setIcon(new ImageIcon(getImage("open.gif")));
			item[0][2].setIcon(new ImageIcon(getImage("save.png")));
			item[0][3].setIcon(new ImageIcon(getImage("saveas.gif")));
			item[0][5].setIcon(new ImageIcon(getImage("print.png")));
			item[0][6].setIcon(new ImageIcon(getImage("exit.gif")));
			item[1][0].setIcon(new ImageIcon(getImage("undo.png")));
			item[1][1].setIcon(new ImageIcon(getImage("redo.png")));
			item[1][2].setIcon(new ImageIcon(getImage("cut.png")));
			item[1][3].setIcon(new ImageIcon(getImage("copy.png")));
			item[1][4].setIcon(new ImageIcon(getImage("paste.png")));
			item[1][5].setIcon(new ImageIcon(getImage("delete.png")));
			item[1][6].setIcon(new ImageIcon(getImage("search.png")));
			item[1][7].setIcon(new ImageIcon(getImage("search.png")));
			item[1][8].setIcon(new ImageIcon(getImage("replace.png")));
			item[1][9].setIcon(new ImageIcon(getImage("goto.png")));
			item[1][10].setIcon(new ImageIcon(getImage("selectall.png")));
			item[1][11].setIcon(new ImageIcon(getImage("date.png")));
			item[2][0].setIcon(new ImageIcon(getImage("font.png")));
			colorItem[0].setIcon(new ImageIcon(getImage("fontcolor.png")));//颜色按钮的图标
			colorItem[1].setIcon(new ImageIcon(getImage("backgroundcolor.png")));
			colorMenu.setIcon(new ImageIcon(getImage("color.png")));
			item[1][0].setDisabledIcon(new ImageIcon(getImage("undo1.png")));//设置不可撤销图标
			item[1][1].setDisabledIcon(new ImageIcon(getImage("redo1.png")));//以下几行设置复制、剪切、粘贴、删除不可用时图标
			item[1][2].setDisabledIcon(new ImageIcon(getImage("cut1.png")));//以下几行设置复制、剪切、粘贴、删除不可用时图标
			item[1][3].setDisabledIcon(new ImageIcon(getImage("copy1.png")));
			item[1][4].setDisabledIcon(new ImageIcon(getImage("paste1.png")));
			item[1][5].setDisabledIcon(new ImageIcon(getImage("delete1.png")));
			but[5].setDisabledIcon(new ImageIcon(getImage("undo1.png")));//设置不可撤销图标
			but[6].setDisabledIcon(new ImageIcon(getImage("redo1.png")));
			but[7].setDisabledIcon(new ImageIcon(getImage("cut1.png")));
			but[8].setDisabledIcon(new ImageIcon(getImage("copy1.png")));
			but[9].setDisabledIcon(new ImageIcon(getImage("paste1.png")));
			but[10].setDisabledIcon(new ImageIcon(getImage("delete1.png")));
			
        }
        catch (Exception e)
        {
System.out.println("缺少相应的图标文件，请下载相应的图标文件，下齐setIcon()里面的图片，原后按setIcon里面的命名,可从百度上搜索图标下载，输入图标英文搜索");
        }
	}
	public void undoableEditHappened(UndoableEditEvent e)
	{
		undo.addEdit(e.getEdit());//e.getEdit()为UndoableEdit,即一个可撤销的编辑
	}
	public void removeUpdate(DocumentEvent e)//覆写DocumentListener方法,给出移除了一部分文档的通知
	{
		item[1][0].setEnabled(true);
		but[5].setEnabled(true);
		but[5].setToolTipText("撤销");
		keyItem[0].setEnabled(true);
	}
	public void insertUpdate(DocumentEvent e)//覆写DocumentListener方法, 给出对文档执行了插入操作的通知。
	{
		item[1][0].setEnabled(true);
		but[5].setEnabled(true);
		but[5].setToolTipText("撤销");
		keyItem[0].setEnabled(true);
	}
	public void changedUpdate(DocumentEvent e)//覆写DocumentListener方法,给出属性或属性集发生了更改的通知
	{
		item[1][0].setEnabled(true);
		but[5].setEnabled(true);
		but[5].setToolTipText("撤销");
		keyItem[0].setEnabled(true);
	}
	public void actionPerformed(ActionEvent e)
	{
		String command=e.getActionCommand();//此事件获得的命令
		if("关于记事本(A)".equals(command))//弹出信息对话框
			JOptionPane.showMessageDialog(this.frame,"版权：嘉应学院中1E502！","关于记事本",JOptionPane.INFORMATION_MESSAGE,new ImageIcon(getImage("roommate.png")));
	    if("帮助主题(H)".equals(command)||e.getSource()==but[18])//弹出信息对话框
			JOptionPane.showMessageDialog(this.frame,"帮助文档已缺失，无法找到help.chm","帮助主题",JOptionPane.WARNING_MESSAGE);
	    if("剪切(T)".equals(command)||e.getSource()==but[7])
		{	
			String info=this.text.getSelectedText(); //从记事本中获得选择的文字
			if(info!=null)
             s=new StringSelection(info);
			clip.setContents(s,s);//将选定内容设置到剪贴板
            this.text.replaceRange(null,this.text.getSelectionStart(),this.text.getSelectionEnd());//以空字符串替换选定的字符串	
			checkOperate();//操作检测，是否可复制，删除，粘贴，剪切
		}
	    if("复制(C)".equals(command)||e.getSource()==but[8])
		{
			String info=this.text.getSelectedText();//从记事本中获得选择的文字
			if(info!=null)
            s=new StringSelection(info);
            clip.setContents(s,null);	//将选定内容设置到剪贴板		
			checkOperate();//操作检测，是否可复制，删除，粘贴，剪切
		}
	    if("粘贴(P)".equals(command)||e.getSource()==but[9])
		{

			try
			{
				Transferable tran=clip.getContents(this);//剪贴板获得传输操作类对象
				if(tran!=null)
				{
					String info=(String)tran.getTransferData(DataFlavor.stringFlavor);// 返回一个对象，该对象表示将要被传输的数据，是剪贴板内容
					if(info!=null)
					this.text.replaceRange(info,this.text.getSelectionStart(),this.text.getSelectionEnd());//将剪贴板内容放到指定位置，若已有内容则替换
					isTextChange=true;//文本改变
				}
				
			}
			catch (Exception e1)
			{
			}
            checkOperate();//操作检测，是否可复制，删除，粘贴，剪切

		}
	  if("删除(L)".equals(command)||e.getSource()==but[10])
		{

          this.text.replaceRange(null,this.text.getSelectionStart(),this.text.getSelectionEnd());//以空字符串替换选定的字符串	
		  checkOperate();//操作检测，是否可复制，删除，粘贴，剪切

		}
	  if("全选(A)".equals(command))
		{
		  this.text.setSelectionStart(0);//选择开始点设置为指定的位置
		  this.text.setSelectionEnd(this.text.getText().length());//选择结束点设置为指定的位置
		  checkOperate();//操作检测，是否可复制，删除，粘贴，剪切
	
		}
	  if("自动换行(W)".equals(command))
		{
		  if(this.text.getLineWrap())//获取文本区的换行策略,若true则为设置自动换行，触发事件后设为false
			  this.text.setLineWrap(false);
		  else
			  this.text.setLineWrap(true);//获取文本区的换行策略,若false则为设置自动换行，触发事件后设为true

		}
	  if("状态栏".equals(command))
		{
		  if(flag)//可见时，触发事件后状态栏设为不可见
			{
			  this.pan.setVisible(false);
			  flag=false;
			}
		else
			{
			this.pan.setVisible(true);//不可见时，触发事件后状态栏设为可见
			flag=true;
			}
		}
		if("时间/日期(D)".equals(command)||e.getSource()==but[12])
		{
			this.text.append("\n现在时间:"+format.format(new Date()));
		}
		if("新建(N)".equals(command)||e.getSource()==but[0])
		{
			file=null;
			text.setCaretPosition(0);//鼠标光标定义在开头
			if(isTextChange)//文本改变，询问是否保存
			{
				isTextChange=false;//设为没改变，等再次改变时再设为true
				//询问对话框
				int i=JOptionPane.showConfirmDialog(this.frame,"文件 "+this.frame.getTitle()+"的文字已改变。\n想保存文件吗?","记事本",JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.WARNING_MESSAGE);
				switch(i)
				{
					case JOptionPane.YES_OPTION://选择是，则保存
					{
					   this.save();
                       break;
					}
					case JOptionPane.NO_OPTION://选择否，重置文本
					{
                        this.reset();
						break;
					}
					case JOptionPane.CANCEL_OPTION:break;//选择取消，什么也不做
					default:break;
				}
			}
			else
			{
               this.reset();//文本没改变时，重置文本
			}
		}  
		if("打开(O)...".equals(command)||e.getSource()==but[1])
		{
			if(isTextChange)//文本改变，询问是否保存
			{
				isTextChange=false;//设为没改变，等再次改变时再设为true
               //询问对话框
				int i=JOptionPane.showConfirmDialog(this.frame,"文件 "+this.frame.getTitle()+"的文字已改变。\n想保存文件吗?","记事本",JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.WARNING_MESSAGE);
				switch(i)
				{
					case JOptionPane.YES_OPTION://选择是，则保存
					{
					   this.save();
                       break;
					}
					case JOptionPane.NO_OPTION://选择否，打开文件
					{
                        this.showOpenDialog();//打开对话框 
						break;
					}
					case JOptionPane.CANCEL_OPTION:break;//选择取消，什么也不做
					default:break;
				}
			}
			else
			{
				this.showOpenDialog();//文本没改变时，打开文件
			}
		
	    }
     if("保存(S)".equals(command)||e.getSource()==but[2])
		{
		  isTextChange=false;//保存后文本设为没改变，等再次改变时再设为true
		  if(path==null)//还没选定文件，弹出保存对话框，选择要保存的位置
			{
			  this.save();//存为
			}
		  else//选定文件，有了文件路径，则将文本写入指定文件
			{
			  this.write();
		      this.lab1.setText("保存文件:"+path);
			}

		}
	  if("另存为(A)".equals(command)||e.getSource()==but[3])
		{	
            this.save();//存为
		}
	  if("退出(X)".equals(command))
		  checkText();
	  if("字体颜色".equals(command)||e.getSource()==but[16])
		{
//从JColorChooser弹出的颜色选择框选择颜色作为文本框前景色，即字体颜色，默认颜色黑色
		     this.text.setForeground(jColor.showDialog(this.text,"选择颜色",Color.black));
		}
	  if("背景颜色".equals(command)||e.getSource()==but[17])
		{
		  Color color=jColor.showDialog(this.text,"选择颜色",Color.white);
		  if(color!=null)
  		  this.text.setBackground(color);//从JColorChooser弹出的颜色选择框选择颜色作为文本框背景色，默认颜色白色
		}

	  if("字体(F)".equals(command)||e.getSource()==but[13])
		{
		  new myFont(text);//设置字体
		}
	  if("查找(F)...".equals(command)||"查找下一个(N)".equals(command)||e.getSource()==but[11])
		{
		  text.requestFocus();//请求此 text获取输入焦点,此时光标在最后，若无此句，则不能设置光标，下语句无效
		  text.setCaretPosition(0);//将光标置前
		  new search(text);//查找类
		}
	  if("替换(R)...".equals(command))
		{
		  text.requestFocus();//请求此 text获取输入焦点,此时光标在最后，若无此句，则不能设置光标，下语句无效
		  text.setCaretPosition(0);//将光标置前
		  new replace(text);//替换类
		}
	  if("撤销(U)".equals(command)||e.getSource()==but[5])
		{
		    if(undo.canUndo())//UndoManager有可撤销的编辑UndoableEdit
			{
				undo.undo();//进行撤销操作，UndoManager将减少一个编辑UndoableEdit
				item[1][1].setEnabled(true);//撤销后可恢复
				but[6].setEnabled(true);
				keyItem[1].setEnabled(true);
				but[6].setToolTipText("恢复");
				if(!undo.canUndo())//进行这次撤销后,UndoManager没有可撤销的编辑
				{
				item[1][0].setEnabled(false);
				but[5].setEnabled(false);
				but[5].setToolTipText("无法撤销");
				keyItem[0].setEnabled(false);
				}
			}
		}
	  if("恢复(K)".equals(command)||e.getSource()==but[6])
		{
		    if(undo.canRedo())//UndoManager有可恢复的编辑UndoableEdit
			{
				undo.redo();//进行恢复操作，UndoManager将增加一个编辑UndoableEdit
				item[1][0].setEnabled(true);//恢复后可撤销恢复
				but[5].setEnabled(true);
				keyItem[0].setEnabled(true);
				but[5].setToolTipText("撤销");
				if(!undo.canRedo())//进行这次恢复后,UndoManager没有可恢复的编辑
				{
				item[1][1].setEnabled(false);
				but[6].setEnabled(false);
				keyItem[1].setEnabled(false);
				but[6].setToolTipText("无法恢复");
				}
			}
		}

	  if("转到(G)...".equals(command))
		{
		  new Goto(text);
		}
	  if("打印(P)...".equals(command)||e.getSource()==but[4])
		{
		  JOptionPane.showMessageDialog(null,"本功能由于时间和技术关系，尚未进行完善","抱歉：",JOptionPane.INFORMATION_MESSAGE);
		}
	  if("页面设置(U)".equals(command))
		{
		  JOptionPane.showMessageDialog(null,"本功能由于时间和技术关系，尚未进行完善","抱歉：",JOptionPane.INFORMATION_MESSAGE);
		}

	  if(e.getSource()==but[14])//设置文本粗体
		{
			Font font=this.text.getFont();//得到记事本原来的颜色
			int style=font.getStyle();//得到记事本中字型
			if(style==Font.BOLD)//本来是粗体的，设为常规
			font=new Font(font.getName(),Font.PLAIN,font.getSize());
			if(style==Font.PLAIN)//本来是常规的，再加粗
			font =new Font(font.getName(),Font.BOLD,font.getSize());
			if(style==Font.ITALIC)//本来是斜体的,再加粗
			font=new Font(font.getName(),Font.ITALIC+Font.BOLD,font.getSize());
			if(style==Font.BOLD+Font.ITALIC)//本来是粗斜体,按下后去除粗体
			font=new Font(font.getName(),Font.ITALIC,font.getSize());
			this.text.setFont(font);//设置字体
		}
	  if(e.getSource()==but[15])//设置文本斜体
		{
			Font font=this.text.getFont();//得到记事本原来的颜色
			int style=font.getStyle();//得到记事本中字型
			if(style==Font.ITALIC)//本来是斜体的，设为常规
			font=new Font(font.getName(),Font.PLAIN,font.getSize());
			if(style==Font.PLAIN)//本来是常规的，再加粗
			font =new Font(font.getName(),Font.ITALIC,font.getSize());
			if(style==Font.BOLD)//本来是粗体的,再加斜
			font=new Font(font.getName(),Font.ITALIC+Font.BOLD,font.getSize());
			if(style==Font.BOLD+Font.ITALIC)//本来是粗斜体,按下后去除斜体
			font=new Font(font.getName(),Font.BOLD,font.getSize());
			this.text.setFont(font);//设置字体
		}

	}
	public int getLineNumber()//得到当前行数
	{
		int row=text.getLineCount();//返回 TextArea 中的行数
		int line[]=new int[row];//分配空间
		int location=text.getCaretPosition();//得到当前位置
		int currentline=0;//当前行数
        line[0]=text.getText().indexOf('\12',0);//'\12'是换行符,返回换行符字符在此字符串中第一次出现处的索引
		for(int i=1;i<line.length;i++)
			line[i]=text.getText().indexOf('\12',line[i-1]+1);//从找到的位置加1继续找
		for(int i=0;i<line.length;i++)
		{
			if(location<=line[i])//找到当前行，退出循环
			{
				currentline=i+1;
				break;
			}
		}
		if(currentline==0)//不在文字中，光标在文字的最下面
		{
			currentline=row;
		}
		return currentline;
	}
	Image getImage(String filename)
	{
		Image image = null;
		URLClassLoader urlLoader = (URLClassLoader)this.getClass().getClassLoader();    /*this.getClass()得到Notepad这个类，再从这个类得到加载器，
		用于从指向 JAR 文件和目录的 URL 的搜索路径加载类和资源 ,这样从MyEclise导出的包中的图片就能找到路径并读取  */    
		URL url = null;// URL 代表一个统一资源定位符

		url = urlLoader.findResource(filename);//得到文件或目录
		if(url==null)/*为什么需要这语句，如果没有这语句，在下面语句getImage(null)时会出现:
		java.lang.NullPointerException
        at sun.awt.image.URLImageSource.getConnection(URLImageSource.java:115)
        at sun.awt.image.URLImageSource.getDecoder(URLImageSource.java:125)
        at sun.awt.image.InputStreamImageSource.doFetch(InputStreamImageSource.j
ava:263)
        at sun.awt.image.ImageFetcher.fetchloop(ImageFetcher.java:205)
        at sun.awt.image.ImageFetcher.run(ImageFetcher.java:169)
		*/		
		return null;
		try
		{
			image = Toolkit.getDefaultToolkit().getImage(url);//根所路径获得图像
			//getImage()抛出SecurityException,由安全管理器抛出的异常，指示存在安全侵犯,try{}catch{}不了(无效)，出现空指针时，抛出安全异常程序终止
				return image;//返回图象		
		
		}//这里try catch多余，url=null时，即时try catch依然弹出异常而终止
		catch (Exception e)
		{
			return image;
		}
	}

	public void checkText()//检查文本是否已变，要不要保存
	{
		file=null;
		text.setCaretPosition(0);//鼠标光标定义在开头
		if(isTextChange)//文本改变，询问是否保存
		{
			isTextChange=false;//设为没改变，等再次改变时再设为true
			//询问对话框
			int i=JOptionPane.showConfirmDialog(this.frame,"文件 "+this.frame.getTitle()+"的文字已改变。\n想保存文件吗?","记事本",JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.WARNING_MESSAGE);
			switch(i)
			{
				case JOptionPane.YES_OPTION://选择是，则保存后关闭
				{
				   this.save();
				  
				}
				case JOptionPane.NO_OPTION://选择否，关闭
				{
					System.exit(0);
				}
				case JOptionPane.CANCEL_OPTION:break;//选择取消，什么也不做
				default:break;
			}
		}
		else
			System.exit(0);

	}
	public void save()//存为
	{
			jFileChooser.setDialogTitle("另存为");//设置保存对话框标题
		   if(JFileChooser.APPROVE_OPTION==jFileChooser.showSaveDialog(this.frame))
		   file=jFileChooser.getSelectedFile();
		   path=file.getPath();//保存对话框按确定后从选择的文件获得选择的文件路径
		   this.lab1.setText("保存文件:"+path);
		   	this.frame.setTitle(file.getName());//将标题设为选定的文件路径
		   this.write();//写入文件

	}
    public void reset()//重置
	{
		this.text.setText("");
		this.frame.setTitle("无标题");
		this.lab1.setText("新建文件");
		undo.discardAllEdits();//清空撤消管理器，向进程中的每个编辑发送一个 die 消息
		item[1][0].setEnabled(false);//撤销、恢复按钮设为不可用
		but[5].setEnabled(false);
		but[5].setToolTipText("无法撤销");
		keyItem[0].setEnabled(false);
		item[1][1].setEnabled(false);
		but[6].setEnabled(false);
		but[6].setToolTipText("无法恢复");
		keyItem[1].setEnabled(false);

	}
    public void showOpenDialog()//显示打开对话框
	{
	   jFileChooser.setDialogTitle("打开");//设置打开对话框标题
		if(JFileChooser.APPROVE_OPTION==jFileChooser.showOpenDialog(this.frame))
		{
			file=jFileChooser.getSelectedFile();
			path=file.getPath();//保存对话框按确定后从选择的文件获得选择的文件路径
			this.lab1.setText("打开文件:"+path);
			this.frame.setTitle(file.getName());
			this.read();//读文件

		}
	}
	public void checkOperate()//操作检测，是否可复制，删除，粘贴，剪切
	{
        String str=text.getSelectedText();//记事本中被选中的字符串
		Transferable tran=clip.getContents(this);//剪贴板获得传输操作类对象
		String info=null;
		try
		{
	    	 info=(String)tran.getTransferData(DataFlavor.stringFlavor);// 返回一个对象，该对象表示将要被传输的数据，是剪贴板内容			
		}
		catch (Exception e)
		{
		}
		if(str==null)//无选中内容
		{
			item[1][2].setEnabled(false);
			item[1][3].setEnabled(false);
			item[1][5].setEnabled(false);
			keyItem[2].setEnabled(false);
			keyItem[3].setEnabled(false);
			keyItem[5].setEnabled(false);
            but[7].setToolTipText("无法剪切");
            but[8].setToolTipText("无法复制");
            but[10].setToolTipText("无法删除");

			but[7].setEnabled(false);
			but[8].setEnabled(false);
			but[10].setEnabled(false);

		}
		else
		{
			item[1][2].setEnabled(true);
			item[1][3].setEnabled(true);
			item[1][5].setEnabled(true);
			keyItem[2].setEnabled(true);
			keyItem[3].setEnabled(true);
			keyItem[5].setEnabled(true);
            but[7].setToolTipText("剪切");
            but[8].setToolTipText("复制");
            but[10].setToolTipText("删除");

			but[7].setEnabled(true);
			but[8].setEnabled(true);
			but[10].setEnabled(true);
   		}
		if(info==null)//剪贴板没内容
		{
			item[1][4].setEnabled(false);
			but[9].setEnabled(false);
			keyItem[4].setEnabled(false);
            but[9].setToolTipText("无法粘贴");
		}
		else
		{
			item[1][4].setEnabled(true);
			but[9].setEnabled(true);
			keyItem[4].setEnabled(true);
            but[9].setToolTipText("粘贴");
		}
		if(text.getText().length()==0)//记事本无内容全选为不可用
		{
			keyItem[6].setEnabled(false);
			item[1][10].setEnabled(false);
		}
		else
		{
			keyItem[6].setEnabled(true);
			item[1][10].setEnabled(true);

		}
	}
	public void write()//写文件
	{
		if(path!=null)
		{
			try
			{
			PrintStream print=new PrintStream(new FileOutputStream(path));//输出流
			String str[]=this.text.getText().split("\n");//从文本框获得的字符串按换行符分隔成多个字符
			for(int i=0;i<str.length;i++)
				print.println(str[i]);//
			undo.discardAllEdits();//清空撤消管理器，向进程中的每个编辑发送一个 die 消息
			item[1][0].setEnabled(false);//写入文件时，上一文件的操作已完成，撤销所有"撤销","恢复"操作
			but[5].setEnabled(false);
			but[5].setToolTipText("无法撤销");
			keyItem[0].setEnabled(false);
			item[1][1].setEnabled(false);
			but[6].setEnabled(false);
			but[6].setToolTipText("无法恢复");

			keyItem[1].setEnabled(false);
			}
			catch (Exception e)
			{
			}

		}
	}
	public void read()//读文件
	{
		if(path!=null)
		{
			try
			{
				Scanner scan=new Scanner(new FileInputStream(path));//输入流
				scan.useDelimiter("\n");//输入流以换行符为分隔符，读到换行符时停止
				this.text.setText("");
				while(scan.hasNext())//还未到结尾时间
				{
					this.text.append(scan.next());
					this.text.append("\n");
				}	
				undo.discardAllEdits();//清空撤消管理器，向进程中的每个编辑发送一个 die 消息
				item[1][0].setEnabled(false);//读入文件时，上一文件的操作已完成，撤销所有"撤销","恢复"操作
				but[5].setEnabled(false);
				but[5].setToolTipText("无法撤销");

				keyItem[0].setEnabled(false);
				item[1][1].setEnabled(false);
				but[6].setEnabled(false);
				but[5].setToolTipText("无法恢复");
				keyItem[1].setEnabled(false);
				
			}
			catch (Exception e)
			{
			}
		}
	}
}
class NotepadTest
{
	public static void main(String args[])throws Exception
	{
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		new Notepad();
		System.out.println();
	}
}