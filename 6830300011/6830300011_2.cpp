#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "input: " ;
    cin >> n;

    for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			cout << " ";
			for (int k = i; k <= j; k++){
				cout << k;

			}
		}
		cout << endl;
	}
	return 0;
}