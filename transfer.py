from PIL import Image
import numpy as np
img=Image.open('D:\\Personal\\Workspace\\data_train\\64-sources\\1200.png')
a=np.array(img)
sz=int(input())
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
            c[i,j,k]=b[i,j,k,0]**0.299 + b[i,j,k,1]*0.587 + b[i,j,k,2]*0.114



with open('D:\\Personal\\Workspace\\output.txt','w') as f:
    for i in range(sz):
        for j in range(sz):
            f.write(str(c[32,i,j])+' ')
        f.write('\n')

    f.write('\n'*20)

    for i in range(sz):
        for j in range(sz):
            f.write(str(c[21,i,j])+' ')
        f.write('\n')
