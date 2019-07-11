#include <iostream>
using namespace std;
int n, h;
struct packages{
    int pounds, cost;
};
// dp[cost] = maximum number of pounds of hay
int dp[20005];
packages ar[101];
int negInf = -10000000;
int main(){
    cin >> n >> h;
    for(int i = 1; i<=n; i++){
        cin >> ar[i].pounds >> ar[i].cost;
    }
    for(int i = 1; i <=20000; i++){
        dp[i] = negInf;
    }
    for(int i = 1; i <= n ;i++){
        for(int j = 0; j <= 20000; j++){
            if(j-ar[i].cost >= 0)
                dp[j] = max(dp[j-ar[i].cost] + ar[i].pounds, dp[j]);
        }
    }
    int answer = 0;
    for(int i = 0; i <= 20000; i++){
        if(dp[i] >= h){
            answer = i;
            break;
        }
    }
    cout << answer;
}


