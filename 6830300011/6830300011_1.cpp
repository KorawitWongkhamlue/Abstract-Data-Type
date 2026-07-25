#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "input: " ;
    cin >> n;

    int count = 0;

    //วน loop check ทุกตีวว่ามันหารได้แค่ตัวมันเองกับ 1 จริงมั้ย
    //(ต้องนับได้ลงตัวแค่ 2 ตัว)
    for (int i = 1 ; i<= n ; i++){
        if (n % i == 0){
            count++;
        }
    }

    if (count == 2){
        cout << "Prime" << endl;
    }else{
        cout << "Not Prime" << endl;
    }

    return 0;
}