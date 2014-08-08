package com.joshu.dnsdynamic;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
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
	private JRadioButton high;
	private JRadioButton med;
	private JRadioButton low;
	private JRadioButton stop;
	private JPanel westPan;
	private ButtonGroup group;
	private JPanel radioPanel;
	private JLabel speed;
	
	public MainPanel()
	{
		setLayout(new BorderLayout());
		createComponents();
		addComponentsWest();
		add(westPan, BorderLayout.WEST);
	}

	private void createComponents(){
		
		//directional buttons
		forward = new JButton("Forward");
		forward.addActionListener(this);
		back = new JButton("Back");
		back.addActionListener(this);
		left = new JButton("Left");
		left.addActionListener(this);
		right = new JButton("Right");
		right.addActionListener(this);
		breaks = new JButton("Break");
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
		westPan.setLayout(new GridLayout(6, 1));
	}
	
	//add components to the westPanel
	private void addComponentsWest(){
		westPan.add(forward);
		westPan.add(back);
		westPan.add(right);
		westPan.add(left);
		westPan.add(breaks);
		westPan.add(radioPanel);
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
	}
	
}
