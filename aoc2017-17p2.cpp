#include <iostream>

using namespace std;


int main(){

    int input = 367;
    int cur = 0;
    int spot = 0;

    for(int i = 1; i <= 50000000; i++){
        cur = ((cur + input) % i) + 1;
        if(cur == 1){
            spot = i;
        }
    }

    cout << spot << endl;

	return 0;
}

