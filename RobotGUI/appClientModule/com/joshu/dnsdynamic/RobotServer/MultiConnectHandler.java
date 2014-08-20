package com.joshu.dnsdynamic.RobotServer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class MultiConnectHandler implements Runnable {

	private Socket socket;
	private PrintWriter out;
	private BufferedReader in;
	private InputProtocol iProt;
	private String dataOut, dataIn;
	
	MultiConnectHandler(Socket socket){
		this.socket = socket;
	}
	
	@Override
	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(socket.getOutputStream(), true);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		initComm();
		mainLoop();
		
	}
	
	public void mainLoop(){
		try {
			while((dataIn = in.readLine()) != null){
				dataOut = iProt.processInput(dataIn);
				out.println(dataOut);
				if(dataOut == "Close"){
					out.write("Closing");
					break;
				}
			}
			//call new instance?
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	
	public void initComm() {
		iProt = new InputProtocol();
		dataOut = iProt.processInput(null);
		out.println(dataOut);
	}

}
