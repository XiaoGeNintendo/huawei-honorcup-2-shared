import os
import sys
import numpy as np
import random
from PIL import Image

data_dir='D:/MyPython/data/data_train/'
size=64
width=32

def getImage(k,src=False):
    full_dir=os.path.join(data_dir,str(size)+['','-sources'][src],str(k)+'.png')
    print('Opening %s'%full_dir)
    img=Image.open(full_dir)
    return img

def toXY(ID):
    return (ID%(512/size),ID/(512/size))

def toID(x,y):
    return y*(512/size)+x

def isAdj(x1,y1,x2,y2):
    if x1==x2 and abs(y1-y2)<=1:
        return True
    if y1==y2 and abs(x1-x2)<=1:
        return True
    return False

def getBlockByID(k,src,ID):
    xy=toXY(ID)
    return getBlock(k,src,xy[0],xy[1])

def getBlock(k,src,x,y):
    box=(size*x,size*y,size*(x+1),size*(y+1))
    return getImage(k,src).crop(box)

def getRandAdj(k):
    if random.randint(0,1)==0:
        x=random.randint(0,512/size-1)
        y=random.randint(0,512/size-2)
        box=(x*size,y*size,(x+1)*size,(y+2)*size)
        return getImage(k,True).crop(box).crop((0,size-width//2,size,size+width//2))
    else:
        x=random.randint(0,512/size-2)
        y=random.randint(0,512/size-1)
        box=(x*size,y*size,(x+2)*size,(y+1)*size)
        return getImage(k,True).crop(box).rotate(90).crop((0,size-width//2,size,size+width//2))

def getRandUnadj(k):
    x1=0
    y1=0
    x2=0
    y2=0
    while isAdj(x1,y1,x2,y2):
        x1=random.randint(0,512/size-1)
        y1=random.randint(0,512/size-1)
        x2=random.randint(0,512/size-1)
        y2=random.randint(0,512/size-1)
    ret=Image.new('RGB',(size,width))
    ret.paste(getBlock(k,True,x1,y1).crop((0,size-width//2,size,size)),(0,0))
    ret.paste(getBlock(k,True,x2,y2).crop((0,0,size,width//2)),(0,width//2))
    return ret

def main():
    getRandAdj(1200).show()

#data_dir
if __name__=='__main__':
    print(sys.argv)
    if len(sys.argv)>=2:
        data_dir=str.join('/',sys.argv[1].split('/')[:-2])
        size=int(sys.argv[1].split('/')[-2].replace('-sources',''))
        num=int(sys.argv[1].split('/')[-1][:-4])
        if sys.argv[1].split('/')[-2].count('-sources')>0:
            source=True
        else:
            source=False
        print(data_dir,size,num,source)
    else:
        main()
