#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<pair<int,int>>> b_list;
void maxBridge(vector<pair<int,int>> unused, vector<pair<int,int>> used, int open);

int main(){

	ifstream infile("2017-24.txt");
    vector< pair<int,int> > bridges;
	
    //parse	
	string s;
	while(getline(infile,s)){
        string del = "/";
        auto it = s.find(del);
        string firstNum = s.substr(0, it);
        string secondNum = s.substr(it + 1);
        bridges.push_back({stoi(firstNum), stoi(secondNum)});
	}
    
    vector<pair<int,int>> blank;
    maxBridge(bridges, blank, 0); 

    int max = 0;
	int maxLength = 0;
	vector<vector<pair<int,int>>> longest;
    vector<pair<int,int>> max_list;
    for(auto b : b_list){
        int b_sum = 0;
        for(auto bridge : b){
            b_sum += bridge.first + bridge.second;
        }
        if(b_sum > max){
            max = b_sum;
            max_list = b;
        }

		if(b.size() > maxLength){
			longest.clear();	
			longest.push_back(b);
			maxLength = b.size();
		}
		else if(b.size() == maxLength){	
			longest.push_back(b);
		}
    }
	
	int strongest = 0;
	for(auto b : longest){	
        int b_sum = 0;
        for(auto bridge : b){
            b_sum += bridge.first + bridge.second;
        }
        if(b_sum > strongest){
            strongest = b_sum;
        }
	}

	
    
    cout << "Part 1: " << max << endl;
	cout << "Part 2: " << strongest << endl;

	return 0;
}	

void maxBridge(vector<pair<int,int>> unused, vector<pair<int,int>> used, int open){
    bool bridgeEnd = true;
    for(int i = 0; i < unused.size(); i++){
        if(unused[i].first == open || unused[i].second == open){
            bridgeEnd = false;
            int newOpen;
            if(unused[i].first == open){
                newOpen = unused[i].second;
            }
            if(unused[i].second == open){
                newOpen = unused[i].first;
            }
			auto newUsed(used);
			auto newUnused(unused);
            newUsed.push_back(unused[i]);
            newUnused.erase(newUnused.begin() + i);
            maxBridge(newUnused, newUsed, newOpen);
        }
    }
    if(bridgeEnd){
        b_list.push_back(used);
    }
}
