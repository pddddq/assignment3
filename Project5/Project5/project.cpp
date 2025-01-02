#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class SimpleVector {
private:
    T* data;                  // 데이터를 저장할 포인터
    int currentSize;          // 현재 원소 개수
    int currentCapacity;      // 배열의 용량

    void resize() {           // 용량을 늘리는함수
        currentCapacity += 5; // 용량 5개 증가
        T* newData = new T[currentCapacity]; // 새로운 배열 생성
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i]; // 기존 데이터를 복사
        }
        delete[] data;        // 기존 메모리 해제
        data = newData;       // 새로운 배열로 교체
    }

public:
    // 기본 생성자: 초기 용량 5
    SimpleVector() : currentSize(0), currentCapacity(5) {
        data = new T[currentCapacity];
    }

    // 용량을 지정하는 생성자
    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
        if (capacity <= 0) {
            throw std::invalid_argument("0보다 커야합니다.");
        }
        data = new T[currentCapacity];
    }

    // 소멸자: 동적 메모리 해제
    ~SimpleVector() {
        delete[] data;
    }

    // 데이터를 추가하는 함수
    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            resize(); // 용량이 꽉 차면 크기를 늘림
        }
        data[currentSize++] = value;
    }

    // 마지막 데이터를 제거하는 함수
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }

    // 현재 원소 개수 반환
    int size() const {
        return currentSize;
    }

    // 배열의 용량 반환
    int capacity() const {
        return currentCapacity;
    }

    // 내부 데이터를 정렬하는 함수
    void sortData() {
        std::sort(data, data + currentSize); // STL sort를 이용해 정렬
    }

    // 디버그용 데이터 출력
    void print() const {
        std::cout << "SimpleVector: [ ";
        for (int i = 0; i < currentSize; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "] (size: " << currentSize << ", capacity: " << currentCapacity << ")" << std::endl;
    }
};

int main() {
    // SimpleVector 테스트
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