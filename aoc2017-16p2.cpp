#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> inputList;
vector<char> dl;
void dance();

int main(){

	ifstream infile("2017-16.txt");

	string s;
	getline(infile,s);
	stringstream lineStream(s);



	while(lineStream.good()){
		string value;
		getline(lineStream, value, ',');
		inputList.push_back(value);
	}

	for(char ch = 'a'; ch <= 'p'; ch++){
		dl.push_back(ch);
	}


	vector<string> perms;

	for(int i = 0; i < 5460; i++){  //find cycle. 5460 found by smart people on reddit
		dance();
		string temp;
		for(char ch : dl){
			temp += ch;
		}
		perms.push_back(temp);	
	}
	
	bool foundLoop = false;
	int loopStart = -1;
	int loopRepeat = -1;

	for(int i = 0; i < perms.size(); i++){
		auto dupe = find(perms.begin() + i + 1, perms.end(), perms[i]);
		if(dupe != perms.end() && !foundLoop){
			foundLoop = true;
			loopStart = i;
			loopRepeat = dupe - perms.begin();
			cout << "FOUND DUPE AT " << i << " AND " << dupe - perms.begin() << endl;
			break;
		}
	}

	//loop start = 0;
	//loop repeat = 63;
	//
	int loopSize = loopRepeat - loopStart;

	int remaining = 1000000000 % loopSize;

	//reset line
	dl.clear();
	for(char ch = 'a'; ch <= 'p'; ch++){
		dl.push_back(ch);
	}

	for(int i = 0; i < loopStart; i++){
		dance();
	}

	for(int i = 0; i < remaining; i++){
		dance();
	}

	for(char ch : dl){
		cout << ch;
	}
	cout << "\n";

	return 0;
}

void dance(){
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
}
