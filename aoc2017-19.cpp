#include <iostream>
#include <fstream>
#include <vector>

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

    Direction dir = down;
    string result;
    int steps = 0;
    
    while(true){
        char c = inputList[cursor.first][cursor.second];
        if(c == ' '){
            cout << result << endl;
            cout << steps << " steps" << endl;
            return 0;
        }
        if(c == '+'){
            if(dir == down || dir == up){
                if(inputList[cursor.first][cursor.second+1] != ' '){
                    dir = _right;
                }
                else if(inputList[cursor.first][cursor.second-1] != ' '){
                    dir = _left;
                }
            }
            else if(dir == _left || dir == _right){
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
   
	return 0;
}

