
#include <iostream>
#include <algorithm>
using namespace std;
int w, n;
int answer = -1;
struct word{
    string w;
    int index;
};
bool compare(pair<string,int> a, pair<string,int> b){
    return a.first < b.first;
}


pair<string, int> list[100000];
string words[100000];
int main(){
    cin >> w >> n;
    // take in words in dictionary
    for(int i =0 ; i < w; i++){
        cin >> list[i].first;
        words[i] = list[i].first;
        list[i].second = i;
    }
    // sorts words in alphabetical order
    sort(list, list + w, compare);
    sort(words, words+w);
    
    
    for(int i = 0;i  < n; i++){
        int num; string str;
        cin >> num >> str;
        int x =lower_bound(words, words+w, str)-words;
        x+=num-1;
        answer = -1;
        if(x >= w){
            answer = -1;
        }
        else if(words[x].substr(0,str.size()) == str){
            answer = list[x].second+1;
        }
        else{
            answer = -1;
        }
        cout << answer << endl;
    }
    
}
