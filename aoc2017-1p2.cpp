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
	int size = inputList.size();
		
	for(int i = 0; i < inputList.size(); i++){
		if(inputList[i] == inputList[((i+(size/2)) % size)]){
			answer += inputList[i];
		}
	}

	cout << answer << endl;
		

	return 0;
}
