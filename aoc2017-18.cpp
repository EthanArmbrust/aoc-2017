#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(){

	ifstream infile("2017-18.txt");
	vector<string> inputList;

    vector<int> vals(26,0);
    vector<int> snd(26,0);

	string s;
	while(getline(infile,s)){
		inputList.push_back(s);
	}


    for(int i = 0; i < inputList.size(); i++){
        string &command = inputList[i];
        int reg = command[4] - 'a';
        string second;
        if(command.length() >= 7){
            second = command.substr(6);
        }
        int reg2;
    
        bool x_reg = false;
        bool y_reg = false;

        if(command[4] >= 'a' && command[4] <= 'z'){
            reg = command[4] - 'a';
            x_reg = true;
        }
        else{
            reg = stoi(command.substr(4,1));
        }
    
        if(second[0] >= 'a' && second[0] <= 'z'){
            reg2 = second[0] - 'a';
            y_reg = true;
        }
        else{
            reg2 = stoi(second);
        }

        

        if(command.substr(0,3) == "snd"){
            snd[reg] = vals[reg];
        }
        else if(command.substr(0,3) == "set"){
            if(y_reg){
                vals[reg] = vals[reg2];
            }
            else{
                vals[reg] = reg2;
            }
        }
        else if(command.substr(0,3) == "add"){
            if(y_reg){
                vals[reg] += vals[reg2];
            }
            else{
                vals[reg] += reg2;
            }
        }
        else if(command.substr(0,3) == "mul"){
            if(y_reg){
                vals[reg] *= vals[reg2];
            }
            else{
                vals[reg] *= reg2;
            }
        }
        else if(command.substr(0,3) == "mod"){
            if(y_reg){
                vals[reg] = vals[reg] % vals[reg2];
            }
            else{
                vals[reg] = vals[reg] % reg2;
            }
        }
        else if(command.substr(0,3) == "rcv"){
            if(vals[reg] != 0){
                vals[reg] = snd[reg];
                cout << snd[reg] << endl;
                return 0;
            }
        }
        else if(command.substr(0,3) == "jgz"){
            int val;
            if(y_reg)
                val = vals[reg2];
            else val = reg2;
            
            int amount;
            if(x_reg)
                amount = vals[reg];
            else amount = reg;

            if(amount < 0){
                amount--;
            }
            if(val > 0){
                i += amount;
            }
        }
    }


	return 0;
}

