#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        stack<char> s;
        string str;

        cin >> str;
        for(int j=0; j<str.length(); j++){
            if(s.empty()) s.push(str[j]);
            else{
                if(s.top() == '(' && str[j] == ')') s.pop();
                else s.push(str[j]);
            }
        }

        if(s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

}