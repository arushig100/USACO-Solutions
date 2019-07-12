
#include <iostream>
using namespace std;
string temps1, temps2;
string s1= " ", s2 = " ";
int length1, length2;
int dp[1005][1005];
int main(){
    cin >> temps1 >> temps2;
    s1 += temps1;
    s2 += temps2;
    length1 = (int)s1.length();
    length2 = (int)s2.length();
    for(int i = 0; i < length1; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i < length2; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i < length1; i++){
        for(int j = 1; j < length2; j++){
            //if equal, no cost
            if(s1[i] == s2[j]) dp[i][j] =  dp[i-1][j-1];
            // if not equal, replacement cost
            else dp[i][j] = dp[i-1][j-1] +1;
            if(s1[i] == s2[j] and (i==0 or j==0)) dp[i][j] = 1;
            // deletion, insertion
            dp[i][j] = min(1+dp[i-1][j], min(dp[i][j-1]+1, dp[i][j]));
        }
    }
    cout << dp[length1-1][length2-1];
}

