
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    freopen("mixmilk.in","r",stdin);
    freopen("mixmilk.out","w",stdout);
    int b1Capacity, b1Milk, b2Capacity, b2Milk, b3Capacity, b3Milk;
    cin >> b1Capacity >> b1Milk >> b2Capacity >> b2Milk >> b3Capacity >> b3Milk;
    
    for(int i = 0; i < 100; i++){
        // pouring bucket 1 into bucket 2
        if(i%3 == 0){
            b2Milk += b1Milk;
            b1Milk = 0;
            // if bucket 2 can not take all of bucket 1's milk because its capacity is too small
            if(b2Capacity < b2Milk){
                // give back the necessary amount of milk to bucket 1 so that bucket 2 is not over capacity
                b1Milk = b2Milk - b2Capacity;
                // set bucket 2 to have the maximum amount of milk (equal to its capacity)
                b2Milk = b2Capacity;
            }
        }
        // pouring bucket 2 into bucket 3
        else if(i%3 == 1){
            b3Milk += b2Milk;
            b2Milk = 0;
            // if bucket 3 can not take all of bucket 2's milk because its capacity is too small
            if(b3Capacity < b3Milk){
                // give back the necessary amount of milk to bucket 2 so that bucket 3 is not over capacity
                b2Milk = b3Milk - b3Capacity;
                // set bucket 3 to have the maximum amount of milk (equal to its capacity)
                b3Milk = b3Capacity;
            }
        }
        // pouring bucket 3 into bucket 1
        else{
            b1Milk += b3Milk;
            b3Milk = 0;
            // if bucket 1 can not take all of bucket 3's milk because its capacity is too small
            if(b1Capacity < b1Milk){
                // give back the necessary amount of milk to bucket 3 so that bucket 1 is not over capacity
                b3Milk = b1Milk - b1Capacity;
                // set bucket 1 to have the maximum amount of milk (equal to its capacity)
                b1Milk = b1Capacity;
            }
        }
    }
   
    
    cout << b1Milk << endl << b2Milk << endl << b3Milk << endl;
    
}
