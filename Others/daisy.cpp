
#include <iostream>
using namespace std;
int n, m;
int pairs[251][251];
int misbehave[251];
void recur(int curCow){
    for(int i = 1; i < n+1; i++){
        if(pairs[curCow][i] ==1 and misbehave[i] == 0){
            misbehave[i] = 1;
            recur(i);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i =0; i < m; i++){
        int a, b;
        cin >> a >> b;
        pairs[a][b] = 1;
        pairs[b][a] = 1;
    }
    misbehave[1] = 1;
    recur(1);
    int count = 0;
    for(int i =1 ;i < n+1; i++){
        if(misbehave[i] == 0){
            count++;
            cout << i << endl;
        }
        
    }
    if(count ==0){
        cout << 0 << endl;
    }
    
}
