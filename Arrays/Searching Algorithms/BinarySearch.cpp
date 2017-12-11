#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const size=10;
int array[] = {1,5,11,15,23,54,76,110,400,1000};
int bin_search_i(int,int);
int bin_search_r(int,int);

int main(){
    cout<<"This Program implements Binary Search Algorithm for Arrays."<<endl;
    //Arrays are assumed as Sorted, for this algorithm to work.
    //Time Complexity = O(log(n))
    int ele;
    char op;
    cout << "Given array is as follows:" << endl;
    for(int i=0;i<size;i++)
        cout<<"array["<<i<<"]:"<<i<<endl;
    cout << "Enter the element you want to find in the array."<<endl;
    cin >> ele;
    //iterative implementation
    cout<<"Which version do you wish to try? Iterative or Recursive? (I/R)"<<endl;
    cin>>op;
    switch(op){
        case 'I':
            int res=bin_search_i(array,ele,0,size-1);
            if(res==0)
                cout<<"Element was not found in the array."<<endl;
            else
                cout<<"Element found at index:"<<res<<endl;
            break;
        case 'R':
            int res=bin_search_r(array,ele,0,size-1);
            if(res==0)
                cout<<"Element was not found in the array."<<endl;
            else
                cout<<"Element found at index:"<<res<<endl;
            break;
        default:
            cout<<"Please enter I or R only. Exiting.";
            break;
    }
    return 0;
}


int bin_search_r(int array[],int ele,int first,int last){          //recursive implementation
    if(last>=1){
        int mid = (first + last)/2;
        if (array[mid] == ele)  return mid;
        if (array[mid] > ele) return bin_search_r(array, last, mid-1, ele); /* If element is smaller than mid, then it
        can only be present in left sub-array */
        return bin_search_r(arr, mid+1, last, ele); // Else the element can only be present in right sub-array
    }

    // We reach here when element is not present in array
    return 0;
}

int bin_search_i(int array[],int ele,int first, int last){          //iterative implementation
    while(first<=last){
        int mid=(first+last)/2; // middle element
        if(ele==array[mid]){
            return mid; //return index after finding the element
        }
        else if(ele>array[mid]) // If element is greater than mid, then it can only be present in right sub-array
            first=mid+1;
        else // Else the element can only be present in right sub-array
            last=mid-1;
    }
    return 0;
}
