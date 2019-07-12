// longest common subsequence
#include <iostream>
using namespace std;
string s1, s2;
int length1, length2;
// dp[prefix of s1 of length x][prefix of s2 of length y]
int dp[1005][1005];
int negInf = -10000000;

int main(){
    cin >> s1 >> s2;
    length1 = (int)s1.length();
    length2 = (int)s2.length();
    //base cases
    for(int i = 0; i < length1; i++){
        for(int j = 0; j < length2; j++){
            dp[i][j] = negInf;
        }
    }
    for(int i = 0; i < length1; i++)
        if(s1[i] == s2[0]) dp[i][0] = 1;
        else dp[i][0] = dp[i-1][0];
    
    for(int i = 0; i < length2; i++)
        if(s2[i] == s1[0]) dp[0][i] = 1;
        else dp[0][i] = dp[0][i-1];
    
    for(int i = 1; i < length1; i++){
        for(int j = 1; j < length2; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[length1-1][length2-1];
    
}

