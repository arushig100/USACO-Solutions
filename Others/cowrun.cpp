#include <iostream>
using namespace std;
int n, m;
int dist[10005];
int dp[10005][505]; // [index][exhaustion factor] = max distance till index
int main(){
    cin >> n >> m;
    for(int i = 1; i <=n; i++){
        cin >> dist[i];
    }
    for(int i = 1; i <=n ;i++){
        // updates dp[i][0]
        dp[i][0] = dp[i-1][0];
        for(int j = 1; j <= m and j <=i; j++){
            dp[i][0] = max(dp[i-j][j], dp[i][0]);
        }
        for(int j = 1; j <= i and j <=m;j++){
            dp[i][j] = max(dp[i-1][j-1] + dist[i], dp[i-1][0]);
        }
    }
    
    cout << dp[n][0];
}

