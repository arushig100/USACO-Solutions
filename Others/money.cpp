// Dynamic Programming
#include <iostream>
using namespace std;
long long int numOfCoins,moneyNeeded;
long long int coinValues[25];
long long int dp[10001];
int main(){
    cin >> numOfCoins >> moneyNeeded;
    for(int i = 0; i < numOfCoins; i++){
        cin >> coinValues[i];
    }
    
    dp[0] = 1;
    for(int i = 0; i < numOfCoins; i++){
        for(int j = 0; j <=moneyNeeded; j++){
            if(dp[j] >= 1){
                if(j+coinValues[i] <= moneyNeeded) dp[j+coinValues[i]] += 1*dp[j];
            }
        }
    }
    cout << dp[moneyNeeded];
}

