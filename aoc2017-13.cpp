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
    vector<bool> direction(totalDepth, false);
    map<int, int> scanner;
    vector<int> caught;

	string s;
	while(getline(infile,s)){

		vector<string> lineData;
		stringstream lineStream(s);

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
        scanner[stoi(line[0])] = 0;
        firewall[stoi(line[0])] = stoi(line[1]);
    }

    for(int t = 0; t < totalDepth; t++){
        if(scanner.find(t) != scanner.end()){
            if(scanner.at(t) == 0){
                caught.push_back(t);
            }
        }
        
        cout << "Scanner positions at time " << t << endl;

        for(auto &mp : scanner){
            int dep = mp.first;
            int pos = mp.second;
            cout << mp.first << ", " << mp.second << endl;
            if(mp.second == firewall[dep] - 1){
                direction[dep] = true;
            }
            if(mp.second == 0){
                direction[dep] = false;
            }
            if(direction[dep]){
                mp.second -= 1;
            }
            else{
                mp.second += 1;
            }
        }
    }

    int sum = 0;

    cout << "Caught at following positions: ";
    for(auto in : caught){
        sum += (firewall[in] * in);
        cout << in << ", ";
    }
    cout << "\n";

    

    cout << sum << endl;

	return 0;
}

