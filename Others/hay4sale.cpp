// Dynamic Programming
#include <iostream>
using namespace std;
int c, h;
int bales[5001];
bool dp[50001];
int main(){
    cin >> c >> h;
    for(int i = 0; i <h; i++){
        cin >> bales[i];
    }
    dp[0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = c; j>= 0; j--){
            if(dp[j] == 1){
                if(j+bales[i] <= c) dp[j+bales[i]] = 1;
            }
        }
    }
    int answer = 0;
    for(int i = c; i >=0; i--){
        if(dp[i] == 1){
            answer = i;
            break;
        }
    }
    cout << answer;
}


