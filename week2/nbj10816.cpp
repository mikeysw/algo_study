#include <iostream>
#include <algorithm>
#include <vector>

int N, M, lookfor, max1, max2;
int have[500001];

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> have[i];
    }

    sort(have, have+N);

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> lookfor;
        cout << upper_bound(have, have+N, lookfor) - lower_bound(have, have+N, lookfor) << " ";
    }

}