
#include <iostream>
using namespace std;

int r, c,k;
int ar[100][100];
long long int dp[100][100];
int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        for(int j =0; j < c; j++)
            cin >> ar[i][j];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            long long sum = 0;
            for(int a = 0; a <= i-1; a++){
                for(int b = 0; b <=j-1; b++){
                    if(ar[a][b] != ar[i][j]){
                        sum+= dp[a][b]%1000000007;
                        if(a == 0 and b == 0) sum+=1;
                    }
                }
            }
            dp[i][j] = sum%1000000007;
        }
    }
    cout << dp[r-1][c-1] % 1000000007;
}
