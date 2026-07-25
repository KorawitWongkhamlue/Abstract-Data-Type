#include <iostream>
using namespace std;

int main() {

    int n[10] = { 3, 8, 6, 5, 1, 9, 4, 10, 7, 2 };

    for (int j = 0; j < 10; j++) {
        int min = n[j], i, indexmin = j, tmp;
        for (i = j + 1; i < 10; i++) {
            if (n[i] < min) {
                min = n[i];
                indexmin = i;
            }
        }
        tmp = n[indexmin];
        n[indexmin] = n[j];
        n[j] = tmp;
    }
    for (int k = 0; k < 10; k++) {
        cout << n[k] << " ";
    }
    return 0;
}