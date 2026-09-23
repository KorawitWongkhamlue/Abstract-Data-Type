#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 100000

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int d[MAX_N], f[MAX_N], pred[MAX_N];
int time_ = 0;

void init(){
    for (int u = 0; u < n; u++){
        visited[u] = false;
        pred[u] = d[u] = f[u] = -1;
    }
}

void read_input(){
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        deg[u]++;
    }
}

void DFS_Visit(int u){
    visited[u] = true;
    d[u] = ++time_;
    for (int k = 0;k < deg[u];k++){
        int v = adj[u][k];
        if (visited[v] == false){
            pred[v] = u;
            DFS_Visit(v);
        }
    }

    f[u] = ++time_;
} 

void DFS(int s){
    time_ = 0;
    pred[s] = s;
    DFS_Visit(s);
}

void show(){
    cout << "\nDFS\n";
    cout << "I d f pred\n";
    cout << "---------------\n";
    for (int i = 0; i < n; i++){
        if (visited[i]){
            cout << i+1 << " : " << d[i] << " " << f[i] << " " << pred[i] + 1 << endl;
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

    DFS(start-1);
    show();

    int end;
    cout << "\nEnter end of Path : ";
    cin >> end;
    end--;

    vector<int> path;
    path.push_back(end);
    while (pred[end] != end){
        end = pred[end];
        path.push_back(end);
    }

    for (int i = (int)path.size() - 1 ; i >= 0; i--){
        cout << path[i] + 1;
        if (i) cout << " ";
    }
    cout << endl;

    return 0;
}