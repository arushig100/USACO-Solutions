
#include <iostream>
#include <queue>
using namespace std;

int n, t_max;
int dancing[100000];
priority_queue <int> q;


int findTime(int k){
    for(int i = 0;i  < k; i++){
        q.push(-dancing[i]);
    }
    for(int i = k; i < n; i++){
        int x = q.top();
        q.pop();
        q.push(x-dancing[i]);
        
    }
    int lastElement;
    while(!q.empty()){
        lastElement = q.top();
        q.pop();
    }
    return -lastElement;
}

int answer = -1;
void binarySearch(int l, int r){
    int m = (l + r)/2;
    if(findTime(m) <= t_max){
        answer = m;
        if(findTime(m-1) > t_max){
            return;
        }
        else{
            binarySearch(0,m-1);
        }
    }
    else if(findTime(m) > t_max){
        binarySearch(m+1, r);
    }
}

int main(){
    cin >> n >> t_max;
    for(int i =0 ;i <n; i++){
        cin >> dancing[i];
    }
    binarySearch(0,n-1);
    cout << answer << endl;
}

