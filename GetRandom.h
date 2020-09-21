#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;



//union DataType {
//	int int_value;
//	string string_value;
//};
//
//class RandomGenerator {
//protected:
//	int size;
//public:
//	RandomGenerator(int s) : size(s) {
//	
//	}
//
//	template<typename T>
//	virtual T getRandom();
//};
//
//class RandomIntGenerator : public RandomGenerator
//{
//protected:
//	vector <int> vc;
//	list <int> li;
//public:
//	RandomIntGenerator(int size, vector<int> v) :RandomGenerator(size) {
//		vc = v;
//	}
//
//	RandomIntGenerator(int size, list <int> l) : RandomGenerator(size) {
//		li = l;
//	}
//
//	DataType getRandom() {
//		DataType d;
//		d.int_value = rand() % size;
//		return d;
//		//for (int i = 0; i < size; i++) {
//		//	vc[i] = rand() % size;
//		//	li.push_back(rand() % size);
//		//}
//	}
//};
//
//
//class RandomStringGenerator : public RandomGenerator
//{
//protected:
//	vector <string> vc;
//	list <string> li;
//public:
//	RandomStringGenerator(int size, vector<string> v) :RandomGenerator(size) {
//		vc = v;
//	}
//
//	RandomStringGenerator(int size, list <string> l) : RandomGenerator(size) {
//		li = l;
//	}
//
//	string generate_string() {
//		// The string size will be random, and contains only lowercase letters.
//		int size = rand() % 11;
//		string ans = "";
//		for (int i = 0; i < size; i++) {
//			ans += 'a' + rand() % 26;
//		}
//
//		return ans;
//	}
//	void getRandom() {
//		for (int i = 0; i < size; i++) {
//			vc[i] = generate_string();
//			li.push_back(generate_string());
//		}
//	}
//};