
#include <iostream>
using namespace std;
int n, m;
int order[10000];
int islands[101][101];
int main(){
    cin >> n >> m;
    for(int i =0; i < m; i++){
        cin >> order[i];
    }
    
    for(int i = 1; i <=n; i++){
        for(int j=  1; j <=n; j++){
            cin >> islands[i][j];
        }
    }
    // floyd marshall
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                islands[i][j] = min(islands[i][j], islands[i][k] + islands[k][j]);
            }
        }
    }
    // find answer
    int totalDanger = 0;
    for(int i =0 ;i<m-1; i++){
        totalDanger += islands[order[i]][order[i+1]];
    }
    cout << totalDanger << endl;
}

