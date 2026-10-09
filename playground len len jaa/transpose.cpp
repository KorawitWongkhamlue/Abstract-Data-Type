#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000
//adj
vector<int> adj[MAX_N];
vector<int> adjT[MAX_N];
int degT[MAX_N];
int deg[MAX_N];
int pred[MAX_N];

bool visited[MAX_N];
int n,m;

void init(){
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
}

void read_input(){
    cout << "input: ";
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;v--;

        adj[u].push_back(v);
        deg[u]++;
    }
}

void transpose(){
    for (int u = 0; u < n ; u++){
        for (int i = 0; i < deg[u] ; i++){
            int v = adj[u][i];
            adjT[v].push_back(u);
            degT[v]++;
        }
    }
}

void show(){
    for (int i = 0; i <n ; i++){
        cout << i+1 << " ";
        for (int j = 0; j < deg[i] ; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void showT(){
    for (int i = 0; i <n ; i++){
        cout << i+1 << " ";
        for (int j = 0; j < degT[i] ; j++){
            cout << adjT[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    read_input();
    init();

    cout << "original:\n";
    show();

    transpose();
    cout << "transpose:\n";
    showT();

    return 0;
}