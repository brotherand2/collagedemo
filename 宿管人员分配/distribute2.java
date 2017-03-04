import java.io.*;
import java.util.Scanner;
import java.util.Random;
import java.util.Date;
import java.text.SimpleDateFormat;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
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
class distribution  extends JFrame implements ActionListener
{
	JPanel pan=new JPanel();//����壬������С���
	JTextArea text[]=new JTextArea[13];//13����ǩ�����13��ѧԺ����Ϣ
	JButton but1=new JButton("���µ�ѧ����Ϣ�ļ�");//��ť
	JButton but2=new JButton("������һ�������");//��ť
	JMenuBar bar=new JMenuBar();//�˵���
	JMenuItem lineColor=new JMenuItem("���ñ߿���ɫ");//�����˵�
	JMenuItem backgroundColor=new JMenuItem("���ñ�����ɫ");//�����˵�
	JMenuItem fontColor=new JMenuItem("����������ɫ");//�����˵�
	JMenu menu=new JMenu("������ɫ");//�˵���
	PrintStream print;//��ӡ�����
    FileInputStream input;//������
	Color linecolor=Color.green;//�߿���ɫ
	Color fontcolor=Color.black;//������ɫ
	Color backgroundcolor=Color.pink;//������ɫ
	Scanner scan,scan1=new Scanner(System.in);//���� ��
	int i,j;
	Institude college[]=new Institude[13];//13��ѧԺ
	Student stu[]=new Student[26];//26��ѧ��
	boolean isSuccess;//��ǰѧ���Ƿ��ѳɹ����䵽ĳ��ѧԺ���
	boolean isSet;//���ñ�ǣ�false��ʾδ���ã�true��ʾ���ú��ˣ����õ���ĳѧԺ�����ѧ���ձ����
	boolean isFormatCorrect=true;//��ʽ��ǳ�ʼ��Ϊtrue���ж϶�����ļ���ʽ������ȷ
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
			text[i].setBorder(BorderFactory.createLineBorder(linecolor));//����һ�����а���б���Ե�ı߿�
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
		if(count==26&&isFormatCorrect)//ѧ����26��ʱ�����и�ʽ��ȷ
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
			text[i].setText("              "+institude[i]+"\n\n            ��δ����");
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
			JOptionPane.showMessageDialog(this,"�Ҳ���student.txt�ļ�����������ѧ����Ϣ�ļ���ť����student�ļ�������ѡ�������ļ�","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
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
				isFormatCorrect=false;//��ʽ����ȷ
			    JOptionPane.showMessageDialog(this,"student�ļ���ʽ����ȷ����ȷ��ʽ��ÿһ�ж���ʾ��\n���� �ַ���  �ַ���  �ַ��� ����1203  ���� ��  �����ѧԺ\n�����´���student.txt","��ʾ��",JOptionPane.INFORMATION_MESSAGE);
			}
			i++;
		}
		count=i;//��¼��ȡ������
		if(count<26)
		{
			System.out.printf("\n");
			JOptionPane.showMessageDialog(this,"�޹�Ա����Ա��Ϣ����26�����޷�Ϊÿ��ѧԺ����2��ѧ������������д���޹�����Ϣ��ʹ����Ա�����ڵ���26","���棺",JOptionPane.WARNING_MESSAGE);
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
			JOptionPane.showMessageDialog(this,"��"+(flag+1)+"��ѧ��"+stu[flag].name+","+stu[flag].sex+","+stu[flag].institude+"�޷����䵽ʣ�µ�ѧԺ","��ʾ������ʧ�ܣ��������������һ����䰴ť�����·���",JOptionPane.INFORMATION_MESSAGE);
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
						System.out.printf("����ʧ��,�����·���\n");
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
		if(e.getSource()==but2)//��������ǽ�����һ�����
		{
				initData();//��ʼ������
				readStudent();//���ڶ�ȡ�ļ���ѧ����Ϣ
				if(count==26&&isFormatCorrect)//ѧ����26��ʱ�����и�ʽ��ȷ
				{
					statistics();//ͳ�� ѧ����Ů����
					distrubute();//�����޹���Ա
					showDistribute();//��ʾ������
					writeDistribute();//��������Ϣд��һ���ļ�����
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