package com.joshu.dnsdynamic.RobotServer;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class FileReader {

	public ArrayList<String> read(Path path){
		Charset charset = Charset.forName("US-ASCII");
		ArrayList<String> al = new ArrayList<String>();
		try (BufferedReader reader = Files.newBufferedReader(path, charset)) {
			String s = null;
			while ((s = reader.readLine()) != null) {
				al.add(s);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return al;
	}
	
}
