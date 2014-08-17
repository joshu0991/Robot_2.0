package com.joshu.dnsdynamic.ClientGUI;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;

import com.joshu.dnsdynamic.ClientGUI.Logic.*;

public class MainFrame extends JFrame implements ActionListener{
	
	private boolean isConnected;
	private static final long serialVersionUID = 1L;
	private final int WIDTH = 900;
	private final int HEIGHT = 600;
	private JMenuBar menuBar;
	private JMenu connectMenu;
	private JMenuItem connectItem;
	private String temperature; 
	private MainPanel mp;
	private JMenuItem closeComItem;
	
	public MainFrame(){
		super("Robot");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setResizable(false);
		setSize(WIDTH, HEIGHT);
		setLocationRelativeTo(null);
		menuBar = new JMenuBar();
		connectMenu = new JMenu("Connect");
		connectItem = new JMenuItem("New Connection", KeyEvent.VK_N);
		closeComItem = new JMenuItem("Close", KeyEvent.VK_C);
		connectItem.addActionListener(this);
		closeComItem.addActionListener(this);
		menuBar.add(connectMenu);
		connectMenu.add(connectItem);
		connectMenu.add(closeComItem);
		setVisible(true);
		setJMenuBar(menuBar);
		mp = new MainPanel();
		add(mp);
		isConnected = false;
	}
	
	public String getTemperature(){
		return temperature;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getActionCommand().equals("New Connection") && isConnected == false) {
		mp.connect();
		}
	}

}
