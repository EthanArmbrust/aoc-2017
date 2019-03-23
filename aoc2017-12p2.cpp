#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void countChildren(int parent, vector<int> &list);

map<int, vector<int>> im;
vector<vector<int>> countedItems;

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

    //select next int
    int current = 0;

    vector<int> unused;
    for(int j = 0; j < 2000; j++){
        unused.push_back(j);
    }

    while(unused.size() > 0){
        vector<int> workspace;
        countChildren(current, workspace);
        sort(workspace.begin(), workspace.end());
        countedItems.push_back(workspace);

        for(auto list : countedItems){
            vector<int> temp(2000);
            vector<int>::iterator it;
            it = set_difference(unused.begin(), unused.end(), list.begin(),
                                                 list.end(), temp.begin());
            temp.resize(it - temp.begin());
            unused = temp;
        }
        current = unused[0];
    
    }

    cout << countedItems.size() << endl; 

	return 0;
}

void countChildren(int parent, vector<int> &list){
    list.push_back(parent);
    for(auto child : im.at(parent)){
        if(find(list.begin(), list.end(), child) == list.end()){
            countChildren(child, list);
        }
    }
}
