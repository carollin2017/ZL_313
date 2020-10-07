
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <time.h>
#include <cmath>
#include <unordered_set>

using std:: cout;
using std::vector;
using std::list;
using namespace std;

#include "Timing.h"
#include "ListandVector.h"
#include "MoveIt.h"
#include "Sorting.h"
#include "DeBruijnSequence.h"
#include "AddToS.h"
#include "VigenereCipher.h"


void Q1_main() {
	
	int const size = 10'000;

	vector<int> v;
	v.push_back(0);

	list<int> l;
	l.push_back(0);

	// compare the speed of buildVector and buildList.
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

	// compare the speed of buildVector and buildList.
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


	// using move semantics
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
	a = new int* [3];
	for (int i = 0; i < 3; i++) {
		a[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			a[i][j] = rand() % 100;
		}
	}

	printMatrix(a, 3, 3);

	//testing sorting individually.
	BubbleSort(a, 3, 3);
	/*InsertionSort(a, 3, 3);
	SelectionSort(a, 3, 3);*/


}

void Q8_main() {
	int size = 20;
	srand(time(0));

	// generate a random array fill with int and print the elements in the array.
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
		cout << array[i] << " ";
	}
	cout << endl;

	AddToS<int> s;
	int target = 18;
	vector<vector<int>> res = s.addtoS(target, array, size);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	if (res.size() == 0) {
		cout << "There's no elements that can add to the target!" << endl;
	}





	// generate a random array fill with int and print the elements in the array.
	double* nums = new double[size];
	for (int i = 0; i < size; i++) {
		// promote the random number to a double.
		nums[i] = (double)((rand() % size) * 1.0);
		cout << nums[i] << " ";
	}
	cout << endl;


	AddToS<double> s1;
	double target_1 = 18.0;
	vector<vector<double>> res_1 = s1.addtoS(target_1, nums, size);
	for (int i = 0; i < res_1.size(); i++) {
		for (int j = 0; j < res_1[i].size(); j++) {
			cout << res_1[i][j] << " ";
		}
		cout << endl;
	}
	if (res_1.size() == 0) {
		cout << "Thers's no elements that can add to the target!" << endl;
	}

}

void Q9_main() {
	// The demo De BruijnSequence will be B(2, 3).
	int k = 2;
	int n = 3;
	int size = pow(k, n);

	
	char* array = new char [size];
	cout << "The array is " << endl;
	testing_array(array, size, n);

	
	Node* head = new Node();
	cout << "The linked list is " << endl;
	testing_ll(head, size, n);

	// testing for array structure and linked list structure 1 time.
	auto arraymilliseconds = TimeFunc([&]() {testing_array(array, size, n); });
	auto linkedlistmilliseconds = TimeFunc([&]() {testing_ll(head, size, n); });
	cout << "Running one time: arraymilliseconds is " << arraymilliseconds << endl;
	cout << "Running one time: linkedlistmilliseconds is " << linkedlistmilliseconds << endl;


	// testing for array structure and linked list structure 100 time.
	/*int mutate_time = 99;
	while (mutate_time > 0) {
		linkedlistmilliseconds += TimeFunc([&]() {testing_ll(head, size, n); });
		arraymilliseconds += TimeFunc([&]() {testing_array(array, size, n); });
		mutate_time--;
	}


	if (arraymilliseconds < linkedlistmilliseconds) {
		cout << "arraymilliseconds is " << arraymilliseconds << endl;
		cout << "linkedlistmilliseconds is " << linkedlistmilliseconds << endl;
		cout << "Array is faster" << endl;
	}
	else if (arraymilliseconds > linkedlistmilliseconds) {
		cout << "arraymilliseconds is " << arraymilliseconds << endl;
		cout << "linkedlistmilliseconds is " << linkedlistmilliseconds << endl;
		cout << "Linked list is faster" << endl;
	}
	else {
		cout << "arraymilliseconds is " << arraymilliseconds << endl;
		cout << "linkedlistmilliseconds is " << linkedlistmilliseconds << endl;
		cout << "same speed" << endl;
	}*/
}

void Q6_main() {
	unordered_set <string> dict;
	read_file(dict, "corncob_lowercase.txt");
	// The following sets will store the first 2-10 characters from the dict respectively.
	unordered_set <string> two_char;
	read_file(two_char, "2char.txt");
	unordered_set <string> three_char;
	read_file(three_char, "3char.txt");
	unordered_set <string> four_char;
	read_file(four_char, "4char.txt");
	unordered_set <string> five_char;
	read_file(five_char, "5char.txt");
	unordered_set <string> six_char;
	read_file(six_char, "6char.txt");
	unordered_set <string> seven_char;
	read_file(seven_char, "7char.txt");
	unordered_set <string> eight_char;
	read_file(eight_char, "8char.txt");
	unordered_set <string> nine_char;
	read_file(nine_char, "9char.txt");
	unordered_set <string> ten_char;
	read_file(ten_char, "10char.txt");

	string secret = "ghihqgwjhhdvwzdooriwkhfdvwohrtya";
	
	while (true) {
		
		string key = generate_key();
		string message = decoder(secret, key);
		int pre = 0;
		int num = test(message, dict, two_char,
			three_char, four_char, five_char, six_char, seven_char, eight_char, nine_char, ten_char);
		cout << message << " " << num << endl;
		
		
		if (num > 16 && num > pre) {
			cout << "do you want to find a better match? enter 1 for yes, enter 0 for no" << endl;
			int input;
			cin >> input;
			if (input == 0) {
				cout << "The decoded message is: " <<message << endl;
				cout << " The key to mutate is :" << key << endl;
				break;
			}
			pre = num;
		}
		
		
	}
	
	
}

int main()
{
	//Q1_main();
	
	//Q3_main();
	
	//Q6_main();
	
	//Q8_main();

	//Q9_main();
	
	
}



