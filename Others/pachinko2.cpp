#include <iostream>
using namespace std;
int r;
int machine[100][100];
int scores[100][100];
int answer = 0;
bool outOfBounds(int x, int y){
    if(x < 0 or y < 0 or x >= r or y >= r) return true;
    else if(y > x) return true;
    return false;
}
int main(){
    cin >> r;
    for(int i = 0; i < r;i++)
        for(int j = 0; j <=i; j++)
            cin >> machine[i][j];

 scores[0][0] = machine[0][0];
    
    for(int i = 1;i  < r; i++){
        for(int j = 0; j <= i; j++){
            if(!outOfBounds(i-1,j))
                scores[i][j] = max(scores[i][j],machine[i][j] +scores[i-1][j]);
            if(!outOfBounds(i-1,j-1))
                scores[i][j] = max(scores[i][j],machine[i][j] +scores[i-1][j-1]);
        }
    }
    
    for(int i = 0; i < r; i++)
        answer = max(answer, scores[r-1][i]);

 cout << answer << endl;
}

