#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class SimpleVector {
private:
    T* data;                  // �����͸� ������ ������
    int currentSize;          // ���� ���� ����
    int currentCapacity;      // �迭�� �뷮

    void resize() {           // �뷮�� �ø����Լ�
        currentCapacity += 5; // �뷮 5�� ����
        T* newData = new T[currentCapacity]; // ���ο� �迭 ����
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i]; // ���� �����͸� ����
        }
        delete[] data;        // ���� �޸� ����
        data = newData;       // ���ο� �迭�� ��ü
    }

public:
    // �⺻ ������: �ʱ� �뷮 5
    SimpleVector() : currentSize(0), currentCapacity(5) {
        data = new T[currentCapacity];
    }

    // �뷮�� �����ϴ� ������
    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
        if (capacity <= 0) {
            throw std::invalid_argument("0���� Ŀ���մϴ�.");
        }
        data = new T[currentCapacity];
    }

    // �Ҹ���: ���� �޸� ����
    ~SimpleVector() {
        delete[] data;
    }

    // �����͸� �߰��ϴ� �Լ�
    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            resize(); // �뷮�� �� ���� ũ�⸦ �ø�
        }
        data[currentSize++] = value;
    }

    // ������ �����͸� �����ϴ� �Լ�
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }

    // ���� ���� ���� ��ȯ
    int size() const {
        return currentSize;
    }

    // �迭�� �뷮 ��ȯ
    int capacity() const {
        return currentCapacity;
    }

    // ���� �����͸� �����ϴ� �Լ�
    void sortData() {
        std::sort(data, data + currentSize); // STL sort�� �̿��� ����
    }

    // ����׿� ������ ���
    void print() const {
        std::cout << "SimpleVector: [ ";
        for (int i = 0; i < currentSize; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "] (size: " << currentSize << ", capacity: " << currentCapacity << ")" << std::endl;
    }
};

int main() {
    // SimpleVector �׽�Ʈ
    SimpleVector<int> vec;
    SimpleVector<int> A(20);
    A.push_back(3);
    A.push_back(4);
    A.print();
    A.pop_back();
    A.print();
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(6);

    vec.print();

    vec.sortData();

    vec.print();

    return 0;
}