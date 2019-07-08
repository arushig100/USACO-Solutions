#include <iostream>
#include <vector>
using namespace std;

int n, q;
int visited[1001];
int endPasture = 0;
int answer;
struct s{
    int node, length;
};
vector <s> adj[1001];

void recur(int curPas, int length){
    if(curPas == endPasture){
        answer = length;
        return;
    }
    else{
        for(int i =0; i < adj[curPas].size(); i++){
            if(!visited[adj[curPas].at(i).node]){
                visited[adj[curPas].at(i).node] = 1;
                recur(adj[curPas].at(i).node,length+adj[curPas].at(i).length);
            }
        }
    }
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int a, b, l;
        cin >> a >> b >>l;
        s neww;
        neww.node = b;
        neww.length = l;
        adj[a].push_back(neww);
        neww.node = a;
        adj[b].push_back(neww);
    }
    
    for(int j = 0; j < q; j++){
        int a, b;
        cin >> a >> b;
        for(int i = 1; i < n+1; i++){
            visited[i] = 0;
        }
        visited[a] = 1;
        endPasture = b;
        recur(a, 0);
        cout << answer << endl;
        
    }
}
