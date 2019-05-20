
#include <iostream>
#include <fstream>
#include<algorithm>
#include<cmath>
using namespace std;

int numSwaps;
int ar[100][3];

// returns the number of points Elsie would get if the pebble started under a certain shell (input)
int findPoints(int shell) {
    int count = 0;
    // swaps the shells and counts the number of right guesses
    for (int i = 0; i < numSwaps; i++) {
        if (ar[i][0] == shell)
            shell = ar[i][1];
        else if (ar[i][1] == shell)
            shell = ar[i][0];
        if (ar[i][2] == shell)
            count++;
    }
    return count;
}

int main() {
    freopen("shell.in","r",stdin);
    freopen("shell.out","w",stdout);
    // input
    cin >> numSwaps;
    for (int i = 0; i < numSwaps; i++) {
        cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    }
    
    int maxPoints = 0;
    for (int i = 1; i <= 3; i++) {
        if (findPoints(i) > maxPoints) {
            maxPoints = findPoints(i);
        }
    }
    cout << maxPoints;
    
}
