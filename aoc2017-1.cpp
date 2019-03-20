#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("2017-1.txt");
	vector<int> inputList;

	string s;
	getline(infile,s);

	for(char num : s){
		inputList.push_back(num - 48);
	}

	int answer = 0;
		
	for(int i = 0; i < inputList.size() - 1; i++){
		if(inputList[i] == inputList[i+1]){
			answer += inputList[i];
		}
	}

	if(inputList[inputList.size() - 1] == inputList[0]){
		answer += inputList[0];
	}

	cout << answer << endl;
		

	return 0;
}
