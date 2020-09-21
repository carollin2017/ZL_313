
#include "Timing.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "ListandVector.h"
#include "MoveIt.h"
#include <utility>


using std::vector;
using std::list;

#include "Sorting.h"

void Q1_main() {
	int const size = 10'000;

	vector<int> v;
	v.push_back(0);

	list<int> l;
	l.push_back(0);

	auto vectormilliseconds = TimeFunc([&]() {BuildVector(size, v); });
	auto listmilliseconds = TimeFunc([&]() {BuildList(size, l); });

	if (vectormilliseconds < listmilliseconds) {
		cout << "vectormilliseconds is " << vectormilliseconds << endl;
		cout << "listmilliseconds is " << listmilliseconds << endl;
		cout << "BuildVector is faster" << endl;
	}
	else if (vectormilliseconds > listmilliseconds) {
		cout << "vectormilliseconds is " << vectormilliseconds << endl;
		cout << "listmilliseconds is " << listmilliseconds << endl;
		cout << "BuildList is faster" << endl;
	}
	else {
		cout << "same speed" << endl;
	}

	vector<string> v_string;
	v_string.push_back("start");

	list <string> l_string;
	l_string.push_back("start");
	auto vectormilliseconds_string = TimeFunc([&]() {BuildVector(size, v_string); });
	auto listmilliseconds_string = TimeFunc([&]() {BuildList(size, l_string); });


	if (vectormilliseconds_string < listmilliseconds_string) {
		cout << "vectormilliseconds_string is " << vectormilliseconds_string << endl;
		cout << "listmilliseconds_string is " << listmilliseconds_string << endl;
		cout << "BuildVector is faster" << endl;
	}
	else if (vectormilliseconds_string > listmilliseconds_string) {
		cout << "vectormilliseconds_string is " << vectormilliseconds_string << endl;
		cout << "listmilliseconds_string is " << listmilliseconds_string << endl;
		cout << "BuildList is faster" << endl;
	}
	else {
		cout << "same speed" << endl;

	}



	MoveIt a("Move", 20);
	a.testMe();
	cout << endl;

	MoveIt b(move(a));
	b.testMe();
	cout << endl;

	MoveIt c(move(MoveIt("Move101", 40)));
	c.testMe();
}

void Q3_main() {
	srand(time(0));
	int** a;
	a = new int *[3];
	for (int i = 0; i < 3; i++) {
		a[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			a[i][j] = rand() % 100;
		}
	}

	printMatrix(a, 3, 3);
	
	//BubbleSort(a, 3, 3);
	//InsertionSort(a, 3, 3);
	SelectionSort(a, 3, 3);
	

}
int main()
{
	Q1_main();
	//Q3_main();

}



