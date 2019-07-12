// longest common subsequence optimized
#include <iostream>
using namespace std;
string temps1, temps2;
string s1 = " " , s2 = " " ;
int length1, length2;
// dp[prefix of s1 of length x][prefix of s2 of length y]
int dp[2][10005];
int negInf = -10000000;

int main(){
    cin >> temps1 >> temps2;
    s1 += temps1;
    s2+=temps2;
    length1 = (int)s1.length();
    length2 = (int)s2.length();
    for(int i = 1; i < length2; i++){
        if(s1[1] == s2[i]) dp[1][i] =1;
        else dp[1][i] = dp[1][i-1];
    }
    for(int i = 1; i < length1; i++){
        for(int j = 1; j < length2; j++){
            if(s1[i] == s2[j]){
                dp[1][j] = dp[0][j-1] + 1;
            }
            else{
                dp[1][j] = max(dp[0][j], dp[1][j-1]);
            }
        }
        swap(dp[0],dp[1]);
    }
    cout << dp[0][length2-1];
    
}
