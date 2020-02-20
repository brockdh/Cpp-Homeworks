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
#include <string>
using namespace std;

/************************************************************************************************
		This is a class that creates a hash array for strings. The class immediately fills the
	hash array with "null" when created. The class has two functions, insert, and display. The
	insert function takes a string, and puts it into the array based on the equation used:
	
	((first_letter) + (last_letter)) % 23
	
	if there is a collision it moves to the next space in the array. The display fucntion just
	goes through the array displaying the contents.
	
************************************************************************************************/
class StringHash{
	public:
	
	string hashes[23];
	
	StringHash(){
		for(int i = 0; i < 23; i++){
			hashes[i] = "null";
		}
	}
			
	void insert(string s){
		int temp;
		bool in = false;
		temp = ((((int) s[0]) + ((int) s[1]))%23);
		while(!in){	
			if(hashes[temp] == "null"){
				hashes[temp] = s;
				in = true;
			}else{
				if(temp == 22){
					temp = 0;
				}else{
					temp++;
				}	
			}	
		}		
	}
	void display(){
		for(int i = 0; i < 23; i++){
			cout << hashes[i] << "\t";
		}
		cout << endl;
	}
	bool find(string s){
		int temp;
		bool found = false;
		temp = ((((int) s[0]) + ((int) s[1]))%23);
		for(int i = 0; (i < 23 && !found); i++){	
			if(hashes[temp] != s){
				if(temp == 22){
					temp = 0;
				}else{
					temp++;
				}
			}else{
				found = true;	
			}	
		}
		return found;
	}
};
/************************************************************************************************
		Main is a rather simple function. It queries the user for a word, until the user stops
	the query. As the words are put in, they are sent to the hash that is established. Lastly
	main calls the display function in the hash.
************************************************************************************************/
int main(){
	string s;
	StringHash strings;
	bool finished = false;
	int i = 0;
	while(!finished){
		cout << "Please input a word (input \"done\" to stop) (15 words have been put in for done to be an exit word):" << endl;
		cin >> s;
		cout << endl;
		if(s == "done" && i >= 15){
			finished = true;
		}else{
			strings.insert(s);
		}
		i++;
	}
	strings.display();
	finished = false;
	while(!finished){
		cout << "Please input a word to find it (input \"done\" to stop):" << endl;
		cin >> s;
		cout << endl;
		if(s == "done"){
			finished = true;
		}else{
			if(strings.find(s)){
				cout << "the word has been found" << endl;
			}else{
				cout << "the word has not been found" << endl;
			}
		}
	}
	return 0;
}