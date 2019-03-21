#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

	vector< vector<string> > inputList;

	ifstream infile("2017-8.txt");

	map<string, int> registerList;

	string s;
	while(getline(infile,s)){

		vector<string> lineData;
		stringstream lineStream(s);

		string value;

		while(lineStream >> value){
			lineData.push_back(value);
		}
		inputList.push_back(lineData);
	}

	for(auto ins : inputList){
		registerList[ins[4]] = 0;
	}

	for (auto ins : inputList){
		string reg = ins[0];
		string target = ins[4];
		int amount = stoi(ins[2]);
		bool inc = "inc" == ins[1];
		int value = stoi(ins[6]);


		int targetValue = registerList.at(target);

		string condition = ins[5];

		int icondition = 0;

		if(condition == ">"){
			icondition = 1;
		}
		if(condition == "<"){
			icondition = 2;
		}
		if(condition == ">="){
			icondition = 3;
		}
		if(condition == "<="){
			icondition = 4;
		}
		if(condition == "=="){
			icondition = 5;
		}
		if(condition == "!="){
			icondition = 6;
		}

		switch(icondition){
			case 1 : 
				if(targetValue > value){
					if(inc){
						registerList[reg] += amount; 
					}
					else{
						registerList[reg] -= amount;
					}
				}
				break;
			case 2 : 
				if(targetValue < value){
					if(inc){
						registerList[reg] += amount; 
					}
					else{
						registerList[reg] -= amount;
					}
				}
				break;
			case 3 : 
				if(targetValue >= value){
					if(inc){
						registerList[reg] += amount; 
					}
					else{
						registerList[reg] -= amount;
					}
				}
				break;
			case 4 : 
				if(targetValue <= value){
					if(inc){
						registerList[reg] += amount; 
					}
					else{
						registerList[reg] -= amount;
					}
				}
				break;
			case 5 : 
				if(targetValue == value){
					if(inc){
						registerList[reg] += amount; 
					}
					else{
						registerList[reg] -= amount;
					}
				}
				break;
			case 6 : 
				if(targetValue != value){
					if(inc){
						registerList[reg] += amount; 
					}
					else{
						registerList[reg] -= amount;
					}
				}
				break;
		}
		

	}

	int maxval = 0;

	for(auto const & mk : registerList){
		if(maxval < mk.second){
			maxval = mk.second;
		}
	}

	cout << maxval << endl;

	return 0;
}

