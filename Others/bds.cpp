
#include <iostream>
#include <algorithm>
using namespace std;
int n, finalSum;
int ar[10];

// calculates factorial
int factorial(int n){
    int answer = 1;
    for(int i =1 ;i  <=n; i++){
        answer*=i;
    }
    return answer;
}
// calculates combination
int nCr(int n, int r){
    return factorial(n)/(factorial(n-r)*factorial(r));
}
//calculates coefficient
int coef(int totalNums, int x){
    totalNums--;
    int ans = nCr(totalNums,x);
    return ans;
}


int main(){
    cin >> n >> finalSum;
    for (int i = 0; i < n; i++) {
        ar[i] = i+1;
    }
    for(int i = 0; i < factorial(n); i++){
        int sum = 0;
        for(int j= 0; j <n; j++){
            sum+=coef(n, j)*ar[j];
        }
        if(sum==finalSum){
            break;
        }
        next_permutation(ar, ar+n);
    }
    for(int i = 0; i < n; i++){
        cout << ar[i] << " ";
    }

}


