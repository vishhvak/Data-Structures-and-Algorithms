#include <iostream>

using std::cout;
using std::cin;
using std::endl;
const int size = 10;
int display(int array[]) {
    for (int k = 0; k < size; k++)
        cout << array[k] << "\t";
    cout << endl;
}
int select_sort(int array[]) {
    int min_idx;
    for (int i = 0; i < size-1; i++) {
        min_idx = i;
        //Check for minimum element in subarray starting from i+1
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        //Swap Minimum element of subarray with beginning of subarray
        int tmp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = tmp;
        cout << "Array in the current iteration (" << i+1 << ") is" << "\t";
        display(array);
    }
    return 0;
}
int main() {
    int array[] = {15, 6, 0, 12, 11, 20, 5, 1, 18, 25};
    cout << "Given Array is as follows: " << "\t";
    display(array);
    select_sort(array);
    return 0;
}