/************************************************************************************************
		This code is written as homework for CS240-01 At Suny Polytechnic Institute during
	Fall 2018. The code was designed and written by Douglas Brock as should be stated below,
	with the exception of any code that may have been given as part of the assignment for the
	homework. If there is any code taken from another source, or based on that of another
	source, it will be marked in comments below, near the code, giving credit to the original
	creator. Once again the code in this program was made by, and for the sole use of the 
	creator of it Douglas Brock. If this code is being submitted by another person it was 
	without his knowledge, and he will not claim responsibility for the unauthorized use of 
	his code.
	
	Name: 			Douglas Brock
	Language:		C++ (run in gaben server)
	Date Submitted:	11/2/18
	Class: 			CS 240-01
	Professor:		Ronald Sarner
************************************************************************************************/
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
/************************************************************************************************
		What main does, is it asks for a word from the user to see if it's a palindrome.
	Main then proceeds to put the word into both a stack and a queue. Main then proceeds
	to go through half of the word from both the stack and the queue, checking the individual
	characters. If any of the characters are not matching as they are removed from both the 
	stack and the queue simultaneously, then it will set the palindrome boolean to false.
	Then main will output the result.
	
	Language:		C++ (run in gaben server)
************************************************************************************************/
int main(){
	stack <char> s;
	queue <char> q;
	string word;
	bool palindrome = true;
	
	cout << "Enter a word to see if it's a palindrome:" << endl;
	cin >> word;
	
	for(int i = 0; i < word.length(); i++){
		s.push(word.at(i));
		q.push(word.at(i));
	}
	
	for(int i = 0;(i < (word.length()/2)) && (palindrome == true); i++){
		if(s.top() != q.front()){
			palindrome = false;
		}
		s.pop();
		q.pop();
	}
	
	if(palindrome){
		cout << endl << word << " is a palindrome" << endl;
	}else{
		cout << endl << word << " is not a palindrome" << endl;
	}	
	return 0;
}