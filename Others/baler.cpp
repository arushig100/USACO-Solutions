#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct circle{
    int x, y, radius, index;
};
int n, begX, begY;

int visited[1055];
double sums[1055];
double totalSums[1055];
circle ar[1055];
queue<circle>q;
int startingIndex, endingIndex;

int finalSum = 0;
bool adjacent(circle a, circle b){
    int part1 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    int part2 = (a.radius + b.radius)*(a.radius + b.radius);
    if(part1==part2) return true;
    return false;
}

bool s(circle a, circle b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main(){
    cin >> n >> begX >> begY;
    for(int i = 1; i <= n; i++){
        cin >> ar[i].x >> ar[i].y >> ar[i].radius;
        ar[i].index = i;
        if(ar[i].x==0 and ar[i].y==0){
            startingIndex = i;
        }
        if(ar[i].x==begX and ar[i].y==begY){
            endingIndex = i;
        }
        
    }

    sums[startingIndex] = 10000;
    totalSums[startingIndex] = 10000;
    q.push(ar[startingIndex]);
    while(!q.empty()){
        circle top = q.front();
        q.pop();
        for(int i = 1; i <=n; i++){
            if(adjacent(ar[i],ar[top.index]) and i!=top.index and !visited[i]){
                sums[i] =  sums[top.index]*((double)ar[top.index].radius/ar[i].radius);
                totalSums[i]=totalSums[top.index] +sums[top.index]*((double)ar[top.index].radius/ar[i].radius);
                q.push(ar[i]);
            }
        }
        visited[top.index] = true;
    }
    cout << (int)totalSums[endingIndex] << endl;
}

