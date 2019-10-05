package com.hhs.xgn.huawei;

import java.awt.BorderLayout;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class Checker extends Module{
	
	String pic,ans;
	int sz;

	
	public void solve(String[] args){
		if(args.length<3){
			System.out.println("Usage: checker <source picture> <answer> <size>");
			return;
		}
		
		try{
			pic=args[0];
			ans=args[1];
			sz=Integer.parseInt(args[2]);
			
			if(sz!=16 && sz!=32 && sz!=64){
				Logger.warning("SIZE SHOULD BE 16 OR 32 OR 64");
			}
			
			BufferedImage bi=ImageIO.read(new File(pic));
			
			Logger.info("Read picture ok:"+bi.getWidth()+"*"+bi.getHeight());
			
			if(bi.getWidth()!=512 || bi.getHeight()!=512){
				Logger.warning("Image Size Incorrect");
			}
			
			BufferedImage[][] sub=new BufferedImage[1025][1025];
			
			for(int i=0;i<bi.getWidth();i+=sz){
				for(int j=0;j<bi.getHeight();j+=sz){
					
					sub[i/sz][j/sz]=bi.getSubimage(i,j, sz, sz);
				}
			}
			
			Logger.info("Sub picture captured!");
			
			Scanner s=new Scanner(new FileInputStream(new File(ans)));
			
			ArrayList<Integer> anses=new ArrayList<>();
			
			while(true){
				String ansName=s.next();
				
				anses.clear();
				for(int i=0;i<512*512/sz/sz;i++){
					anses.add(s.nextInt());
				}
				
				if(pic.toLowerCase().endsWith(ansName.toLowerCase())){
					break;
				}
			}
			
			s.close();
			
			Logger.info("Read answer successful:"+anses);
			
			BufferedImage bo=new BufferedImage(bi.getWidth(), bi.getHeight(),BufferedImage.TYPE_INT_ARGB);
			
			int x=0;
			
			Logger.info("Generating");
			for(int i=0;i<bi.getWidth();i+=sz){
				for(int j=0;j<bi.getHeight();j+=sz){
					for(int k=0;k<sz;k++){
						for(int l=0;l<sz;l++){
							
							int now=anses.get(x);
							
							int xind=now/(512/sz);
							int yind=now%(512/sz);
							
//							System.out.println(String.format("Setting RGB at %d %d to index %d %d 's %d %d",i+k, j+l, xind,yind,k,l ));
							
							bo.setRGB(i+l, j+k, sub[yind][xind].getRGB(k, l));
						}
					}
					
					x++;
				}
				
			}
			
			Logger.info("Rotating");
			BufferedImage rot=new BufferedImage(bi.getWidth(), bi.getHeight(),BufferedImage.TYPE_INT_ARGB);
			for(int i=0;i<bi.getWidth();i++){
				for(int j=0;j<bi.getHeight();j++){
					rot.setRGB(i, j, bo.getRGB(j,i));
				}
			}
//			
//			for(int i=0;i<bi.getWidth();i++){
//				for(int j=0;j<bi.getHeight();j++){
//					bo.setRGB(i, j, rot.getRGB(i, bi.getHeight()-j-1));
//				}
//			}
			
			
			Logger.info("Writing files");
			ImageIO.write(rot,"png",new File("ans.png"));
			
			Logger.info("End formatting! See ans.png for detail");
			
			Logger.info("Starting viewing window");
			
			JFrame vw=new JFrame("Viewing Window");
			vw.setLayout(new BorderLayout());
			
			JLabel jl=new JLabel();
			jl.setIcon(new ImageIcon(rot));
			
			vw.add(jl);
			
			vw.setSize(512,512);
			vw.setVisible(true);
			vw.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			
		}catch(Exception e){
			Logger.error(e);
			System.exit(2);
		}
	}
}
