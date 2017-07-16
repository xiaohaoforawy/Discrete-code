'maketextfile.py--create text file'
import os


ls=os.linesep
fname=["newforder"]

while True:
    if os.path.exists(fname):
        print("ERROR:'s%' already exists"% fname)
    else:
        break

all=[]

print ("\nenter lines ('.' by self to quit).\n")

while True:
    entry=input()
    if entry=='.':
        break
    else:
        all.append(entry)

fobj=open(fname,'w')
fobj.writelines(['s%s%' % (x,ls)]for x in all)
fobj.close()
print("DONE!")
