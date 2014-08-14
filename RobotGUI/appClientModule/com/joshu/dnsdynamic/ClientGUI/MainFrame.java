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
	
	private static final long serialVersionUID = 1L;
	private final int WIDTH = 900;
	private final int HEIGHT = 600;
	private JMenuBar menuBar;
	private JMenu connectMenu;
	private JMenuItem connectItem;
	private ClientLogics temp;
	private String [] addr;
	private String temperature;
	private MainPanel mp;
	private JMenuItem closeComItem;
	private Thread dataThread;
	
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
	}
	
	public void buildAddr(String url){
		addr = new String[2];
		int colenLoc = url.indexOf(':');
		String port = url.substring(colenLoc + 1);
		String ipAddr = url.substring(0, colenLoc);
		addr[0] = ipAddr ;
		addr[1] = port;
	}
	
	public String getTemperature(){
		return temperature;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getActionCommand().equals("New Connection")) {
		String url = JOptionPane.showInputDialog(this, "Enter the the location", "example.location.com:9454");
		buildAddr(url);
		
		mp.forward.setEnabled(true);
		mp.back.setEnabled(true);
		mp.left.setEnabled(true);
		mp.right.setEnabled(true);
		mp.breaks.setEnabled(true);
		mp.high.setEnabled(true);
		mp.med.setEnabled(true);
		mp.low.setEnabled(true);
		mp.stop.setEnabled(true);
		
		temp = new ClientLogics(addr[0], addr[1], "Temp");
		dataThread = new Thread(temp);
		dataThread.start();
		}
	}

}
