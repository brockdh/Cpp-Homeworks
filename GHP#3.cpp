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
	Language:		C++ (Run in Gaben)
	Date Submitted:	9/11/18
	Class: 			CS 240-01
	Professor:		Ronald Sarner
************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdio>
using namespace std;
/************************************************************************************************
		The main function sets a counter for the number of words beginning with the letter
	D. Then it asks the user for the name of a file. The user will input the file name, and
	the program will look for the file. When the file has been found, the program will then
	start to go through the file checking for words that start with D, regardless of case
	after spaces, quotation marks, new lines, and spaces that are after quotation marks,
	along with new lines that are after quotation marks. Each time it finds a word starting
	in D, it increments the counter. Then main outputs the number of words it counted.
************************************************************************************************/
int main(){
	string FileName; 
	ifstream fileIn;
	char ch;
	int dCount = 0;
	string s;
	cout << "Please input a file name: ";
	cin >> FileName;
	fileIn.open(FileName.data());
	assert(fileIn.is_open());
	int i = 0;
	while(!(fileIn.eof())){
		ch = fileIn.get();
		s.insert(i, 1, ch);
		i++;
	}
	for(int j = 0; j < s.length(); j++){
		if(j == 0&&(s[j] == 'd' || s[j] == 'D')){
			dCount++;
		}
		if(s[j] == ' '||s[j] == '\n'){
			j++;
			if(s[j] == '"'){
				j++;
				if(s[j] == 'd'||s[j] == 'D'){
					dCount++;
				}
			}
			if(s[j] == 'd'||s[j] == 'D'){
				dCount++;
			}
		}else if(s[j] == '"'){
			j++;
			if(s[j] == ' '||s[j] == '\n'){
				j++;
				if(s[j] == 'd'||s[j] == 'D'){
					dCount++;
				}	
			}
		}
		
	}
	cout << "The number of words in the file that start with the letter d, is " << dCount << endl;
}