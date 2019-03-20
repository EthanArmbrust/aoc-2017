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

	int bottom = 0;
	int top = inputList.size() - 1;

	int cursor = 0;
	int steps = 0;

	while(cursor >= bottom && cursor <= top){
		int instruction = inputList[cursor];
		if(instruction < 3){
			inputList[cursor]++;
		}
		else{
			inputList[cursor]--;
		}
		cursor += instruction;
		steps++;
	}

	cout << steps << endl;

	return 0;
}
