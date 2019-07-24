#include <iostream>
#include <algorithm>
#include<queue>
#include <vector>
using namespace std;

int n,m;
priority_queue<pair<int, int>>pq;
int visited[50001];
int ar[50001];
vector<pair<int, int>>grid[50001];
int answer = 0;
int main(){
    
    // pair: 1st = length, 2nd = index
    // n barns, m paths
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        ar[i] = 1000000000;
    }
    for(int i  = 1; i <= m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        grid[a].push_back(make_pair(-c,b));
        grid[b].push_back(make_pair(-c,a));
        
    }
    ar[1] = 0;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        pair<int, int>front = pq.top();
        pq.pop();
        int cost = -front.first;
        int index = front.second;
        if(!visited[index]){
            for(int i = 0; i < grid[index].size(); i++){
                int b = -grid[index].at(i).first; // cost
                int a = grid[index].at(i).second; // neighbor
                if(!visited[a] and  ar[a]>b+ar[index]){
                    ar[a] = b+ar[index];
                    pq.push(make_pair(-ar[a],a));
                }
            }
        }
        visited[index] = 1;
        
    }
    cout << ar[n] << endl;
}
