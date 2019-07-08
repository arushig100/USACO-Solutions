#include <iostream>
using namespace std;
int n,c;
int fields[2000][2];
int fields2[2000][2000];
int visited[2001];
int ar[2001];
int inf = 1000000;
int main(){
    cin >> n >> c;
    
    for(int i = 0; i < n; i++){
        cin >> fields[i][0] >> fields[i][1];
    }
    for(int i = 0; i <n; i++){
        for(int j= 0; j < n; j++){
            if(j==i){
                fields2[i][j] = 0;
            }
            else{
                fields2[i][j] = (fields[i][0] - fields[j][0])*(fields[i][0] - fields[j][0]) + (fields[i][1] - fields[j][1])*(fields[i][1] - fields[j][1]);
                if(fields2[i][j] < c){
                    fields2[i][j] = inf;
                }
            }
        }
    }
    
    for(int i = 0;i <n; i++){
        ar[i] = inf;
    }
    ar[0] = 0;
    
    int ans = 0;
    for(int i = 0; i <n; i++){
        int smallest = inf;
        int index;
        for(int j = 0; j <n; j++){
            if(ar[j] < smallest and !visited[j]){
                smallest = ar[j];
                index = j;
            }
        }
        ans+= smallest;
        for(int j = 1; j <=n; j++){
            ar[j] = min(ar[j], fields2[index][j]);
        }
        visited[index] = 1;
    }
    int counter = 0;
    for(int i = 0;i < n; i++){
        if(ar[i] != inf){
            counter++;
        }
    }
    if(counter != n){
        cout << -1;
    }
    else{
        cout << ans << endl;
    }

    
}

