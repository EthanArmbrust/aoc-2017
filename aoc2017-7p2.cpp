#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
int getDiskWeight(string);
vector<vector <string> > inputList;

int main(){

	ifstream infile("2017-7.txt");
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

        //lineData.erase(lineData.begin() + 1); //remove weight
		
		lineData[1] = lineData[1].substr(1,lineData[1].length() - 2);

        if(lineData.size() > 2){
            lineData.erase(lineData.begin() + 2); //remove arrow
            for(auto &str : lineData){
                if(str[str.length() - 1] == ','){
                    str = str.substr(0, str.length() - 1);
                }
            }
        }

		inputList.push_back(lineData);
	}

	cout << "lnpuarm weight: " << getDiskWeight("lnpuarm") << endl;
	cout << "jfrda weight: " << getDiskWeight("jfrda") << endl;

	getDiskWeight("vtzay");

	

	return 0;
}

int getDiskWeight(string diskname){
	for(auto entry : inputList){
		if(entry[0] == diskname){ //found disk
			int diskweight = stoi(entry[1]);
			if(entry.size() > 2){
				vector<string> childNames;
				vector<int> childWeights;
				for(int i = 2; i < entry.size(); i++){
					childNames.push_back(entry[i]);
					childWeights.push_back(getDiskWeight(entry[i])); //recursion
				}
				int childSum = 0;
				for(auto w : childWeights){
					childSum += w;
				}
				if(std::equal(childWeights.begin() + 1, childWeights.end(), childWeights.begin())){
					return childSum + diskweight;
				}
				else{
					cout << "CHILDREN ARE NOT EQUAL" << endl;
					cout << "DUMPING CHILDREN WEIGHT" << endl;
					cout << "DISK NAME: " << diskname << endl;
					for(int z = 0; z < childWeights.size(); z++){
						cout << childNames[z] << ": " << childWeights[z] << endl;
					}
					return childSum + diskweight;
					
				}
			}
			else{
				return diskweight;
			}
		}
	}


	
	return 0;
}
