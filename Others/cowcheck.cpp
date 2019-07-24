#include <iostream>
using namespace std;
int m, n,t;
int finalAnswer = 0;
int ar[1000001];


int main(){
    cin >> m >> n >> t;
    for(int i= 0; i < 1000001; i++){
        ar[i] = -1;
    }
    ar[0] = 0;
    ar[1] = 2;
    ar[2] = 1;
    int x = 3;
    int y = 2;
    while(x+y < 1000000){
        if(ar[x] == -1){
            ar[x] = x+y;
            ar[x+y] = x;
            y++;
        }
        x++;
    }
    
    for(int games=0; games < t; games++){
        int startX,  startY;
        cin >> startX >> startY;
        if(ar[startX]==startY){
            cout << "Farmer John" << endl;
        }
        else{
            cout << "Bessie"<< endl;
        }
    }
    
    
}

