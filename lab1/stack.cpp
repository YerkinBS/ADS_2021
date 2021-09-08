#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()


struct st{
    int a[100];
    int topIndex;
    st(){
        topIndex = -1;
    }

    int top(){
        if(topIndex != -1) return -1;
        return a[topIndex];
    }

    void push(int x){
        topIndex++;
        a[topIndex] = x;
    }

    void pop(){
        if(topIndex != -1){
            topIndex--;
        }
    }
};


void solve(){
    st s;
    int sz = 0;
    while(true){
        str c; getline(cin, c);
        if(c == "exit"){
            cout << "bye";
            break;
        }
        else if(c == "pop"){
            if(sz > 0){
                cout << s.top() << "\n";
                s.pop();
                sz--;
            } 
            else cout << "error" << "\n";
            
        }
        else if(c == "back"){
            if(sz > 0) cout << s.top() << "\n";
            else cout << "error" << "\n";
        }
        else if(c == "size"){
            cout << sz << "\n";
        }
        else if(c == "clear"){
            fr(i, sz){
                s.pop();
            }
            sz = 0;
            cout << "ok" << "\n";
        }
        else if(c.size() > 5){
            s.push(stoi(c.substr(5)));
            sz++;
            cout << "ok" << "\n";
        }
    }
}
    

int main(){
    solve();
}