#include <iostream>

using namespace std;

int main(){
    long long N, M; //N: 나무의 수 M: 가져가려는 나무의 길이
    cin >> N >> M;
    
    long long trees[1000000];
    long long max = 0;
    for(int i=0; i<N; i++){
        cin >> trees[i];
        if(max < trees[i]) max = trees[i];
    }

    long long low = 0;
    long long high = max;
    long long mid;
    long long ans = 0;

    while(low <= high){
        mid = (low + high) / 2;
        //cout << "mid: " << mid << endl;
        long long cnt = 0;

        for(int i=0; i<N; i++){
            if(trees[i]>=mid) cnt += (trees[i] - mid);
        }
        //cout << "cnt: " << cnt << endl;

        if(cnt >= M){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << ans;
/*
    mid += 1;
    long long cnt2 = 0;
    for(int i=0; i<N; i++){
            if(trees[i]>=mid) cnt2 += (trees[i] - mid);
    }
    if(cnt2 >= M) cout << mid;
    else cout << mid-1;
*/

}