#include <iostream>
using namespace std;
int n, k;
int counter = 0;
long long dp[100001];
int main(){
    cin >> n >> k;
    dp[1] = 2;
    for(int i = 2; i <= n; i++){
        dp[i] += dp[i-1]%5000011;
        if(i-k-1 <= 0)
            dp[i] += 1;
        else
            dp[i] += dp[i-k-1]%5000011;
    }
    cout << dp[n]%5000011;
}
