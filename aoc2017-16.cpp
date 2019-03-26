#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

	ifstream infile("2017-16.txt");
	vector<string> inputList;

	string s;
	getline(infile,s);
	stringstream lineStream(s);


	while(lineStream.good()){
		string value;
		getline(lineStream, value, ',');
		inputList.push_back(value);
	}

	vector<char> dl;
	for(char ch = 'a'; ch <= 'p'; ch++){
		dl.push_back(ch);
	}

	for(string move : inputList){
		if(move[0] == 's'){
			int r_amount = stoi(move.substr(1));
			r_amount = dl.size() - r_amount;
			rotate(dl.begin(), dl.begin() + r_amount, dl.end());
		}
		if(move[0] == 'x'){
			string del = "/";
			string original = move.substr(1);
			auto it = original.find(del);
			string first = original.substr(0, it);
			string second = original.substr(it + 1);
			int f = stoi(first);
			int s = stoi(second);
			iter_swap(dl.begin() + f, dl.begin() + s);
		}
		if(move[0] == 'p'){
			char first = move[1];
			char second = move[3];

			auto it_f = find(dl.begin(), dl.end(), first);
			auto it_s = find(dl.begin(), dl.end(), second);
			iter_swap(it_f, it_s);
		}
	}

	for(auto ch : dl){
		cout << ch;
	}
	cout << "\n";


	return 0;
}

