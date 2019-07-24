#include <iostream>
#include <algorithm>
using namespace std;
// n = num of questions, k = num of (num of possible questions)
long long n, k;
long long possibleTrues[10001];
long long maxBestScore =-1;
long long prevIndex = 0;
bool s(int a, int b){
    return a > b;
}
// given how many trues he will guess, find the best score he can achieve
long long bestScore(long long a, long long startIndex, long long endIndex){
    
    long long aFalses = n-a;
    long long answer = 10000000;
    for(long long i = startIndex; i < endIndex and i<k; i++){
        if(abs(aFalses-possibleTrues[i]) < answer){
            answer =abs(aFalses-possibleTrues[i]);
            prevIndex = i;
        }
    }
    return answer;
}


int main(){
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> possibleTrues[i];
    }
    sort(possibleTrues, possibleTrues+k,s);
    maxBestScore = bestScore(0, 0, k+1);
    for(long long i = 1; i <=n; i++){
        maxBestScore = max(maxBestScore, bestScore(i, prevIndex, prevIndex+5));
    }
    cout << maxBestScore;
}

