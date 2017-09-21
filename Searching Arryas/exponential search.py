def binarysearch(a,beg,last,ele):
    mid=(beg+last)//2
    if a[mid]==ele:
        return mid
    elif a[mid]<ele:
        return binarysearch(a,mid+1,last,ele)
    elif a[mid]>ele:
        return binarysearch(a,beg,mid-1,ele)
    else:
        return -1
def expsearch(a,b):
    if a[0]==b:
        return 0
    i=1
    while(i<len(a) and a[i]<=b):
        i=i*2
    return binarysearch(a,i//2,min(i,n),b)
n=int(input('Enter size of array'))
l=[int(input()) for i in range(0,n)]
l.sort()
print('Sorted array is',l)
x=int(input('Enter the element to be searched'))
res=expsearch(l,x)
if res==-1:
    print('Element not found')
else:
    print('Element found at position',res+1)
        
