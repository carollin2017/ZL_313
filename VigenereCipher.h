#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;
//Author: Zexian Lin
//6. We have received a secret message encoded with a Vigenere cipher(wiki).We know
//that the key is 32 digits longand a brute force attack would take us a long time(see
//	here).We do not know any “tricks” how to break a Vigenere cipher, but we do know how
//	it works.Instead we are going to test random possible solutionsand use a feature
//	function to evaluate the possible solution.We will collect solutions that pass a certain
//	thresholdand mutate those solutions with some low probability, hopefully getting closer
//	to the ‘true solution”.We will also use recombination(see here), with some low
//	probability, continually increasing our threshold as we narrow in on a solution.Create a
//	program that does this, paying special attention to the data structure you wish to
//	manage your possible solutions.

//For this question, we use a pre-defined dictionary corncob_lowercase, which contains about 58000 English words.
//In addition, we use 9 txt files which contains the first 2 -10 characters from the dictionary, which will
//be used to tested if a string is a word that appears in the dictionary.
//The algorithm as follows:
//1.Given a specific message, we generate a 32 bit random key.
//2.Using decoder() to decode the message by Vigenere cipher.
// decrypted char = (encrypted char - key char + 26) % 26 + 'a' (we want the decrypted message to be lowercase letters).
//3.Test how many words are appear in the decrypted. test() return a int matching_char, which indicates how 
// many characters can be used to form a word. The larger the returned value, the more accurate the 
// decrypted message is.
// Inside the test():
// we are going to use 2-10 character set to test if a substring is a word.
// let say a substring "ca" is in the two_char set, we add one more char to the substring from the encrypted
// message, assume it is "cat", then we test if it is in the three_char set...
// we keep testing the substring until it is not in the 2 -10 char_set.
// If a string of size 5 is not in the five_char set, then the first 4 char could be a valid word since we 
// test for the four_char set before.
// Once we find a valid word, we print out the valid word and add up the length of the valid word.
// In this way, we can keep track of how close we are to the orginal text.
//4.Since the key is randomly generated, we don't know how long it will take a generate a reasonable key.
// Therefore, when we test it in the main function, the user have an option to choose whether to run the 
// program continuely when the matching_char is exceed 16.



//reading from a txt file and put the contents in the set.
void read_file(unordered_set<string>& dict, string filename) {
	ifstream ifs(filename);
	string s;
	while (true) {
		// keep inserting elements from the txt file to the set until the file reaches the end.
		ifs >> s;
		dict.insert(s);
		if (ifs.eof() == true) {
			break;
		}
	}
	
	ifs.close();
}


string generate_key() {
	// The key contains only lowercase letters.
	srand(time(0));
	int size = 32;
	string ans = "";
	
	for (int i = 0; i < size; i++) {
	
			ans += 'a' + rand() % 26;
		
	}

	return ans;
}

//void mutate(string& message) {
//	srand(time(0));
//	
//	// since 'e', 's', 'i', 'r','n', 't', 'o', 'l' are the most frequent letters that appear(average >= 5%) 
//	// in a English word. 
//	// we want to mutate the letter within the probability 2.5%.
//	int start = rand() % 16;
//	int end = rand() % 16 + 16;
//	for (int i = start; i <= end; i++) {
//		int num = rand() % 40;
//		//cout <<"NUM: "<< num << endl;
//		// within prob 5% and it is not a most common letter, we mutate
//
//		
//		if (num == 0) {
//			message.at(i) = 'e';
//			/*cout << i << " change to e" << endl;
//			message.replace(i, 1, "e");*/
//		}
//		else if (num == 1) {
//			message.at(i) = 's';
//			//message.replace(i, 1, "s");
//		}
//		else if (num == 2) {
//			message.at(i) = 'i';
//			//message.replace(i, 1, "i");
//		}
//		else if (num == 3) {
//			message.at(i) = 'r';
//			//message.replace(i, 1, "r");
//		}
//		else if(num == 4){
//			message.at(i) = 'n';
//			//message.replace(i, 1, "n");
//		}
//		else if (num == 5) {
//			message.at(i) = 't';
//			//message.replace(i, 1, "t");
//		}
//		else if (num == 6) {
//			message.at(i) = 'o';
//			//message.replace(i, 1, "o");
//		}
//		else if (num == 7) {
//			message.at(i) = 'l';
//		}
//		
//		
//		
//	}
//}

string decoder(string secret, string key) {
	string ans = "";
	for (int i = 0; i < key.size(); i++) {
		char x = (secret.at(i) - key.at(i) + 26) % 26 + 'a';
		ans += x;
	}
	cout << ans << endl;
	return ans;
}




int test(string message, unordered_set<string>& dict, unordered_set<string>& two_char,
	unordered_set<string>& three_char, unordered_set<string>& four_char,
	unordered_set<string>& five_char, unordered_set<string>& six_char,
	unordered_set<string>& seven_char, unordered_set<string>& eight_char,
	unordered_set<string>& nine_char, unordered_set<string>& ten_char) {


	unordered_set<string> prefixes[11];
	prefixes[2] = two_char;
	prefixes[3] = three_char;
	prefixes[4] = four_char;
	prefixes[5] = five_char;
	prefixes[6] = six_char;
	prefixes[7] = seven_char;
	prefixes[8] = eight_char;
	prefixes[9] = nine_char;
	prefixes[10] = ten_char;

	int match_char = 0;
	int start = 0;
	int end;
	int max = message.length();
	while (true) {
		// start with 2 chars at a time.
		string substring = "";
		end = start;
		substring += message.at(start);
		end++;
		//cout << "start: " << start << ", end: " << end << endl;
		if (end == max) {
			// when we reach the end, check if the previous selection is a word and stop.
			if (dict.find(substring) != dict.end()) {
				cout << "found a valid word: " << substring << " with score: " << substring.length() << endl;
				match_char += substring.length();
			}
			break;
		}
		substring += message.at(end);

		// find if the substring is in the 2-10char set.
		int i;
		int stepback = 0;
		for (i = 2; i <= 10; i++) {
		
			if (prefixes[i].find(substring) == prefixes[i].end()) {
				// stop when the substring does not match any of the char set.
				break;
			}
			// else, continue to look with the next char included.
			end++;
			// if we found a match in the char set, we need to start to end - 1 in the next iteration.
			stepback = 1;
			if (end == max) {
				// stop when we reached the end.
				break;
			}
			substring += message.at(end);
		}
		// check if the selection is a valid word.
		// remove the last letter because adding it will cause the word to fail the char set match.
		substring = substring.substr(0, substring.length() - 1);
		if (dict.find(substring) != dict.end()) {
			cout << "A valid word: " << substring << " with score: " << substring.length() << endl;
			match_char += substring.length();
		}
		start = end - stepback;

	}
	return match_char;
}