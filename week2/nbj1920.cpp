#include <iostream>
#include <algorithm>

using namespace std;

int N, M, lookfor;
int arr[100000];

void binary_search(int x){
    int low = 0;
    int high = N-1;
    int mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(arr[mid] == lookfor){
            cout << "1\n";
            return;
        }

        if(arr[mid] < x){ low = mid + 1; }
        else if(arr[mid] > x){ high = mid - 1; }
    }
    cout << "0\n";
    return;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    cin >> M;

    for(int i=0; i<M; i++){
        cin >> lookfor;
        binary_search(lookfor);
    }
}