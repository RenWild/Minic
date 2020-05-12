import sys,os,glob

files = glob.glob('tuning*.csv')
files.sort();
print(files)

for f in files:
    print(f)
    ff = open(f, "r")
    ll = ff.readlines()[-1]
    ff.close()
    if "PST" in f:
        os.system("python ./Tools/PST.py \"" + ll + "\"")
    elif "imbalance" in f:
        os.system("python ./Tools/imbalance.py \"" + ll + "\"")
    elif "mobility" in f:
        os.system("python ./Tools/MOB.py \"" + ll + "\"")
    elif "pawnStructure1" in f:
        os.system("python ./Tools/PawnStr1.py \"" + ll + "\"")
    elif "pawnStructure2" in f:
        os.system("python ./Tools/PawnStr1.py \"" + ll + "\"")
    elif "pawnStructure3" in f:
        os.system("python ./Tools/PawnStr1.py \"" + ll + "\"")
    elif "attDefKing" in f:
        o = ""
        v = ll.split(';')[1:-1]
        for i in range(6):
            o += '{0:>3}, '.format(v[i])
        o = "{ " + o + "},"
        o2 = ""
        for i in range(5):
            o2 += '{0:>3}, '.format(v[6+i])
        o2 = "{ " + o2 + " 0 }"
        print("{ " + o + o2 + " }")
    elif "att" in f:
        print(ll)
    else:
        v = ll.split(';')[1:-1]
        i = len(v)/2
        p = ""
        for i in range(i):
            p += '{{{0:>3},{1:>3}}}, '.format(v[2*i],v[2*i+1])
        print(p)
        
        
        

