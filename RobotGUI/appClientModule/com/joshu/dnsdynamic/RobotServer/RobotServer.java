package com.joshu.dnsdynamic.RobotServer;

import java.io.IOException;
import java.net.ServerSocket;

public class RobotServer {

	private int portNum = 35530;
	private ServerSocket serverSocket;
	private Thread handle;
	{
		try {
			serverSocket = new ServerSocket(portNum);
			while(true){
				handle = new Thread(new MultiConnectHandler(serverSocket.accept()));
				handle.start();
			}
	
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	RobotServer() {
		System.out.println("Server started");
	}

	RobotServer(int portNum) {
		this.portNum = portNum;
	}

	  //test main 
	public static void main(String [] args){ 
	new RobotServer(); 
	} 
}
