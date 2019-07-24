#include <iostream>
#include <algorithm>
#include<queue>
#include <vector>
using namespace std;

int v, e,s;
priority_queue<pair<int, int>>pq;
int visited[50001];
int ar[50001];
vector<pair<int, int>>grid[50001];
int answer = 0;
int main(){
    // pair: 1st = length, 2nd = index
        cin >> v >> e >> s;
    for(int i = 0; i <= v; i++){
        ar[i] = 10000000;
    }
    for(int i  = 1; i <= e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        grid[a].push_back(make_pair(-c,b));
        grid[b].push_back(make_pair(-c,a));
        
    }
    ar[s] = 0;
    pq.push(make_pair(0,s));
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
    for(int i = 1; i <= v; i++){
        if(ar[i] != 10000000)
            cout << ar[i] << endl;
        else
            cout << -1 <<endl;
    }
}


