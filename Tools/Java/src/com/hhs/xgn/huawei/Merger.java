package com.hhs.xgn.huawei;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Merger extends Module{

	String format;
	int st,ed,skipErr;
	
	PrintWriter pw;
	
	public void merge(int id) throws Exception{
		String path=String.format(format, id);
		Logger.info("Start reading "+id+" from "+path);
		
		BufferedReader br=new BufferedReader(new InputStreamReader(new FileInputStream(path)));
		String ln;
		int lnc=0;
		while((ln=br.readLine())!=null){
			pw.println(ln);
			lnc++;
		}
		
		br.close();
		
		Logger.info("Read "+lnc+" line(s)");
	}
	
	@Override
	public void solve(String[] args) {
		if(args.length<3){
			System.out.println("Merger <format> <st> <ed> [skip error]");
			System.out.println("Format Example: folder/ans%d.txt");
			System.out.println("Skip Error: Not necessary. non-zero value for skip errors, 0 for not.");
			System.exit(1);
		}
		
		try{
			format=args[0];
			st=Integer.parseInt(args[1]);
			ed=Integer.parseInt(args[2]);
			if(args.length>=4){
				skipErr=Integer.parseInt(args[3]);
			}
			
			pw=new PrintWriter("answer_"+st+"_"+ed+".txt");
			for(int i=st;i<=ed;i++){
				try{
					merge(i);
				}catch(Exception e){
					if(skipErr!=0){
						Logger.warning("Merge failed:");
						Logger.error(e);
						Logger.warning("But continue due to skipError!");
					}else{
						throw e;
					}
				}
			}
			
			pw.close();
			
			Logger.info("Success");
		}catch(Exception e){
			Logger.error(e);
			System.exit(2);
		}
	}

}
