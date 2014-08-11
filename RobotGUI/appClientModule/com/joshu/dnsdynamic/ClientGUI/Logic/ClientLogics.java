package com.joshu.dnsdynamic.ClientGUI.Logic;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import com.joshu.dnsdynamic.ClientGUI.*;

public class ClientLogics implements Runnable{
	
	private String hostName;
	private int portNum;
	private Socket sock;
	private PrintWriter out;
	private BufferedReader in;
	private String dataIn;
	private String request;
	private FileWriter dataFile;
	
	public ClientLogics(String hostName, String port, String request){
		this.hostName = hostName;
		this.portNum = Integer.parseInt(port);
		this.request = request;
		System.out.println("Host name " + hostName);
		System.out.println("Port " + port);
		try {
			sock = new Socket(hostName, portNum);
			out = new PrintWriter(sock.getOutputStream(), true);
			in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			//dataFile = new PrintWriter(new BufferedWriter(new FileWriter("DataFile.txt", false)));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public void mainLoop(String request){
		try {
			int counter = 0;
			while((dataIn = in.readLine()) != null){
				dataFile = new FileWriter("DataFile.txt", false);
				System.out.println("Data In " + dataIn);
				
				dataFile.write(dataIn + counter);// write the data to a file so gui can access
				counter++;
				
				dataFile.close();
				if(dataIn == "Close"){
					break;
				}
                 System.out.println("Client: " + request);
                 out.println(request);
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	//return the data returned by the server
	public String getDataIn(){
		return dataIn;
	}
	/*
	//test main
	public static void main(String [] args) throws InterruptedException{
		//spawn a thread with a mainLoop for each thing required from the server 
		Thread l = new Thread(new ClientLogics("localhost", "35530", "Temp"));
		l.start();
		Thread.sleep(1000);
	}
	*/

	@Override
	public void run() {
		// TODO Auto-generated method stub
		mainLoop(request);//start a new thread based on wht the user instantiates this obj with
	}
}
