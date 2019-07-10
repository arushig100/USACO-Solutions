#include <iostream>
using namespace std;
int r, c;
int ar[100][100];
int gold[100][100];
bool outOfBounds(int x, int y){
    if(x < 0 or y  < 0 or x >= r or y >= c) return true;
    return false;
}
int main(){
    cin >> r >> c;
    for(int i =0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> ar[i][j];

    gold[0][0] = ar[0][0];
    for(int j = 0; j < c; j++){
        for(int i= 0; i<r and i < j+1; i++){
            if(!outOfBounds(i+1, j-1))
                gold[i][j] = max(gold[i][j], gold[i+1][j-1] + ar[i][j]);
            if(!outOfBounds(i, j-1))
                gold[i][j] = max(gold[i][j], gold[i][j-1] + ar[i][j]);
            if(!outOfBounds(i-1, j-1))
                gold[i][j] = max(gold[i][j], gold[i-1][j-1] + ar[i][j]);
        }
    }
    cout << gold[r-1][c-1];
}

