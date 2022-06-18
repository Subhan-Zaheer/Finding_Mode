#include<iostream>

using namespace std;
struct a {
	int highestNumber = -1;
	int index = -1;
};

int highest(int* arr,int size) {
	int highestnum = arr[0];
	for (int i = 1; i <size; i++) {
		if (arr[i] > highestnum) {
			highestnum = arr[i];
		}
	}
	return highestnum;
}
a highestN(int* arr,int size) {
	a k;
	int highestnum = arr[0];
	for (int i = 1; i <size; i++) {
		if (arr[i] > highestnum) {
			highestnum = arr[i];
			k.index = i;
		}
	}
	k.highestNumber = highestnum;
	return k;
}

int findingMode(int arr[], int size) {
	int highestNum = highest(arr, size);
	int* ar = new int[highestNum];
	ar[0] = 0;
	int mode = 0;
	a b;
	for (int i = 0; i <size; i++) {
		mode = arr[i];
	int countMode = 1;
		for (int j = 0; j < size ; j++) { 

			if (arr[j] == mode) {
				countMode++;
			}
		}
		ar[mode] = countMode;
	}
	b = highestN(ar, size);
	cout << "Mode is : " << b.index << endl;
	return 0;
}

int main() {

	int arr[] = { 5, 7, 5, 5, 10, 4, 5, 6, 6, 4, 6 };
	findingMode(arr,11);
	
	
	return 0;
}