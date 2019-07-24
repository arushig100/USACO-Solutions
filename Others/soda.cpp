#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct cows{
    int pos, se;
};

int n;
int ar[50001][2];

cows greedy[100001];
int answer[100001];
bool s(cows a, cows b){
    if(a.pos == b.pos){
        return a.se == 0;
    }
    else return a.pos < b.pos;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ar[i][0] >> ar[i][1];
        cows a;
        a.pos = ar[i][0];
        a.se = 0;
        cows b;
        b.pos = ar[i][1];
        b.se = 1;
        greedy[i*2] = a;
        greedy[i*2+1]=b;;
    }
    
    sort(greedy, greedy + n*2, s);
    int ans = 0;
    for(int i = 0; i < n*2; i++){
        if(greedy[i].se == 0){
            ans++;
        }
        else if(greedy[i].se == 1){
            ans--;
        }
        answer[i] = ans;
    }
    int finalAnswer = -1;
    for(int i =0; i < n*2; i++){
        finalAnswer = max(finalAnswer, answer[i]);
    }
    cout << finalAnswer << endl;
    
}
