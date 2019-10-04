import picHelper as pic
import keras
import random
import os
import numpy as np
from PIL import Image

size=64
width=32
data_dir='D:/MyPython/huawei-honorcup-2-shared/CNN/data/'

def getBlockFromImg(img,x,y):
    box=(size*x,size*y,size*(x+1),size*(y+1))
    return img.crop(box)

def imgToData(img):
    if img.mode!='RGB':
        img=img.convert('RGB')
    ret=np.empty((1,img.height,img.width,3))
    for i in range(img.height):
        for j in range(img.width):
            tmp=img.getpixel((j,i))
            ret[0][i][j][0]=tmp[0]/255
            ret[0][i][j][1]=tmp[1]/255
            ret[0][i][j][2]=tmp[2]/255
    return ret

#con
#0  2 1
#
#1  2
#   1
#
#2  1 2
#
#3  1
#   2
def getEdge(img,x1,y1,x2,y2,con,sz=None):
    if sz==None:
        sz=size
    if con>1:
        x1,x2=x2,x1
        y1,y2=y2,y1
        con-=2
    if con==0:
        ret=Image.new('RGB',(sz*2,sz))
        ret.paste(getBlockFromImg(img,x1,y1),(sz,0))
        ret.paste(getBlockFromImg(img,x2,y2),(0,0))
        ret=ret.rotate(90,expand=True)
        return ret.crop((0,sz-width//2,sz,sz+width//2))
    elif con==1:
        ret=Image.new('RGB',(sz,sz*2))
        ret.paste(getBlockFromImg(img,x1,y1),(0,sz))
        ret.paste(getBlockFromImg(img,x2,y2),(0,0))
        return ret.crop((0,sz-width//2,sz,sz+width//2))
        

def getTrainData(cnt):
    x_train=np.empty((cnt,width,size,3))
    y_train=np.empty((cnt,1))
    ans=[]
    with open(os.path.join(data_dir,'ans.txt')) as f:
        for i in range(cnt):
            ans.append(int(f.readline()[:-1]))
    for i in range(cnt):
        y_train[i]=ans[i]
        with open(os.path.join(data_dir,str(i)+'.txt')) as f:
            for j in range(width):
                tmp=f.readline().split(' ')
                for k in range(size):
                    x_train[i][j][k][0]=int(tmp[k*3])/256
                    x_train[i][j][k][1]=int(tmp[k*3+1])/256
                    x_train[i][j][k][2]=int(tmp[k*3+2])/256
    return (x_train,y_train)

def main():
    getEdge('D:/MyPython/data/data_train/64-sources/1200.png',6,1,5,1,3).show()

if __name__=='__main__':
    main()
