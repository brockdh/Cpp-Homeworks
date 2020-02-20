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
#include <numeric>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

/************************************************************************************************
		This function, average, is meant to find the average of values stored in an int vector.
	The value uses temp, which is initialized at zero, to store the accumulation of the values
	within the vector. Then the function divides the temp by the size of the vector. temp is
	then returned.
	
	Language:		C++ (run in gaben server)
************************************************************************************************/
int average(vector<int> v){
	int temp = 0;
	if(!v.empty()){
		temp = accumulate(v.begin(), v.end(),temp);
		temp /= v.size();
	}else{
		cout << "cannot read from file not containing data" << endl;
	}
	return temp;
}

/************************************************************************************************
		This function, prodLevelChanges, finds the changes in the values of a vector from entry
	to entry. These values are stored in their own vector. Then the function outputs a well
	organized grid displaying the index of the entries, matched up with the values from the 
	original vector, and the new vectors values that show the changes from the original vectors
	current value, with the previous value. The previous value from the first value is assumed
	to be 0. Then function then returns 0 when it succesfully completes.
	
	Language:		C++ (run in gaben server)
************************************************************************************************/
int prodLevelChanges(vector<int> v){
	int days[(int) v.size()];
	int levelChanges[(int) v.size()];
	adjacent_difference(v.begin(),v.end(),levelChanges);
	cout << "Day:" << "\t\t";
	for(int i = 0; i < (int) v.size(); i++){
		cout << "\t" << days[i];
	}
	cout << endl;
	cout << "Production Level:" << "\t\t";
	for(int i = 0; i < (int) v.size(); i++){
		cout << "\t" << v[i];
	}
	cout << endl;
	cout << "Production Level Change:";
	for(int i = 0; i < levelChanges.size(); i++){
		cout << "\t" << levelChanges[i];
	}
	cout << endl;
	return 0;
}

/************************************************************************************************
		This function, totalLevels, takes a vector of integers, and goes through it, putting the
	accumulation of all values from the begining, to the current entry into the corresponding
	entry of a new vector. total Levels then displays the new vector, showing the accumulation
	of values entry by entry.
	
	Language:		C++ (run in gaben server)
************************************************************************************************/
int totalLevels(vector<int> v){
	int totals[(int) v.size()];
	partial_sum(v.begin(),v.end(),totals);
	cout << "Totals up to day:" << "\t";
	for(int i = 0; i < v.size(); i++){
		cout << "\t" << totals[i];
	}
	cout << endl;
	return 0;
}

/************************************************************************************************
		Main is the base function of this program. Main initializes an int vector, along with
	four different integers. these integers will be used to store and average, a highest value,
	a lowest value, and one to be used to fill the vector. The vector is filled with user input
	and then sent to different functions in order to fill the other integers with their
	respective values, which are then output for the user to see. Then the vector is sent to more 
	functions to output specific information from the vector which is shown in the specific 
	functions. Main will return 0 when it succesfully completes.
	
	Language:		C++ (run in gaben server)
************************************************************************************************/
int main(){
	vector <int>  prodLevels{};
	int n;
	int avg;
	
	cout << "Input the production levels for each day in a four week period, for five work days, one at a time: " << endl;
	for(int i = 0; i < 20; i++){
		cin >> n;
		prodLevels.push_back(n);
	}
	avg = average(prodLevels);
	cout << "The highest production level for a single day is " << max_element(prodLevels.begin(), prodLevels.end()) << endl;
	cout << "The lowest production level for a single day is " << min_element(prodLevels.begin(), prodLevels.end()) << endl;
	cout << "The average production level for a single day is " << avg << endl;
	prodLevelChanges(prodLevels);
	totalLevels(prodLevels);
	return 0;
}