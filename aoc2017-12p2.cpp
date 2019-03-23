#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>


void countChildren(int parent, std::vector<int> &list);

std::map<int, std::vector<int>> im;
std::vector<std::vector<int>> countedItems;

int main(){

	std::ifstream infile("2017-12.txt");
	std::vector<std::vector<std::string>> inputList;

	std::string s;
	while(getline(infile,s)){

		std::vector<std::string> lineData;
		std::stringstream lineStream(s);

		std::string value;

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
            im[std::stoi(line[0])].push_back(std::stoi(line[i]));
        }
    }

    int current = 0;

    std::vector<int> unused;
    for(int j = 0; j < 2000; j++){
        unused.push_back(j);
    }

    while(unused.size() > 0){
        std::vector<int> workspace;
        countChildren(current, workspace);
        std::sort(workspace.begin(), workspace.end());
        countedItems.push_back(workspace);

        for(auto list : countedItems){
            std::vector<int> temp(2000);
            std::vector<int>::iterator it;
            it = set_difference(unused.begin(), unused.end(), list.begin(),
                                                 list.end(), temp.begin());
            temp.resize(it - temp.begin());
            unused = temp;
        }
        current = unused[0];
    
    }

    std::cout << countedItems.size() << std::endl; 

	return 0;
}

void countChildren(int parent, std::vector<int> &list){
    list.push_back(parent);
    for(auto child : im.at(parent)){
        if(find(list.begin(), list.end(), child) == list.end()){
            countChildren(child, list);
        }
    }
}
