#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
struct point{
    int x;
    int y;
};

bool sorty(point a, point b){
    return a.y < b.y;
}

point ar[100000];
bool inTriangle(point tri, point p){
    int x1b = tri.x-tri.y;
    int x2b = tri.x+tri.y;
    if(p.x >= x1b and p.x <= tri.x and p.y-p.x <= tri.y-tri.x){
        return true;
    }
    if(p.x <= x2b and p.x >= tri.x and p.y + p.x <= tri.y+tri.x ){
        return true;
    }
    return false;
}


int main(){
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    cin >> n;
    for(int i =0 ; i < n; i++){
        cin >> ar[i].x >> ar[i].y;
    }
    sort(ar, ar + n, sorty);
    int count = n;
    bool x= false;
    for(int i = 0; i < n-1; i++){
        for(int j =i+1; j < n; j++){
            if(i!=j and inTriangle(ar[j],ar[i])){
               // cout << ar[j].x << " " << ar[i].x << endl;
                x = true;
                break;
            }
        }
        if(x){
            count--;
            x = false;
        }
    }
    cout << count << endl;
}
