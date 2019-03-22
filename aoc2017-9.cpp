#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main(){

    stack<char> stck;
	ifstream infile("2017-9.txt");

	string s;
	getline(infile,s);

    int sum = 0;
    bool inGarbage = false;
    int gc = 0;

    for(int i = 0; i < s.length(); i++){
        if(!inGarbage){
            if(s[i] == '{'){
                stck.push('{');
            }
            else if(s[i] == '}'){
                sum += stck.size();
                stck.pop();
            }
            else if(s[i] == '<'){
                inGarbage = true;
            }
        }
        else{
            if(s[i] == '!'){
                i++;
            }
            else if(s[i] == '>'){
                inGarbage = false;
            }
            else{
                gc++;
            }
        }   
    }
    cout << sum << endl;
    cout << gc << endl;

	return 0;
}
