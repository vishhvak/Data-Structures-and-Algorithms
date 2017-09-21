from math import sqrt, floor
def jumpsearch(a,ele):
    step=floor(sqrt(len(a)))
    for i in range(0,len(a),step):
        if i+step<len(a):
            if a[i]<ele and a[i+step]>ele:
                for j in range(i,i+step):
                    if a[j]==ele:
                        return j+1
        if i+step==len(a):
            for j in range(i,i+step-1):
                if a[j]==ele:
                    return j+1
    return -1
n=int(input('Enter size of array'))
l=[int(input()) for i in range(0,n)]
l.sort()
print(l,'\n')
x=int(input('Enter elemenet to be searched'))
res=jumpsearch(l,x)
if res==-1:
    print('Element not found')
else:
    print('Element found at position',res)
                
