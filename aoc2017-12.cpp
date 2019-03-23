#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void countChildren(int);

map<int, vector<int>> im;
vector<int> countedItems;

int main(){

	ifstream infile("2017-12.txt");
	vector<vector <string> > inputList;

	string s;
	while(getline(infile,s)){

		vector<string> lineData;
		stringstream lineStream(s);

		string value;

		while(lineStream >> value){
            if(value != "<->"){
                if(value[value.length() - 1] == ','){
                    value.pop_back();
                }
                lineData.push_back(value);
            }
		}
		inputList.push_back(lineData);
	}

    for(auto line : inputList){
        for(int i = 1; i < line.size(); i++){
            im[stoi(line[0])].push_back(stoi(line[i]));
        }
    }

    countChildren(0);
    cout << countedItems.size() << endl; 

	return 0;
}

void countChildren(int parent){
    countedItems.push_back(parent);
    for(auto child : im.at(parent)){
        if(find(countedItems.begin(), countedItems.end(), child) == countedItems.end()){
            countChildren(child);
        }
    }
}
