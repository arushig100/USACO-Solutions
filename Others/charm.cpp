// knapsack
#include <iostream>
using namespace std;
int n, m;
struct charm{
    int weight, desire;
};
charm ar[3408];
int dp[2][12881]; // dp[current index of charm][current Weight] = max desirability
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> ar[i].weight >> ar[i].desire;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // possible to take the charm
            if(j-ar[i].weight >=0)
                dp[1][j] = max(dp[0][j], dp[0][j-ar[i].weight] + ar[i].desire);
            // not possible to take charm
            else
                dp[1][j] =dp[0][j];
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][m];

}
