#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main(){

	ifstream infile("2017-13.txt");
    int totalDepth = 89;
	vector<vector <string> > inputList;
    vector<int> firewall(totalDepth,0);
    vector<int> caught;

	string s;
	while(getline(infile,s)){

		vector<string> lineData;

		string value;

		while(lineStream >> value){
                if(value[value.length() - 1] == ':'){
                    value.pop_back();
                }
                lineData.push_back(value);
		}
		inputList.push_back(lineData);
	}

    for(auto line : inputList){
        firewall[stoi(line[0])] = stoi(line[1]);
    }

    int offset = -1;
    caught.push_back(-1);
    
    while(caught.size() != 0){
LOOP_START:
        offset++;
        caught.clear();

        for(int t = 0; t < totalDepth; t++){
            if(firewall[t] != 0){
                int range = firewall[t];
                if((t + offset) % ((range * 2) - 2) == 0){
                    goto LOOP_START;
                }
            }
        }
    }

    cout << offset << endl;

	return 0;
}

