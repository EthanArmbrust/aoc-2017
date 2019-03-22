#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){

    vector<int> input;
    vector<int> rope;
	ifstream infile("2017-10.txt");

	string s;
	getline(infile,s);

    for(char ch : s){
        input.push_back(ch);
    }
    input.push_back(17);
    input.push_back(31);
    input.push_back(73);
    input.push_back(47);
    input.push_back(23);

    //create rope
    for(int n = 0; n < 256; n++){
        rope.push_back(n);
    }
    
    int skip = 0;
    int pos = 0;

    for(int round = 0; round < 64; round++){
        for(int step : input){
            //put area of rope in separate work area
            vector<int> work;
            for(int x = pos; x < pos + step; x++){
                work.push_back(rope[x % 256]);
            }
            //reverse work area
            reverse(work.begin(), work.end());
            //put work area back in rope
            for(int x = pos; x < pos + step; x++){
                rope[x % 256] = work[x - pos];
            }

            pos += step + skip;
            skip++;
        }
    }

    vector<int> dense;
    
    for(int y = 0; y < rope.size(); y++){
        int dc = y / 16; 
        if(y % 16 == 0){
            dense.push_back(rope[y]);
        }
        else{
            dense[dc] = dense[dc] ^ rope[y];
        }
    }


    for(auto val : dense){
        cout << hex << setfill('0') << setw(2) << val;
    }
    cout << "\n"; 

	return 0;
}
