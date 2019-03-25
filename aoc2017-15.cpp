#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){

    long gen_a = 618;
    long gen_b = 814;

    long mul_a = 16807;
    long mul_b = 48271;

    long div = 2147483647;

    int count = 0;

    for(int i = 0; i < 40000000; i++){
        gen_a = (gen_a * mul_a) % div;
        gen_b = (gen_b * mul_b) % div;

        string ga = bitset<16>(gen_a).to_string();
        string gb = bitset<16>(gen_b).to_string();

        if(ga == gb){
            count++;
        }
    }
    
    cout << count << endl;

    
    return 0;
}
