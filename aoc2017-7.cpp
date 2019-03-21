#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("2017-7.txt");
	vector<vector <string> > inputList;
    vector<string> baseList;
    vector<string> depList;

	string s;
	while(getline(infile,s)){

		vector<string> lineData;
		stringstream lineStream(s);

		string value;

		while(lineStream >> value){
			lineData.push_back(value);
		}

        lineData.erase(lineData.begin() + 1); //remove weight

        if(lineData.size() > 2){
            lineData.erase(lineData.begin() + 1); //remove arrow
            for(auto &str : lineData){
                if(str[str.length() - 1] == ','){
                    str = str.substr(0, str.length() - 1);
                }
            }
        }

		inputList.push_back(lineData);
	}

    for(auto list : inputList){
        baseList.push_back(list[0]);
        for(int i = 1; i < list.size(); i++){
            depList.push_back(list[i]);
        }
    }

    cout << baseList.size() << endl;
    cout << depList.size() << endl;

    for(auto str : baseList){
        if(find(depList.begin(), depList.end(), str) == depList.end()){
            cout << str << endl;
            return 0;
        }
    }
	return 0;
}
