#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    bool end=false;
    Node* links[26];
 
    bool containsChar(char c ){
        return (links[c-'a']!=NULL);
    }
 
 
    void put(char c){
        links[c-'a']=new Node();
    }
 
 
    Node * get(char c){
        return links[c-'a'];
    }
};
 
 
class Trie{
 
    public: 
 
        Node *root;
        Trie(){
            root= new Node();
        }
 
        void insert(string word){
            Node * node=root;
            for(auto x: word){
                if(!node->containsChar(x)){
                    node->put(x);
                }
                node=node->get(x);
            }
 
            node->end=true;
        }
 
        bool search(string word){
            Node *node=root;
            for(auto x: word){
                if(!node->containsChar(x)){
                    return false;
                }
                node=node->get(x);
            }
 
            return (node->end);
        }
};


void solve() {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
return 0;
}