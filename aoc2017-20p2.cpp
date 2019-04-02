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


	int max_time = 20000;


	for(int time = 0; time <= max_time; time++){
		if(time % 100 == 0){
			cout << "Time: " << time << " Particles: " << master.size() << endl;
		}
		for(int i = 0; i < master.size(); i++){
			vector<long> pos;
			for(int j = 0; j < 3; j++){
				master[i][1][j] += master[i][2][j];
				master[i][0][j] += master[i][1][j];
			}
		}
		//check for collisions
		vector<int> colIdx;
		for(int q = 0; q < master.size(); q++){
			for(int r = q + 1; r < master.size(); r++){
				if(master[r][0] == master[q][0]){ //collision
					cout << "collision found " << endl;
					colIdx.push_back(r);
					colIdx.push_back(q);
				}
			}
		}
		//remove duplicates and sort in reverse order
		sort(colIdx.begin(), colIdx.end());
		colIdx.erase(unique(colIdx.begin(), colIdx.end()), colIdx.end());
		reverse(colIdx.begin(), colIdx.end());

		for(int index : colIdx){
			master.erase(master.begin() + index);
		}

	}

	cout << master.size() << endl;

	return 0;
}

