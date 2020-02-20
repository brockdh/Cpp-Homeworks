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
using namespace std;

#include "Stack.cpp"
/************************************************************************************************
		The point of main is to take a number, which a user inputs, and factorize it. As main
	gets the factors for the number, from lowest to highest, it puts them into a stack. When
	main has determined that the number has been fully factorized, it outputs the numbers in
	the stack which will be from highest to lowest.

	Name: 			Douglas Brock
	Language:		C++ (run in gaben server)
	Date Submitted:	11/2/18
	Class: 			CS 240-01
	Professor:		Ronald Sarner
************************************************************************************************/
int main(){
	int factorizeNum;
	Stack factors;
	cout << endl << "Please input a positive integer to factorize:" << endl;
	cin >> factorizeNum;
	int n = factorizeNum;
	for(int i = 2; i <= n; i++){  	//This should skip over any numbers that aren't primes
		if(n%i == 0){  				//by the time it gets to them, because their own factors
			factors.push(i);  		//will have been taken care of
			n /= i;
			i = 1;
		}
	}
	cout << factorizeNum << " factorized is:" << endl;
	while(!factors.empty()){
		cout << factors.top() << " ";
		factors.pop();
	}
	cout << endl;
	return 0;
}