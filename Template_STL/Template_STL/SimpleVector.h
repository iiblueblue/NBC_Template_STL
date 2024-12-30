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

// ====================<������>=========================

// �⺻ ������
template <typename T>
SimpleVector<T>::SimpleVector()
{
	data = new T[10];
	currentSize = 0;
	currentCapacity = 10;
}

// �迭�� ũ�⸦ �޴� ������
template <typename T>
SimpleVector<T>::SimpleVector(int capacity)
{
	data = new T[capacity];
	currentSize = 0;
	currentCapacity = capacity;
}

// ���� ������
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& simpleVector)
{
	currentSize = simpleVector.currentSize;
	currentCapacity = simpleVector.currentCapacity;

	// ���� ����
	data = new T[currentCapacity];
	for (int i = 0; i < currentSize; i++)
	{
		data[i] = simpleVector.data[i];
	}
}

// �迭 ũ��(currentCapacity) ����
// : ���� �ϳ��� ���ڷ� �޾� �ش� ������ ���� �迭�� ũ�⺸�� ������ �ƹ� ���۵� ���� �ʴ´�. 
//   ���� ������ �������� ũ�Ⱑ ũ�� �ش� ����ŭ ũ�⸦ ���Ҵ� �Ѵ�.
//   ���� ���Ҵ� �״�� �־�� �Ѵ�.
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

// �� �ڿ� ���� �߰� �Լ�
// : ���ڷ� ���� ���Ҹ� �� �㿡 �߰��Ѵ�.
//   �迭�� �� á�µ� ���Ұ� �� ���� ���, ���� �迭���� ũ�⸦ 5��ŭ �� �ø��� ���ο� ���ұ��� �߰��Ѵ�. (���� ���� ����)
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

// ������ ���� ���� �Լ�
// : ������ ������ ���Ҹ� �����Ѵ�.
//	 ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� �ʴ´�.
template <typename T>
void SimpleVector<T>::SimpleVector::pop_back()
{
	if (currentSize > 0)
	{
		currentSize--;
	}
	else
	{
		cout << "�迭�� ��� �ֽ��ϴ�." << endl;
	}
}

// ���� ������ ���� ��ȯ
// : ���� ������ ������ ��ȯ�Ѵ�.
template <typename T>
int SimpleVector<T>::size()
{
	return currentSize;
}

// �迭�� ũ�� ��ȯ �Լ�
// : ���� ���� �迭�� ũ�⸦ ��ȯ�Ѵ�.
template <typename T>
int SimpleVector<T>::capacity()
{
	return currentCapacity;
}

// ���� ������ ����Ʈ �Լ�
// : data�� ����Ѵ�.
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

// ���� ������ ���� �Լ�
// : ���� �������� �ʰ� STL�� sort �Լ��� Ȱ���ؼ� ����(��������)
template<typename T>
void SimpleVector<T>::sortData()
{
	sort(data, data + currentSize);
}

// �Ҹ���
template <typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data; // ���� �޸� ����
}

#endif // !SIMPLEVECTOR_H_


