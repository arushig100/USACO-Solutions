#include <iostream>
#include <cmath>
using namespace std;
int n;
int side1[1000];
int side2[1000];
int dp[1000][1000];

bool outOfBounds(int x, int y){
    if(x <0 or y <0 or x>= n or y >= n)
        return true;
    return false;
}
bool friendly(int a, int b){
    if(abs(side1[a]-side2[b]) <= 4){
        return true;
    }
    return false;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> side1[i];
    for(int i = 0; i < n; i++)
        cin >> side2[i];
    
    for(int i = 0; i < n; i++) {
        if(friendly(i, 0)){
            dp[i][0] = 1;
        }
        if(friendly(0,i)){
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(!outOfBounds(i,j-1))
                dp[i][j] = max(dp[i][j-1],dp[i][j]);
            if(!outOfBounds(i-1,j))
                dp[i][j] = max(dp[i-1][j],dp[i][j]);
            if(!outOfBounds(i-1,j-1)){
                if(friendly(i,j))
                    dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]);
                else
                    dp[i][j] = max(dp[i-1][j-1],dp[i][j]);
            }

            
        }
    }
    int maxx = 0;
    for(int i = 0; i < n; i++)
        for(int j =0; j < n; j++)
            maxx = max(dp[i][j], maxx);
    cout << maxx<< endl;
}

