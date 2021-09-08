#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

struct deq{
    int a[100000];
    int start = 50000, tail = 50000;

    void push_back(int x){
        a[tail] = x;
        tail++;
    }

    void push_front(int x){
        a[start-1] = x;
        start--;
    }

    void pop_front(){
        start++;
    }

    void pop_back(){
        tail--;
    }

    void clear(){
        start = 50000;
        tail = 50000;
    }

    int front(){
        return a[start];
    }

    int back(){
        return a[tail-1];
    }

    int size(){
        return tail - start;
    }

    bool empty(){
        return start == tail;
    }
};

void solve(){
    deq d;
    while(true){
        str s; getline(cin, s);
        if(s == "exit"){
            cout << "bye";
            break;
        }
        else if(s == "pop_front"){
            if(d.size() > 0){
                cout << d.front() << "\n";
                d.pop_front();
            }
            else cout << "error" << "\n";
        }
        else if(s == "pop_back"){
            if(d.size() > 0){
                cout << d.back() << "\n";
                d.pop_back();
            }
            else cout << "error" << "\n";
        }
        else if(s == "front"){
            if(!d.empty()) cout << d.front() << "\n";
            else cout << "error" << "\n";
        }
        else if(s == "back"){
            if(!d.empty()) cout << d.back() << "\n";
            else cout << "error" << "\n";
        }
        else if(s == "size") cout << d.size() << "\n";
        else if(s == "clear"){
            d.clear();
            cout << "ok" << "\n";
        }
        else if(s.size() > 8){
            if(s[5] == 'f') d.push_front(stoi(s.substr(11)));
            else if(s[5] == 'b') d.push_back(stoi(s.substr(10)));
            cout << "ok" << "\n";
        }
    }
}


int main(){
    solve();
}