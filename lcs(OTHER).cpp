// longest common substring
#include <iostream>
using namespace std;
string temps1, temps2;
string s1 = " " , s2 = " " ;
int length1, length2;
int dp[1005][1005];
int main(){
    cin >> temps1 >> temps2;
    s1 += temps1;
    s2+= temps2;
    length1 = (int)s1.length();
    length2 = (int)s2.length();
    
    for(int i = 1; i < length1; i++){
        for(int j = 1; j < length2; j++){
            if(s1[i] == s2[j]){
                if(i-1 <= 0 or j-1 <= 0 or dp[i-1][j-1] > 0) dp[i][j] = dp[i-1][j-1] +1;
                else{
                    dp[i][j] = 1;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int answer =0;
    for(int i = 1; i < length1; i++){
        for(int j = 1; j < length2; j++){
            answer= max(answer, dp[i][j]);
            
        }
    }
    cout << answer;
    
}

