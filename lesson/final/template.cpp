#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000
int n,m; //n = จำนวนโหนด, m = จำนวนเส้นเชื่อม
vector<int> adj[MAX_N];

//array ต่างๆ
int deg[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int pred[MAX_N];
list<int> Q;


void init(){ //ใช้กำหนดค่าเริ่มต้นให้ตัว arr ต่างๆ
    for (int i = 0; i < n; i++){
        deg[i] = 0;
        visited[i] = false;
        layer[i] = -1;
        pred[i] = -1;
    }
}

void read_input(){
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u,v; //u = โหนดต้นทาง v = โหนดปลายทาง
        cin >> u >> v;

        adj[u].push_back(v); //เอา v ไปต่อ u
        deg[u]++; //นับ degree
    }
}

void show(){
    cout << "Show Transpose" << endl;
    for (int i = 1; i <= n; i++){

        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }
}

int main(){
    read_input();
    init();
    show();
    return 0;
}