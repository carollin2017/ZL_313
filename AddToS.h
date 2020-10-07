#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//Author: Zexian Lin
//8. Create a templated class that effectively finds all possibilities of a list of random numbers
//that adds to some s.

//The following template only considers the numbers within 32 digits. Otherwise, it will cause overflow.
//The algothrism for sovling this question is: 
//1.We turn the index of the num list into binary number.
//2.For the binary number, we find out positions that have 1's, 
// and find the corresponding index in the num list, add the nums[ corresponding index ] to a list.
//3.If the sum of nums[ corresponding index ] == target, we save the list to the result.
//Notice: since this is a template, we need to consider the case when we compare two floats or double.
//As long as the difference between two float(double) is smaller enough, we consider they are equal.


template <class T>
class AddToS 
{
public:
	
	string toBinary(int n) {
		//array to store binary number;
		int binaryNum[32];
		int i = 0;
		while (n > 0) {
			binaryNum[i] = n % 2;
			n = n / 2;
			i++;
		}
		string res = "";
		for (int j = i - 1; j >= 0; j--) {
			res += '0' + binaryNum[j];
		}

		return res;
	}

	// As long as the difference between x and y is less or equal to 2.22045e-016, 
	// we assume x and y is equal.
	bool isEqual(T x, T y) {
		if (fabs(x - y) <= 2.22045e-016) {
			return true;
		}
		return false;
	}
	


	vector<vector<T>> addtoS(T target, T* nums, int size) {
		vector< vector<T> > res;
		vector <T> elem;
	
		// The outter for loop runs pow(2, size) times since we have 2^n permutations 
		// if we have a size n array.
		for (int i = 0; i < pow(2, size); i++) {
			elem.clear();
			// convert every i to binary number
			string str = toBinary(i);
			// find out what index of the str is 1 in order to add the corresponding element in the nums with
			// the same index to the vector elem.
			T sum = (T)0;
			for (int j = 0; j < str.size(); j++) {
				if (str.at(j) == '1') {
					elem.push_back(nums[j]);
					sum += *(nums + j);
				}
			}

			if (isEqual(sum, target)) {
				res.push_back(elem);	
			}

		}

		return res;
	}
};


