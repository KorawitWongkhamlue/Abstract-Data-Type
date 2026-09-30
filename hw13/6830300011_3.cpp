#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_N 100000
int n = 8, m = 0;
string nodeName[MAX_N];
vector<int> adj[MAX_N];
int deg[MAX_N];
bool visited[MAX_N];
int f[MAX_N];
int time_counter = 0;

int topoOrder[MAX_N];
int topoIndex = 0;

void init(){
    for (int i = 0; i < MAX_N; i++){
        deg[i] = 0;
        visited[i] = false;
        f[i] = 0;
        adj[i].clear();
    }
}

void DFS_Visit(int u){
    visited[u] = true;
    time_counter++;

    for (int d = 0; d < adj[u].size(); d++){
        int v = adj[u][d];
        if(!visited[v]){
            DFS_Visit(v);
        }
    }
    time_counter++;
    f[u] = time_counter;

    topoOrder[topoIndex++] = u;
}

void DFS(){
    time_counter = 0;
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            DFS_Visit(i);
        }
    }
}

int main(){
    init();
    int choice;

    do {
        cout << "==========MENU===========\n";
        cout << "1)\tInput name\n";
        cout << "2)\tInput Graph\n";
        cout << "3)\tTopological sort\n";
        cout << "4)\tExit\n";
        cout << "Please choose > ";
        cin >> choice;
        
        if(choice == 1) {
            // รับชื่อโหนดเก็บลงใน Array
            for(int i = 0; i < n; i++) {
                cout << "Enter name #" << (i + 1) << " : ";
                cin >> nodeName[i];
            }
        } 
        else if(choice == 2) {
            // รับ Adjacency list[cite: 2]
            //cout << "Enter number of vertices and edges: ";
            cin >> n >> m;
            for(int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                // สมมติรับแบบ 1-based index แปลงเป็น 0-based index
                adj[u - 1].push_back(v - 1);
                deg[u - 1]++;
            }
        } 
        else if(choice == 3) {
            // ทำ Topological sort
            DFS();
            
            cout << "Topological sort\n";
            cout << "===================\n";
            // พิมพ์ผลลัพธ์จาก finish time มากไปน้อย (เนื่องจาก topoOrder เก็บตามลำดับ finished ก่อนหลัง ให้พิมพ์จากหลังมาหน้า)[cite: 2, 5]
            for(int i = n - 1; i >= 0; i--) {
                int u = topoOrder[i];
                cout << nodeName[u];
                if(i > 0) cout << " -> ";
            }
            cout << endl << endl;
        }
    }while(choice != 4);

    return 0;
}