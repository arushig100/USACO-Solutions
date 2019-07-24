#include <iostream>
using namespace std;

int n;
int ar[100001];
int dp[100001];
int maxx = -1000000000;
int main(){
    cin >> n;
    for(int i =0; i <n; i++){
        cin >> ar[i];
    }
    for(int i =0; i < n; i++){
        dp[i] = max(dp[i-1] + ar[i], ar[i]);
        maxx = max(maxx, dp[i]);
    }
    cout << maxx << endl;
}

