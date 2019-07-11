
#include <iostream>
using namespace std;
int n, c;
struct object{
    int size, value;
};
object ar[1001];
int dp[1001][5001];
int negInf = -1000000;
int main(){
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        // size and then value
        cin >>ar[i].size >> ar[i].value;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 0; j <=c; j++){
            dp[i][j] = negInf;
        }
    }

    for(int i = 1; i <=n; i++){
        for(int j = 0; j <= c; j++){
            if(j-ar[i].size >=0)
                dp[i][j] = max(dp[i - 1][j], dp[i-1][j-ar[i].size] + ar[i].value);
            else
                dp[i][j] =dp[i-1][j];
        }
    }
    
    cout << dp[n][c];

}

