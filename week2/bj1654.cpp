#include <iostream>

using namespace std;

int main(){
    int K, N;
    cin >> K >> N;

    int karr[10000];
    int total = 0;
    int max1 = 0;
    for(int i=0; i<K; i++){
        cin >> karr[i];
        total += karr[i];
        if(max1 < karr[i]) max1 = karr[i];
    }

    int limit = total / N;

    int cnt = 0;
    int max2 = 0;
    
    for(int j=1; j<max1; j++){
        cnt = 0;
        for(int k=0; k<K; k++){
            cnt += (karr[k] / j);
        }
        cout << cnt << " ";
        if(cnt > N-1){
            if(max2 < j) max2 = j;
        } 
    }

}