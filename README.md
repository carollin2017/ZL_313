# ZL_313
Group 4:

Lin,Zexian

Lopez,Kirk

Maqsood,Hasnain

Mina,Luis

Mistry,Jay

To run the Q1, 3, 6, 8, 9, you need to look at Qi_main() in the CS313_hw1_Zexian_lin.cpp file and uncomment the corresponding problems
you wish to test.

Q2, 4, 5, 7, 10 will be txt files which contains the cpp program. You can run them individually. 

Q8 has two solutions that are come from Zexian and Luis respectively. 

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
Q2 Kirk Lopez									

2. Test whether a recursive, iterative or linked-type binary search is faster by testing it on
arrays of size 1 million, 10 million, and 100 million with arrays that are filled with random
numbers going from smallest to largest.


Attacking this problem, I decided to make the algorithms for the recursive and iterative search first. I have seen it before, so it was not hard to understand when looking it up. The recursion algorithm has 4 parameters to pass, the array, start of the array, end of the array, and the element we are searching for. Since we are going to use the function to adjust the side that will be searched, we need them in the parameters. We first get the middle index of the array which we use the start + end and we divide that answer by 2. From there we check if the array at that index is our element. If so, we return the index. If not, we go down to the if statements and we check to see what side of the array we will check next. If the element is less than the mid then we call the function again, but we change the end index of the array to be the mid-1. If its greater than we make the start mid+1. We run this function till we get the array[mid] to equal the element. If it does not exist, then the function returns -1.


The iterative solution is nearly identical to the recursive, but we have less parameters and we only call the function once. We must create the start and end variables in the function to change where we are going to check in the array. From there a while loop will keep going while start is less than or equal to end. We get the mid index and do the same as the recursion by checking the if array[mid] is greater than or less than the element and changing the start and end variables accordingly.


Linked binary search was tricky. I easily made the classes to handle the linked list but how to get the mid value in the list was not easy. After a bit of searching I got a neat solution. We have a function that works the same as the others. It checks the mid object data to see if it equals the element and it has if statements with greater than and less than the element to see which side of the list to check next. To find the mid a function with two pointers were used to go through the array along with 2 other pointers to keep track of the side of the array we are checking. A fast-moving pointer and a slow pointer that goes through the array till the end. The fast pointer moves twice as fast as the slow. When the fast pointer reaches the end the slow should be at the middle of the array since its moving half as fast. From there the slow pointer is returned and checked trough the if statements. From there the two pointers holding the position in the array are adjusted to the side that we need to check next.


Finally, the final part of the program was a sort to make our random array in ascending order. I tried a bubble sort from another question, but it takes too long and caused some issues with the array size. From there I decided to use quick sort which I read was fast. From there I just needed to code the quick sort algorithm which splits the array into two sides and swaps values from the array that are less than a pivot point (middle value) and moves the values less than the pivot to the left and the values greater than the pivot to the right. From there the array is divided again into 2 and the program sorts that again. Toke a sort (bubble) which toke a minute or 2 and completed it in less than 30 sec.
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
Q4 Kirk Lopez									

4. Compare the times it takes to sort a random array vs a linked list with a bubble sort.

Bubble sort was a new sort for me. I have heard of it but never coded it myself. I seemed simple enough but as the values got bigger the sort toke a long time to complete.

The code was straight forward for an array. We go through the array checking to see if the position we are at is greater than the position+1. If so, we swap those values. We continue this down the line till we reach then end with the biggest value in the array. 
I used a while loop with a bool variable, called sorted, that checks if it is false. If so, the loop continues. The next line changes sorted to true. In the for loop there is an if statement that checks the position is greater than position+1. If that if statement is used the sorted is changed to false and the while loop will continue. Once the for loop can go through the array and never trigger the if statement then sorted ends as true and the array is sorted. 

The linked list required me to create my own class. I kept it bare since I did not need everything it had to offer. The bubble sort is the same, but it required a few tricks to swap out the node. I used a trailing pointer to stay one node back of the current pointer. A while loop like the array bubble sort kept going till bool sorted returned true. If a value less than current is found, then a temp pointer is used to hold the next object. The trailer.next points to temp, current.next points to temp.next. This moves the position+1 object to position. From there current will equal temp, trailer equal current and current equal current.next. Position is now in front of position+1 and the links are back in order. Sorted becomes false and the loop runs again. If position is less than position+1 then the pointers just move down the list. Doing the swap this way keeps our object data consistent and isn’t changed in the process.

Lastly the main just creates the array with random objects and times the two searches. It prints the results to console so you can see the speed of one to the other

**********************************************************************************************************************
Q5 Jay Mistry

Q5) Create a multi-level sort. For instance, for all selections of n > 10 you do sort X and
within sort X, when you have a situation with n < 10 you do sort Y. Be creative. Time
your sort against two “reasonably comparable” sorts (you may use libraries for the
“reasonably comparable sorts”).

- MultiSort :- A Function which takes an array and splits into two parts i.e one part has elements > 10 and one has elements < 10. Then it stores the two parts into  two different temp arrays. These temp arrays used two sort functions to sort the elements. After sorting, the temp arrays are merged into one array and printed.

- SelectionSort :- A function used to sort the elements of the array with total elements <= 10.

- InsertionSort :- A function used to sort the elements of the array with total elements > 10.

- Main :- Creates an array of size 22. Then the array is filled with random numbers between 1-99. We pass this array through the Multisort function which prints the sorted array.
**********************************************************************************************************************
Q6 (Zexian Lin):

ichar.txt (i from 2-10) and corncob_lowercase.txt are necessary for this question. 
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
Maqsood Hasnain

Q7:

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
**********************************************************************************************************************
Maqsood Hasnain

Q10) create a linked list and fill with numbers 1 to k,then create a function that
sorts the list so that first all odd numbers are listed and then all even numbers.
Some conditions that were taken by the question:
1. create linked list
2. fill with numbers
3. create a sort function

addlist function: function in which when 
called will take the inputted number and insert
it after the head node which is a nullptr

printlist function : the generic function of printing a linked list from couting
the info and then continuing on to the next node via current=current->link

changeEvenToOdd: function that works multiple checks to make sure
that the odd number of elements are moved to the back and in the same order
and then checks to make sure those even nodes are push to the front in the
same order

Main: initiated a linked list and filled it with 10 numbers 1-10 and
then print out the list when the list is printed the next function is
the changeEventoOdd function which would switch around the nodes from
the beginning becoming even nodes and the ending become odd nodes, then
proceed to print out the same list after the function is processed and 
show the changing of the even to odd nodes
