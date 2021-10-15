#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    private:
        node * _root;

        node * add(node * current, int x){
            if(current == NULL) return new node(x);
                
            if(current->val < x){
                current->right = add(current->right, x);
            }

            if(current->val > x){
                current->left = add(current->left, x);
            }
            return current;
        }

        bool find(node * current, int x){
            if(current == NULL) return false;
            if(current->val == x) return true;
            if(current->val > x) return find(current->left, x);
            return find(current->right, x);
        }

        void print(node * current, int level){
            if(current != NULL){
                print(current->left, ++level);
                cout << current->val << " " << level << "\n";
                print(current->right, ++level);
            }
        }

        void print_leaves(node * current){
            if(current != NULL){
                if(current->left == NULL and current->right == NULL){
                    cout << current->val << "\n";
                    return;
                }

                if(current->left != NULL) print_leaves(current->left);

                if(current->right != NULL) print_leaves(current->right);
            }
        }

        int rightmost(node * current){
            if(current == NULL) return -1;

            if(current->right == NULL) return current->val;
            return rightmost(current->right);         
        }

        int leftmost(node * current){
            if(current == NULL) return -1;

            if(current->left == NULL) return current->val;
            return leftmost(current->left);
        }

        node * del(node * current, int x){
            if(current == NULL) return NULL;
            if(current->val == x){
                if(current->right == NULL and current->left == NULL){
                    delete current;
                    return NULL;
                }
                else if(current->left != NULL and current->right == NULL){
                    node * temp = current->left;
                    delete current;
                    return temp;
                }
                else if(current->right != NULL and current->left == NULL){
                    node * temp = current->right;
                    delete current;
                    return temp;
                }
                else if(current->left != NULL and current->right != NULL){
                    current->val = rightmost(current->left);
                    current->left = del(current->left, current->val);
                }
            }
            else if(current->val < x){
                current->right = del(current->right, x);
                return current;
            }
            else if(current->val > x){
                current->left = del(current->left, x);
                return current;
            }
            return current;
        }

        int size(node * current){
            if(current == NULL) return 0;
            return size(current->left) + 1 + size(current->right);
        }   

    public:
        bst(){
            _root = NULL; 
        }

        void add(int x){
            node * res = add(_root, x);
            if(_root == NULL) _root = res;
        }

        void del(int x){
            del(_root, x);
        }

        bool find(int x){
            return find(_root, x);
        }

        void print(){
            print(_root, 0);
            cout << "\n";
        }

        int size(){
            return size(_root);
        }

        int rightmost(){
            return rightmost(_root);
        }

        int leftmost(){
            return leftmost(_root);
        }

        void print_leaves(){
            print_leaves(_root);
        }
};

void solve(){
    bst * tree = new bst();
    int x;
    while(true){
        cin >> x;
        if(x != 0) tree->add(x);
        else break;
    }
    tree->print_leaves();
}

int main(){
    solve();
}