
#include <iostream>
using namespace std;
int n;
int ar[30005];
int dp1[30005][4]; // [index][id number] = min number of changes up to that index so that the current index cow has a certain id number
int dp2[30005][4];
int answer = 1000000;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }

    //ascending order
    for(int i = 1; i <= n; i++){
        dp1[i][1] = dp1[i-1][1] + (ar[i]!=1);
        dp1[i][2] = min(dp1[i-1][1], dp1[i-1][2]) + (ar[i]!=2);
        dp1[i][3] = min(dp1[i-1][1], min(dp1[i-1][2], dp1[i-1][3])) + (ar[i] !=3);
        
    }
    answer = min(dp1[n][1], min(dp1[n][2], dp1[n][3]));
    
    
    
    for(int i = 1; i <= n; i++){
        dp2[i][3] = dp2[i-1][3] + (ar[i]!=3);
        dp2[i][2] = min(dp2[i-1][3], dp2[i-1][2]) + (ar[i]!=2);
        dp2[i][1] = min(dp2[i-1][1], min(dp2[i-1][2], dp2[i-1][3])) + (ar[i] !=1);
        
    }
    answer = min(dp2[n][1], min(dp2[n][2], min(dp2[n][3], answer)));
    cout << answer;

}
