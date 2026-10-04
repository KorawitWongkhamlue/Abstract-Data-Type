//Undigraph adj List

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define MAX_N 1000000

//n = จน.Node m = จน.Edge;
int n,m;

vector<int> adj[MAX_N]; //array ที่จะมาเก็บว่าโหนดเลข ... ชี้เลข ... อยู่
int deg[MAX_N]; //array ไว้เก็บจำนว่าโหนดเลข... มีกี่เพื่อนเชื่อม
//

/*โดยที่ 
adj[u] = ขาไป
adj[v] = ขากลับ

*/

//reset everything
void init(){
    for (int i = 0; i < n ; i++){
        deg[i] = 0;
    }
}


//รับ input
void read_input(){
    int u,v; //ตัวรับ: u = node, v =edge;

    //สมมุติให้ u = 1, v = 2

    cout << "#node #edge : \n";
    cin >> n >> m;

    for (int i = 0; i < m ; i++){ //ตามจน m เพราะใน 1 รอบมันเชื่อม 1 edge
        cin >> u >> v;
        u--;v--; //ทำให้ node 1 เป็น 0, ให้เริ่มนับสอดคล้องกัน
        //กลายเป็น u = 0, v = 1

        adj[u].push_back(v); //ขาไป ตำแหน่ง 0 ให้ใส่ adj 1
        deg[u]++; //อัพเดท u
        adj[v].push_back(u); //ขากลับ
        deg[v]++;
    }
    
}


void show(){
    for (int i = 0; i < n; i++){
        cout << i << " : ";
        for (int j = 0; j <deg[i] ;j++){ //
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    init();
    read_input();
    show();
}