package com.joshu.dnsdynamic.ClientGUI.Logic;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientLogics {

	private String hostName;
	private int portNum;
	private Socket sock;
	private PrintWriter out;
	private BufferedReader in;
	
	ClientLogics(String hostName, int portNum){
		this.hostName = hostName;
		this.portNum = portNum;
		
		try {
			sock = new Socket(hostName, portNum);
			out = new PrintWriter(sock.getOutputStream(), true);
			in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
