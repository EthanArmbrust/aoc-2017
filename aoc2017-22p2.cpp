#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Direction {_up, _right, _down, _left};

int main(){

	ifstream infile("2017-22.txt");
    vector<string> inputList;
	
    //parse	
	string s;
	while(getline(infile,s)){
        inputList.push_back(s);
	}

	int row = inputList.size() / 2;
	int col = inputList[0].length() / 2;

	int dir = _up;
	int infections = 0;
	
	for(int i = 0; i < 10000000; i++){
		//determine new direction
		if(inputList[row][col] == '#'){
			dir = (dir + 1) % 4;
			inputList[row][col] = 'F';
		}
		else if(inputList[row][col] == '.'){
			dir = (dir + 3) % 4;
			inputList[row][col] = 'W';
		}
		else if(inputList[row][col] == 'W'){
			inputList[row][col] = '#';
			infections++;
		}
		else if(inputList[row][col] == 'F'){
			dir = (dir + 2) % 4;
			inputList[row][col] = '.';
		}

		if(dir == _up){
			row--;
		}
		if(dir == _down){
			row++;
		}
		if(dir == _right){
			col++;
		}
		if(dir == _left){
			col--;
		}

		if(row < 0 || col < 0 || row >= inputList.size() || col >= inputList[0].length()){
			int padAmount = 5;
			int currentLength = inputList[0].length();
			string blank(currentLength + (2 * padAmount), '.');
			string ends(padAmount, '.');
			for(int j = 0; j < padAmount; j++){
				inputList.insert(inputList.begin(), blank);
				inputList.push_back(blank);
			}
			for(int j = padAmount; j < inputList.size() - padAmount; j++){
				inputList[j] = ends + inputList[j] + ends; 
			}
			row += padAmount;
			col += padAmount;
		}
	}
	cout << infections << endl;
	return 0;
}	
