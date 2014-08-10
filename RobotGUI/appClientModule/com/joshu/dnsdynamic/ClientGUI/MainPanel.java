package com.joshu.dnsdynamic.ClientGUI;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

import com.joshu.dnsdynamic.ClientGUI.Logic.*;

public class MainPanel extends JPanel implements ActionListener{

	private static final long serialVersionUID = 1L;
	private JButton forward;
	private JButton back;
	private JButton left;
	private JButton right;
	private JButton breaks;
////////////////////////////////////////////////////////////////////////////
	private JRadioButton high;
	private JRadioButton med;
	private JRadioButton low;
	private JRadioButton stop;
////////////////////////////////////////////////////////////////////////////
	private JPanel westPan;
	private JPanel eastPan;
	private JPanel centerPan;
	private JPanel northPan;
	private JPanel southPan;
////////////////////////////////////////////////////////////////////////////
	private ButtonGroup group;
	private JPanel radioPanel;
	private JLabel speed;
	private ImageIcon upIm;
	private ImageIcon downIm;
	private ImageIcon leftIm;
	private ImageIcon rightIm;
	private JLabel temp;
	private JLabel date;
	private JTextField tempField;
	private JTextField dateField;
////////////////////////////////////////////////////////////////////////////	
	
	public MainPanel()
	{
		setLayout(new BorderLayout());
		createComponents();
		addComponentsWest();
		addComponentsSouth();
		add(southPan, BorderLayout.SOUTH);
		add(westPan, BorderLayout.WEST);
	}

////////////////////////////////////////////////////////////////////////////	
	
	private void createComponents(){
		
		//Button images
		upIm = loadImages("Img/up.jpg");//loadImages("Img/up.jpg");
		downIm = loadImages("Img/down.jpg");
		rightIm = loadImages("Img/right.jpg");
		leftIm = loadImages("Img/left.jpg");
		
		//directional buttons
		forward = new JButton("Forward", upIm);
		forward.setIcon(upIm);
		forward.setMnemonic(KeyEvent.VK_W);
		forward.addActionListener(this);
		
		back = new JButton("Back", downIm);
		back.addActionListener(this);
		back.setMnemonic(KeyEvent.VK_S);
		
		left = new JButton("Left", leftIm);
		left.addActionListener(this);
		left.setMnemonic(KeyEvent.VK_A);
		
		right = new JButton("Right", rightIm);
		right.addActionListener(this);
		right.setMnemonic(KeyEvent.VK_D);
		
		breaks = new JButton("Break");
		breaks.setMnemonic(KeyEvent.VK_E);
		breaks.addActionListener(this);
		
		//radio speed buttons
		speed = new JLabel("Speed");
		high  = new JRadioButton("High");
		high.addActionListener(this);
		med  = new JRadioButton("Med");
		med.addActionListener(this);
		low  = new JRadioButton("Low");
		low.addActionListener(this);
		stop = new JRadioButton("Stop");
		stop.addActionListener(this);
		group = new ButtonGroup();//group the radio buttons
		group.add(high);
		group.add(med);
		group.add(low);
		group.add(stop);
		radioPanel = new JPanel(new GridLayout(0, 1));//create a panel for radio buttons
		radioPanel.add(speed);
		radioPanel.add(high);
		radioPanel.add(med);
		radioPanel.add(low);
		radioPanel.add(stop);	
		
		//Text fields
		temp = new JLabel("Temperature:");
		date = new JLabel("Date Updated:");
		tempField = new JTextField();
		dateField = new JTextField();
		
		//fit buttons and on the west section
		westPan = new JPanel();
		eastPan = new JPanel();
		northPan = new JPanel();
		southPan = new JPanel();
		centerPan = new JPanel();
		
		westPan.setLayout(new GridLayout(6, 1));
		//southPan.setLayout(new GridLayout(2, 6));
	}

////////////////////////////////////////////////////////////////////////////	
	
	//add components to the westPanel
	private void addComponentsWest(){
		westPan.add(forward);
		westPan.add(back);
		westPan.add(right);
		westPan.add(left);
		westPan.add(breaks);
		westPan.add(radioPanel);
	}
	
///////////////////////////////////////////////////////////////////////////
	
	private void addComponentsSouth(){
		Path path = Paths.get("DataFile.txt");
		String data = readFile(path);
		//System.out.println(data);
		tempField.setText(data);//index where temps will be
		dateField.setText(data);//where date will be
		tempField.setSize(20, 20);
		southPan.add(temp);
		southPan.add(tempField);
		southPan.add(date);
		southPan.add(dateField);
	}
////////////////////////////////////////////////////////////////////////////
	
	private String readFile(Path path){
		Charset charset = Charset.forName("US-ASCII");
		String al = "";
		try (BufferedReader reader = Files.newBufferedReader(path, charset)) {
			String s = null;
			while ((s = reader.readLine()) != null) {
				al = s;
			}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		return al;
	}
	
////////////////////////////////////////////////////////////////////////////	
	
	//this doesn't work yet
	private ImageIcon loadImages(String path) {
		java.net.URL imgURL = MainPanel.class.getResource(path);
		if (imgURL != null) {
	        return new ImageIcon(imgURL);
		}else{
			System.err.println("Cannot open " + path);
			return null;
		}
	}
	
//////////////////////////////////////////////////////////////////////////////	
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		System.out.println(e.getActionCommand());
		
	}
	
}
//to do
//make gui update periodically