import os
from PIL import Image
import numpy as np

def fixGrey(img_dir):
    img=Image.open(img_dir)
    if img.mode=='RGB':
        return
    if img.mode=='L':
        img=img.convert('RGB')
        img.save(img_dir)
        return
    a=np.asarray(img)
    if img.mode=='I' and a.max()<65536:
        print('Fixing 16bit greyscale: %s'%(img_dir.split('/')[-1]))
        b=np.empty((img.height,img.width),np.uint8)
        for i in range(img.height):
            for j in range(img.width):
                b[i][j]=a[i][j]//256
        img2=Image.fromarray(b)
        img2=img2.convert('RGB')
        img2.save(img_dir)

def check(img_dir):
    img=Image.open(img_dir)
    if img.mode!='RGB':
        print('WTF?? mode=%s\tname=%s'%(img.mode,img_dir.split('/')[-1]))

def main():
    #fixGrey('D:/MyPython/data/data_train/64-sources/1203.png')
    dirr='D:/MyPython/data/data_test2_blank/'
    for k in ['16','32','64']:
        for i in os.listdir(dirr+k):
            fixGrey('%s%s/%s'%(dirr,k,i))
    

if __name__=='__main__':
    main()
