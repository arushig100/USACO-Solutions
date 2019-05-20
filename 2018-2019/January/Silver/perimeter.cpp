#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
char ar[1000][1000];
bool visited[1000][1000];
int area = 0;
int maxarea = 0;
int perimeter = 0;
int lowper = 100000000;
//finding perimeter
//find number of neighbors of a cell
int neigh(int x, int y){
    int c = 0;
    
        if( x < n-1 and ar[x+1][y] == '#'){
            c++;
        }
        if(x > 0 and ar[x-1][y] == '#'){
            c++;
        }
        if(y < n-1 and ar[x][y+1] == '#'){
            c++;
        }
        if( y > 0 and ar[x][y-1] == '#'){
            c++;
        }
    
    return c;
}

//finding area
void largestarea(int x, int y){
    // if visited or out of bounds
    if(visited[x][y] or x < 0 or y < 0 or x >= n or y >=n){
        return;
    }
    // if '.'
    else if(ar[x][y] == '.'){
        visited[x][y] = true;
        return;
    }
    //area +1, recurse in all directions
    else{
        perimeter += (4-neigh(x,y));
        area++;
        visited[x][y] = true;
        largestarea(x, y-1);
        largestarea(x-1, y);
        largestarea(x+1, y);
        largestarea(x, y+1);
    }
}

int main(){
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
            cin >> ar[i][j];
        }
    }
    for(int i =0; i < n;i++){
        for(int j = 0; j < n; j++){
            largestarea(i, j);
            //finds perimeter if already max area
            if(maxarea == area and perimeter < lowper ){
                lowper = perimeter;
            }
            //updates max area
            else if(area > maxarea){
                maxarea = area;
                lowper = perimeter;
            }
            //resets area and perimeter
            area =0;
            perimeter = 0;
        }  
    }
    cout << maxarea << " " << lowper <<  endl;
}
