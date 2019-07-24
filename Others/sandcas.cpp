#include <iostream>
#include <algorithm>
using namespace std;
int n, x, y;
int merlons[100001];
int changed[100001];
int main(){
    cin >> n >> x >> y;
    for(int i= 0; i < n; i++){
        cin >> merlons[i] >> changed[i];
    }
    sort(merlons, merlons+n);
    sort(changed, changed+n);
    
    int remove = 0;
    int add = 0;
    for(int i = 0; i < n; i++){
        if(merlons[i] > changed[i]){
            remove += merlons[i]-changed[i];
        }
        else{
            add += changed[i] - merlons[i];
        }
    }
    cout << x*add + y*remove << endl;
}

