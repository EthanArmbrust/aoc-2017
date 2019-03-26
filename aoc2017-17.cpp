#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int input = 367;
    vector<int> buffer;
    
    buffer.push_back(0);
    int cur = 0;

    for(int i = 1; i <= 2017; i++){
        cur = ((cur + input) % buffer.size()) + 1;
        buffer.insert(buffer.begin() + cur, i);
    }

    cout << buffer[cur + 1] << endl;

	return 0;
}

