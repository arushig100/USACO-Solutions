#include <iostream>
using namespace std;

struct cow{
    int h, v;
};
int n;
cow ar[50000];
int volumes[50000];
int maxVol = 0;
int main(){
    cin >> n;
    for(int i = 0;i < n; i++){
        cin >> ar[i].h >> ar[i].v;
    }
    for(int i = 0; i <n; i++){
        
        int count = 0;
        int last = 0;
        // from cow position to right
        if(i+1 < n and ar[i+1].h < ar[i].h){
            count+=ar[i+1].v;
            last = ar[i+1].h;
            for(int j= i+2; j < n; j++){
                if( ar[j].h > ar[i].h){
                    break;
                }
                else if( ar[j].h > last){
                    last = ar[j].h;
                    count+= ar[j].v;
                }
            }
        }
        // from cow position to left
        if(i-1 >= 0 and ar[i-1].h < ar[i].h){
            count+=ar[i-1].v;
            last = ar[i-1].h;
            for(int j= i-2; j >=0; j--){
                if( ar[j].h > ar[i].h){
                    break;
                }
                else if(ar[j].h > last){
                    last = ar[j].h;
                    count+= ar[j].v;
                }
            }
        }
        volumes[i] = count;
    }
    for(int i = 0; i < n; i++){
        if(volumes[i] > maxVol){
            maxVol = volumes[i];
        }
    }
    cout << maxVol << endl;
}

