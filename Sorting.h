#pragma once
#include <iostream>
#include <vector>
using namespace std;
//Author: Zexian Lin
//3. Create a sort for 2d matrices.Do a bubble sort, insertion sort, and selection sort
//variation of this.

//For sorting in the 2d matices, we need to pay attention to the indexing. 
//Let say we have a 2d matrix with i rows and j column.
//When we traverse from one row to its second row, i needs to starting from 0, j only needs to plus 1.
//To solve the problem, we use the following strategy:
//Given a matrix[3][3] = {{0,1,2},{3,4,5},{6,7,8}}
//Known 5 is the 5th element in the matrix.(starting from index 0)
//5 / row_size ==> 5/3 = 1 
//5 mod row_size ==> 5 mod 3 = 2
// matrix[1][2] --> the indexing of 5 in the matrix


void printMatrix(int** array, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}



void BubbleSort(int** array, int row, int col) {
	int size = row * col;
	for (int i = 0; i < size; i++) {
		//The last element is already in place.
		for (int j = 0; j < size-i-1; j++) {
			// r will be the row number,c will be the col number.
			int r = j / col;
			int c = j % col;

			// The index of next element
			int r_next = (j + 1) / col;
			int c_next = (j + 1) % col;

			if (array[r][c] > array[r_next][c_next]) {
				int temp = array[r][c];
				array[r][c] = array[r_next][c_next];
				array[r_next][c_next] = temp;
			}
		}

	}
	cout << "After Bubblesort" << endl;
	printMatrix(array, row, col);
}


void InsertionSort(int** array, int row, int col) {
	int size = row * col;
	for (int i = 1; i < size; i++) {
		int r = i / col;
		int c = i % col;
		// key is the current element we want to insert.
		int key = array[r][c];

		// j starts from i-1 since i labels current element we want to insert,
		// and before i, are the elements that are already sorted
		int j = i - 1;
		while (j >= 0 && array[j / col][j % col] > key) {
			array[(j + 1) / col][(j + 1) % col] = array[j / col][j % col];
			j =  j-1;
		}
		array[(j + 1) / col][(j + 1) % col] = key;
	}
	cout << "After Insertion Sort" << endl;
	printMatrix(array, row, col);
}


void SelectionSort(int** array, int row, int col) {
	int size = row * col;
	for (int i = 0; i < size; i++) {
		int min_index = i;
		
		for (int j = i+1; j < size; j++) {
			if (array[j / col][j % col] < array[min_index / col][min_index % col]) {
				min_index = j;
			}
		}
		
		int temp = array[min_index / col][min_index % col];
		array[min_index / col][min_index % col] = array[i / col][i % col];
		array[i / col][i % col] = temp;

	}

	cout << "After Selection Sort" << endl;
	printMatrix(array, row, col);
}








