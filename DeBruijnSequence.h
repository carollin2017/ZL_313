#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <time.h>
using namespace std;

//Author: Zexian Lin
//9. Create a random array of size k.Create a function to check if it is a deBruijn
//sequence of B(n, k).If it is not randomly mutate each spot in the array(from a 0 to 1 or 1 to 0)
//with a 5 % probability, keep doing this until you have found a deBruijn sequence.
//Do this with an array structureand a linked structure.
//To this 100 times for each, time itand compare your results.
//
//For this question, We aware that a DeBruijn Sequence if order n in a size k is a
//cyclic sequence in which every possible length - n string occurs exactly once as
//a substring.We denoted B(k, n).
//
//To detect if a sequence is a DeBruijn Sequence, we will use a unordered_set to
//keep track of the substring.If every substring appears only once, then we
//successfully find the sequence.Otherwise, return false.
//
//To mutate the sequence, we need to make sure that every element in the array /
//linked list only has 5 % probability to change its value(from 0 -> 1 or 1 -> 0).
//
//Besides detecting and mutating, we have another function called testing, which
//will generate a random array / linked list that filled with '0's and '1's.Then
//we will test the randomly array / linked list to see if it is a De Bruijn sequence.
//If not, we keep calling the mutate function until the sequence becomes a De Bruijn
//sequence.
//
//We will use array strustureand linked list strusture for this question.For array,
//it is straightforward.We will use the default substr method to construct the substring.
//Notice at the end of the array, the substring needs to include index(0 - substring_size).
//We will use mod to achieve this.
//
//Linked list is different from array.First, it doesn't have the indexing, so we need 
//to keep track of the number of the Nodes.Besides, we want our linked list become a
//circular linked list in order to keep tracker of the substring.Array doesn't have 
//circular array, but for linked list, we can construct a circular linked list when we
//are testing.


void print(char* a, int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

bool isDeBruijnSequence(char* a, int a_size, int substring_size) {
	// Using a set to keep track of the substring.
	unordered_set<string> tracker;
	string substring = "";
	for (int i = 0; i < a_size; i++) {
		if (i == 0) {
			substring = string(a).substr(0, substring_size);
		}
		else {
			// cut off the first character and add one more character to the end of the substring
			substring = substring.substr(1);
			// example: substring_size = 3, a_size = 8
			// when i = 7, a[(i + substring_size - 1)] = a[9], which will be out of bound.
			// a[(i + substring_size - 1) % a_size] = a[9 % 8] = a[1] will go back the begining of the array.
			substring += a[(i + substring_size - 1) % a_size];
		}
		

		// if the string is already in the set, then the sequence is not De Brujin Sequence
		// since the substring is not unique.
		if (tracker.find(substring) == tracker.end()) {
			tracker.insert(substring);
		}
		else {
 			return false;
		}
	}

	return true;
}


void mutate(char* a, int a_size,int substring_size) {
	srand(time(0));
	for (int i = 0; i < a_size; i++) {
		int num = rand() % 20;
		// Within the probability 5%,  mutate the char (0 -> 1 or 1 -> 0).
		if (num < 1) {
			a[i] = a[i] == '0' ? '1' : '0';
		}
	}
}

void testing_array(char* array, int size, int substring_size) {
	// generate a random array
	srand(time(0));
	for (int i = 0; i < size; i++) {
		int num = rand() % 100;
		array[i] = num < 50 ? '0' : '1';
	}

	//mutate the array until it is a De Brujin Sequence.
	while (true) {
		if (!isDeBruijnSequence(array, size, substring_size)) {
			mutate(array, size, substring_size);
			print(array, size);
		}
		else {
			cout << "Array: De Bruijn Sequence is " << endl;
			print(array, size);
			break;
		}

	}
}










//The following class and method is for testing if a Linked List is a De Brujin Sequence.
class Node {
public:
	char data;
	Node* next;
	
};

void print_ll(Node* head) {
	Node* cur = head;

	if (head != NULL) {
		do {
			cout << cur->data << " ";
			cur = cur->next;
		} while (cur != head);
	}
	
	cout << endl;
}


bool isDeBruijnSequence_ll(Node* head, int substring_size) {
	unordered_set<string> tracker;
	string substring;
	Node* cur = head;
	

	do {
		substring = "";
		Node* ptr = cur;
		for (int i = 0; i < substring_size; i++) {
			substring += ptr->data;
			ptr = ptr->next;
		}

		// if the string is already in the set, then the sequence is not De Brujin Sequence
		// since the substring is not unique.
		if (tracker.find(substring) == tracker.end()) {
			tracker.insert(substring);
		}
		else {
			return false;
		}

		cur = cur->next;
		
	} while (cur != head);

	return true;

}

void mutate_ll(Node* head, int size, int substring_size) {
	srand(time(0));
	Node* cur = head;
	
	int counter = 0;
	while (counter < size) {
		int num = rand() % 20;
		// Within the probability 5%, mutate the char (0 -> 1 or 1 -> 0).
		if (num < 1) {
			cur->data = (cur->data == '0' ? '1' : '0');
		}
		cur = cur->next;
		counter++;
		
	}
}

void testing_ll(Node* head, int size, int substring_size) {
	//generate a random circular linked list
	int counter = 0;
	Node* cur = head;
	while (counter < size) {
		int num = rand() % 2;
		cur->data = (num == 0 ? '0' : '1');

		// create a new node for next;
		Node* n = new Node();

		if (counter == size-1) {
			// make it a circular linked list.
			cur->next = head;
			delete n;
		}
		else {
			cur->next = n;
		}

		cur = cur->next;
		counter++;
	}

	//mutate the linked list until it is a De Brujin Sequence
	while (true) {
		if (!isDeBruijnSequence_ll(head, substring_size)) {
			mutate_ll(head, size, substring_size);
			print_ll(head);
		}
		else {
			cout << "Linked List: De Bruijn Sequence is " << endl;
			print_ll(head);
			break;
		}
	}
}

