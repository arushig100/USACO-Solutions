
#include <iostream>
using namespace std;
int n, m;
int rounds[4501][2];
int adj[101][101];
int finalCount = 0;
int main(){
    cin >> n >> m;
    // input
    for(int i = 1; i <=m; i++){
        cin >> rounds[i][0] >> rounds[i][1];
        adj[rounds[i][0]][rounds[i][1]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j =1; j <=n; j++){
            if(i==j) adj[i][j] = 1;
        }
    }
    // floyd marshall
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<=n; j++){
                if(adj[i][k] and adj[k][j]){
                    adj[i][j] = 1;
                }
            }
        }
    }
    // check for how many are known
    
    for(int i = 1; i <=n; i++){
        int count = 0;
        for(int j = 1; j <=n; j++){
            if(adj[i][j] ==1 or adj[j][i] == 1){
                count++;
            }
        }
        if(count == n){
            finalCount++;
        }
    }
    cout << finalCount << endl;
}
