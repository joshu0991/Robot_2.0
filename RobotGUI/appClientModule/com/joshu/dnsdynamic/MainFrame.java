package com.joshu.dnsdynamic;

import javax.swing.JFrame;

public class MainFrame extends JFrame{
	
	private static final long serialVersionUID = 1L;
	private final int WIDTH = 900;
	private final int HEIGHT = 600;
	
	public MainFrame(){
		super("Robot");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setResizable(false);
		setSize(WIDTH, HEIGHT);
		setLocationRelativeTo(null);
		setVisible(true);
		add(new MainPanel());
	}
	
}
