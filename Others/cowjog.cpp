#include <iostream>
#include <vector>
using namespace std;


long long n,t;
struct group{
    long long beg, speed, end;
};
group cows[100001];
vector<int> v;
int main(){
    cin >> n >> t;
    for(long long i = 0; i < n; i++){
        cin >> cows[i].beg >> cows[i].speed;
    }
    for(long long i = 0; i <n; i++){
        cows[i].end = cows[i].beg + cows[i].speed*t;
    }
    long long counter = 1;
    long long minPos = cows[n-1].end;
    for(long long i = n-2; i >=0; i--){
        if(cows[i].end <cows[i+1].end){
            counter++;
            minPos = cows[i].end;
        }
        else{
            cows[i].end= minPos;
        }
        
    }
    cout << counter << endl;
    
}

