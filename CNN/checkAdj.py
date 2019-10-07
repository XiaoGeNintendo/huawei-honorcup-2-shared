import keras
import picHelper
import dataGen
import numpy as np
import sys
import os
import random
from PIL import Image

model_dir='D:/MyPython/huawei-honorcup-2-shared/CNN/saved_models/model_4.h5'
model=None
verb=True
batch_size=32
buffer_size=1024
size=64
width=32

pure_var=0.001

def init():
    global model
    model = keras.models.load_model(model_dir)
    opt = keras.optimizers.RMSprop(learning_rate=0.0001, decay=1e-6)
    
    model.compile(loss='mean_squared_error',optimizer=opt,metrics=['accuracy'])
    #model.summary()


def check(img_dir,id1,id2,con,sz=None):
    global model
    if model==None:
        init()
    if sz==None:
        sz=size
    img=Image.open(img_dir)
    tmp=dataGen.getEdge(img,picHelper.toXY(id1,sz)[0],picHelper.toXY(id1,sz)[1],picHelper.toXY(id2,sz)[0],picHelper.toXY(id2,sz)[1],con,sz)
    tmp=dataGen.imgToData(tmp)
    p=model.predict(tmp,verbose=verb)
    return p[0]


def bruteForce(dat,sz=None,w=None):
    if sz==None:
        sz=size
    if w==None:
        w=width

    dat1=dat[w//2-3]+dat[w//2-2]+dat[w//2-1]
    dat1/=3
    dat2=dat[w//2]+dat[w//2+1]+dat[w//2+2]
    dat2/=3
    var1=dat1.var(axis=0)
    var2=dat2.var(axis=0)
    pure1=False
    pure2=False
    if var1[0]<pure_var and var1[1]<pure_var and var1[2]<pure_var:
        pure1=True
    if var2[0]<pure_var and var2[1]<pure_var and var2[2]<pure_var:
        pure2=True
    avg1=dat1.mean(axis=0)
    avg2=dat2.mean(axis=0)
    dif=avg1-avg2
    dif[0]=abs(dif[0])
    dif[1]=abs(dif[1])
    dif[2]=abs(dif[2])
    #print(dat1)
    #print(dat2)
    #print()
    #print(var1)
    #print(var2)
    #print()
    #print(avg1)
    #print(avg2)
    #print()
    #print(dif)
    #print()
    if pure1 and pure2:
        return np.tanh(1/(dif.max()*50))
    elif pure1 or pure2:
        return np.tanh(1/(dif.max()*50))/10
    else:
        return -1

def runBatch(batch,ops,ret,sz=None):
    global model
    if model==None:
        init()
    if sz==None:
        sz=size
    batch=np.asarray(batch)
    p=model.predict(batch,batch_size=batch_size,verbose=verb)
    for op in range(len(ops)):
        i=ops[op][0]
        j=ops[op][1]
        k=ops[op][2]
        if p[op]>0.5:
            print(p[op],picHelper.toXY(i,sz),picHelper.toXY(j,sz),k)
        ret[i][j][k]=p[op]


def getAVM(img_dir,save_dir,sz=None,w=None):
    global model
    if model==None:
        init()
    if sz==None:
        sz=size
    if w==None:
        w=width
    
    ret=np.empty(((512//sz)**2,(512//sz)**2,4))
    img=Image.open(img_dir)
    ops=[]
    batch=[]
    for i in range((512//sz)**2):
        for j in range((512//sz)**2):
            for k in range(4):
                if i==j:
                    ret[i][j][k]=0
                else:
                    ops.append((i,j,k))
                    tmp=dataGen.getEdge(img,picHelper.toXY(i,sz)[0],picHelper.toXY(i,sz)[1],picHelper.toXY(j,sz)[0],picHelper.toXY(j,sz)[1],k,sz,w)
                    tmp=dataGen.imgToData(tmp)
                    tmp=tmp[0]
                    bf=bruteForce(tmp)
                    if bf!=-1:
                        ret[i][j][k]=bf
                        continue
                    batch.append(tmp)
                    if len(batch)>=buffer_size:
                        runBatch(batch,ops,ret,sz)
                        batch=[]
                        ops=[]
    
    runBatch(batch,ops,ret,sz)
    batch=[]
    ops=[]
    
    with open(save_dir,'w') as f:
        for i in range((512//sz)**2):
            for j in range((512//sz)**2):
                for k in range(4):
                    f.write('%.3f'%ret[i][j][k])
                    f.write(' ')
                f.write('\n')
            f.write('\n')

def getAVM2(img_dir,save_dir,sz=None,w=None):
    global model
    if model==None:
        init()
    if sz==None:
        sz=size
    if w==None:
        w=width
    
    ret=np.empty(((512//sz)**2,(512//sz)**2,4))
    img=Image.open(img_dir)
    ops=[]
    batch=[]
    for i in range((512//sz)**2):
        for j in range((512//sz)**2):
            for k in range(4):
                if i==j:
                    ret[i][j][k]=0
                else:
                    tmp=dataGen.getEdge(img,picHelper.toXY(i,sz)[0],picHelper.toXY(i,sz)[1],picHelper.toXY(j,sz)[0],picHelper.toXY(j,sz)[1],k,sz,6)
                    tmp=dataGen.imgToData(tmp)
                    tmp=tmp[0]
                    bf=bruteForce(tmp,sz,6)
                    if bf!=-1:
                        ret[i][j][k]=bf
                        continue
                    tmp=dataGen.getEdge(img,picHelper.toXY(i,sz)[0],picHelper.toXY(i,sz)[1],picHelper.toXY(j,sz)[0],picHelper.toXY(j,sz)[1],k,sz,w)
                    tmp=dataGen.imgToData(tmp)
                    tmp=tmp[0]
                    ops.append((i,j,k))
                    batch.append(tmp)
                    if len(batch)>=buffer_size:
                        runBatch(batch,ops,ret,sz)
                        batch=[]
                        ops=[]
    
    runBatch(batch,ops,ret,sz)
    batch=[]
    ops=[]
    
    with open(save_dir,'w') as f:
        for i in range((512//sz)**2):
            for j in range((512//sz)**2):
                for k in range(4):
                    if ret[i][j][k]<0.001:
                        continue
                    f.write('%d %d %d %.3f\n'%(i,j,k,ret[i][j][k]))

def main():
    getAVM2('D:/MyPython/data/data_train/64-sources/1200.png','D:/MyPython/huawei-honorcup-2-shared/CNN/matrix/1200_test.avm',64,32)
    #for i in range(2400,2410):
    #    getAVM('D:/MyPython/data/data_test1_blank/64/%d.png'%i,'D:/MyPython/huawei-honorcup-2-shared/CNN/matrix1/64/%d.txt'%i,64)
    #img=picHelper.getImage(1200,True,64)
    #tmp=dataGen.getEdge(img,2,0,3,0,3,64,32)
    #tmp=dataGen.imgToData(tmp)
    #tmp=tmp[0]
    #bf=bruteForce(tmp)
    #print(bf)


if __name__=='__main__':
    init()
    if len(sys.argv)==1:
        main()
    else:
        if sys.argv[1]=='check':
            #check img_dir result_dir sz id1 id2 con
            if len(sys.argv)>=7:
                img_dir=sys.argv[2]
                result_dir=sys.argv[3]
                sz=int(sys.argv[4])
                id1=int(sys.argv[5])
                id2=int(sys.argv[6])
                con=int(sys.argv[7])
                ret=check(img_dir,id1,id2,con,sz)
                if not os.path.exists(result_dir):
                    os.makedirs(result_dir)
                print(p[0])
                with open(result_dir,'w') as f:
                    f.write('%.3f'%ret)
            else:
                print('Not enough arguments!!!')
                print('Try: python checkAdj.py check img_dir result_dir size id1 id2 direction')
                print('Direction Number | B is to the ___ of A')
                print('0                  left')
                print('1                  top')
                print('2                  right')
                print('3                  bottom')
                print()
                print('Call 911 plz')
        elif sys.argv[1]=='matrix':
            #matrix img_dir
            if len(sys.argv)>=5:
                img_dir=sys.argv[2]
                result_dir=sys.argv[3]
                sz=int(sys.argv[4])
                getMatrix(img_dir,result_dir,sz)
            else:
                print('Try: python checkAdj.py matrix img_dir result_dir size')
                print('e.g. python checkAjd.py matrix D:/MyPython/data/data_train/64-sources/1200.png 1200.txt 64')
        else:
            print('plz use command "matrix" or "check"')

