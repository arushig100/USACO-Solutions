#include <iostream>
#include <algorithm>
using namespace std;
int t, c,ts,te;
int grid[2501][2501];
int visited[2501];
int ar[2501];
int inf = 1000000;
int main(){
    cin >> t >> c >> ts >> te;
    
    for(int i = 1; i <= t; i++){
        for(int j =1; j <= t; j++){
            grid[i][j] = inf;
        }
    }
    for(int i = 1; i <= c; i++){
        int a, b, l;
        cin >> a >> b >> l;
        grid[a][b] = min(grid[a][b], l);
        grid[b][a] = grid[a][b];
        
    }
    
    
    for(int i = 1;i <=t; i++){
        ar[i] = inf;
    }
    ar[ts] = 0;
    
    for(int i = 1; i <=t; i++){
        int smallest = inf;
        int index;
        // finds neighbor nodes
        for(int j = 1; j <=t; j++){
            if(ar[j] < smallest and !visited[j]){
                smallest = ar[j];
                index = j;
            }
        }
        // updates node
        for(int j = 1; j <=t; j++){
            ar[j] = min(ar[j], grid[index][j]+ar[index]);
        }
        visited[index] = 1;
        
    }
    cout << ar[te] << endl;
}
