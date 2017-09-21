def linearsearch(a,ele):
    if ele in a:
        return a.index(ele)
    else:
        return -1
n=int(input('Enter size of array'))
l=[int(input()) for i in range(0,n)]
x=int(input('Enter element to be searched'))
pos=linearsearch(l,x)
if pos==-1:
    print('Element not found')
else:
    print("Element found at index %d"%(pos+1))
    
