#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000

//adj list
vector<int> adj[MAX_N];
vector<int> adjT[MAX_N];
int deg[MAX_N];
int degT[MAX_N];
bool visited[MAX_N];
bool visitedT[MAX_N];

int n,m;

void init(){
    for (int i = 0 ; i < n ; i++){
        visited[i] = false;
        visitedT[i] = false;
        deg[i] = 0;
        degT[i] = 0;
    }
}

void read_input(){
    cout << "Input #N and #M: ";
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
    for (int u = 0; u < m; u++){
        for (int j = 0; j < deg[u]; j++){
            int v = adj[u][j];
            adjT[v].push_back(u);
            degT[v]++;
        }
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

void showT(){
    for (int i = 0; i < n; i++){
        cout << i << " : ";
        for (int j = 0; j < degT[i] ; j++){
            cout << adjT[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    init();
    read_input();
    cout << "--------------\n";
    cout << "Normal Graph\n";
    cout << "--------------\n";
    show();
    cout << "--------------\n";

    transpose();
    cout << "--------------\n";
    cout << "Transposed Graph\n";
    cout << "--------------\n";
    showT();
    cout << "--------------\n";
}