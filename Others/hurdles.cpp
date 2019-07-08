#include <iostream>
using namespace std;
int numStations, numPaths, numTasks;
int best[301][301];
int inf = 100000000;
int main(){
    cin >> numStations >> numPaths >> numTasks;
    // intialize array dist
    for(int i = 1; i <301; i++){
        for(int j = 1; j < 301; j++){
            if(i == j){
                best[i][j] = 0;
            }
            else{
                best[i][j] = inf;
            }
        }
    }
    
    // input
    for(int i = 0;i < numPaths; i++){
        int a, b, l;
        cin >> a >> b >> l;
        best[a][b] = min(best[a][b],l);
    }
    
    //floyd marshall
    for(int k = 1; k <= 300; k++){
        for(int i = 1; i <= 300; i++){
            for(int j = 1; j <=300; j++){
                best[i][j] = min(best[i][j], max(best[i][k],best[k][j]));
            }
        }
    }
    // tasks
    for(int i = 0; i < numTasks; i++){
        int a, b;
        cin >> a >>b;
        if(best[a][b] == inf){
            cout << -1 << endl;
        }
        else{
            cout << best[a][b] << endl;
        }
    }
}
