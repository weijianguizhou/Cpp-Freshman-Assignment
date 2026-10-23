#include <iostream>
using namespace std;

// 用数组实现的顺序表
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

    bool insert(int index, T value) {
        if (index < 0 || index > length || length >= maxSize) {
            cout << "False" << endl;
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
            cout << "False" << endl;
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

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    SqList<int> list(arr, 6);
    cout << "初始顺序表: ";
    list.display();

    list.remove(1);
    cout << "删除下标 1 后: ";
    list.display();

    list.insert(1, 3);
    cout << "在下标 1 处插入 3: ";
    list.display();

    list.insert(2, 4);
    cout << "表已满时再插入: ";
    list.display();

    list.deleteValue(7);
    cout << "删除值为 7 的元素: ";
    list.display();

    return 0;
}
