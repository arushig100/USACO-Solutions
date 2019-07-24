#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

long long l,m,n;
long long rocks[50002];
long long minPossible = 10000000000;

bool isPossible(long long x){
    long long safe = 0;
    long long curIndex = 1;
    long long removed = 0;
    
    for(long long i = 1; i <= n; i++){
        if(rocks[i]-safe < x){
            removed++;
        }
        else {
            safe = rocks[i];
        }
    }
    if(removed > m){
        return false;
    }
    return true;
}

void binarySearch(long long start, long long end){
    if(end < start){
        return;
    }
    long long mid = start+(end-start)/2;
    if(isPossible(mid)){
        minPossible = mid;
        return binarySearch(mid+1, end);
    }
    else{
        return binarySearch(start, mid-1);
    }
}

int main(){
    cin >> l >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> rocks[i];
    rocks[n + 1] = l;
    sort(rocks, rocks+n+1);
    binarySearch(0,l);
    cout << minPossible << endl;
    
}
