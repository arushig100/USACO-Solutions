
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int t[1000];
int n;
int startTime, endTime, numBuckets;
int main(){
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);
    cin >> n;
    for(int i = 0;i < 1000; i++){
        t[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cin >> startTime >> endTime >> numBuckets;
        // adds the number of buckets needed to the corresponding time slot in the array
        for(int j = startTime; j < endTime; j++){
            t[j] += numBuckets;
        }
    }
    // iterates through array to check for the max number of buckets needed at any time
    int maxBuckets = -1;
    for(int i = 0; i < 1000; i++){
        if(t[i] > maxBuckets){
            maxBuckets = t[i];
        }
    }
    cout << maxBuckets << endl;
}
