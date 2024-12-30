#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
	// Ŭ���� �׽�Ʈ
	SimpleVector<int> my_vector(5);

	my_vector.push_back(10);
	my_vector.push_back(7);
	my_vector.push_back(5);

	my_vector.printData();

	my_vector.pop_back();
	my_vector.printData();


	// ���� ���� �׽�Ʈ
	SimpleVector<int> my_copy_vector(my_vector);

	my_vector.pop_back();

	my_vector.printData();
	my_copy_vector.printData();

	// sort �Լ� �׽�Ʈ
	my_copy_vector.push_back(50);
	my_copy_vector.push_back(5);

	my_copy_vector.sortData();

	my_copy_vector.printData();

	// resize �׽�Ʈ
	my_copy_vector.push_back(7);
	my_copy_vector.push_back(44);
	my_copy_vector.push_back(2);

	my_copy_vector.printData();
	cout << my_copy_vector.capacity() << endl;

	return 0;
}