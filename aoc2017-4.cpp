#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("2017-4.txt");
	vector<vector <string> > inputList;

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

	int valid = 0;

	for(auto line : inputList){
		bool lineValid = true;
		for(int i = 0; i < line.size() - 1; i++){
			for(int j = i + 1; j < line.size(); j++){
				if(line[i] == line[j]){
					lineValid = false;
				}
			}
		}
		if(lineValid){
			valid++;
		}
	}

	cout << valid << endl;

	return 0;
}
