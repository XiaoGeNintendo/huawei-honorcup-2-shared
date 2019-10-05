package com.hhs.xgn.huawei;

import java.io.FileOutputStream;
import java.util.Arrays;

public class Entrance {
	
	public static String[] modName={"checker","autorun","merger"};
	public static Module[] modules={new Checker(),new Autorun(),new Merger()};
	
	public static void main(String[] args) {
		if(args.length<2){
			System.out.println("usage: <log file path> <module name> <module argument>");
			System.out.println("Possible module name:"+Arrays.toString(modName));
			System.out.println("Possible log file path: stdout/stderr/<file path>");
			System.exit(1);
		}
		
		//proceed log
		try{
			if(args[0].equalsIgnoreCase("stdout")){
				Logger.setDest(System.out);
			}else{
				if(args[0].equalsIgnoreCase("stderr")){
					Logger.setDest(System.err);
				}else{
					Logger.setDest(new FileOutputStream(args[0]));
				}
			}
		}catch(Exception e){
			System.out.println("Not being able to set destination of logger");
			e.printStackTrace();
			System.exit(-1);
		}
		
		for(int i=0;i<modName.length;i++){
			if(args[1].equalsIgnoreCase(modName[i])){
				System.out.println("Calling tweak class:"+modName[i]);
				modules[i].solve(Arrays.copyOfRange(args, 2,args.length));
				return;
			}
		}
	}
}
