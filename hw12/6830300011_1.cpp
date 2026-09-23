//6830300011
#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int pred[MAX_N];
list<int> Q;

void init(){
    for (int i = 0 ; i < n; i++){
        deg[i] = 0;
        visited[i] = false;
        layer[i] = -1;
        pred[i] = -1;
    }
}

void read_input(){
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

void bfs(int s){
    visited[s] = true;
    layer[s] = s;
    pred[s] = s;
    Q.push_back(s);

    while (!Q.empty()){
        int u = Q.front();
        Q.pop_front();
        for (int d = 0; d < deg[u]; d++){
            int v = adj[u][d];
            if (visited[v] == false){
                visited[v] = true;
                layer[v] = layer[u] + 1;
                pred[v] = u;
                Q.push_back(v);
            }
        }
    }

    cout << "\nBFS\n";
    for (int i = 0; i < n; i++){
        if (layer[i] != -1){
            cout << i+1 << ", " << layer[i] << endl;
        }
    }
}

int main(){
    cin >> n >> m;
    init();
    read_input();

    int start;
    cout << "Start node : ";
    cin >> start;

    bfs(start - 1);

    return 0;
}