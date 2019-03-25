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

    for(int i = 0; i < 5000000; i++){
        do{
            gen_a = (gen_a * mul_a) % div;
        } while(gen_a % 4 != 0);

        do{
            gen_b = (gen_b * mul_b) % div;
        } while(gen_b % 8 != 0);

        string ga = bitset<16>(gen_a).to_string();
        string gb = bitset<16>(gen_b).to_string();

        if(ga == gb){
            count++;
        }
    }
    
    cout << count << endl;

    
    return 0;
}
