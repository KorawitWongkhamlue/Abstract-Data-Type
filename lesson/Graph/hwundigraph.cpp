#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000

vector<int> adj[MAX_N];
int deg[MAX_N];

int n,m;

void init(){
    for (int i = 0; i < n; i++){
        deg[i] = 0;
    }
}

void read_input(){
    cout << " Enter N node & M node: ";
    cin >> n >> m;

    int u,v;
    for (int i = 0; i < m; i++){
        cin >> u >> v; u--; v--;

        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[v]++;


    }
}

void show(){
    for (int i = 0; i < n; i++){
        cout << i << " : ";
        for (int j = 0; j < deg[i] ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    init();
    read_input();
    show();
}
