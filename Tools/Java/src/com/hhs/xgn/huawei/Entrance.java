package com.hhs.xgn.huawei;

import java.util.Arrays;

public class Entrance {
	
	public static String[] modName={"checker","autorun"};
	public static Module[] modules={new Checker(),new Autorun()};
	
	public static void main(String[] args) {
		if(args.length<1){
			System.out.println("usage: <module name> <module argument>");
			System.out.println("Possible module name:"+Arrays.toString(modName));
			System.exit(1);
		}
		
		for(int i=0;i<modName.length;i++){
			if(args[0].equalsIgnoreCase(modName[i])){
				System.out.println("Calling tweak class:"+modName[i]);
				modules[i].solve(Arrays.copyOfRange(args, 1,args.length));
				return;
			}
		}
	}
}
