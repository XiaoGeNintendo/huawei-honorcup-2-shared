package com.hhs.xgn.huawei;

import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Date;

public class Logger {
	
	static PrintWriter dest;
	
	public static void setDest(OutputStream os){
		dest=new PrintWriter(os);
	}
	
	public static void info(String s){
		dest.println("[INFO|"+new Date()+"]"+s);
		dest.flush();
	}
	
	public static void error(Exception e){
		dest.println("[ERROR|"+new Date()+"]Unexpected Error Occurred:");
		e.printStackTrace(dest);
		dest.flush();
	}
	
	public static void warning(String s){
		dest.println("[WARN|"+new Date()+"]"+s);
		dest.flush();
	}
}
