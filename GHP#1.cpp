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
	Language:		C++
	Date Submitted:	9/11/18
	Class: 			CS 240-01
	Professor:		Ronald Sarner
************************************************************************************************/

#include <iostream>
using namespace std;

int mat[10][10];		//declares matrix size
const int n = 10;		//Sets a permamnent number for n

int find(int item){						//searches linearly through matrix to find
	bool found = false;					//integer of value equal to item. Then will
	for (int row=0; row<n; row++){				//print the result
		for (int col=0; col<n; col++){
			if (mat[row][col]==item){
				found=true;
			}else if(!found){
			  found=false;
			}
		}
	}
	if (found){
		cout<<"\nitem found\n";
	}else{
		cout<<"\nitem not found\n";
	}
	return 0;
}

int main(void){
	int item;							//Presets item
	for(int i = 0; i < n; i++){			//Two for loops with a bit of
		for(int j = 0; j < n; j++){		//calculations to fill matrix 
			mat[i][j] = ((10*i)+(1+j));	//with numbers 1 to 100
		}
	}
	cout<<"please input a positive integer (decimals will be rounded down): "; //asks user for input
	cin>>item;							//assign user input to item
	if(item<1){							//determines validity of input
		cout<<"\n input is invalid\n";
	}else{								//if valid, executes function find
		find(item);
	}
	return 0;
}
