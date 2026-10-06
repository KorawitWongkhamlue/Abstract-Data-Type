#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define MAX_N 100000

int n,m;
vector<int> adj[MAX_N];
int deg[MAX_N];

//เพิ่มเข้ามาจาก bfs
int pred[MAX_N];
int layer[MAX_N];
bool visited[MAX_N];
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
    cout << "Input N, M : ";
    cin >> n >> m;

    int u,v;
    for (int i = 0 ; i < m ; i++){
        cin >> u >> v; u--; v--;

        adj[u].push_back(v);
        deg[u]++;
        adj[v].push_back(u);
        deg[v]++;
    }
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

/////////////////////////////////////////////
/*BFS FOR REAL*/
void bfs(int s){

    // s = ตัวแรก
    int u = s;
    visited[s] = true;
    layer[s] = 0; //Top layer
    pred[s] = 0;
    Q.push_back(s); //push เข้า Q

    //วนลูปสำรวจกราฟ
    while(!Q.empty()){
        int u = Q.front(); //ดึงตัวหน้าสุด แล้ว Pop ออกมาดู
        Q.pop_front();
        visited[u] = true; //status = เข้าแล้ว

        //สำรวจเพื่อนบ้าน u
        for (int d = 0; d < deg[u] ; d++){ //ลูปสำรวจเพื่อนบ้านที่เชื่อมกับ u อยู่
            int v = adj[u][d]; //สำรวจโหนดอื่นๆที่อยู่ชั้นเดียวกัน

            // v คือ ตัวที่เราดึงออกมาดู เหมือน u เลย!

            if (visited[v] == false){ //ถ้ายังไม่เคยแวะ
                layer[v] = layer[u]+1;  //คำนวณ layer ของตัวนั้นๆว่าลึกแค่ไหน
                Q.push_back(v); // เอาเพื่อนบ้านไปใส่ในคิว รอสำรวจเป็น u ต่อไป
            }
        }
    }

    cout << "Node  Layer\n" ;
    for (int i=0;i < n ; i++){
        cout << i+1 << ", " << layer[i] << endl;
    }

}

int main(){
    init();
    read_input();
    show();
    bfs(0);
}