#include <iostream>

using namespace std;

int main(){

    int a = 1;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;

    //program start

    b = 57;
    c = b;

    if( a != 0){
        b *= 100;
        b += 100000;
        c = b;
        c += 17000;
    }
    do{
        f = 1;
        d = 2;
        e = 2;

        for(d = 2; d*d <= b; d++){
            if(b%d == 0){
                f = 0;
                break;
            }
        }

        if( f == 0){
            h += 1;
        }
        g = b;
        g -= c;
        b += 17;
    } while(g != 0); 

    cout << h << endl;
    return 0;
}
