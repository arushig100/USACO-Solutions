
#include <iostream>
using namespace std;
int p;
int dist[54][54];
int inf = 1000000;
int main(){
    cin >> p;
    
    // intialize array dist
    for(int i = 1; i <53; i++){
        for(int j = 1; j < 53; j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = inf;
            }
        }
    }
    
    // input
    for(int i = 0;i < p; i++){
        char a, b;
        int a1, b1;
        int l;
        cin >> a >> b >> l;
        // converts letters to numbers
        if((int)a > 90){
            a1 = (int)(a -'a')+1;
        }
        else{
            a1 = (int)(a-'A')+27;
        }
        if((int)b > 90){
            b1 = (int)(b -'a')+1;
        }
        else{
            b1 = (int)(b-'A')+27;
        }
        //cout << a1 << " " << b1 << endl;
        // add lengths in inputs to array dist
        dist[a1][b1] = min(dist[a1][b1],l);
        dist[b1][a1] = min(dist[b1][a1],l);

    }
    // uses floyd marshall
    for(int k = 1; k <= 52; k++){
        for(int i = 1; i <= 52; i++){
            for(int j = 1; j <=52; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int minn = inf;
    int ans = 0;
    for(int i =27; i <=51; i++){
        if(dist[i][52] <minn){
            minn = dist[i][52];
            ans = i;
        }
    }
    ans= ans-27+65;
    char answer = (char)ans;
    cout << answer << " " << minn << endl;
}

