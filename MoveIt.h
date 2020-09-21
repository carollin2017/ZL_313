#pragma once
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class MoveIt {
private:
	string sentence;
	string* ptr;
	int size;

public:
	MoveIt(string sentence = nullptr, int size = 1) : sentence(sentence), size(size) {
		//cout << "Running the constructor\n";
		ptr = new string[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = generate_string();
		}
	}

	//destructor
	~MoveIt() {
		//cout << "Running the destructor\n";
		delete[] ptr;
	}

	//copy constructor
	MoveIt(const MoveIt& obj) noexcept {
		//cout << "In copy constructor\n";

		
		this->sentence = obj.sentence;
		this->size = obj.size;
		ptr = new string[size];

		for (int i = 0; i < size; i++)
		{
			ptr[i] = obj.ptr[i];
		}
	}

	//assignment operator
	MoveIt& operator=(const MoveIt& obj) noexcept {
		//cout << "In operator equals\n";

		if (this != &obj) {
			if (size > 0) {
				delete[] ptr;
			}

			
			this->sentence = obj.sentence;
			this->size = obj.size;
			ptr = new string[this->size];
			for (int i = 0; i < size; i++)
			{
				this->ptr[i] = obj.ptr[i];
			}
		}
		return *this;
	}

	//move assignment operator
	MoveIt& operator=(MoveIt&& obj) noexcept {
		//cout << "In move assignment operator\n";

		if (this != &obj) {
			delete[] ptr;

			
			this->sentence = obj.sentence;
			this->size = obj.size;
			ptr = obj.ptr;

			obj.ptr = nullptr;
		}
		return *this;
	}

	//move constructor
	MoveIt(MoveIt&& obj) noexcept {
		//cout << "In move constructor\n";

		//*this = move(obj);
		
		this->sentence = obj.sentence;
		this->size = obj.size;
		ptr = obj.ptr;

		obj.ptr = nullptr;
	}
	void testMe() {
		
		cout << "The sentence is: " << sentence << endl;
		cout << "My array is:\n";
		for (int i = 0; i < size; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << endl;
	}
};