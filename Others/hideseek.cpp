#include <iostream>
#include <algorithm>
#include<queue>
#include <vector>
using namespace std;

// n = number of barns, m = number of paths
int n, m;
priority_queue<pair<int, int>>pq;
int visited[20001];
int ar[20001]; // number of pathways to get to each index
vector<int>grid[200001];
int answer = 0;
int main(){
    
    // pair: 1st = length, 2nd = index
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        ar[i] = 10000000;
    }
    for(int i  = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    
    ar[1] = 0;
    // pair(number of paths to get to index, index)
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        pair<int, int>front = pq.top();
        pq.pop();
        int numPathways = -front.first;
        int index = front.second;
        if(!visited[index]){
            for(int i = 0; i < grid[index].size(); i++){
                int neighbor = grid[index].at(i); // neighbor
                if(!visited[neighbor] and  ar[neighbor]>ar[index]+1){
                    ar[neighbor] = ar[index]+1;
                    pq.push(make_pair(-ar[neighbor],neighbor));
                }
            }
        }
        visited[index] = 1;
        
    }
    int maxx = 0;
    for(int i = 1; i <= n; i++){
        if(ar[i] != 10000000 and ar[i] > maxx){
            maxx=max(ar[i],maxx);
        }
    }
    int countMax = 0;
    int lowestIndex = 10000000;
    for(int i = 1; i <=n; i++){
        if(ar[i] == maxx){
            lowestIndex = min(i,lowestIndex);
            countMax++;
        }
    }
    cout << lowestIndex << " " << maxx << " " << countMax << endl;
}

