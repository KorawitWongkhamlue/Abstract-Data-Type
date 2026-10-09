#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000

//adj
vector<int> adj[MAX_N];
bool visited[MAX_N];
int d[MAX_N];
int f[MAX_N];
int pred[MAX_N];
int deg[MAX_N];
int t = 0;

int n,m;

void init(){
    for (int i = 0 ; i < n ; i++){
        visited[i] = false;
        d[i] = f[i] = pred[i] = -1;
    }
}

void read_input(){
    cout << "Input: ";
    cin >> n >> m;
    init();

    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;v--;

        adj[u].push_back(v);
        deg[u]++;
    }
}

void show(){
    for (int i = 0; i < n; i++){
        cout << i+1 << " , ";
        for (int j = 0; j < deg[i] ; j++){
            cout << adj[i][j];
        }
        cout << endl;
    }
}

void dfs(int u){
    visited[u] = true;
    t++;
    d[u] = t;

    for (int i = 0; i < deg[u] ; i++){
        int v = adj[u][i];
        if (visited[v] == false){
            pred[v] = u;
            dfs(v);
        }
    }
    t++;
    f[u] = t;
}

int main(){
    read_input();

    for (int i = 0; i < n ; i++){
        if (!visited[i]) dfs(i);
    }

    show();
    cout << "----------\n";

    for (int i = 0; i < n; i++){
        cout << i + 1 << ": d = " << d[i] << " f = " << f[i]
        << " pred = " << (pred[i] == -1 ? -1 : pred[i] +1) << endl;

    }

    return 0;
}