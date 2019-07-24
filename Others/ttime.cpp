#include <iostream>
using namespace std;
int n, m, q;
int adj[1001][1001];
int inf = 10000000;
int main(){
    cin >> n >> m >> q;
    // create adjacency matrix
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                adj[i][j] = 0;
            }
            else{
                adj[i][j] = -1;
            }
        }
    }
    
    // input
    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    
    //floyd marshall
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                adj[i][j] = max(adj[i][j], min(adj[i][k],adj[k][j]));
            }
        }
    }
    
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        if(adj[a][b] == 1){
            cout << "Y" << endl;
        }
        else cout << "N" << endl;
    }
}
