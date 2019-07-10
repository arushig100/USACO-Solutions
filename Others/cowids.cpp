#include <iostream>
using namespace std;
int n, k;
// dp[total # of bits][# of 1 bits] = # ways to do this
int dp[5005][11];

int main(){
    cin>> n>> k;
    if(k==1){
        cout << 1;
        for(int i = 1; i<n; i++){
            cout <<0;
        }
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i <5000; i++){
        dp[i][0] = 1;
    }
    
    
    //input values in dp array
    for(int i = 1; i <= 5000; i++){
        for(int j = 1; j <=10; j++){
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i-1][j-1]+dp[i][j], dp[i][j]);
        }
    }
    int kk = k;
    int nn = n;
    int startingPos=0;
    int ar[2000000];
    int index;
    while(kk>0){
        for(int i = 1; i <=n; i++){
            if(dp[i][kk]>=nn){
                nn = nn-dp[i-1][kk];
                index = i;
                break;
            }
        }
        ar[index-1] = 1;
        startingPos =max(startingPos, index-1);
        kk--;
    }
    for(int i = startingPos; i>=0; i--){
        cout << ar[i];
    }
}

