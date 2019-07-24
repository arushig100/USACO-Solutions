#include <iostream>
#include <algorithm>
using namespace std;
int n;
int original[1001];
int sorted[1001];
int swaps =0;
int main(){
    cin >> n;
    for(int i =0 ; i < n; i++){
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted, sorted +n);
    int one2 = 0;
    int one3 = 0;
    int two1 = 0;
    int two3 = 0;
    int three1 = 0;
    int three2 = 0;
    for(int i = 0; i < n; i++){
        if(original[i] == 1 and sorted[i] == 2) one2++;
        else if(original[i] == 1 and sorted[i] == 3) one3++;
        else if(original[i] == 2 and sorted[i] == 3) two3++;
        else if(original[i] == 2 and sorted[i] == 1) two1++;
        else if(original[i] == 3 and sorted[i] == 1) three1++;
        else if(original[i] == 3 and sorted[i] == 2) three2++;
    }
    
    swaps+=  min(one2, two1);
    one2-=  min(one2, two1);
    two1-=  min(one2, two1);
    
    swaps+= min(two3, three2);
    two3-= min(two3, three2);
    three2-= min(two3, three2);
    
    swaps+= min(three1, one3);
    one3-= min(three1, one3);
    three1-= min(three1, one3);
    
    swaps+= (one2+one3)*2;
    cout << swaps << endl;
    
}
