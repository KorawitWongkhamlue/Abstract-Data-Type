#include <iostream>
#include <vector>
#include <list>
using namespace std;

//6830300011

#define MAX_N 100000
int n,m;
vector<int> adj[MAX_N];
vector<int> adjt[MAX_N];

int time_counter = 0;

//arrararararrays
bool visited[MAX_N];
int pred[MAX_N];
int deg[MAX_N];
int layer[MAX_N];
list<int> Q;

//for DFS
int d[MAX_N];
int f[MAX_N];


void init(){
    for (int i = 1; i <= n ; i++){
        visited[i] = false;
        deg[i] = -1;
        layer[i] = -1;
        pred[i] = -1;
    }
}

void read_input(){
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u,v; 
        cin >> u >> v;

        adj[u].push_back(v);
        adjt[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

void DFS_Visit(int u){
    visited[u] = true;

    d[u] = ++time_counter;

    for (int i = 0;i < adj[u].size(); i++){
        int v = adj[u][i];

        if (visited[v] == false){
            pred[v] = u;
            DFS_Visit(v);
        }
    }

    f[u] = ++time_counter;
    Q.push_front(u);
}

void DFS_Visit_T(int u){
    visited[u] = true;

    for (int i = 0;i < adjt[u].size(); i++){
        int v = adjt[u][i];

        if (visited[v] == false){
            pred[v] = u;
            DFS_Visit_T(v);
        }
    }

    f[u] = ++time_counter;
}

void DFS(){
    time_counter = 0;

    for (int i = 1; i <= n ; i++){
        if (visited[i] == false){
            DFS_Visit(i);
        }
    }
}

int component_count = 0;

void find_SCC(){
    init();
    DFS();

    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }


    for (int u : Q){
        if (visited[u] == false){
            component_count++;
            DFS_Visit_T(u);
        }
    }

}

void show_transpose() {
    cout << "Transpose" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ":";
        // วนลูปพิมพ์เฉพาะกราฟฝั่ง Transpose (adjt)
        for (int j = 0; j < adjt[i].size(); j++) {
            cout << " " << adjt[i][j];
        }
        cout << endl;
    }
}

int main(){
    read_input();
    find_SCC();
    show_transpose();
    cout << "Component = " << component_count << " Group" << endl;

    return 0;
}