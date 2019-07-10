#include <iostream>
using namespace std;
int n;
// dp[first i values][sum of j]
int dp[40][410];
int sum, answer=-1;
int main(){
    cin >> n;
    double summ = n*(n+1)/4.0;
    sum = n*(n+1)/4;
    if(summ != sum){
        answer = 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j]+dp[i-1][j-i],dp[i][j]);
        }
    }
    if(answer != 0) answer = dp[n][sum];
    cout << answer;
    
}

