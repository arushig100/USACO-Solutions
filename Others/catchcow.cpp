
#include <iostream>
#include <queue>
using namespace std;
int n, k;
int visited[200000];
int minTime = 10000;

bool legal(int x){
    if(x < 0 or x > 2*k){
        return false;
    }
    return true;
}
void bfs(int x, int t){
    queue<pair<int, int>> q;
    q.push(make_pair(x,t));
    while(!q.empty()){
        if(!legal(x) or t > minTime){
            return;
        }
        visited[x] = 1;
        pair<int, int> a = q.front();
        q.pop();
        x = a.first;
        t = a.second;
        if(x == k){
            minTime = t;
        }
        if(legal(x+1) and !visited[x+1]){
            q.push(make_pair(x+1, t+1));
            visited[x+1] = true;
            
        }
        if(legal(x-1) and !visited[x-1]){
            q.push(make_pair(x-1, t+1));
            visited[x-1] = true;
        }
        if(legal(x*2) and !visited[x*2]){
            q.push(make_pair(x*2, t+1));
            visited[x*2] = true;
        }
    }

}

int main(){
    cin >> n >> k;
    bfs(n,0);
    cout << minTime << endl;
}
