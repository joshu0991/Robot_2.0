package com.joshu.dnsdynamic;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;

public class FileReader {

	
	
	public ArrayList<String> read(Path path) throws IOException{
		Charset charset = Charset.forName("US-ASCII");
		ArrayList<String> al = new ArrayList<String>();
		try (BufferedReader reader = Files.newBufferedReader(path, charset)) {
			String s = null;
			while ((s = reader.readLine()) != null) {
				al.add(s);
			}
		}
		return al;
	}
	
}
