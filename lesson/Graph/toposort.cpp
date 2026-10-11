
//Topological Sort : เก็บลำดับการทำงาน

#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000
//adjlist
vector<int> adj[MAX_N];
int deg[MAX_N];
int pred[MAX_N];
int f[MAX_N];
int layer[MAX_N];
int d[MAX_N];
int t = 0;
bool visited[MAX_N];

//topo sort
int topoOrder[MAX_N];
int topoIndex = 0;

int n,m;
void init(){
    for (int i = 0;i<n;i++){
        visited[i] = false;
        f[i] = d[i] = -1;
        deg[i] = 0;
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
    topoOrder[topoIndex++] = u;
    //เก็บได้เป็น topoOrder = [3,4,2,1]; 3 เสร็จก่อน
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

int main(){
    init();
    read_input();

    cout << "-------Normal------\n";
    show();
    cout << "-------------------\n";
    dfs(0);

    cout << "--------DFS--------\n";
    for (int i = 0; i < n; i++)
    cout << i + 1 << " : d=" << d[i] << " f=" << f[i] << endl;
    cout << "------------------\n";

    cout << "-Topological Sort-\n";
    for (int i = n-1; i >= 0; i--){
        cout << topoOrder[i] + 1;
        if (i > 0) cout << " -> ";
    }
    cout << endl;
    cout << "------------------\n";
}
