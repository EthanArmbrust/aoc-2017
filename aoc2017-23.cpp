#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


int main(){

	ifstream infile("2017-23.txt");
	vector<vector<string>> inputList;

    vector<long> vals(8,0);
    int snd;

	string s;
	while(getline(infile,s)){
    
        vector<string> temp;
        stringstream ss(s);
        string word;
        while(ss >> word){
            temp.push_back(word);
        } 

		inputList.push_back(temp);
	}

	int mulCount = 0;

    for(int i = 0; i < inputList.size(); i++){
        vector<string> &command = inputList[i];

        if(command[0] == "snd"){
            int reg = command[1][0] - 'a';
            cout << "Playing register " << command[1] << " with freq " << vals[reg] << endl;
            snd = vals[reg];
        }
        else if(command[0] == "set"){
            int reg = command[1][0] - 'a';
            bool y_reg = command[2][0] >= 'a' && command[2][0] <= 'z';
            int reg2;
            if(!y_reg){
                reg2 = stoi(command[2]);
            }
            else reg2 = command[2][0] - 'a';

            if(y_reg){
                vals[reg] = vals[reg2];
            }
            else{
                vals[reg] = reg2;
            }
        }
        else if(command[0] == "sub"){
            int reg = command[1][0] - 'a';
            bool y_reg = command[2][0] >= 'a' && command[2][0] <= 'z';
            int reg2;
            if(!y_reg){
                reg2 = stoi(command[2]);
            }
            else reg2 = command[2][0] - 'a';

            if(y_reg){
                vals[reg] -= vals[reg2];
            }
            else{
                vals[reg] -= reg2;
            }
        }
        else if(command[0] == "mul"){
			mulCount++;
            int reg = command[1][0] - 'a';
            bool y_reg = command[2][0] >= 'a' && command[2][0] <= 'z';
            int reg2;
            if(!y_reg){
                reg2 = stoi(command[2]);
            }
            else reg2 = command[2][0] - 'a';

            if(y_reg){
                vals[reg] *= vals[reg2];
            }
            else{
                vals[reg] *= reg2;
            }
        }
        else if(command[0] == "jnz"){

            int belowZero;
            if(command[1][0] >= 'a' && command[1][0] <= 'z'){
                belowZero = vals[command[1][0] - 'a'];
            }
            else{
                belowZero = stoi(command[1]);
            }

            if(belowZero != 0){
                int jumpAmount;
                if(command[2][0] >= 'a' && command[2][0] <= 'z'){
                    jumpAmount = vals[command[2][0] - 'a'];
                }
                else{
                    jumpAmount = stoi(command[2]);
                }
                i += (jumpAmount - 1);
            }
        }
		/*
        cout << "Line Number: " << i << endl;
        for(char l = 'a'; l <= 'z'; l++){
            cout << l;
            int spaces = to_string(vals[l-'a']).length();
            for(int z = 0; z < spaces; z++){
                cout << " ";
            }
        }
        cout << "\n";
        for(auto v : vals){
            cout << v << " ";
        }
        cout << "\n" << endl;
		*/
    }
	cout << mulCount << endl;


	return 0;
}

