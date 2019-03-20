#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int input = 265149;
	
	int n = 1;

	while(n*n < input){
		n += 2;
		cout << n*n << endl;
	}
	cout << "n is " << n << endl;
	cout << "bottom row is from " << ((n*n) - n) + 1 << " to " << n*n << endl;

	int oneRow = (n / 2) + 1;

	cout << "row with one: " << oneRow << endl;
	
	int distance = n - ((n*n) - input);

	//cout << distance << endl;

	int xdis = n - oneRow;
	int ydis = distance - oneRow;

	cout << xdis + ydis << endl;

	return 0;
}
