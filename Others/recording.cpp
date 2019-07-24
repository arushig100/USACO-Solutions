#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct program{
    int beg, end;
};
bool s(program a, program b){
        return a.end< b.end;
}

program programs[151];
program curPro1;
program curPro2;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> programs[i].beg >> programs[i].end;
    }
    sort(programs, programs+n, s);
    
    curPro1.end = -1;
    curPro2.end = -1;

    int counter = 0;
    for(int i = 0; i < n; i++){
        if(programs[i].beg >= curPro1.end and programs[i].beg >= curPro2.end){
            int a =programs[i].beg-curPro1.end;
            int b =programs[i].beg-curPro2.end;
            if(a > b) curPro2 = programs[i];
            else curPro1 = programs[i];
            counter++;
        }
        else if(programs[i].beg >= curPro1.end){
            curPro1 = programs[i];
            counter++;
        }
        else if(programs[i].beg >= curPro2.end){
            curPro2 = programs[i];
            counter++;
        }
        cout << curPro1.end << " " << curPro2.end << endl;
    }
    cout << counter << endl;
}
