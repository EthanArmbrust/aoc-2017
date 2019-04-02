#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

vector<vector<char>> flip(vector<vector<char>> canvas, bool vertical);
vector<vector<char>> rotate(vector<vector<char>> canvas, bool clockwise);

int main(){

	//ifstream infile("2017-21.txt");

	/*
	
	//god awful parsing
	string s;
	while(getline(infile,s)){
		vector<string> line;
		stringstream ss(s);
		string word;
		while(ss >> word){
			word = word.substr(3);
			while(word[word.length() - 1] == '>' || word[word.length() - 1] == ','){
				word.pop_back();
			}
			line.push_back(word);
		}
		vector<vector<long>> particle;
		for(int i = 0; i < line.size(); i++){
			string thisLine = line[i];
			replace(thisLine.begin(), thisLine.end(), ',', ' ');
			stringstream stream(thisLine);
			int l;
			vector<long> xyz;
			string token;
			while(getline(stream, token, ' ')){
				l = stoi(token);
				xyz.push_back(l);
			}
			particle.push_back(xyz);
		}
		master.push_back(particle);
	}
	*/

	vector<vector<char>> canvas;
	vector<vector<char>> small;

	small.push_back({'.','#'});
	small.push_back({'.','.'});

	canvas.push_back({'.','#','.'});
	canvas.push_back({'.','.','#'});
	canvas.push_back({'#','#','#'});

	auto flipped = rotate(canvas, true);
	auto flippedSmall = rotate(small, true);
	flippedSmall = rotate(flippedSmall, true);

	for(auto line : flipped){
		for(char c : line){
			cout << c;
		}
		cout << "\n";
	}
	cout << "\n----\n";

	flipped = rotate(canvas, false);

	for(auto line : flipped){
		for(char c : line){
			cout << c;
		}
		cout << "\n";
	}
	cout << "\n----\n";


	for(auto line : flippedSmall){
		for(char c : line){
			cout << c;
		}
		cout << "\n";
	}

	return 0;
}

vector<vector<char>> flip(vector<vector<char>> canvas, bool vertical){
	if(vertical){
		reverse(canvas.begin(), canvas.end());
	}
	else{
		for(auto &line : canvas){
			reverse(line.begin(), line.end());
		}
	}
	return canvas;
}

vector<vector<char>> rotate(vector<vector<char>> canvas, bool clockwise){
	int size = canvas.size();
	auto temp = canvas;
	if(clockwise){
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				temp[i][j] = canvas[size - j - 1][i];
			}
		}

	}
	else{
		temp = rotate(rotate(rotate(canvas, true), true), true);
	}
	return temp;
}
