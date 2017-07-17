'readtextfile.py--read and display text file'
fname= input("enter file name !")
print   #("")
try:
    fobj=open(fname,'r')
except IOError:
    print("file open error")
else:
    for eachline in fobj:
        print (eachline)
    fobj.close()
