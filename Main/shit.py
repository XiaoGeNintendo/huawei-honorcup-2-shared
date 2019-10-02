f=open("out.txt",'w')
for i in range(2400,2700):
    f.write(str(i)+".png\n")
    for i in range(0,64):
        f.write(str(64-i-1)+" ")
    f.write("\n")
    f.flush()
