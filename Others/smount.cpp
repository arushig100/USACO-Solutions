#include <iostream>
using namespace std;

int n;
int heights[100001];
int maxWidth = 0;
int main(){
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> heights[i];
    }
    bool isIncreasing;
    if(heights[0] > heights[1]) isIncreasing = false;
    else isIncreasing = true;
    int curMountain = 1;
    int numOfDuplicates = 1;
    for(int i =1; i < n; i++){
        if(isIncreasing and heights[i-1] <= heights[i]){
            curMountain++;
        }
        else if(isIncreasing){
            curMountain++;
            isIncreasing = false;
        }
        else if(!isIncreasing and heights[i-1] >= heights[i]){
            curMountain++;
            if(heights[i-1] > heights[i]) numOfDuplicates = 1;
            else numOfDuplicates++;
        }
        else if(!isIncreasing and heights[i-1] < heights[i]){
            maxWidth = max(maxWidth, curMountain);
            isIncreasing = true;
            curMountain = numOfDuplicates+1;
            numOfDuplicates = 1;
        }
        
    }
    maxWidth= max(maxWidth, curMountain);
    cout << maxWidth;
}
