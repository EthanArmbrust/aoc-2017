#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <queue>
#include <chrono>

using namespace std;

void runProgram(vector<vector<string>> &inputList, vector<long> &vals,
               queue<long> &inqueue, queue<long> &outqueue, int &returnVal, bool &timer, bool &otherTimer);

int main(){

	ifstream infile("2017-18.txt");
	vector<vector<string>> inputList;

    vector<long> vals1(26,0);
    vector<long> vals2(26,0);

    queue<long> queue1;
    queue<long> queue2;

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

    vals2['p' - 'a'] = 1;

    int sendCount1;
    int sendCount2;

    bool timer1 = false;
    bool timer2 = false;
    
    thread first(runProgram, ref(inputList), ref(vals1), ref(queue1), ref(queue2), ref(sendCount1), ref(timer1), ref(timer2));
    thread second(runProgram, ref(inputList), ref(vals2), ref(queue2), ref(queue1), ref(sendCount2), ref(timer2), ref(timer1));

    first.join();
    second.join();

    cout << "send count for first program " << sendCount2 << endl;

    

	return 0;
}

void runProgram(vector<vector<string>> &inputList, vector<long> &vals,
               queue<long> &inqueue, queue<long> &outqueue, int &returnVal, bool &timer, bool &otherTimer){
    int sendCount = 0;
    int programID = vals['p' - 'a'];
    for(int i = 0; i < inputList.size(); i++){
        vector<string> &command = inputList[i];
        if(command[0] == "snd"){
            bool is_reg = command[1][0] >= 'a' && command[1][0] <= 'z';
            long reg;
            if(!is_reg){
                reg = stoi(command[1]);
            }
            else{
                reg = vals[command[1][0] - 'a'];
            }
            outqueue.push(reg);
            sendCount++;

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
        else if(command[0] == "add"){
            int reg = command[1][0] - 'a';
            bool y_reg = command[2][0] >= 'a' && command[2][0] <= 'z';
            int reg2;
            if(!y_reg){
                reg2 = stoi(command[2]);
            }
            else reg2 = command[2][0] - 'a';

            if(y_reg){
                vals[reg] += vals[reg2];
            }
            else{
                vals[reg] += reg2;
            }
        }
        else if(command[0] == "mul"){
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
        else if(command[0] == "mod"){
            int reg = command[1][0] - 'a';
            bool y_reg = command[2][0] >= 'a' && command[2][0] <= 'z';
            int reg2;
            if(!y_reg){
                reg2 = stoi(command[2]);
            }
            else reg2 = command[2][0] - 'a';

            if(y_reg){
                vals[reg] = vals[reg] % vals[reg2];
            }
            else{
                vals[reg] = vals[reg] % reg2;
            }
        }
        else if(command[0] == "rcv"){
            int reg = command[1][0] - 'a';
            if(inqueue.size() > 0){
                //cout << "received" << endl; //this is vital!
                timer = false;
                vals[reg] = inqueue.front();
                inqueue.pop();
            }
            else{
                //waiting
                timer = true;
                i--;
                cout << programID << " waiting" << endl;
                if(otherTimer){
                    cout << "DEADLOCK" << endl;
                    returnVal = sendCount;
                    return;
                }
            }
        }
        else if(command[0] == "jgz"){

            int belowZero;
            if(command[1][0] >= 'a' && command[1][0] <= 'z'){
                belowZero = vals[command[1][0] - 'a'];
            }
            else{
                belowZero = stoi(command[1]);
            }

            if(belowZero > 0){
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
    this_thread::sleep_for(chrono::microseconds(1));
    }
    returnVal = sendCount;
    return;
}
