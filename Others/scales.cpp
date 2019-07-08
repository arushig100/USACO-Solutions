
#include <iostream>
using namespace std;

int n, c;
int weights[1000];
int weight[1000];
int totalWeight = 0;
int answer = 0;

// if current index and next index weight is less than c, take current index weight
// if current index weight is greater than c, don't take it

void recur(int idx, int minWeight){
    if(idx == n){
        if(c-minWeight > answer){
            answer = c-minWeight;
        }
    }
    else{
        if(weight[idx] + weight[idx+1] <= minWeight){
            recur(idx+1, minWeight-weight[idx]);
        }
        else if(weight[idx] > minWeight){
            recur(idx+1, minWeight);
        }
        else if(weight[idx] <= minWeight and weight[idx] + weight[idx+1] > minWeight){
            recur(idx+1, minWeight-weight[idx]);
            recur(idx +1, minWeight);
        }
        
    }
    
}

int main(){
    cin >> n >> c;
    for(int i =0 ;i <n; i++){
        cin >> weights[i];
        weight[n-i-1] = weights[i];
    }
    recur(0,c);
    cout << answer << endl;
    
}



