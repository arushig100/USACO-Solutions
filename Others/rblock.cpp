
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int n, m;
int farm[101][101];
int pathways[10000][3];
int ar[101];
int visited[101];
int inf = 1000000000;
int maxNum = 0;
int normalAnswer;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            farm[i][j] = inf;
            if(i==j){
                farm[i][j] = 0;
            }
        }
    }
    // adjacency matrix
    for(int i =1; i <= m; i++){
        int a, b, l;
        cin >> a >> b >> l;
        farm[a][b] = min(farm[a][b], l);
        farm[b][a] = farm[a][b];
        pathways[i][0] = a;
        pathways[i][1] = b;
        pathways[i][2] = l;
    }
    
    //normal dijkstra to find shortest distance without lengthening any paths
    for(int i = 1;i <=n; i++){
        ar[i] = inf;
        visited[i] = 0;
    }
    ar[1] = 0;
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
            ar[j] =min(ar[j], (farm[index][j]+ar[index]));
        }
        visited[index] = 1;
    }
    normalAnswer = ar[n];
 
    // for each pathway, remove it and do dijkstras to find the new shortest path
    for(int i = 1; i<=m; i++){
        farm[pathways[i][0]][pathways[i][1]] = pathways[i][2]*2;
        farm[pathways[i][1]][pathways[i][0]] = pathways[i][2]*2;
        //resets
        for(int i = 1;i <=n; i++){
            ar[i] = inf;
            visited[i] = 0;
        }
        //dijkstra
        ar[1] = 0;
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
                ar[j] =min(ar[j], (farm[index][j]+ar[index]));
            }
            visited[index] = 1;
        }
        // updates max min length
        if(ar[n] > maxNum){
            maxNum = ar[n];
        }
        //resets
        farm[pathways[i][0]][pathways[i][1]] = pathways[i][2];
        farm[pathways[i][1]][pathways[i][0]] = pathways[i][2];

    }
    cout << maxNum-normalAnswer << endl;
}

