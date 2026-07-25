#include <iostream>
using namespace std;

int main() {
    int map[12][12] = {0}; 

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {

            if (map[i][j] == 1 && map[i][j+1] == 1 &&
                map[i+1][j] == 1 && map[i+1][j+1] == 1) {


                if (map[i-1][j] == 0 && map[i-1][j+1] == 0 &&
                    map[i+2][j] == 0 && map[i+2][j+1] == 0 &&
                    map[i][j-1] == 0 && map[i+1][j-1] == 0 &&
                    map[i][j+2] == 0 && map[i+1][j+2] == 0) {
                    count++;
                }
            }
        }
    }

    cout << "Islands : " << count << endl;
    return 0;
}