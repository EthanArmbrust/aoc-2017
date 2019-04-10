#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct State{
	char stateName;

	int zeroWrite;
	int oneWrite;

	int zeroMove;
	int oneMove;

	int zeroState;
	int oneState;

};


int main(){

	char next_state = 'A';
	int diag_num = 12173597;

	vector<int> tape(50, 0);
	int cursor = 25;

	State a('A', 1, 0, 1, -1, 'B', 'C');
	State b('B', 1, 1, -1, 1, 'A', 'D');
	State c('C', 1, 0, 1, -1, 'A', 'E');
	State d('D', 1, 0, 1, 1, 'A', 'B');
	State e('E', 1, 1, -1, -1, 'F', 'C');
	State f('F', 1, 1, 1, 1, 'D', 'A');
	
	vector<State> states{a,b,c,d,e,f};

	for(int i = 0; i < diag_num; i++){
		State currentState;
		for(auto s : states){
			if(s.stateName == next_state){
				currentState = s;
			}
		}

		if(tape[cursor] == 0){
			tape[cursor] = currentState.zeroWrite;
			cursor += currentState.zeroMove;
		   	next_state = currentState.zeroState;
		}
		else{
			tape[cursor] = currentState.oneWrite;
			cursor += currentState.oneMove;
		   	next_state = currentState.oneState;
		}


	}

	return 0;
}
