/*�Լ�д�ļ�����������Ŀǰ���*/
import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Date;
import java.text.SimpleDateFormat;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.border.*;
class Student//ѧ����
{
	int  classes;//�༶
	String name;//����
	String sex;//�ձ�
	String institude;//ѧԺ
}
class myFont  implements MouseListener,ActionListener
{
	 JTextArea text[];//���±��༭��
	 JDialog  dialog=new JDialog();//������
	 String myFont=null;//����
	 Font fontText=null;//���±���������
	 int zip=0;//����
	 int size=0;//�����С
	String data1[]={"����","б��","����","��б��"};//����
	String data2[]={"8","9","10","11","12","14","16","18","20","22","24","26",
		"28","36","48","72"};//�����С
	String font[]=GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();//��û����Լ�������������
	JLabel lab1=new JLabel("����(F):");
	JLabel lab2=new JLabel("����(Y):");
	JLabel lab3=new JLabel("��С(S):");
	final JLabel lab4=new JLabel("��1E502�������",JLabel.CENTER);//�����ǩ�Ǽ������ı������ӡ�Ч��
	JLabel lab5=new JLabel("�ַ���(R):");
	JComboBox box=new JComboBox();//�ַ��������б�
	JPanel pan=new JPanel();//������Ч�������
	JList list1=new JList(font);//�����б�
	JList list2=new JList(data1);//�����б�
	JList list3=new JList(data2);//�����С�б�
	JTextField field1=new JTextField();//�����
	JTextField field2=new JTextField();//���Ϳ�
	JTextField field3=new JTextField();//�����С��
	JButton but1=new JButton("ȷ��");
	JButton but2=new JButton("ȡ��");
	public myFont(JTextArea text[])
	{
		this.text=text;
		fontText=this.text[0].getFont();//��ü��±���������
		Container con=dialog.getContentPane();//�õ�����Ի������
		con.setLayout(null);
		lab1.setBounds(10,10,60,20);//���ô�С
		lab2.setBounds(200,10,60,20);
		lab3.setBounds(320,10,60,20);
		pan.setBounds(200,210,180,100);
		pan.add(lab4);
        dialog.setResizable(false);
		lab4.setBounds(10,20,160,70);
		lab5.setBounds(200,320,60,20);
		pan.setLayout(null);
		lab4.setBorder(BorderFactory.createLoweredBevelBorder());//����һ�����а���б���Ե�ı߿�
		pan.setBackground(Color.lightGray);
		TitledBorder bord=BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.white),"ʾ��");//�ٴ���һ���б���ı߿򣬱߿�����Ϊ��ɫ
		bord.setTitleColor(Color.blue);//�߿���ɫΪ��ɫ
		pan.setBorder(bord);//���˱߿�ӵ����
		field1.setText(fontText.getFontName());//��������ʼ���Ӽ��±���õ�����
		field1.selectAll();//����������ȫѡ
		list1.setSelectedValue((Object)field1.getText(),false);//���б���ѡ��ָ���Ķ��������ѡ������ڣ����б���Ҫ����������ʾ����Ϊ true������Ϊ false
		field2.setText(data1[fontText.getStyle()]);//�����Ϳ��ʼ���Ӽ��±���õ�����
		list2.setSelectedValue((Object)field2.getText(),false);//���б���ѡ��ָ���Ķ��������ѡ������ڣ����б���Ҫ����������ʾ����Ϊ true������Ϊ false
		field3.setText(""+fontText.getSize());//�������С���ʼ���Ӽ��±���õ������С��һ 
		list3.setSelectedValue((Object)field3.getText(),false);//���б���ѡ��ָ���Ķ��������ѡ������ڣ����б���Ҫ����������ʾ����Ϊ true������Ϊ false
		field1.setBounds(10,40,180,20);//���ô�С
		field2.setBounds(200,40,110,20);
		field3.setBounds(320,40,60,20);
		box.addItem("����");
		box.addItem("����");
		box.setBounds(200,340,180,20);
		JScrollPane scro=new JScrollPane(list1);
		JScrollPane scro1=new JScrollPane(list3);		
		scro.setBounds(10,60,180,140);//���ô�С
		list2.setBounds(200,60,110,140);
		scro1.setBounds(320,60,60,140);
		but1.setBounds(400,40,60,20);
		but2.setBounds(400,74,60,20);
		size=Integer.parseInt(field3.getText());//�������С���ô�С
		zip=Font.PLAIN;//�����Ϳ�������
		myFont=field1.getText();//�������������
		lab4.setFont(new Font(myFont,zip,size));//������ʽ��ǩ������
		con.setBackground(Color.lightGray);//������������ı���ɫ
		con.add(lab1);//��������������
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
		dialog.setSize(480,440);//���ô�С
		dialog.setTitle("����");//��������Ի������
		dialog.show();//��ʾ		
		list1.addMouseListener(this);//������������
		list2.addMouseListener(this);
		list3.addMouseListener(this);
		but1.addActionListener(this);//�����¼�������
		but2.addActionListener(this);
	}	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==but1)
		{
			for(int i=0;i<text.length;i++)
		     text[i].setFont(new Font(myFont,zip,size));//��ȷ���趨�Լ�ѡ������壬���ͣ������С
		}
		dialog.hide();//���ܰ�ȷ��������ʧ�����˺��������ʧ
	}
	public void mouseClicked(MouseEvent e)
	{
		if(e.getSource()==list1)
		{
			int temp=list1.locationToIndex(e.getPoint());//�����������λ���������б������������
			list1.setSelectedIndex(temp);//���б���ѡ��ָ��������
			myFont=list1.getSelectedValue().toString();//��ô��б���ѡ�е�ֵ)Object�ͣ����ٽ���ת����String
			field1.setText(myFont);//������������Լ�ѡ�������
			field1.requestFocus();//��������б����л�ʧȥ����꣬Ҫ�����»�ù��
			field1.selectAll();//�ڿ��ڵ�����ȫѡ
		}
		if(e.getSource()==list2)
		{
			int temp=list2.locationToIndex(e.getPoint());//�����������λ���������б������������
			list2.setSelectedIndex(temp);//���б���ѡ��ָ��������
			String str=list2.getSelectedValue().toString();//��ô��б���ѡ�е�ֵ(Object�ͣ����ٽ���ת����String
			if(str.equals("����"))//��õ������ַ��������������ַ����Ƚϣ��õ�����(int)
			 zip=Font.PLAIN;
			if(str.equals("б��"));
			zip=Font.ITALIC;
			if(str.equals("����"))
			zip=Font.BOLD;
			if(str.equals("��б��"))
			zip=Font.ITALIC+Font.BOLD;
			field2.setText(str);//�����Ϳ�������
			field2.requestFocus();//��������б����л�ʧȥ����꣬Ҫ�����»�ù��
			field2.selectAll();//�ڿ��ڵ�����ȫѡ
		}
		if(e.getSource()==list3)
		{
			int temp=list3.locationToIndex(e.getPoint());//�����������λ���������б������������
			list3.setSelectedIndex(temp);//���б���ѡ��ָ��������
			String str=list3.getSelectedValue().toString();//��ô��б���ѡ�е�ֵ)Object�ͣ����ٽ���ת����String
			size=Integer.parseInt(str);//�������С���ַ���ת��������
			field3.setText(str);//�����ʹ�С�����������С
			field3.selectAll();//�ڿ��ڵ�����ȫѡ
			field3.requestFocus();//��������б����л�ʧȥ����꣬Ҫ�����»�ù��
		}
		lab4.setFont(new Font(myFont,zip,size));//�����ǩ��ʽ����ѡ�������壬���ͣ������С
	}
	public void mouseEntered(MouseEvent e){};//ʵ��������¼��ӿڣ�Ҫ��дȫ������
	public void mouseExited(MouseEvent e){};
	public void mousePressed(MouseEvent e){};
	public void mouseReleased(MouseEvent e){};
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
class distribution  extends JFrame implements ActionListener
{
	JPanel pan=new JPanel();//����壬������С���
	JTextArea text[]=new JTextArea[13];//13����ǩ�����13��ѧԺ����Ϣ
	JButton but1=new JButton("���µ�ѧ����Ϣ�ļ�");//��ť
	JButton but2=new JButton("������һ�������");//��ť
	JMenuBar bar=new JMenuBar();//�˵���
	JMenuItem fontBackgroundColor=new JMenuItem("�������屳����ɫ");//�����˵�
	JMenuItem backgroundColor=new JMenuItem("������屳����ɫ");//�����˵�
	JMenuItem fontColor=new JMenuItem("����������ɫ");//�����˵�
	JMenuItem fontSize=new JMenuItem("���������С");
	JMenu menu=new JMenu("������ɫ");//�˵���
	TitledBorder titleBord[]=new TitledBorder[13];//����߿�
	Border bord=BorderFactory.createEtchedBorder(EtchedBorder.RAISED,Color.blue,Color.red);//ʹ��ָ����ͻ����ʾ��ɫ����Ӱ��ɫ����һ�����С����񻯡����Ч���ı߿� 
	PrintStream print;//��ӡ�����
    FileInputStream input;//������
	JColorChooser colorSelect=new JColorChooser();//JColorChooser �ṩһ�����������û�������ѡ����ɫ�Ŀ���������
    JFileChooser fileChoose=new JFileChooser();//JFileChooser Ϊ�û�ѡ���ļ��ṩ��һ�ּ򵥵Ļ���
	Scanner scan,scan1=new Scanner(System.in);//���� ��
	int i,j;
	Institude college[]=new Institude[13];//13��ѧԺ
	Student stu[]=new Student[26];//26��ѧ��
	boolean isSuccess;//��ǰѧ���Ƿ��ѳɹ����䵽ĳ��ѧԺ���
	boolean isSet;//���ñ�ǣ�false��ʾδ���ã�true��ʾ���ú��ˣ����õ���ĳѧԺ�����ѧ���ձ����
	boolean isFormatCorrect=true;//��ʽ��ǳ�ʼ��Ϊtrue���ж϶�����ļ���ʽ������ȷ
	boolean isReadSuccess=true;//��ȡ�Ƿ�ɹ�����ʼ��Ϊ�ɹ�
    boolean isTheFistDistribute=true;//�Ƿ��һ�η��䣬��ʼ��Ϊ��
	File file=new File("student.txt");//Ҫ��ȡ���ļ�
	int count;//��ȡѧ���ĸ���
	int flag;//����ĸ�ѧ����ʼ���䲻��
	int male=0;//��ͬѧ����
	int female=0;//Ůͬѧ����
	int isMaleBig;//�Ƿ���ͬѧ�����϶࣬1��ʾ�ǣ�0��ʾ��ȣ�-1��ʾŮͬѧ�϶�
	int theSameSexCount;//ͬ�ձ�Ķ���
	public distribution()
	{
		for(i=0;i<13;i++)
		{
			text[i]=new JTextArea();//Ϊ�ı��������ռ�
			text[i].setEditable(false);//���ò��ɱ༭
			text[i].setLineWrap(true);//������һ�к��Զ�����
	        titleBord[i]=BorderFactory.createTitledBorder(bord);//�ٴ���һ���б���ı߿�,�����ʼ��Ϊ��
			text[i].setBorder(titleBord[i]);//���ñ߿�
			college[i]=new Institude();//ΪѧԺ�����ռ�
		}
		for(i=0;i<26;i++)
			stu[i]=new Student();//Ϊѧ�������ռ�	
		pan.setLayout(null);
        for(i=0;i<4;i++)//4��
		{
			for(j=0;j<4;j++)//4��
			{
				if(i*4+j<13)//����13����ǩ��λ��
				{
					text[i*4+j].setBounds(j*200+10,i*150+5,180,130);
				    pan.add(text[i*4+j]);
				}
			}
		}
		initData();//��ʼ������
		readStudent();//���ڶ�ȡ�ļ���ѧ����Ϣ
		if(count==26&&isFormatCorrect&&isReadSuccess)//ѧ����26��ʱ�����и�ʽ��ȷ����ȡ�ɹ�
		{
			statistics();//ͳ�� ѧ����Ů����
			distrubute();//�����޹���Ա
			showDistribute();//��ʾ������
			writeDistribute();//��������Ϣд��һ���ļ�����
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
		setTitle("��ӦѧԺ���ɻ���ٰ��ű�");
		setLocation(200,100);
		setSize(810,640);
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//ʹ�� System exit �����˳�Ӧ�ó��򡣽���Ӧ�ó�����ʹ��
		show();
		isTheFistDistribute=false;//���ܷ���ɹ����ִ�е������Ѿ������һ�Σ����ǵ�һ�η���
		if(!isReadSuccess)
			JOptionPane.showMessageDialog(this,"�Ҳ���student.txt�ļ�����������ѧ����Ϣ�ļ���ť����student�ļ�������ѡ�������ļ�","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
	    if(count<26)
			JOptionPane.showMessageDialog(this,"���ļ��޹�Ա����Ա��Ϣ����26�����޷�Ϊÿ��ѧԺ����2��ѧ������������д���޹�����Ϣ��\n��ѡ����һ�ļ���ѧ����Ϣ��ʹ����Ա�����ڵ���26","���棺",JOptionPane.WARNING_MESSAGE);
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
			text[i].setText("\n\n            ��δ����");
		    titleBord[i].setTitle(institude[i]);
			text[i].setBorder(titleBord[i]);
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
            scan=new Scanner(file);
		}
		catch (Exception e)
		{
			isReadSuccess=false;//��ȡ���ɹ�
			if(!isTheFistDistribute)//������ǵ�һ�η���
			JOptionPane.showMessageDialog(this,"�Ҳ���student.txt�ļ�����������ѧ����Ϣ�ļ���ť����student�ļ�������ѡ�������ļ�","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
			return;
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
				isFormatCorrect=false;//ĳЩѧ����Ϣ��ʽ����ȷ
			    JOptionPane.showMessageDialog(this,"���ܶ�ȡ�����ļ���student�ļ���ʽ����ȷ����ȷ��ʽ��ÿһ�ж���ʾ��\n���� �ַ���  �ַ���  �ַ��� ����1203  ���� ��  �����ѧԺ\n�����´���student.txt","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
		        return ;	
			}
			if(stu[i].classes<=0||(!(stu[i].sex).equals("��")&&!(stu[i].sex).equals("Ů")))//�����������С�ڵ���0�����Ա����к�Ů������ܶ�ȡ�����ļ������ļ���ʽ����ȷ
			{
				isFormatCorrect=false;//ĳЩѧ����Ϣ��ʽ����ȷ
			    JOptionPane.showMessageDialog(this,"���ܶ�ȡ�����ļ������ļ�student�ļ���ʽ����ȷ����ȷ��ʽ��ÿһ�ж���ʾ��\n���� �ַ���  �ַ���  �ַ��� ����1203  ���� ��  �����ѧԺ\n�����´���student.txt","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
			    return;
			}
			i++;
		}
		count=i;//��¼��ȡ������
		if(count<26&&count>0)
		{
            isFormatCorrect=true;//��ʽ��ȷ
			if(!isTheFistDistribute)//������ǵ�һ�η���
			JOptionPane.showMessageDialog(this,"���ļ��޹�Ա����Ա��Ϣ����26�����޷�Ϊÿ��ѧԺ����2��ѧ������������д���޹�����Ϣ��\n��ѡ����һ�ļ���ѧ����Ϣ��ʹ����Ա�����ڵ���26","���棺",JOptionPane.WARNING_MESSAGE);
		}
		if(count<=0)//1����ѧ����Ϣ��û���������Ŀ������Ƕ����ļ���Ҳ�п��ܸ�ʽ����ȷ
		{
			isFormatCorrect=false;//��ʽ����ȷ
		    JOptionPane.showMessageDialog(this,"��ȡ�����ļ�","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
		}
		if(count==26)
		{
			isFormatCorrect=true;//��ʽ��ȷ
			isReadSuccess=true;//��ȡ�ɹ�
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
	public void showDistribute()//��ʾ������
	{
		int i;
		String str;
		while(!isSuccess&&isFormatCorrect)//�����ʽ��ȷ���䲻�ɹ���һֱ���ɵ��ɹ�Ϊֹ������ʾ�������ѷ��䲻�ɹ��ıܵ�������ʾ
		{
			initData();//��ʼ������
			if(count==26&&isFormatCorrect)//ѧ����26��ʱ�����и�ʽ��ȷ
			{
				statistics();//ͳ�� ѧ����Ů����
				distrubute();//�����޹���Ա
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
	public void distrubute()//�����޹���Ա
	{
		int i,j,n;
		int number;//����������Ĵ���
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
			while(!isSuccess)//δ�����ʱ�������������
			{
					n=(int)(13*Math.random());
					number++;//����������Ĵ�����1
					if(number>100000)//100000�λ����ɹ���˵������һ��ѧ����δ��������Ϊ��δ���źõ�ʣ��һ��ѧԺ�������ѧ����ѧԺ���޷�����
					{
						flag=i;//����ĸ�ѧ����ʼ���䲻��
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
	public void actionPerformed(ActionEvent e)//��д�����¼��������ķ�������������ڷ������������������Զ�����
	{
		if(e.getSource()==but1)//���������ѡ���ļ�
		{
			fileChoose.setDialogTitle("���ļ�");//���ô��ļ��Ի������
			if(JFileChooser.APPROVE_OPTION==fileChoose.showOpenDialog(this))//showOpenDialog����һ�� "Open File" �ļ�ѡ�����Ի���,APPROVE_OPTION��ȷ��
			{
				file=fileChoose.getSelectedFile();
				initData();//��ʼ������
				readStudent();//���ڶ�ȡ�ļ���ѧ����Ϣ
				if(count==26&&isFormatCorrect&&isReadSuccess)//ѧ����26��ʱ�����и�ʽ��ȷ
				{
					statistics();//ͳ�� ѧ����Ů����
					distrubute();//�����޹���Ա
					showDistribute();//��ʾ������
					writeDistribute();//��������Ϣд��һ���ļ�����
				}
			}
		}		
		if(e.getSource()==but2)//��������ǽ�����һ�����
		{
				initData();//��ʼ������
				readStudent();//���ڶ�ȡ�ļ���ѧ����Ϣ
				if(count==26&&isFormatCorrect&&isReadSuccess)//ѧ����26��ʱ�����и�ʽ��ȷ
				{
					statistics();//ͳ�� ѧ����Ů����
					distrubute();//�����޹���Ա
					showDistribute();//��ʾ������
					writeDistribute();//��������Ϣд��һ���ļ�����
				}
		}
		if(e.getSource()==backgroundColor)//���������������屳����ɫ
		{
		  Color color=colorSelect.showDialog(this,"ѡ����屳����ɫ",Color.pink);//ʾ����ɫ�ۺ�ɫ
		  if(color!=null)//���ѡ��������һ����ɫ
		  {
			  pan.setBackground(color);
		  }

		}
		if(e.getSource()==fontBackgroundColor)//��������ǽ������屳����ɫ�ı�
		{
		  Color color=colorSelect.showDialog(this,"ѡ�����屳����ɫ",Color.white);//ʾ����ɫ��ɫ
		  if(color!=null)//���ѡ��������һ����ɫ
		  {
			  for(i=0;i<13;i++)
			  {
				  text[i].setBackground(color);
			  }
		  }
		}
		if(e.getSource()==fontColor)//��������ǽ���������ɫ�ı�
		{
		  Color color=colorSelect.showDialog(this,"ѡ��������ɫ",Color.black);//ʾ����ɫΪ��ɫ
		  if(color!=null)//���ѡ��������һ����ɫ
		  {
			  for(i=0;i<13;i++)
			  {
				  text[i].setForeground(color);
				  titleBord[i].setTitleColor(color);//���ñ�����ɫ
			  }
		  }
		}
		if(e.getSource()==fontSize)//��������ǽ��������С�ı�
		{
			 new myFont(text);
		}
	}
}
class distribute1
{
	public static void main(String args[]) throws Exception
	{
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());//����ʵ�ֱ���ϵͳ��ۣ������һ������ LookAndFeel �������,���ñ�������ϵͳ����۵���������������
		new distribution();
	} 
}