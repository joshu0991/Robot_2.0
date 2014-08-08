package com.joshu.dnsdynamic;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;

public class MainFrame extends JFrame implements ActionListener{
	
	private static final long serialVersionUID = 1L;
	private final int WIDTH = 900;
	private final int HEIGHT = 600;
	private JMenuBar menuBar;
	private JMenu connectMenu;
	private JMenuItem connectItem;
	
	public MainFrame(){
		super("Robot");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setResizable(false);
		setSize(WIDTH, HEIGHT);
		setLocationRelativeTo(null);
		menuBar = new JMenuBar();
		connectMenu = new JMenu("Connect");
		connectItem = new JMenuItem("New Connection", KeyEvent.VK_N);
		connectItem.addActionListener(this);
		menuBar.add(connectMenu);
		connectMenu.add(connectItem);
		setVisible(true);
		setJMenuBar(menuBar);
		add(new MainPanel());
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getActionCommand().equals("New Connection")) {
		JOptionPane.showInputDialog(this, "Enter the the location");
		}
	}
	
}
