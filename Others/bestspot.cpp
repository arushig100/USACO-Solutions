#include <iostream>
using namespace std;

// p = total pastures, f = favorite pastures, c = num of paths
int p, f, c;
int favPastures[501];
int adj[501][501];
int inf = 1000000000;
int main(){
    cin >> p >> f >> c;
    for(int i = 1; i <= f; i++){
        cin >> favPastures[i];
    }
    
    // create adjacency matrix
    for(int i = 1; i <=p; i++){
        for(int j = 1; j <= p; j++){
            if(i == j){
                adj[i][j] = 0;
            }
            else{
                adj[i][j] = inf;
            }
        }
    }
    
    // input
    for(int i = 0;i < c; i++){
        int a, b, l;
        cin >> a >> b >> l;
        adj[a][b] = min(adj[a][b],l);
        adj[b][a] = adj[a][b];
    }
    
    //floyd marshall
    for(int k = 1; k <= p; k++){
        for(int i = 1; i <= p; i++){
            for(int j = 1; j <=p; j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    int answer =100000000;
    int pastureAnswer =0;
    for(int i= 1; i <= p; i++){
        int sum = 0;
        for(int j = 1; j <= f;j++){
            sum+= adj[i][favPastures[j]];
        }
        if(sum < answer){
            answer = sum;
            pastureAnswer = i;
        }
    }
    cout << pastureAnswer << endl;
}
