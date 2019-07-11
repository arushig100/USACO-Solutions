#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int n, m;
int farms[1002][2];
int preRoads[1001][2];
double grid[1001][1001];
double ar[1001];
int visited[1001];
int inf = 100000000;

double round(double x){
    double y = (int)(x*100 + 0.5);
    return (double)y/100.0;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> farms[i][0] >> farms[i][1];
    }
    for(int i = 1; i <= m; i++){
        cin >> preRoads[i][0] >> preRoads[i][1];
    }
    for(int i = 1; i <=n; i++){
        for(int j= 1; j <= n; j++){
            if(j==i){
                grid[i][j] = 0;
            }
            else{
                grid[i][j] = sqrt((double)((double)farms[i][0] - farms[j][0])*(double)((double)farms[i][0] - farms[j][0]) + (double)((double)farms[i][1] - farms[j][1])*(double)((double)farms[i][1] - farms[j][1]));
            }
        }
    }
    for(int i = 1; i <= m; i++){
        grid[preRoads[i][0]][preRoads[i][1]] = 0;
        grid[preRoads[i][1]][preRoads[i][0]] = 0;
    }
    for(int i = 1;i <=n; i++){
        ar[i] = inf;
    }
    ar[1] = 0;
    double ans = 0.0;
    for(int i = 1; i <=n; i++){
        double smallest = inf;
        int index;
        for(int j = 1; j <=n; j++){
            if(ar[j] < smallest and !visited[j]){
                smallest = ar[j];
                index = j;
            }
        }
        ans+= smallest;
        for(int j = 1; j <=n; j++){
            ar[j] = min((double)ar[j], (double)grid[index][j]);
        }
        visited[index] = 1;
    }
    int counter = 0;
    for(int i = 1;i <= n; i++){
        if(ar[i] != inf){
            counter++;
        }
    }
    cout << fixed<<setprecision(2)<<ans << endl;
    
}
