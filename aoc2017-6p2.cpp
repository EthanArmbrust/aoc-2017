#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("2017-6.txt");
	vector<int> inputList;
	vector<string> states;

	string s;
	getline(infile,s);

	stringstream lineStream(s);

	string value;

	while(lineStream >> value){
		inputList.push_back(stoi(value));
	}

	int bc = inputList.size();

	string state;
	for(auto block : inputList){
		state += to_string(block);
		state += "."; //must seperate
	}
	//cout << state << endl;

	states.push_back(state);

	int steps = 0;



	while(true){
		//find largest block
		//distribute to all other blocks one by one
		//write config to string
		steps++;
		auto max = max_element(inputList.begin(), inputList.end());
		int blockValue = *max;
		int blockPos = distance(inputList.begin(), max);

		inputList[blockPos] = 0;
		
		for(int i = 0; i < blockValue; i++){
			//cout << "incrementing postion " << (i + blockPos + 1) % bc << endl; 
			inputList[(i + blockPos + 1) % bc]++;
		}

		string s;
		for(auto block : inputList){
			s += to_string(block);
			s += "."; //must seperate
		}
		//cout << s << endl;
		for(int i = 0; i < states.size(); i++){
		//for(auto str : states){
			string str = states[i];
			if(s == str){
				cout << steps - i << endl;
				return 0;
			}
		}
		states.push_back(s);
	}

	return 0;
}
