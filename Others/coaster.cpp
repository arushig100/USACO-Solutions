#include <iostream>
#include <algorithm>
using namespace std;
long long len,n, budget;
struct part{
    long long start, end, fun, cost;
};
bool s(part a, part b){
    return a.start < b.start;
}
long long dp[1005][1005]; // dp[length][cost] = maximum fun rating
part ar[10005];
long long negInf = -10000000;
int main(){
    cin >> len >> n >> budget;
    for(int i = 1; i <= n; i++){
        cin >> ar[i].start >> ar[i].end >> ar[i].fun >> ar[i].cost;
        ar[i].end += ar[i].start;
    }
    
    sort(ar+1, ar+1+n, s);
    
    for(int i =0; i<=len; i++){
        for(int j = 0; j <=budget; j++){
            dp[i][j] = negInf;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <=n; i++){
        for(int j = 0; j <= budget; j++){
            if(j-ar[i].cost >= 0 )
                dp[ar[i].end][j] = max(dp[ar[i].end][j], dp[ar[i].start][j-ar[i].cost]+ar[i].fun);
        }
    }
    long long answer = -1;
    for(int i = 0; i <=budget; i++){
        answer = max(answer, dp[len][i]);
    }
    cout << answer;
}

