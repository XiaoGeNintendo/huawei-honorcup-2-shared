import keras
import picHelper
import dataGen
import numpy as np
from PIL import Image

model_dir='D:/MyPython/huawei-honorcup-2-shared/CNN/saved_models/model_2.h5'

def init():
    global model
    model=keras.models.load_model(model_dir)
    opt = keras.optimizers.RMSprop(learning_rate=0.0001, decay=1e-6)
    
    model.compile(loss='mean_squared_error',optimizer=opt,metrics=['accuracy'])
    model.summary()

def getMatrix(img_dir,save_dir,sz):
    ret=np.empty(((512//sz)**2,(512//sz)**2,4))
    img=Image.open(img_dir)
    for i in range((512//sz)**2):
        for j in range((512//sz)**2):
            for k in range(4):
                if i==j:
                    ret[i][j][k]=0
                else:
                    tmp=dataGen.getEdge(img,picHelper.toXY(i)[0],picHelper.toXY(i)[1],picHelper.toXY(j)[0],picHelper.toXY(j)[1],k)
                    tmp=dataGen.imgToData(tmp)
                    p=model.predict(tmp,verbose=0)
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


if __name__=='__main__':
    init()
    getMatrix('D:/MyPython/data/data_train/64-sources/1202.png','D:/MyPython/huawei-honorcup-2-shared/CNN/matrix/1202.txt',64)
