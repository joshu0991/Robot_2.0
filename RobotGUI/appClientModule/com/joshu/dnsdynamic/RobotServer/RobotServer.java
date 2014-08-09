package com.joshu.dnsdynamic.RobotServer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class RobotServer {
	
	private int portNum = 35530;
	private Socket clientSocket;
	private ServerSocket serverSocket;
	private PrintWriter out;
	private BufferedReader in;
	private ArrayList<String> tempList;
	
	RobotServer(){
		 try {
			serverSocket = new ServerSocket(portNum);
			clientSocket = serverSocket.accept();
			out = new PrintWriter(clientSocket.getOutputStream(), true);
			in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	RobotServer(int portNum){
		this.portNum = portNum;
		try {
			serverSocket = new ServerSocket(portNum);
			clientSocket = serverSocket.accept();
			out = new PrintWriter(clientSocket.getOutputStream(), true);
			in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void writeData(String filePath){
		Path p1 = Paths.get("/Temps.txt");
		int counter = 0;
		FileReader r = new FileReader();
		tempList = r.read(p1);
		while(counter < tempList.size()){
			//System.out.println(tempList.get(counter));
			out.println(tempList.get(counter));
			counter++;
		}
		
	}
	//test main
	public static void main(String [] args){
		
		RobotServer s = new RobotServer();
		System.out.println("Made bot");
		s.writeData("/Temps.txt");
	}
	
}
