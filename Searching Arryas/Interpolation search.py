from math import floor
def interpolsearch(a,x):
    p=0
    h=len(a)-1
    while p<=h and x>=a[p] and x<=a[h]:
        pos=floor(p+(((h-p)/(a[h]-a[p]))*(x-a[p])))
        if a[pos]==x:
            return pos
        if a[pos]<x:
            p=pos+1
        else:
            h=pos-1
    return -1

l=[int(input()) for i in range(int(input('Enter number of elements')))]
ele=int(input('Enter element to be searched'))
index=interpolsearch(l,ele)
if index==-1:
    print('Element not found')
else:
    print('Element found at',index)
    
