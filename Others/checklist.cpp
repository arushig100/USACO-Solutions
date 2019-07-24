#include <iostream>
using namespace std;
long long g, h;
struct point{
    int x, y;
};
point arh[1001];
point arg[1001];
long long dp[1001][1001][2]; // dp[index of h][index of g][current cow, h or g] = minimum energy
long long inf = 100000000000;
int findDistance(point a, point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
int main(){
    cin >> h >> g;
    for(long long i =1 ; i <= h; i++){
        cin >> arh[i].x >> arh[i].y;
    }
    for(long long i = 1; i <=g; i++){
        cin >> arg[i].x >> arg[i].y;
    }
    for(long long i = 0; i <=h; i++){
        for(long long j = 0; j <= g; j++){
            dp[i][j][0] = inf;
            dp[i][j][1] = inf;
        }
    }
    
    dp[1][0][0] = 0;
    for(long long i = 1; i <=h ; i++){
        for(long long j = 0; j <=g; j++){
            if(i!=1 or j!=0){
                dp[i][j][0] = dp[i-1][j][1] + findDistance(arg[j], arh[i]);
                dp[i][j][0] = min(dp[i-1][j][0] + findDistance(arh[i-1], arh[i]), dp[i][j][0]);
            }
            if(j!=0){
                dp[i][j][1] = dp[i][j-1][0] + findDistance(arh[i], arg[j]);
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + findDistance(arg[j-1], arg[j]));
            }
        }
    }
    cout << dp[h][g][0];

}
