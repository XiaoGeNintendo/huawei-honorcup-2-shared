import keras
import picHelper
import dataGen
import numpy as np
import sys
import os
from PIL import Image

model_dir='D:/MyPython/huawei-honorcup-2-shared/CNN/saved_models/model_2.h5'
model=None
verb=False

def init():
    global model
    model = keras.models.load_model(model_dir)
    opt = keras.optimizers.RMSprop(learning_rate=0.0001, decay=1e-6)
    
    model.compile(loss='mean_squared_error',optimizer=opt,metrics=['accuracy'])
    model.summary()


def check(img_dir,id1,id2,con,sz):
    global model
    if model==None:
        init()
        
    img=Image.open(img_dir)
    tmp=dataGen.getEdge(img,picHelper.toXY(id1)[0],picHelper.toXY(id1)[1],picHelper.toXY(id2)[0],picHelper.toXY(id2)[1],con,sz)
    tmp=dataGen.imgToData(tmp)
    p=model.predict(tmp,verbose=verb)
    return p[0]
    


def getMatrix(img_dir,save_dir,sz):
    global model
    if model==None:
        init()
    
    ret=np.empty(((512//sz)**2,(512//sz)**2,4))
    img=Image.open(img_dir)
    for i in range((512//sz)**2):
        for j in range((512//sz)**2):
            for k in range(4):
                if i==j:
                    ret[i][j][k]=0
                else:
                    tmp=dataGen.getEdge(img,picHelper.toXY(i)[0],picHelper.toXY(i)[1],picHelper.toXY(j)[0],picHelper.toXY(j)[1],k,sz)
                    tmp=dataGen.imgToData(tmp)
                    p=model.predict(tmp,verbose=verb)
                    #print(p)
                    if p[0]>0.5:
                        print(p[0],picHelper.toXY(i),picHelper.toXY(j),k)
                    ret[i][j][k]=p[0]
    
    with open(save_dir,'w') as f:
        for i in range((512//sz)**2):
            for j in range((512//sz)**2):
                for k in range(4):
                    f.write('%.3f'%ret[i][j][k])
                    f.write(' ')
                f.write('\n')
            f.write('\n')


def main():
    #getMatrix('D:/MyPython/data/data_train/64-sources/1204.png','D:/MyPython/huawei-honorcup-2-shared/CNN/matrix/1204.txt',64)
    for i in range(1205,1798):
        getMatrix('D:/MyPython/data/data_train/64-sources/%d.png'%i,'D:/MyPython/huawei-honorcup-2-shared/CNN/matrix/%d.txt'%i,64)


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

