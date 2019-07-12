#include <iostream>
#include <algorithm>
using namespace std;
// n = num of hours, m = num of intervals, r = rest time
int n, m, r;
struct milking{
    int start, end, efficiency;
};
// dp[index of interval]= max amount of milk
int dp[1005];
milking intervals[1005];
bool s(milking a, milking b){
    return a.start < b.start;
}
int main(){
    cin >> n >> m >> r;
    for(int i = 1; i <= m; i++){
        cin >> intervals[i].start >> intervals[i].end >> intervals[i].efficiency;
    }
    
    // sort starting times of milking
    sort(intervals+1, intervals+m+1, s);
    for(int i = 1; i <= m; i++){
        dp[i] = intervals[i].efficiency;
        for(int j = 1; j < i; j++){
            if(intervals[i].start >= intervals[j].end + r){
                dp[i] = max(dp[i],dp[j] + intervals[i].efficiency);
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <=m; i++){
        answer = max(answer, dp[i]);
    }
    
    cout << answer;
}
