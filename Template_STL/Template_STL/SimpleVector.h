#include <iostream>
#include <algorithm>
using namespace std;

#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

template <typename T>
class SimpleVector
{
protected:
	T* data;
	int currentSize;
	int currentCapacity;
private:
	void resize(int newCapacity);
public:
	SimpleVector();
	SimpleVector(int capacity);
	SimpleVector(const SimpleVector& simpleVector);

	
	void push_back(const T& value);
	void pop_back();
	int size();
	int capacity();
	void printData();
	void sortData();

	~SimpleVector();
};

// ====================<구현부>=========================

// 기본 생성자
template <typename T>
SimpleVector<T>::SimpleVector()
{
	data = new T[10];
	currentSize = 0;
	currentCapacity = 10;
}

// 배열의 크기를 받는 생성자
template <typename T>
SimpleVector<T>::SimpleVector(int capacity)
{
	data = new T[capacity];
	currentSize = 0;
	currentCapacity = capacity;
}

// 복사 생성자
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& simpleVector)
{
	currentSize = simpleVector.currentSize;
	currentCapacity = simpleVector.currentCapacity;

	// 깊은 복사
	data = new T[currentCapacity];
	for (int i = 0; i < currentSize; i++)
	{
		data[i] = simpleVector.data[i];
	}
}

// 배열 크기(currentCapacity) 변경
// : 정수 하나를 인자로 받아 해당 정수가 현재 배열의 크기보다 작으면 아무 동작도 하지 않는다. 
//   만약 현재의 레벨보다 크기가 크면 해당 값만큼 크기를 재할당 한다.
//   기존 원소는 그대로 있어야 한다.
template <typename T>
void SimpleVector<T>::resize(int newCapacity)
{
	if (newCapacity > currentCapacity)
	{
		T* new_capacity_data = new T[newCapacity];
		for (int i = 0; i < currentSize; i++)
		{
			new_capacity_data[i] = data[i];
		}
		delete[] data;
		data = new_capacity_data;
		new_capacity_data = nullptr;
		currentCapacity = newCapacity;
	}
}

// 맨 뒤에 인자 추가 함수
// : 인자로 받은 원소를 맨 쥐에 추가한다.
//   배열이 꽉 찼는데 원소가 더 들어올 경우, 기존 배열보다 크기를 5만큼 더 늘리고 새로운 원소까지 추가한다. (기존 값도 유지)
template <typename T>
void SimpleVector<T>::push_back(const T& value)
{
	if (currentSize < currentCapacity)
	{
		data[currentSize] = value;
		currentSize++;
	}
	else
	{
		resize(currentCapacity + 5);
		data[currentSize] = value;
		currentSize++;
	}
}

// 마지막 원소 제거 함수
// : 벡터의 마지막 원소를 제거한다.
//	 만약 제거할 원소가 없다면 아무 동작도 하지 않는다.
template <typename T>
void SimpleVector<T>::SimpleVector::pop_back()
{
	if (currentSize > 0)
	{
		currentSize--;
	}
	else
	{
		cout << "배열이 비어 있습니다." << endl;
	}
}

// 현재 원소의 개수 반환
// : 현재 원소의 개수를 반환한다.
template <typename T>
int SimpleVector<T>::size()
{
	return currentSize;
}

// 배열의 크기 반환 함수
// : 현재 내부 배열의 크기를 반환한다.
template <typename T>
int SimpleVector<T>::capacity()
{
	return currentCapacity;
}

// 내부 데이터 프린트 함수
// : data를 출력한다.
template <typename T>
void SimpleVector<T>::printData()
{
	cout << "[";
	for (int i = 0; i < currentSize; i++)
	{
		cout << data[i] << ", ";
	}
	cout << "\b\b]" << endl;
}

// 내부 데이터 정렬 함수
// : 직접 정렬하지 않고 STL의 sort 함수를 활용해서 정렬(오름차순)
template<typename T>
void SimpleVector<T>::sortData()
{
	sort(data, data + currentSize);
}

// 소멸자
template <typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data; // 동적 메모리 해제
}

#endif // !SIMPLEVECTOR_H_


