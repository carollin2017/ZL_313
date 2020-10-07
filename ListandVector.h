#pragma once

#include <vector>
#include <string>
#include <list>
#include <time.h>
#include <iostream>
#include "Timing.cpp"
#include "MoveIt.h"
using namespace std;
//Author: Zexian Lin
//1. Test whether a vector or a list is faster by timing them via :
//a.Filling them with random numbers
//b.Filling them with random strings(use ascii)
//c.Doing the above with move semantics when filling with random strings
//
// The build functions will fill vector and list random int and string. 
// when filling strings, we use generate_string() to generate lowercase string with random size.
// In Q1_main(), we time the speed of buildVector() and buildList() using "Timing.cpp"

string generate_string() {
	// The string size will be random, and contains only lowercase letters.
	srand(time(0));
	int size = rand() % 11;
	string ans = "";
	for (int i = 0; i < size; i++) {
		ans += 'a' + rand() % 26;
	}
	
	return ans;
}



void BuildVector(int size, vector <int> v) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		v.push_back(rand() % size);
	}
}


void BuildVector(int size, vector <string> v) {
	for (int i = 0; i < size; i++) {
		v.push_back(generate_string());
	}
}


void BuildList(int size, list <int> l) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		l.push_back(rand() % size);
		
	}
}


void BuildList(int size, list <string> l) {
	for (int i = 0; i < size; i++) {
		l.push_back(generate_string());
	}
}


