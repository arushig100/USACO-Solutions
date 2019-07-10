#include <iostream>
using namespace std;
int n;
int ar[20000];
int dp[20000];
int answer = 0;
int main(){
    cin >> n;
    for(int i= 0; i < n; i++)
        cin >> ar[i];
 
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(ar[j] < ar[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for(int i = 0; i < n; i++)
        answer = max(answer, dp[i]);
 
    cout << answer;
}

