#include <iostream>
#include <algorithm>
#include<queue>
#include <vector>
using namespace std;

int v, e;
priority_queue<pair<int, int>>pq;
int visited[50001];
int ar[50001];
vector<pair<int, int>>grid[50001];
int answer = 0;
int main(){
    cin >> v >> e;
    for(int i = 0; i <= v; i++){
        ar[i] = 10000000;
    }
    for(int i  = 1; i <= e; i++){
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
        cout << cost << " " << index << endl;
        if(!visited[index]){
            for(int i = 0; i < grid[index].size(); i++){
                int b = -grid[index].at(i).first; // cost
                int a = grid[index].at(i).second; // neighbor
                if(!visited[a] and  ar[a]>b){
                    ar[a] = b;
                    pq.push(grid[index].at(i));
                }
            }
        }
        visited[index] = 1;
        
    }
    int answer = 0;
    for(int i = 1; i <= v; i++){
        answer+= ar[i];
        
    }
    cout << answer << endl;
}

