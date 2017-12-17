#include <iostream>
using std::min;
using std::cout;
using std::cin;

int binarySearch(int arr[], int, int, int);

// Returns position of first ocurrence of
// x in array
int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at firt location itself
    if (arr[0] == x)
        return 0;

    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;

    //  Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n), x);
}

// A recursive binary search function. It returns
// location of x in  given array arr[l..r] is
// present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
    }

    // We reach here when element is not present
    // in array
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40, 57, 65, 72, 89, 110, 111};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x;
    cout << "Given Array is as follows" << "\n";
    for (int i = 0; i < n; i++)
        cout << "Array [" << i << "]" << arr[i] << "\n";
    cout << "Enter the number you want to find ";
    cin >> x;
    int result = exponentialSearch(arr, n, x);
    if(result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index :" << result;
    return 0;
}