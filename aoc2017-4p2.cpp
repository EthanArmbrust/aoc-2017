#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("2017-5.txt");
	vector<int> inputList;

	string s;
	while(getline(infile,s)){
		inputList.push_back(stoi(s));
	}

	cout << inputList[0] + inputList[1] << endl;

	return 0;
}
