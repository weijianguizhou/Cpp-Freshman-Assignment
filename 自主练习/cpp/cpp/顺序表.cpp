#include <iostream>

using namespace std;

class SqList {
private:
	int* data;      // Pointer to the array storing the elements
	int maxSize;    // Maximum size of the list
	int length;     // Current number of elements in the list

public:
	SqList(int num) {
		data = new int[num];
		maxSize = num;
		length = 0;
	}

	SqList(int* arr, int num) {
		data = new int[num];
		maxSize = num;
		length = num;
		for (int i = 0; i < num; i++) {
			data[i] = arr[i];
		}
	}
	~SqList() {
		delete[] data;
	}

	void display() {
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

	bool insert(int index, int value) {
		if (index<0 || index > length || length >= maxSize) {
			return false; // Invalid index or list is full
		}
		for (int i = length; i > index; i--) {
			data[i] = data[i - 1]; // Shift elements to the right
		}
		data[index] = value; // Insert the new element
		length++;
		return true;
	}
	bool remove(int index) {
		if (index < 0 || index >= length) {
			return false; // Invalid index
		}
		for (int i = index; i < length - 1; i++) {
			data[i] = data[i + 1]; // Shift elements to the left
		}
		length--;
		return true;
	}

	bool deleteValue(int value) {
		for (int i = 0; i < length; i++) {
			if (data[i] == value) {
				return remove(i); // Remove the first occurrence of the value
			}
		}
		return false; // Value not found
	}
};

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	SqList list(arr, 5);
	list.display();
	list.insert(2, 10);
	list.display();
	list.remove(4);
	list.display();
	list.deleteValue(10);
	list.display();
	return 0;
}