// Dynamic Programming
#include <iostream>
using namespace std;
// dp = [index][total weight of haybales eaten]  = true/false;
int n, h;
int haybales[501];
bool dp[501][45000];
int main(){
    cin >> h>> n;
    for(int i = 1; i  <= n; i++)
        cin >> haybales[i];
    for(int i = 1; i <=n; i++){
        dp[i][haybales[i]] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= h; j++){
            if(dp[i-1][j])
                dp[i][j] = true;
            if(j-haybales[i] >= 0 and dp[i-1][j-haybales[i]] == true)
                dp[i][j] = true;
        }
    }
    int maxx = 0;
    for(int i = 1; i <=n; i++){
        for(int j = 0; j <=h; j++){
            if(dp[i][j]){
                maxx = max(maxx, j);
            }
        }
    }
    cout << maxx;
}
