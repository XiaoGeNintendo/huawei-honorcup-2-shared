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

def readAVM(avm_dir,sz,new=None):
    ret=[]
    if new==None:
        if avm_dir.endswith('.avm'):
            new=True
        else:
            new=False
    if new:
        ret2=np.zeros(((512//sz)**2,(512//sz)**2,4))
        print('Reading file %s , format=new'%avm_dir)
        with open(avm_dir) as f:
            while True:
                s=f.readline()
                if s=='':
                    break
                tmp=s.split(' ')
                ret2[int(tmp[0])][int(tmp[1])][int(tmp[2])]=float(tmp[3])
        
        for i in range((512//sz)**2):
            for j in range((512//sz)**2):
                for k in range(4):
                    ret.append((i,j,k,ret2[i][j][k]))
    
    else:
        print('Reading file %s , format=old'%avm_dir)
        with open(avm_dir) as f:
            for i in range((512//sz)**2):
                for j in range((512//sz)**2):
                    tmp=list(map(float,f.readline().split(' ')[:-1]))
                    for k in range(4):
                        ret.append((i,j,k,tmp[k]))
                f.readline()
    return ret

def analyzeAVM(avm_dir,sz):
    con=[]
    uncon=[]
    ret=readAVM(avm_dir,sz)
    for i in ret:
        if isAdjID(i[0],i[1],i[2],sz):
            con.append(i)
        else:
            uncon.append(i)
    
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
    plt.xlabel('Accuracy: %.3f%%'%((1-len(rtow)/len(con))*100))

    plt.subplot(224)
    plt.hist(list(map(lambda x:x[3],wtor)),100)
    plt.title('Wrong to Right')
    plt.xlabel('Accuracy: %.3f%%'%((1-len(wtor)/len(uncon))*100))

    plt.suptitle('Total: %.3f%%'%(((1-len(rtow)/len(con))*(sz-1)+(1-len(wtor)/len(uncon)))/sz*100),fontsize='medium')

    plt.tight_layout()
    plt.show()

def main():
    analyzeAVM('D:/MyPython/huawei-honorcup-2-shared/CNN/matrix/1235.avm',64)

if __name__=='__main__':
    main()
        
