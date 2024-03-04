#include <iostream>
#include <string>

using namespace std;

struct stack{
    int arr[10000];
    int pos;

    void init(){
        pos = -1;
    }

    void push(int n){
        arr[++pos] = n;
    }

    int pop(){
        if(pos == -1) return -1;
        else return arr[pos--];
    }

    int size(){
        return pos+1;
    }

    int empty(){
        if(pos == -1) return 1;
        else return 0;
    }

    int top(){
        if(empty()) return -1;
        else return arr[pos];
    }
};

int main(){
    stack s;
    s.init();

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        string cmd;
        cin >> cmd;
        int num;

        if(cmd == "push"){
            cin >> num;
            s.push(num);
        }
        if(cmd == "pop") cout << s.pop() << endl;
        if(cmd == "size") cout << s.size() << endl;
        if(cmd == "empty") cout << s.empty() << endl;
        if(cmd == "top") cout << s.top() << endl;
    }

    return 0;
}