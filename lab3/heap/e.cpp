#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()
#define N 100001
int n, m; 

struct heap{
    int val[N];
    int hs;

    heap(){
        hs = 0;
    }

    int get_max(){ 
        return val[0];
    }

    void add(int x){
        if(hs == n) cout << -1 << "\n";
        else{
            int i = hs++;
            val[i] = x;
            int p = (i - 1) / 2; 
            while(i && val[i] > val[p]){
                swap(val[i], val[p]);
                i = p;
                p = (i - 1) / 2; 
            }
            cout << ++i << "\n";
        }
    }

    void del(int ind){
        if(ind < 1 || ind > hs) cout << -1 << "\n";
        else{
            int deleted_el = val[--ind];
            val[ind] = val[--hs];
            if(deleted_el > val[ind]){
                while(2 * ind + 1 < hs){
                    int c1 = 2 * ind + 1;
                    int c2 = 2 * ind + 2;
                    
                    if(c2 < hs && val[c2] > val[c1] && val[c2] > val[ind]){
                        swap(val[c2], val[ind]);
                        ind = c2;
                    }
                    else if(val[c1] > val[ind]){
                        swap(val[c1], val[ind]);
                        ind = c1;
                    }
                    else break;
                }
            }
            else{
                int p = (ind - 1) / 2; 
                while(ind && val[ind] > val[p]){
                    swap(val[ind], val[p]);
                    ind = p;
                    p = (ind - 1) / 2; 
                }
            }
            cout << deleted_el << "\n";
        }
    }

    void print(){
        fr(i, hs){
            cout << val[i] << " ";
        }
        cout << "\n";
    }

    void Extract_Max(){
        if(hs == 0) cout << -1 << "\n";
        else{
            int mx = val[0];
            if(hs == 1){
                cout << 0 << ' ' << mx << "\n";
                --hs;
            }
            else{
                val[0] = val[--hs];
                int ind = 0;

                while(2 * ind + 1 < hs){
                    int c1 = 2 * ind + 1;
                    int c2 = 2 * ind + 2;
                    
                    if(c2 < hs && val[c2] > val[c1] && val[c2] > val[ind]){
                        swap(val[c2], val[ind]);
                        ind = c2;
                    }
                    else if(val[c1] > val[ind]){
                        swap(val[c1], val[ind]);
                        ind = c1;
                    }
                    else break;
                }
                cout << ++ind << ' ' << mx << "\n";
            }
        }
    }
};

void solve(){
    cin >> n >> m;
    heap hp;
    int command;
    while(m--){
        cin >> command;
        if(command == 1) hp.Extract_Max();
        else if(command == 2){
            int x; cin >> x;
            hp.add(x);
        }
        else if(command == 3){
            int ind; cin >> ind;
            hp.del(ind);
        }
    }
    hp.print();
}


int main(){
    solve();
}