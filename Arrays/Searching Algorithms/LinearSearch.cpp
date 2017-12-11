#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
int main() {
    int array[] = {7,13,167,65,3,9,54,12,49,87},ele,signal;
    char op;
    int size = sizeof(array)/ sizeof(array[0]);
    cout << "This Program implements the Linear Search Algorithm for an Array of size 10." << endl;
    //Time Complexity of this algorithm = O(n), n=size of the array
    do {
        cout << "Given array is" << endl;
        for (int i = 0; i < size; i++)
            cout << "array[" << i << "]:" << "\t" << a[i] << endl;
        cout << "Enter the element you want to find.";
        cin >> ele;
        signal=0; //signal is 0 by default to indicate element hasn't been found
        //Using a loop to check if element to find, is equal to an existing element in given array
        for (int i = 0; i < size; i++) {
            if (array[i] == ele) {
                cout << "Element found. Index:" << i << endl;
                signal = 1; //signal is 1 after the element is found
            }
        }
        if (signal == 0)
            cout << "Element was not found in the array. Sorry! Try another element if you wish." << endl;
        cout << "Do you wish to try again?(Y/N)";
        cin >> op;
    }while(op=='Y' || op=='y');
}