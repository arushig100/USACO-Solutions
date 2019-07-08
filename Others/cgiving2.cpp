#include <iostream>
#include <algorithm>
using namespace std;
int n, m,b;
int grid[2501][2501];
int visited[2501];
int ar[2501];
int inf = 1000000;
int main(){
    cin >> n >> m >> b;
    
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            grid[i][j] = inf;
        }
    }
    for(int i = 1; i <= m; i++){
        int a, b, l;
        cin >> a >> b >> l;
        grid[a][b] = min(grid[a][b], l);
        grid[b][a] = grid[a][b];
        
    }
    
    
    for(int i = 1;i <=n; i++){
        ar[i] = inf;
    }
    ar[1] = 0;
        //reset stuff
    for(int i = 1; i <=n; i++){
        int smallest = inf;
        int index;
        // finds neighbor nodes
        for(int j = 1; j <=n; j++){
            if(ar[j] < smallest and !visited[j]){
                smallest = ar[j];
                index = j;
            }
        }
        // updates node
        for(int j = 1; j <=n; j++){
            ar[j] = min(ar[j], grid[index][j]+ar[index]);
        }
        visited[index] = 1;
    }
    
    for(int i = 0; i < b; i++){
        int x, y;
        cin >> x >>y;
        cout << ar[x] + ar[y] << endl;
    }
    
}
