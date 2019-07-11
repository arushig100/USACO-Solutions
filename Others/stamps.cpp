#include <iostream>
using namespace std;
long long int maxNumStamps,numofStamps;
long long int stampValues[51];
long long int dp[2000001];
long long int dp2[2000001];
int main(){
    cin >> maxNumStamps >> numofStamps;
    for(int i = 1; i <= numofStamps; i++){
        cin >> stampValues[i];
    }
    
    for(int i = 1; i <= 2000000; i++){
        dp2[i] = 100000000000;
    }
    dp2[0] = 0;
    dp[0] = 1;
    for(int i = 1; i <= numofStamps; i++){
        for(int j = 0; j <=2000000; j++){
            if(j+stampValues[i] <= 2000000){
                dp[j+stampValues[i]] +=dp[j];
                if(dp2[j]+1 <= maxNumStamps)
                    dp2[j+stampValues[i]] = min(dp2[j+stampValues[i]], dp2[j]+1);
            }
        }
    }
    int answer=0;
    for(int i = 1; i <= 2000000; i++){
        if(dp2[i] == 100000000000){
            answer = i;
            break;
        }
    }
    cout << answer-1;
}

