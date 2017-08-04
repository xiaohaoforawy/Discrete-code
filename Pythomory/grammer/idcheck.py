#idcheck.py head must belong alferbater or "_"and the rest must have nunmber or alferbater
import string

alphas = string.ascii_letters+'_'
nums = string.digits

print ("welcome to the identifier checker V1.0")
print ("testees must be at leaast 2  chars long.")
myinput=input("identifier to test?")

if len(myinput)>1:
    if myinput[0] not in alphas:
        print("invalid: first symbol must be alphabetic")
    else:
        for otherchar in myinput[1:]:
            if otherchar not in alphas+nums:
                print("invalid: first symbol must be alphabetic")
            break
        print("good game!")
else:
    print("longer!!")
