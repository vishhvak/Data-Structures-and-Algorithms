//Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

#include <iostream>
using namespace std;
int main() {
	int a[] = {1,2,3,4,5,6,7}, step, temp, temp1;
	int n = 7;
	cout << "\nOriginal:";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << "Enter the number of rotation steps\n";
	cin >> step;
	for (int i = 0; i < step; i++) {
		for (int j = n-1; j >= 0; j++) {
			temp1 = a[j];
			temp = a[j-1];
			a[j-1] = temp1;
			temp1 = temp;
		}
		cout << "\nIteration:" << i;
		for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	}
	
	cout << "\nModified array:";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	return 0;
}