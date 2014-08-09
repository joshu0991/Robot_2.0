package com.joshu.dnsdynamic;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

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
////////////////////////////////////////////////////////////////////////////	
	
	public MainPanel()
	{
		setLayout(new BorderLayout());
		createComponents();
		addComponentsWest();
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
		
		//fit buttons and on the west section
		westPan = new JPanel();
		eastPan = new JPanel();
		northPan = new JPanel();
		southPan = new JPanel();
		centerPan = new JPanel();
		
		westPan.setLayout(new GridLayout(6, 1));
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
