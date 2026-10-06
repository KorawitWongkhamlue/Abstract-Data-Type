#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000

int n,m;

vector<int> adj[MAX_N];
int deg[MAX_N];
int layer[MAX_N];
list<int> Q;
bool visited[MAX_N];
int pred[MAX_N];

void init(){
    for (int i = 0 ; i < n; i++){
        deg[i] = 0;
        visited[i] = false;
        layer[i] = -1;
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

void bfs(int s){
    visited[s] = true;
    layer[s] = 0;
    pred[s] = 0;
    Q.push_back(s);

    while (!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        visited[u] = true;

        for (int d = 0; d < deg[u] ; d++){
            int v = adj[u][d];

            if ( visited[v] == false){
                layer[v] = layer[u] + 1;
                Q.push_back(v);
            }
        }
    }

    cout << "N Ly\n";
    for (int i = 0 ; i < n ; i++){
        cout << i << " , " << layer[i] << endl;
    }
}