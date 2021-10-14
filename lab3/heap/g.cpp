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
        int i = hs++;
        val[i] = x;
    }

    void del(){
        val[0] = val[--hs];
        int i = 0;
        while(2 * i + 1 < hs){
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            int mp = c1;
            if(c2 < hs){
                if(val[c2] < val[c1]) mp = c2;
            }
           
            if(val[i] > val[mp]){
                swap(val[i], val[mp]);
                i = mp;
            }
            else break;
        }
    }

    void print(){
        fr(i, hs){
            cout << val[i] << " ";
        }
        cout << "\n";
    }

    void Sift_Down(int ind){
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

    void Reverse_Sift(){
        for(int i = hs - 1; i >= 0; --i){
            Sift_Down(i);
        }
    }
};

void solve(){
    int n, el; cin >> n;
    heap hp;
    while(n--){
        cin >> el;
        hp.add(el);
    }
    hp.Reverse_Sift();
    hp.print();
}


int main(){
    solve();
}