from PIL import Image
import numpy as np
import sys
import os

if not os.path.isdir('.\\output\\'):
    os.makedirs('.\\output\\')

image_folder=sys.argv[1]
start_image=int(sys.argv[2])
end_image=int(sys.argv[3])
sz=int(sys.argv[4])

for nowimg in range(start_image,end_image+1):

    img=Image.open(image_folder+'\\'+str(nowimg)+'.png')
    a=np.array(img)
    #sz=int(input())
    sz_per_row=512//sz
    b=np.zeros([sz_per_row**2,sz,sz,3],dtype=np.int16)
    c=np.zeros([sz_per_row**2,sz,sz],dtype=float)
    for i in range(0,512,sz):
        for j in range(0,512,sz):
            for k in range(0,sz):
                for l in range(0,sz):
                    for m in range(3):
                        b[i//sz*sz_per_row+j//sz,k,l,m]=a[i+k,j+l,m]

    for i in range(sz_per_row**2):
        for j in range(sz):
            for k in range(sz):
                c[i,j,k]=b[i,j,k,0]*0.299 + b[i,j,k,1]*0.587 + b[i,j,k,2]*0.114



    with open('.\\output\\output'+str(nowimg)+'.txt','w') as f:
        for i in range(sz_per_row**2):
            for j in range(sz):
                for k in range(sz):
                    f.write(str(c[i,j,k])+' ')
                f.write('\n')

            f.write('\n')
