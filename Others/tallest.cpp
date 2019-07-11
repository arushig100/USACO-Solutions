#include <iostream>
#include <algorithm>
using namespace std;
int n, i, h, r;
int ar[10000];
int visited[100][100];
int a, b;

struct point{
    int x;
    int y;
};

point list[10000];

bool s(point a, point b){
    return a.x > b.x;
}
int main(){
    cin >> n >> i >> h >> r;
    // sets everything to max
    for(int i =0;i  < n; i++){
        ar[i] = h;
    }
    // takes in list
    for(int i =0 ;i <r; i++){
        cin >> list[i].x >> list[i].y;
        
        if(list[i].x > list[i].y){
            int temp = list[i].x;
            list[i].x = list[i].y;
            list[i].y = temp;
        }
    }
    // sorts list
    sort(list, list+r, s);
    // removes duplicates
    for(int i = 0; i <r-1 ;i++){
        if(list[i+1].x == list[i].x and list[i+1].y == list[i].y){
            list[i].x = 0;
            list[i].y = 0;
        }
    }    
    for(int i = 0; i <r; i++){
        a = list[i].x-1;
        b = list[i].y-1;
        for(int j = a+1; j < b; j++){
            ar[j]--;
        }
        
    }
    for(int i =0 ; i < n; i++){
        cout << ar[i] << endl;
    }
    
}
