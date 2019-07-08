
#include <iostream>
#include <algorithm>
using namespace std;
int v, e,s;
int grid[2501][2501];
int visited[2501];
int ar[2501];
int inf = 1000000;
int main(){
    cin >> v >> e >> s;
    
    for(int i = 1; i <= v; i++){
        for(int j =1; j <= v; j++){
            grid[i][j] = inf;
        }
    }
    for(int i = 1; i <= e; i++){
        int a, b, l;
        cin >> a >> b >> l;
        grid[a][b] = min(grid[a][b], l);
        grid[b][a] = grid[a][b];

    }

    
    for(int i = 1;i <=v; i++){
        ar[i] = inf;
    }
    ar[s] = 0;
    
    for(int i = 1; i <=v; i++){
        int smallest = inf;
        int index;
        // finds neighbor nodes
        for(int j = 1; j <=v; j++){
            if(ar[j] < smallest and !visited[j]){
                smallest = ar[j];
                index = j;
            }
        }
        // updates node
        for(int j = 1; j <=v; j++){
            ar[j] = min(ar[j], grid[index][j]+ar[index]);
        }
        visited[index] = 1;
        
    }
    for(int i = 1; i <= v; i++){
        if(ar[i] == inf){
            cout << -1 << endl;
        }
        else{
            cout << ar[i] << endl;
        }
    }
}

