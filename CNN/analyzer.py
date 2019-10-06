from PIL import Image
import os
import numpy as np
import sys
import random
import picHelper
import dataGen
import matplotlib.pyplot as plt
import keras

model_dir='D:/MyPython/huawei-honorcup-2-shared/CNN/saved_models/model_4.h5'
model=None
verb=True
batch_size=32
buffer_size=1024

def init():
    global model
    model = keras.models.load_model(model_dir)
    opt = keras.optimizers.RMSprop(learning_rate=0.0001, decay=1e-6)
    
    model.compile(loss='mean_squared_error',optimizer=opt,metrics=['accuracy'])
    #model.summary()


def isAdjID(id1,id2,con):
    x1,y1=picHelper.toXY(id1)
    x2,y2=picHelper.toXY(id2)
    if not picHelper.isAdj(x1,y1,x2,y2):
        return False
    if con==0:
        if x1==x2+1 and y1==y2:
            return True
        else:
            return False
    elif con==1:
        if x1==x2 and y1==y2+1:
            return True
        else:
            return False
    elif con==2:
        if x1==x2-1 and y1==y2:
            return True
        else:
            return False
    elif con==3:
        if x1==x2 and y1==y2-1:
            return True
        else:
            return False
    else:
        return False


def analyzeAVM(avm_dir,sz):
    con=[]
    uncon=[]
    with open(avm_dir) as f:
        for i in range(sz):
            for j in range(sz):
                tmp=list(map(float,f.readline().split(' ')[:-1]))
                for k in range(4):
                    #print(i,j,k)
                    x=tmp[k]
                    if isAdjID(i,j,k):
                        con.append((i,j,k,x))
                    else:
                        uncon.append((i,j,k,x))
            f.readline()
    plt.hist(list(map(lambda x:x[3],con)),100)
    plt.hist(list(map(lambda x:x[3],uncon)),100)
    plt.show()

def main():
    analyzeAVM('D:/MyPython/huawei-honorcup-2-shared/CNN/matrix/64-sources/1200.txt',64)

if __name__=='__main__':
    main()
        
