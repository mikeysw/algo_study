#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    queue<int>q;
    for(int i=1; i<N+1; i++) q.push(i);
    
    cout << "<";
    while(q.size()>1){
        for(int j=1; j<K; j++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">" << endl;

    return 0;
}