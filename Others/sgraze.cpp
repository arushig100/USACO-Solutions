#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct c{
    int start, end;
};
c cows[50000];
bool s(c a, c b){
    return a.end < b.end;
}
int main(){
    cin >> n;
    // input
    for(int i =0; i < n; i++){
        cin >> cows[i].start >> cows[i].end;
    }
    // sorts the ends
    sort(cows, cows+n, s);
    int curEnd = cows[0].end;
    int answer = 1;
    for(int i = 1; i < n; i++){
        if(cows[i].start >= curEnd){
            curEnd = cows[i].end;
            answer++;
        }
    }
    cout << answer;
}

