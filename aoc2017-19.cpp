#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

enum Direction {up, down, _right, _left};

int main(){

	ifstream infile("2017-19.txt");
	vector<string> inputList;

	string s;
	while(getline(infile,s)){
		inputList.push_back(s);
	}

    pair<int,int> cursor;

    for(int i = 0; i < inputList[0].length(); i++){
        if(inputList[0][i] == '|'){
            cursor = make_pair(0,i);
        }
    }
    cout << "number of lines " << inputList.size() << endl;

    bool end = false;
    Direction dir = down;
    string result;
    int steps = 0;
    
    while(!end){
        char c = inputList[cursor.first][cursor.second];
        if(c == ' '){
            cout << result << endl;
            cout << steps << " steps" << endl;
            return 0;
        }
        cout << "Cursor pos: " << cursor.first << "," << cursor.second << "   " << c << " " <<  dir << endl;
        if(c == '+'){
            if(dir == down){
                if(inputList[cursor.first][cursor.second+1] != ' '){
                    dir = _right;
                }
                else if(inputList[cursor.first][cursor.second-1] != ' '){
                    dir = _left;
                }
            }
            else if(dir == up){
                if(inputList[cursor.first][cursor.second+1] != ' '){
                    dir = _right;
                }
                else if(inputList[cursor.first][cursor.second-1] != ' '){
                    dir = _left;
                }
            }
            else if(dir == _left){
                if(inputList[cursor.first-1][cursor.second] != ' '){
                    dir = up;
                }
                else if(inputList[cursor.first+1][cursor.second] != ' '){
                    dir = down;
                }
            }
            else if(dir == _right){
                if(inputList[cursor.first-1][cursor.second] != ' '){
                    dir = up;
                }
                else if(inputList[cursor.first+1][cursor.second] != ' '){
                    dir = down;
                }
            }
        }

        if(c >= 'A' && c <= 'Z'){
            result += c;
        }

        if(dir == down){
            cursor.first++;
        }
        if(dir == up){
            cursor.first--;
        }
        if(dir == _left){
            cursor.second--;
        }
        if(dir == _right){
            cursor.second++;
        }
        steps++;
    }
   
    cout << result << endl; 

	return 0;
}

