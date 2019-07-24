#include <iostream>
using namespace std;
int n;
int elsie[50005];
int determineOtherCards[100005];
int bessie[50005];
int wins = 0;
bool s(int a, int b){
    return a > b;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> elsie[i];
        determineOtherCards[elsie[i]] = true;
    }
    int counter = 0;
    for(int i = 1; i <= n*2; i++){
        if(!determineOtherCards[i]){
            bessie[counter] = i;
            counter++;
        }
    }
    // sort first half of eslies, sort all of bessies so its a decreasing sequence
    sort(elsie, elsie+n/2, s);
    sort(bessie, bessie+n, s);

   
    // do first half of game (person with highest card wins)
    int p1 = 0; // elsie
    int p2 = 0; // bessie
    while(p1 < n/2 and p2 < n){
        // bessie wins
        if(bessie[p2]>elsie[p1]){
            wins++;
            // get rid of card for next half of game because already used (card will never be able to win next game)
            bessie[p2] = 1000000;
            p1++;
            p2++;
        }
        else{
            p1++;
        }
    }
    
    // sort second half of eslies, sort all of bessies so its a increasing sequence
    sort(elsie + n/2, elsie+n);
    sort(bessie, bessie+n);
    
    // do second half of the game (person with lowest card wins)
    p1 = n/2; // elsie
    p2 = 0; // bessie
    while(p1 < n and p2 < n){
        if(bessie[p2] < elsie[p1]){
            wins++;
            p1++;
            p2++;
        }
        else{
            p1++;
        }
    }
    cout << wins << endl;
}
