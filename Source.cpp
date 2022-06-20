#include<iostream>
#include<ctime>

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

int findNum(int num, int* arr, int size) {
	int* a, * b;
	a = &arr[0];
	b = &arr[size - 1];

	for (int i = 0; i < (size/2); i++) {
		if (*a == num || *b == num) {
			return 1;
		}
		a++; b--;
	}
	return 0;
}

int findingMode(int arr[], int size) {
	int highestNum = highest(arr, size);
	int* ar = new int[highestNum];
	int* newar = new int[size];
	*(newar) = 0;
	ar[0] = 0;
	int mode = 0;
	a b;
	for (int i = 0; i <size; i++) {
		// This loop will pick up the number to count number of occurences in array.
		mode = arr[i];
		int countMode = 1;
		if (i > 0 && findNum(arr[i], newar, size)) {
			
				continue;
		}
		for (int j = i + 1; j < size ; j++) { 
			// This loop will calculate the number of occurences of specific number in array.

			if (arr[j] == mode) {
				countMode++;
			}
		}
		ar[mode] = countMode;
		newar[i] = arr[i];
	}
	b = highestN(ar, size);
	cout << "Mode is : " << b.index << endl;
	return 0;
}

time_t gettime() {
	time_t t;
	t = time(NULL);
	return t;
}

int main() {
	time_t initialTime,finalTime;
	initialTime = gettime();
	int arr[] = { 5, 7, 5, 5, 10, 4, 5, 6, 6, 4, 6, 6, 6, 5 };
	findingMode(arr, 14);
	
	finalTime = gettime();
	cout << endl << "Total time taken is " << finalTime - initialTime << endl;
	
	return 0;
}