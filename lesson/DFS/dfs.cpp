
//DFS use STACK, d, time, finish time
//use recursive to depth

#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000

int n,m;
int time = 0;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int pred[MAX_N];
int d[MAX_N]; //discovery time
int f[MAX_N]; //finish time

void init(){
    for (int i = 0 ; i < n; i++){
        deg[i] = 0;
        visited[i] = false;
        d[i] = -1;
        f[i] = -1
        pred[i] = -1;
    }
}

void read_input(){
    cout << "Input N, M : ";
    cin >> n >> m;

    int u,v;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v; u--; v--;

        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[v]++;
    }
}

void show(){
    for (int i = 0; i < n; i++){
        cout << i << " : " ;
        for (int j = 0; j < deg[i] ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

///////////////////////////////////////
void dfs(int u){
    visited[u] = true;
    time++;
    d[u] = time;

    //แอดเพื่อนบ้าน
    for (int i = 0; i < deg[u]; i++){
        int v = adj[u][i];
        if (visited[v] == false){
            pred[v] = u;
            dfs(v); //recursive
        }
    }
    time++;
    f[u] = time;
}
