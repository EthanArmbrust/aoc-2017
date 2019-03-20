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
		auto min = min_element(line.begin(), line.end());
		auto max = max_element(line.begin(), line.end());
		cout << *min << endl;
		cout << *max << "\n" << endl;
		sum += (*max - *min);
	}

	cout << sum << endl;
		

	return 0;
}
