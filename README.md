# ZL_313
To run the following question, you need to look at Qi_main() in the CS313_hw1_Zexian_lin.cpp file and uncomment the corresponding problems
you wish to test.
**********************************************************************************************************************
Q1 (Zexian Lin): includes header files as follow: 
 "Timing.h"
 "ListandVector.h"
"MoveIt.h"
1. Test whether a vector or a list is faster by timing them via :
a.Filling them with random numbers
b.Filling them with random strings(use ascii)
c.Doing the above with move semantics when filling with random strings

The build functions will fill vector and list random int and string. 
when filling strings, we use generate_string() to generate lowercase string with random size.
In Q1_main(), we time the speed of buildVector() and buildList() using "Timing.cpp"

**********************************************************************************************************************

Q3 (Zexian Lin):  
"Sorting.h"
3. Create a sort for 2d matrices.Do a bubble sort, insertion sort, and selection sort
variation of this.

For sorting in the 2d matices, we need to pay attention to the indexing. 
Let say we have a 2d matrix with i rows and j column.
When we traverse from one row to its second row, i needs to starting from 0, j only needs to plus 1.
To solve the problem, we use the following strategy:
Given a matrix[3][3] = {{0,1,2},{3,4,5},{6,7,8}}
Known 5 is the 5th element in the matrix.(starting from index 0)
5 / row_size ==> 5/3 = 1 
5 mod row_size ==> 5 mod 3 = 2
 matrix[1][2] --> the indexing of 5 in the matrix
**********************************************************************************************************************

Q6 (Zexian Lin): 
"VigenereCipher.h"
6. We have received a secret message encoded with a Vigenere cipher(wiki).We know
that the key is 32 digits longand a brute force attack would take us a long time(see
here).We do not know any “tricks” how to break a Vigenere cipher, but we do know how
it works.Instead we are going to test random possible solutionsand use a feature
function to evaluate the possible solution.We will collect solutions that pass a certain
thresholdand mutate those solutions with some low probability, hopefully getting closer
to the ‘true solution”.We will also use recombination(see here), with some low
probability, continually increasing our threshold as we narrow in on a solution.Create a
program that does this, paying special attention to the data structure you wish to
manage your possible solutions.

For this question, we use a pre-defined dictionary corncob_lowercase, which contains about 58000 English words.
In addition, we use 9 txt files which contains the first 2 -10 characters from the dictionary, which will
be used to tested if a string is a word that appears in the dictionary.
The algorithm as follows:
1.Given a specific message, we generate a 32 bit random key.
2.Using decoder() to decode the message by Vigenere cipher.
 decrypted char = (encrypted char - key char + 26) % 26 + 'a' (we want the decrypted message to be lowercase letters).
3.Test how many words are appear in the decrypted. test() return a int matching_char, which indicates how 
 many characters can be used to form a word. The larger the returned value, the more accurate the 
 decrypted message is.
 Inside the test():
 we are going to use 2-10 character set to test if a substring is a word.
 let say a substring "ca" is in the two_char set, we add one more char to the substring from the encrypted
 message, assume it is "cat", then we test if it is in the three_char set...
 we keep testing the substring until it is not in the 2 -10 char_set.
 If a string of size 5 is not in the five_char set, then the first 4 char could be a valid word since we 
 test for the four_char set before.
 Once we find a valid word, we print out the valid word and add up the length of the valid word.
 In this way, we can keep track of how close we are to the orginal text.
4.Since the key is randomly generated, we don't know how long it will take a generate a reasonable key.
 Therefore, when we test it in the main function, the user have an option to choose whether to run the 
 program continuely when the matching_char is exceed 16.
**********************************************************************************************************************


Q8 (Zexian Lin):
"AddToS.h"
8. Create a templated class that effectively finds all possibilities of a list of random numbers
that adds to some s.

The following template only considers the numbers within 32 digits. Otherwise, it will cause overflow.
The algothrism for sovling this question is: 
1.We turn the index of the num list into binary number.
2.For the binary number, we find out positions that have 1's, 
 and find the corresponding index in the num list, add the nums[ corresponding index ] to a list.
3.If the sum of nums[ corresponding index ] == target, we save the list to the result.
Notice: since this is a template, we need to consider the case when we compare two floats or double.
As long as the difference between two float(double) is smaller enough, we consider they are equal.
**********************************************************************************************************************

Q9 (Zexian Lin):
"DeBruijnSequence.h"
9. Create a random array of size k.Create a function to check if it is a deBruijn
sequence of B(n, k).If it is not randomly mutate each spot in the array(from a 0 to 1 or 1 to 0)
with a 5 % probability, keep doing this until you have found a deBruijn sequence.
Do this with an array structureand a linked structure.
To this 100 times for each, time itand compare your results.

For this question, We aware that a DeBruijn Sequence if order n in a size k is a
cyclic sequence in which every possible length - n string occurs exactly once as
a substring.We denoted B(k, n).

To detect if a sequence is a DeBruijn Sequence, we will use a unordered_set to
keep track of the substring.If every substring appears only once, then we
successfully find the sequence.Otherwise, return false.

To mutate the sequence, we need to make sure that every element in the array /
linked list only has 5 % probability to change its value(from 0 -> 1 or 1 -> 0).

Besides detecting and mutating, we have another function called testing, which
will generate a random array / linked list that filled with '0's and '1's.Then
we will test the randomly array / linked list to see if it is a De Bruijn sequence.
If not, we keep calling the mutate function until the sequence becomes a De Bruijn
sequence.

We will use array strustureand linked list strusture for this question.For array,
it is straightforward.We will use the default substr method to construct the substring.
Notice at the end of the array, the substring needs to include index(0 - substring_size).
We will use mod to achieve this.

Linked list is different from array.First, it doesn't have the indexing, so we need 
to keep track of the number of the Nodes.Besides, we want our linked list become a
circular linked list in order to keep tracker of the substring.Array doesn't have 
circular array, but for linked list, we can construct a circular linked list when we
are testing.
