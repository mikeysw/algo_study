#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[100000];

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int M;
    cin >> M;

    for(int j=0; j<M; j++){
        int find;
        cin >> find;

        int low = 0;
        int high = N-1;
        int mid;
        int flag = 0;

        while(low <= high){
            mid = (low + high) / 2;

            if(arr[mid] == find){
                flag = 1;
                break;
            }

            if(arr[mid] < find){ low = mid + 1; }
            else if(arr[mid] > find){ high = mid - 1; }
        }
        cout << flag << endl;
        if(flag == 1){ flag = 0;}


    }   
}