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
		}
		return outPut;
	}
	
	public String writeData(String filePath){
		String data = null;
		Path p1 = Paths.get(filePath);
		int counter = 0;
		FileReader r = new FileReader();
		tempList = r.read(p1);
		while(counter < tempList.size()){
			//System.out.println(tempList.get(counter));
			data+=tempList.get(counter) + " ";
			System.out.println(data);
			counter++;
		}
		return data;
	}

}
