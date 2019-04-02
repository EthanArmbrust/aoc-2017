#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

vector<vector<char>> flip(vector<vector<char>> canvas, bool vertical);
vector<vector<char>> rotate(vector<vector<char>> canvas, bool clockwise);
vector<vector<vector<vector<char>>>> split(vector<vector<char>> canvas);

int main(){

	ifstream infile("2017-21.txt");
    vector<vector<string>> inputList;
	
	
	string s;
	while(getline(infile,s)){
		vector<string> line;
		stringstream ss(s);
		string word;
		while(ss >> word){
			line.push_back(word);
		}
        inputList.push_back(line);
	}
	

	vector<vector<char>> canvas;
	vector<vector<char>> small;
    vector<vector<char>> four;

	four.push_back({'.','#','.','.'});
	four.push_back({'.','.','#','.'});
	four.push_back({'.','#','.','.'});
	four.push_back({'.','.','.','#'});

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

vector<vector<vector<vector<char>>>> split(vector<vector<char>> canvas){
    int cs = canvas.size();
    vector<vector<vector<vector<char>>>> output;
    if(canvas.size() % 2 == 0){
        for(int i = 0; i < cs; i += 2){
            vector<vector<vector<char>>> row;
            for(int j = 0; j < cs; j+= 2){
                vector<vector<char>> chunk;
                chunk.push_back({canvas[i][j], canvas[i][j+1]});
                chunk.push_back({canvas[i+1][j], canvas[i+1][j+1]});
                row.push_back(chunk);
            }
            output.push_back(row); 
        }
    }
    else{
        for(int i = 0; i < cs; i += 3){
            vector<vector<vector<char>>> row;
            for(int j = 0; j < cs; j+= 3){
                vector<vector<char>> chunk;
                chunk.push_back({canvas[i][j], canvas[i][j+1], canvas[i][j+2]});
                chunk.push_back({canvas[i+1][j], canvas[i+1][j+1], canvas[i+1][j+2]});
                chunk.push_back({canvas[i+2][j], canvas[i+2][j+1], canvas[i+2][j+2]});
                row.push_back(chunk);
            }
            output.push_back(row); 
        }
    }
    return output;
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

vector<vector<char>> draw(string flat){
    vector<vector<char>> output;



    
    return output;
}
