#include <iostream>
#include <algorithm>
using namespace std;
int k, e, n;
struct object{
    int pos, cost, value;
};
bool s(object a, object b){
    return a.pos < b.pos;
}
// int dp[index of store][amount of feed] = minimum cost

// k = amount of feed (100), e = length of axis of stores(350), n = number of stores (100)
object ar[105];
int dp[105][105];
int inf = 1000000000;
int main(){
    for(int i = 0; i < 105; i++){
        for(int j= 0; j < 105; j++){
            dp[i][j] = inf;
        }
    }
    cin >> k >> e >>n;
    
    for(int i = 1; i <= n; i++){
        // position, value, cost of feed
        cin >>ar[i].pos >> ar[i].value >> ar[i].cost;
    }
    sort(ar+1, ar+1+n, s);
    ar[n+1].pos = e;
    dp[1][0] = 0;
    
    for(int i = 1; i <=n; i++){
        for(int j = 0; j <= k; j++){
            for(int v = 0; v <= ar[i].value; v++){
                if(j-v>=0){
                    dp[i][j] = min(dp[i-1][j-v] + ar[i].cost*v + (ar[i+1].pos-ar[i].pos)*(j), min(dp[i][j],dp[i-1][j] + (ar[i+1].pos-ar[i].pos)*j));
                }
                else{
                    dp[i][j] = min(dp[i][j],dp[i-1][j]+(ar[i+1].pos-ar[i].pos)*j);
                }
            }
            
        }
    }
    cout << dp[n][k] << endl;
}
