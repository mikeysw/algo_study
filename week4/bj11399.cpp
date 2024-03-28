#include <iostream>
#include <algorithm>

using namespace std;

int N;
int Parr[1001];

int getSum(int x){
    int sum = 0;
    for(int i=0; i<x+1; i++){
        sum += Parr[i];
    }
    return sum;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> Parr[i];
    }
    sort(Parr, Parr+N);

    int ans = 0;
    for(int j=0; j<N; j++){
        ans += getSum(j);
    }
    cout << ans;
}