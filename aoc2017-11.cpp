#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    vector<string> input;
	ifstream infile("2017-11.txt");

	string s;
	getline(infile,s);
    stringstream ss(s);

    string i;

    while(getline(ss, i, ',')){
        input.push_back(i);
    }

    int x = 0, y = 0, z = 0;

    for(auto str : input){
        if(str == "sw"){
            x--;
            z++;
        }
        if(str == "ne"){
            x++;
            z--;
        }
        if(str == "se"){
            y--;
            x++;
        }
        if(str == "nw"){
            y++;
            x--;
        }
        if(str == "n"){
            z--;
            y++;
        }
        if(str == "s"){
            z++;
            y--;
        }
    
    }
    int sum = max(max(abs(x),abs(y)), abs(z));
    

    cout << sum << endl;

	return 0;
}
