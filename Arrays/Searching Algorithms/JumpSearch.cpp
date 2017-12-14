#include <iostream>
#include <math.h>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::min;

int jumpsearch(int array[], int x, int n) {
    int step = sqrt(n);
    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (array[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (array[prev] < x) {
        prev++;

        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, n))
            return -1;
    }
    // If element is found
    if (array[prev] == x)
        return prev;

    return -1;
}

int main() {
    int array[] = {0, 1, 1, 2, 3, 5, 8, 13, 21,
                   34, 55, 89, 144, 233, 377, 610};
    int x;
    int n = sizeof(array) / sizeof(array[0]);
    cout << "Given Array is as follows" << "\n";
    for (int i = 0; i < n; i++)
        cout << "Array [" << i << "]" << array[i] << "\n";
    cout << "Enter the number you want to find";
    cin >> x;
    // Find the index of 'x' using Jump Search
    int index = jumpsearch(array, x, n);

    // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}
