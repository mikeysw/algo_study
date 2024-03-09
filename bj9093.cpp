#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int T;
    cin >> T;
    cin.ignore();

    for(int i=0; i<T; i++){
        string str;
        getline(cin, str);
        str += ' ';

        stack<char>s;

        for(int j=0; j<str.length(); j++){
            if(str[j] == ' '){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << " ";
            }
            else s.push(str[j]);
        }
        cout << "\n";
    }
}