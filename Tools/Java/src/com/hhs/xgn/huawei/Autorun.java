package com.hhs.xgn.huawei;

import java.io.*;

public class Autorun extends Module {
	String dir;
	int st;
	int ed;
	
	public void copyFile(String from,String to) throws Exception{
		System.out.println("[INFO]Start copying from "+from+" to "+to);
		long st=System.currentTimeMillis();
		
		FileInputStream fis=new FileInputStream(new File(from));
		FileOutputStream fos=new FileOutputStream(new File(to));
		byte[] b=new byte[1024*1024];
		int len;
		while((len=fis.read(b))!=-1){
			fos.write(b,0,len);
		}
		
		fos.close();
		fis.close();
		
		long ed=System.currentTimeMillis();
		System.out.println("[INFO]Copy costs:"+(ed-st)+"ms");
	}
	
	int run(String exe,String para,String para2) throws Exception{
		System.out.println("[INFO]Start executing:"+exe+" "+para+" "+para2);
		
		ProcessBuilder pb=new ProcessBuilder(exe,para,para2);
		pb.directory(new File(dir));
		Process p=pb.start();
		
		long st=System.currentTimeMillis();
		p.waitFor();
		long ed=System.currentTimeMillis();
		
		System.out.println("[INFO]Execute success!");
		System.out.println("[INFO]Time cost for this task is:"+(ed-st)+"ms");
		
		return p.exitValue();
	}
	
	void stressRun(String exe,String para,String para2) throws Exception{
		
		int ret=run(exe,para,para2);
		
		if(ret!=0){
			throw new Exception("Stress Failed:return value is not 0!?!?("+ret+")");
		}
	}
	
	public boolean runLayer(int lid,int pid) throws Exception{
		stressRun(dir+"/layer"+lid+".exe","","");
		int ret=run(dir+"/checkadj.exe","value"+lid+".out",pid+".png");
		if(ret==0){
			return true;
		}
		return false;
	}
	
	void runFor(int id) throws Exception{
		System.out.println("\n[INFO] Start auto run for "+id);
		stressRun(dir+"/layer0.exe",id+".txt","");
		
		for(int i=1;i<=9;i++){
			boolean ret=runLayer(i,id);
			if(ret){
				System.out.println("[INFO]Layer "+i+" returned 0. Break as intended");
				
				copyFile(dir+"/answer.out","answer"+id+".txt");
				return;
			}
		}
		
		stressRun(dir+"/ExtraLayer.exe",id+".png","");
		
		copyFile(dir+"/answer.out","answer"+id+".txt");
		
		System.out.println("[WARN]Extra Layer was triggered on "+id);
	}
	
	
	public void solve(String[] args){
		if(args.length!=3){
			System.out.println("aar <workspace> <start id> <end id>");
			System.exit(1);
		}
		
		try{
			dir=args[0];
			st=Integer.parseInt(args[1]);
			ed=Integer.parseInt(args[2]);
			
			for(int i=st;i<=ed;i++){
				runFor(i);
			}
		}catch(Exception e){
			System.out.println("[ERROR] Autorun failed! See me:");
			e.printStackTrace();
			System.exit(2);
		}
	}
}
