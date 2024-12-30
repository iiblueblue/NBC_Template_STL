#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
	// 클래스 테스트
	SimpleVector<int> my_vector(5);

	my_vector.push_back(10);
	my_vector.push_back(7);
	my_vector.push_back(5);

	my_vector.printData();

	my_vector.pop_back();
	my_vector.printData();


	// 깊은 복사 테스트
	SimpleVector<int> my_copy_vector(my_vector);

	my_vector.pop_back();

	my_vector.printData();
	my_copy_vector.printData();

	// sort 함수 테스트
	my_copy_vector.push_back(50);
	my_copy_vector.push_back(5);

	my_copy_vector.sortData();

	my_copy_vector.printData();

	// resize 테스트
	my_copy_vector.push_back(7);
	my_copy_vector.push_back(44);
	my_copy_vector.push_back(2);

	my_copy_vector.printData();
	cout << my_copy_vector.capacity() << endl;

	return 0;
}