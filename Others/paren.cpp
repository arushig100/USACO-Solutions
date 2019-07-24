#include <iostream>
#include <vector>
#include <stack>
using namespace std;
long long n;
long long ar[100001];
long long far[100001];
long long answer = 0;
stack<int>s;

long long solve(long long left, long long right){
    if(left + 1 == right){
        return 1%12345678910;
    }
    else{
        if(far[left] == right){
            return 2*solve(left+1, right-1)%12345678910;
        }
        else{
            return solve(left, far[left]) + solve(far[left] + 1, right)%12345678910;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        if(ar[i] == 0){
            s.push(i);
        }
        else if(ar[i] == 1){
            far[s.top()] =i;
            s.pop();
        }
    }
    cout << solve(0, n-1)%12345678910;
    
    
}


