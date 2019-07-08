#include <iostream>
#include <algorithm>
using namespace std;
int n;
int connected[101][101];
int visited[101];
int ar[101];
int inf = 1000000;
int main(){
    cin >> n; // number of farms
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> connected[i][j];
        }
    }
    for(int i = 1;i <=n; i++){
        ar[i] = inf;
    }
    ar[1] = 0;
    
    int ans = 0;
    for(int i = 1; i <=n; i++){
        int smallest = inf;
        int index;
        for(int j = 1; j <=n; j++){
            if(ar[j] < smallest and !visited[j]){
                smallest = ar[j];
                index = j;
            }
        }
        ans+= smallest;
        for(int j = 1; j <=n; j++){
            ar[j] = min(ar[j], connected[index][j]);
        }
        visited[index] = 1;
    }
    cout << ans << endl;

}
