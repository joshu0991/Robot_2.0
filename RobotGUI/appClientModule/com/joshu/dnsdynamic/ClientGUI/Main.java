package com.joshu.dnsdynamic.ClientGUI;

public class Main {

	public static void main(String[] args) {
		//invoke later with an annon class
		  javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run(){
				new MainFrame();
			}
		});
	}
}
