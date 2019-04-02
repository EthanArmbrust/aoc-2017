#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;


int main(){

	ifstream infile("2017-20.txt");
	vector<vector<vector<long>>> master;

	
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

	//master[a][b][c]
	//a = particle num
	//b = pos, velocity, accel as 0,1,2
	//c = x, y, z as 0,1,2


	int time = 100000;

	long minDis = LONG_MAX;
	long minIdx;

	for(int i = 0; i < master.size(); i++){
		long distance = 0;
		for(int j = 0; j < 3; j++){
			long dirDis = master[i][0][j] + ((master[i][1][j] * time) + (0.5 * master[i][2][j] * (time * time)));
			distance += abs(dirDis);
		}
		if(distance < minDis){
			minIdx = i;
			minDis = distance;
		}
	}

	cout << "Closest point after " << time << " time is " << minIdx << endl;
	

	return 0;
}

