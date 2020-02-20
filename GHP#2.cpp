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
	Language:		C++ (run in gaben)
	Date Submitted:	9/28/18
	Class: 			CS 240-01
	Professor:		Ronald Sarner
************************************************************************************************/
#include <iostream>
using namespace std;

int magic[5][5]; //while saying the name of this matrix, jazz hands are a requirement
				 //the sides of this matrix must be equal, and odd
const int n = 5; //n must equal the size of one side of the matrix


/************************************************************************************************
		Function main, This function begins by setting the starting point int the matrix at 
	0,(n/2) where n is the size of a side of the matrix. The function then moves on to a for 
	loop in which it begins to fill the matrix in a manner htat will make it a magic square.
	it does this by going through numerous checks using coordinates r and c, representing the 
	current row and column which was just filled. These checks basically try to see if the next
	square, generally shown by r-1 and c+1, is still empty, which is shown by it being occupied
	by a zero, which it was filled with beforehand. If the matrix cannot execute r-1, or c+1, it
	will jump to the opposite edge using r+(n-1) or c-(n-1). if the spot is already occupied it
	will try to use r+1, however if it cannot execute that due to being on an edge, it uses 
	r-(n-1).
	
	
	Name: 			Douglas Brock
	Language:		C++ (run in gaben)
	Date Submitted:	9/28/18
	Class: 			CS 240-01
	Professor:		Ronald Sarner
************************************************************************************************/
int main(){
	int r = 0, c = n/2;
	for(int a = 0; a < n; a++){
		for(int b = 0; b < n; b++){
			magic[a][b] = 0;
		}
	}	
	for(int i = 0; i < (n*n); i++){
		magic[r][c] = (i+1);
		if(r==0){
			if(c==(n-1)){
				if(magic[r+(n-1)][c-(n-1)]==0){
					r+=(n-1);
					c-=(n-1);
				}else{
					r+=1;
				}	
			}else{
				if(magic[r+(n-1)][c+1]==0){
					r+=(n-1);
					c+=1;
				}else{
					r+=1;
				}
			}	
		}else{
			if(c==(n-1)){
				if(magic[r-1][c-(n-1)]==0){
					r-=1;
					c-=(n-1);
				}else{
					if(r == n-1){
						r-=(n-1);
					}else{
						r+=1;
					}	
				}	
			}else{
				if(magic[r-1][c+1]==0){
					r-=1;
					c+=1;
				}else{
					if(r == n-1){
						r-=(n-1);
					}else{
						r+=1;
					}	
				}
			}
		}
	}
	cout << "Magic square, side size: "<< n << endl;
	for(int f = 0; f < n; f++){
		for(int g = 0; g < n; g++){
			cout << magic[f][g] << "\t";
		}
		cout << endl << endl;
	}
	return 0;
}
