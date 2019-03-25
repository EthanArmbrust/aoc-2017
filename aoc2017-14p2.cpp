#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> knothash(string s);
void findNeighbors(pair<int, int> source, vector<pair<int,int>> &group);
vector<string> ba;


int main(){

	string input = "wenycdww";

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
        ba.push_back(entireLine);
	}

    //binary array finished

    vector<vector<pair<int,int>>> group_list;

    for(int row = 0; row < 128; row++){
        for(int col = 0; col < 128; col++){
            if(ba[row][col] == '1'){
                bool recorded = false;
                pair<int,int> coord = make_pair(row, col);
                for(auto list : group_list){
                    if(find(list.begin(), list.end(), coord) != list.end()){
                        recorded = true;
                    }
                }
                if(!recorded){
                    vector<pair<int,int>> new_group;
                    findNeighbors(coord, new_group);
                    group_list.push_back(new_group);
                }
            }
        }
    }

	cout << group_list.size() << endl;

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

void findNeighbors(pair<int, int> source, vector<pair<int,int>> &group){
    
    group.push_back(source);

    vector<pair<int,int>> potentialNeighbors;
    if(source.first > 0){
        potentialNeighbors.push_back({source.first - 1, source.second});
    }
    if(source.first < 127){
        potentialNeighbors.push_back({source.first + 1, source.second});
    }
    if(source.second > 0){
        potentialNeighbors.push_back({source.first, source.second - 1});
    }
    if(source.second < 127){
        potentialNeighbors.push_back({source.first, source.second + 1});
    }
    
    for(auto ne : potentialNeighbors){
        if(ba[ne.first][ne.second] == '1'){
            if(find(group.begin(), group.end(), ne) == group.end()){
                findNeighbors(ne, group);
            }
        }
    }
}
