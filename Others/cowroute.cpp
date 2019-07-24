#include <iostream>
using namespace std;
long long a, b, n;
long long tempCities[101];
long long grid[1001][1001];
long long ar[1001];
long long flights[1001];
int visited[1001];
long long numFlights[1001][1001];
long long inf = 100000000000000;
int main(){
    cin >> a >> b >> n;
    // initializing adjancency matrix
    for(int i = 0; i <=1000; i++){
        for(int j= 0; j <=1000; j++){
            grid[i][j] = inf;
            numFlights[i][j] = inf;
        }
    }
    // adjacency matrix
    for(int i = 1; i <= n; i++){
        long long cost, num;
        cin >> cost >> num;
        for(int j= 1; j <=num; j++){
            cin >> tempCities[j];
            for(int k =1; k < j; k++){
                long long x = tempCities[k];
                long long y = tempCities[j];
                if(cost < grid[x][y]){
                    grid[x][y] = cost;
                    numFlights[x][y] = j-k;
                }
                if(cost == grid[x][y]){
                    numFlights[x][y] = min(numFlights[x][y] ,(long long)j-k);
                }
                
            }
        }
    }
    
    for(int i = 1;i <=1000; i++){
        ar[i] = inf;
        flights[i] = numFlights[a][i];
    }
    ar[a] = 0;
    flights[a] = 0;
    for(int i = 1; i <=1000; i++){
        long long smallest = inf;
        long long index;
        // finds neighbor nodes
        for(int j = 1; j <=1000; j++){
            if(ar[j] < smallest and !visited[j]){
                smallest = ar[j];
                index = j;
            }
        }
        // updates node
        for(int j = 1; j <=1000; j++){
            if(grid[index][j]+ar[index] < ar[j]){
                ar[j] = grid[index][j] + ar[index];
                flights[j] = numFlights[index][j] + flights[index];
            }
            else if(grid[index][j]+ar[index] == ar[j]){
                flights[j] = min(flights[j], numFlights[index][j] + flights[index]);
            }
        }
        visited[index] = 1;
        
    }
    if(ar[b] == inf){
        cout << -1 << " " << -1 << endl;
    }
    else cout << ar[b] << " " << flights[b] << endl;
    
}
