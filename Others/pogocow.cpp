#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[1000][1000]; // max number of points at each position + latest jump
struct target{
    int pos, points;
};
bool s(target a, target b){
    return a.pos < b.pos;
}
bool s2(target a, target b){
    return a.pos > b.pos;
}
target arr[1000];
int answer = 0;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].pos >> arr[i].points;
        
    }
    // LEFT TO RIGHT
    sort(arr, arr+n, s);
    for(int j = 0; j < n; j++){
        int index = j-1;
        for(int i = j+1; i < n; i++){
            int maxx = 0;
            for(int k = index; k >=0; k--){
                if(arr[j].pos-arr[k].pos <= arr[i].pos-arr[j].pos){
                    if(dp[j][k] > maxx){
                        maxx = dp[j][k];
                        index = k;
                    }
                }
                else{
                    break;
                }
            }
            dp[i][j] = maxx + arr[i].points;
            if(maxx == 0){
                dp[i][j] = arr[i].points + arr[j].points;
            }
            dp[i][j] = max(arr[i].points + dp[i-1][j] - arr[i-1].points, dp[i][j]);
            answer = max(answer, dp[i][j]);
        }
        
    }
    // reset dp array
    for(int i = 0; i <1000; i++){
        for(int j = 0; j < 1000; j++){
            dp[i][j] = 0;
        }
    }
    // RIGHT TO LEFT
    sort(arr, arr+n, s2);
    for(int j = 0; j < n; j++){
        int index = j-1;
        for(int i = j+1; i < n; i++){
            int maxx = 0;
            for(int k = index; k >=0; k--){
                if(arr[k].pos-arr[j].pos<= arr[j].pos-arr[i].pos){
                    if(dp[j][k] > maxx){
                        maxx = dp[j][k];
                        index = k;
                    }
                }
                else{
                    break;
                }
            }
            dp[i][j] = maxx + arr[i].points;
            if(maxx == 0){
                dp[i][j] = arr[i].points + arr[j].points;
            }
            dp[i][j] = max(arr[i].points + dp[i-1][j] - arr[i-1].points, dp[i][j]);
            answer = max(answer, dp[i][j]);
        }
    }
    cout <<answer;
}

