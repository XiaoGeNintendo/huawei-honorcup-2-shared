import picHelper as pic
import keras
import random
import os
import numpy as np

size=64
width=32
data_dir='D:/MyPython/huawei-honorcup-2-shared/CNN/data/'

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
    getTrainData(10)


if __name__=='__main__':
    main()
