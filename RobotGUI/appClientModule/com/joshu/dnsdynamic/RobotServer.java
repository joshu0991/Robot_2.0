package com.joshu.dnsdynamic;

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
	
	RobotServer() throws IOException{
		 serverSocket = new ServerSocket(portNum);
		 writeData("/Temps.txt");
		 clientSocket = serverSocket.accept();
		 out = new PrintWriter(clientSocket.getOutputStream(), true);
		 in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 
	}
	
	RobotServer(int portNum) throws IOException{
		this.portNum = portNum;
		serverSocket = new ServerSocket(portNum);
		clientSocket = serverSocket.accept();
		out = new PrintWriter(clientSocket.getOutputStream(), true);
		in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
	}
	public void writeData(String filePath) throws IOException{
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
	public static void main(String [] args){
		
		try {
			RobotServer s = new RobotServer();
			System.out.println("Made bot");
			s.writeData("/Temps.txt");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
