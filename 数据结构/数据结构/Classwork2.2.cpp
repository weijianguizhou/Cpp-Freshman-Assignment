#include <iostream>
using namespace std;

template<typename T>
class SqList {
private:
    T* data;
    int maxSize;
    int length;

public:
    SqList(int num) {
        data = new T[num];
        maxSize = num;
        length = 0;
    }

    SqList(T* arr, int num) {
        data = new T[num];
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

    bool insert(int index, T value) {
        if (index < 0 || index > length || length >= maxSize) {
        	cout<<"Flase"<<endl; 
            return false;
        }
        for (int i = length; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        length++;
        return true;
    }

    bool insert(T value) {
        return insert(length, value);
    }

    bool remove(int index) {
        if (index < 0 || index >= length) {
        	cout<<"Flase"<<endl; 
            return false;
        }
        for (int i = index; i < length - 1; i++) {
            data[i] = data[i + 1];
        }
        length--;
        return true;
    }

    bool deleteValue(T value) {
        for (int i = 0; i < length; i++) {
            if (data[i] == value) {
                return remove(i);
            }
        }
        return false;
    }
};
