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
pcon=0.8
puncon=0.2
size=32

def init():
    global model
    model = keras.models.load_model(model_dir)
    opt = keras.optimizers.RMSprop(learning_rate=0.0001, decay=1e-6)
    
    model.compile(loss='mean_squared_error',optimizer=opt,metrics=['accuracy'])
    #model.summary()


def isAdjID(id1,id2,con,sz=None):
    if sz==None:
        sz=size
    x1,y1=picHelper.toXY(id1,sz)
    x2,y2=picHelper.toXY(id2,sz)
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
        for i in range((512//sz)**2):
            for j in range((512//sz)**2):
                tmp=list(map(float,f.readline().split(' ')[:-1]))
                for k in range(4):
                    #print(i,j,k)
                    x=tmp[k]
                    if isAdjID(i,j,k,sz):
                        con.append((i,j,k,x))
                    else:
                        uncon.append((i,j,k,x))
            f.readline()
    plt.subplot(221)
    plt.hist(list(map(lambda x:x[3],con)),100)
    plt.title('Connected')
    
    plt.subplot(222)
    plt.hist(list(map(lambda x:x[3],uncon)),100)
    plt.title('Unconnected')

    rtow=[]
    wtor=[]
    for i in con:
        if i[3]<pcon:
            rtow.append(i)
    for i in uncon:
        if i[3]>puncon:
            wtor.append(i)
            
    plt.subplot(223)
    plt.hist(list(map(lambda x:x[3],rtow)),100)
    plt.title('Right to Wrong')

    plt.subplot(224)
    plt.hist(list(map(lambda x:x[3],wtor)),100)
    plt.title('Wrong to Right')

    plt.tight_layout()
    plt.show()

def main():
    analyzeAVM('D:/MyPython/huawei-honorcup-2-shared/CNN/matrix/32-sources/0600.txt',32)

if __name__=='__main__':
    main()
        
