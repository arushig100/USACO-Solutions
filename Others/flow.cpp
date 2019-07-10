#include <iostream>
using namespace std;
int n;
int pipes[53][53];

// returns -1 if no edge, returns -2 if more than one edge, returns index of edge if only one edge
int outgoingEdges(int a){
    int counter = 0;
    int index=-1;
    for(int i = 0; i < 52; i++)
        if(pipes[a][i] != 0 and a != i){
            counter++;
            index = i;
        }
    if(counter==0) return -1;
    if(counter > 1) return -2;
    return index;
}
int ingoingEdges(int a){
    int counter = 0;
    int index=-1;
    for(int i = 0; i < 52; i++)
        if(pipes[i][a] != 0 and a!= i){
            counter++;
            index = i;
        }
    if(counter==0) return -1;
    if(counter > 1) return -2;
    return index;
}
int main(){
    cin >> n;
    //input
    for(int i = 0; i < n; i++){
        char a, b;
        int a1, b1, c;
        cin >> a >> b >> c;
        if((int)a > 90) a1 = a - 'a'+26;
        else a1 = a - 'A';
        if((int)b > 90) b1 = b -'a'+26;
        else b1 = b - 'A';
        pipes[a1][b1] +=c;
    }
    
    // delete nodes if possible (0 outgoing edges)
    for(int i = 0; i < 52; i++){
        // if no outgoing edges and not Z
        if(outgoingEdges(i) == -1 and i!=25){
            for(int j = 0; j < 52; j++){
                pipes[i][j] = 0;
                pipes[j][i] = 0;
            }
        }
    }
    // combine
    int end;
    for(int j = 0; j < 52; j++){
        for(int i = 0; i < 52; i++){
            int a = ingoingEdges(i);
            int c= outgoingEdges(i);
            if(a!=-1 and a!=-2 and c!=-1 and c!=-2){
                pipes[a][c] +=min(pipes[a][i], pipes[i][c]);
                pipes[a][i] = 0;
                pipes[i][c] = 0;
                end = a;
                //cout << "In: " << a << " Out: " << c << " Flow: " << pipes[a][c] << endl;
            }
        }
    }
    if(pipes[0][25] != 0)
        cout << pipes[0][25];
    else
        cout << pipes[end][25];
}

