#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> knothash(string s);

int main(){

	string input = "wenycdww";

	cout << bitset<8>(9).to_string() << endl;


    cout << input << endl;

	int sum = 0;

	for(int i = 0; i < 128; i++){
		string work = input + "-" + to_string(i);
		vector<int> khash = knothash(work);
		string entireLine;
		
		for(int n : khash){
			string num = bitset<8>(n).to_string();
			entireLine += num;
			sum += count(num.begin(), num.end(), '1');
		}
	}

	cout << sum << endl;

	return 0;
}

vector<int> knothash(string s){
	vector<int> input;
    vector<int> rope;

	for(char ch : s){
        input.push_back(ch);
    }
    input.push_back(17);
    input.push_back(31);
    input.push_back(73);
    input.push_back(47);
    input.push_back(23);

    //create rope
    for(int n = 0; n < 256; n++){
        rope.push_back(n);
    }
    
    int skip = 0;
    int pos = 0;

    for(int round = 0; round < 64; round++){
        for(int step : input){
            //put area of rope in separate work area
            vector<int> work;
            for(int x = pos; x < pos + step; x++){
                work.push_back(rope[x % 256]);
            }
            //reverse work area
            reverse(work.begin(), work.end());
            //put work area back in rope
            for(int x = pos; x < pos + step; x++){
                rope[x % 256] = work[x - pos];
            }

            pos += step + skip;
            skip++;
        }
    }

    vector<int> dense;
    
    for(int y = 0; y < rope.size(); y++){
        int dc = y / 16; 
        if(y % 16 == 0){
            dense.push_back(rope[y]);
        }
        else{
            dense[dc] = dense[dc] ^ rope[y];
        }
    }

	return dense;
}
