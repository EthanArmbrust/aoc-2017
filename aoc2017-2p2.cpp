#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("2017-2.txt");
	vector<vector <int> > inputList;

	string s;
	while(getline(infile,s)){

		vector<int> lineData;
		stringstream lineStream(s);

		int value;

		while(lineStream >> value){
			lineData.push_back(value);
		}
		inputList.push_back(lineData);
	}

	int sum = 0;

	for(auto line : inputList){
		for(int i = 0; i < line.size(); i++){
			for(int j = 0; j < line.size(); j++){
				if(line[i] % line[j] == 0 && line[i] != line[j]){
					sum += line[i] / line[j];
				}
			}
		}
	}

	cout << sum << endl;
		

	return 0;
}
