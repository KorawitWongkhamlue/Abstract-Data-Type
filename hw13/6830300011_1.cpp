#include <iostream>
#include <vector>
#include <list>
using namespace std;

//6830300011

#define MAX_N 100000
int n,m; //n = จำนวนโหนด, m = จำนวนเส้นเชื่อม
vector<int> adj[MAX_N];
vector<int> adjt[MAX_N];

//array ต่างๆ
int deg[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int pred[MAX_N];
list<int> Q;


void init(){ //ใช้กำหนดค่าเริ่มต้นให้ตัว arr ต่างๆ
    for (int i = 1; i <= n; i++){
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

        adj[u].push_back(v);
        adjt[v].push_back(u); //เอา u ต่อ v เพราะฉันทรานโพสเว่ย
        deg[u]++;
        deg[v]++; //นับ degree
    }
}

void show(){
    cout << "Show     Transpose" << endl;
    for (int i = 1; i <= n; i++){

        //พิมฝั่งปกติ
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }

        cout << "\t";
        //พิมกราฟ transpose
        cout << i << ": ";
        for (int j = 0; j < adjt[i].size(); j++){
            cout << adjt[i][j] << " ";
        }

        cout << endl;
    }
}



int main(){
    init();
    read_input();
    show();
    return 0;
}