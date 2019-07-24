#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int>grid[10001];

// k = num of cows, n = num of pastures, m = num of paths
int k, n, m;
int cows[101];
int ar[1001];
int visited[1001];
int possible[1001];
queue<pair<int, int>>pq;
int main(){
    cin >> k >> n >> m;
    for(int i = 0; i < k; i++) cin >> cows[i];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
    }
    for(int t = 0; t <k; t++){
        for(int i = 0; i <= n; i++){
            ar[i] = 0;
            visited[i] = 0;
        }
        ar[cows[t]] = 1;
        pq.push(make_pair(1,cows[t]));
        while(!pq.empty()){
            pair<int, int>front = pq.front();
            pq.pop();
            int index = front.second;
            // cout << cost << " " << index << endl;
            if(!visited[index]){
                for(int i = 0; i < grid[index].size(); i++){
                    int a = grid[index].at(i); // neighbor
                    if(!visited[a] and  ar[a]==0){
                        ar[a] = 1;
                        pq.push(make_pair(1,a));
                    }
                }
            }
            visited[index] = 1;
        }
        for(int i = 1; i <=n; i++){
            if(ar[i]){
                possible[i]++;
            }
        }
    }
    int counter =0;
    for(int i = 1; i <= n; i++){
        if(possible[i] == k){
            counter++;
        }
    }
    cout << counter << endl;
}

