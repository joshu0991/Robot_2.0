package com.joshu.dnsdynamic.RobotServer;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class InputProtocol {
	
	private ArrayList<String> tempList;
	
	public String processInput(String input){
		String outPut = null;
		if(input == "Close"){
			outPut = "Close";
		}else if(input == null){
			outPut = "Hello";
		}else if(input.equals("Temp")){
			outPut = writeData("/Temps.txt");
		}else if(input.equals("forward")){
			//write forward plus speed to the text file for reading from the daemon
		}else if(input.equals("distance")){
			//send ping
		}else if(input.equals("back")){
			//write back to file
		}else if(input.equals("left")){
			//write left to file
		}else if(input.equals("right")){
			//write right to file
		}
		return outPut;
	}
	
	public String writeData(String filePath){
		String data = "";
		Path p1 = Paths.get(filePath);
		int counter = 0;
		FileReader r = new FileReader();
		tempList = r.read(p1);
		while(counter < tempList.size()){
			data += tempList.get(counter) + " ";
			counter++;
		}
		return data;
	}

}
