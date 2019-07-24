
#include <iostream>
#include <algorithm>
using namespace std;
// c = number of cows, l = number of bottles of sunscreen
struct cow{
    int startSF, endSF;
};
struct lotion{
    int type, num, numCanHelp;
};
bool s(lotion a, lotion b){
    return a.type > b.type;
}
bool s2(cow a, cow b){
    return a.startSF > b.startSF;
}
int c, l;
cow ar[2505];
int visited[2505];
lotion lo[2505];
int needed[1005];
int counter =0;
int main(){
    cin >> c >> l;
    for(int i = 1; i <= c; i++){
        cin >> ar[i].startSF >> ar[i].endSF;
        for(int j = ar[i].startSF; j <= ar[i].endSF; j++){
        }
    }
    sort(ar+1, ar+1+c, s2);
    for(int i = 1; i <=l; i++){
        cin >> lo[i].type >> lo[i].num;
    }
    sort(lo+1, lo+1+l, s);
    for(int i = 1; i<=l; i++){
        for(int j = 1; j <= c;j++){
            if(lo[i].type <= ar[j].endSF and lo[i].type >= ar[j].startSF and lo[i].num >0 and !visited[j]){
                counter++;
                lo[i].num--;
                visited[j] = true;
            }
        }
    }
    cout << counter << endl;
}


