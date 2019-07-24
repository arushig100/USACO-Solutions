#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
string a;
int len;
int counter = 0;
int answer =0;
int main(){
    cin >> a;
    len = (int)a.length();
    for(int i = 0; i < len; i++){
        if(a[i] == '('){
            counter++;
        }
        else if(a[i] == ')'){
            counter--;
        }
        if(counter==-1){
            answer++;
            counter=1;
        }
    }
    if(counter > 0){
        answer += counter / 2;
    }
    cout << answer;
}

