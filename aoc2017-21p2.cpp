#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> flip(vector<vector<char>> canvas, bool vertical);
vector<vector<char>> rotate(vector<vector<char>> canvas, bool clockwise);
vector<vector<vector<vector<char>>>> split(vector<vector<char>> canvas);
vector<vector<char>> draw(string flat);
vector<vector<char>> merge(vector<vector<vector<vector<char>>>> large);
string flatten(vector<vector<char>> canvas);

int main(){

	ifstream infile("2017-21.txt");
    vector<vector<string>> inputList;
	
    //parse	
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
	
    //create default canvas
	vector<vector<char>> canvas;

	canvas.push_back({'.','#','.'});
	canvas.push_back({'.','.','#'});
	canvas.push_back({'#','#','#'});

    vector<vector<char>> four;

	four.push_back({'1','2','3','4'});
	four.push_back({'5','6','7','8'});
	four.push_back({'9','a','b','c'});
	four.push_back({'d','e','f','g'});

    auto splitUp = split(four);
    auto merged = merge(splitUp);

    
    for(int t = 0; t < 18; t++){

        //1. Break up canvas into pieces
        auto exploded = split(canvas);
        vector<vector<vector<vector<char>>>> newExplode;
        //2. Find rules for every piece of canvas
        for(auto row : exploded){
            vector<vector<vector<char>>> newRow;
            for(auto chunk : row){
                //cout << chunk.size() << endl;
                auto flip_x = flip(chunk, false);
                auto rotate90 = rotate(chunk, true);
                auto rotate180 = rotate(rotate90, true);
                auto rotate270 = rotate(chunk, false);
                auto flip90 = flip(rotate90, false);
                auto flip180 = flip(rotate180, false);
                auto flip270 = flip(rotate270, false);

                vector<string> possibleAns; 
                possibleAns.push_back(flatten(chunk));
                possibleAns.push_back(flatten(flip_x));
                possibleAns.push_back(flatten(rotate90));
                possibleAns.push_back(flatten(rotate180));
                possibleAns.push_back(flatten(rotate270));
                possibleAns.push_back(flatten(flip90));
                possibleAns.push_back(flatten(flip180));
                possibleAns.push_back(flatten(flip270));

                //cout << "Possible permutations: " << endl;
                for(auto stt : possibleAns){
                    //cout << stt << endl;
                }
                //cout << "\n";

                string resultString;

                for(int i  = 0; i < inputList.size(); i++){
                    for(string str : possibleAns){
                        if(inputList[i][0] == str){
                            //cout << "found rule" << endl;
                            resultString = inputList[i][2];
                        }
                    }
                }
                //3. Draw new chunk for each given chunk
                auto newChunk = draw(resultString);
                newRow.push_back(newChunk);
            }
            newExplode.push_back(newRow);
        }
        auto newCanvas = merge(newExplode);
        canvas = newCanvas;

    }
    int count = 0;
    for(auto line : canvas){
		for(char c : line){
            if(c == '#'){
                count++;
            }
			cout << c;
		}
		cout << "\n";
    }
   
    cout << count << endl; 

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
    stringstream ss(flat);
    string temp;
    while(getline(ss, temp, '/')){
        vector<char> row;
        for(char c : temp){
            row.push_back(c);
        }
        output.push_back(row);
    } 
    return output;
}

string flatten(vector<vector<char>> canvas){
    string output;
    for(auto row : canvas){
        for(char c : row){
            output += c;
        }
        output += '/';
    }
    output.pop_back(); //remove / from end
    return output;
}

/*
  1 2   3  4
  5 6   7  8

  9 A   B  C
  D E   F  G

large[a][b][c][d]
a = big row
b = big col
c = small row
d = small col
*/


vector<vector<char>> merge(vector<vector<vector<vector<char>>>> large){
    vector<vector<char>> output;
    
    int dim = large.size() * large[0][0].size();
    int chunkSize = large[0][0].size();

    for(int i = 0; i < dim; i++){
        vector<char> row;
        int bigRow = i / chunkSize;
        int smallRow = i - (bigRow * chunkSize);
        for(int j = 0; j < dim; j++){
            int bigCol = j / chunkSize;
            int smallCol = j - (bigCol * chunkSize);
            row.push_back(large[bigRow][bigCol][smallRow][smallCol]);
        }
        output.push_back(row);
    }
    return output;
}
