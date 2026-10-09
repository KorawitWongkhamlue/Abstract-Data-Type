#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000

//adj
vector<int> adj[MAX_N];
int deg[MAX_N];
int layer[MAX_N];
bool visited[MAX_N];
int pred[MAX_N];
int n,m;

list<int> Q;

void init(){
    for (int i = 0; i < n; i++){
        visited[i] = false;
        layer[i] = pred[i] = -1;
    }
}

void read_input(){
    cout << "input: ";
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

void bfs(int u){
    visited[u] = true;
    layer[u] = 0;
    pred[u] = -1;
    Q.push_back(u);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        //cout << u + 1 << " ";

        for (int d = 0; d < deg[u] ; d++){
            int v = adj[u][d];
            if (visited[v] == false){
                layer[v] = layer[u] + 1;
                pred[v] = u;
                Q.push_back(v);
            }
        }
    }
}

void showtable(){
    for (int i = 0; i <n ; i++){
        cout << i + 1 << " : layer = " << layer[i] << " : pred = " << pred[i]+1 << endl;
    }
}

int main(){
    read_input();
    bfs(0);
    showtable();
}