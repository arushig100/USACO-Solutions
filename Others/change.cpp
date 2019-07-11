#include <iostream>
using namespace std;
long long int numOfCoins,moneyNeeded;
long long int coinValues[10];
long long int dp[1001];
long long int dp2[1001];
int main(){
    cin >> moneyNeeded >> numOfCoins;
    for(int i = 0; i < numOfCoins; i++){
        cin >> coinValues[i];
    }
    
    for(int i = 0; i <= moneyNeeded; i++){
        dp2[i] = 1000000000;
    }
    dp2[0] = 0;
    dp[0] = 1;
    for(int i = 0; i < numOfCoins; i++){
        for(int j = 0; j <=moneyNeeded; j++){
            if(dp[j] >= 1){
                if(j+coinValues[i] <= moneyNeeded){
                    dp[j+coinValues[i]] += 1*dp[j];
                    dp2[j+coinValues[i]] = min(dp2[j+coinValues[i]], dp2[j]+1);
                }
                
            }
        }
    }
    cout << dp2[moneyNeeded];
}

