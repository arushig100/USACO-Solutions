#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int barn1[11];
int barn2[11];
int sums[2000];


void recur(int b1[11], int b2[11], int sum, int count, int index){
    if(count == 4){
        bool y = true;
        for(int i = 0; i < 10; i++){
            if(b1[i] == 0){
                y = false;
            }
        }
        if(y){
            sums[1000+sum] = 1;
        }
        return;
    }
    else{
        //moving to barn 2
        if(count%2 == 0){
            for(int i = 0; i < 10; i++){
                int x = b2[index];
                b2[index] = b1[i];
                sum-=b1[i];

                b1[i] = 0;
                recur(b1, b2, sum, count+1, i);
                b1[i] = b2[index];
                sum+=b1[i];
                b2[index] = x;
            }
        }
        // moving to barn 1
        else{
            for(int i =0 ;i < 11; i++){
                int x = b1[index];
                b1[index] = b2[i];
                sum += b2[i];
                b2[i] = 0;
                recur(b1, b2, sum , count+1, i);
                b2[i] = b1[index];
                sum-=b2[i];
                b1[index] = x;
                
            }
            
        }
    }
}


int main(){
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    for(int i =0; i < 10; i++){
        cin >> barn1[i];
    }
    for(int i =0; i < 10; i++){
        cin >> barn2[i];
    }
    barn1[10] = 0;
    barn2[10] = 0;
    for(int i =0; i < 2000; i++){
        sums[i] = 0;
    }
    recur(barn1, barn2, 0, 0, 11);
    sums[1000] = 1;
    int count = 0;
    for(int i =0; i < 2000; i++){
        if(sums[i] == 1){
            count++;
            //cout << i << " ";
        }
    }
    cout << count;
}
