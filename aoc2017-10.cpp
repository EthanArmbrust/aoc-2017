#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    vector<int> input;
    vector<int> rope;
	ifstream infile("2017-10.txt");

	string s;
	getline(infile,s);
    stringstream ss(s);

    int i;

    while(ss >> i){
        input.push_back(i);

        if(ss.peek() == ','){
            ss.ignore();
        }
    }

    //create rope
    for(int n = 0; n < 256; n++){
        rope.push_back(n);
    }
    
    int skip = 0;
    int pos = 0;

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
   
    cout << rope[0] * rope[1] << endl; 

	return 0;
}
