#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

struct que{
    int a[99999];
    int start = 0, tail = 0;

    void push_back(int x){
        a[tail] = x;
        tail++;
    }

    void pop(){
        start++;
    }

    void clear(){
        start = 0;
        tail = 0;
    }

    int front(){
        return a[start];
    }

    int size(){
        return tail - start;
    }

    bool empty(){
        return start == tail;
    }
};

void solve(){
    que q;
    while(true){
        str s; getline(cin, s);
        if(s == "exit"){
            cout << "bye";
            break;
        }
        else if(s == "pop"){
            if(q.size() > 0){
                cout << q.front() << "\n";
                q.pop();
            }
            else cout << "error" << "\n";
        }
        else if(s == "front"){
            if(q.size() > 0) cout << q.front() << "\n";
            else cout << "error" << "\n";
        }
        else if(s == "size") cout << q.size() << "\n";
        else if(s == "clear"){
            q.clear();
            cout << "ok" << "\n";
        }
        else if(s.size() > 5){
            q.push_back(stoi(s.substr(5)));
            cout << "ok" << "\n";
        }
    }
}


int main(){
    solve();
}