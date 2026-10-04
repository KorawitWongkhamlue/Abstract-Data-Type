#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000
vector<int> adj[MAX_N];
int deg[MAX_N];

int n,m;

void init(){
    for (int i =0; i < n; i++){
        deg[i] = 0;
    }
}

void read_input(){
    int u,v;
    cout << "n,m : ";
    cin >> n >> m;
    
    for (int i = 0; i < m ; i++){
        cin >> u >> v;
        u--;v--;

        adj[u].push_back(v);
        deg[u]++;
    }
}

void show(){
    for (int i = 0; i < n ; i++){
        cout << i+1 << " : ";

        for (int j = 0; j < deg[i];j++){
            cout << (adj[i][j] + 1) << " ";
        }
        cout << endl;
    }
}

int main(){
    init();
    read_input();
    show();
}