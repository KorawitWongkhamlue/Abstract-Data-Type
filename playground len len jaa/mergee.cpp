#include <iostream>
using namespace std;

int a[30] = {74, 12, 95, 33, 58, 4, 81, 27, 69, 16,
    49, 88, 3, 62, 37, 91, 20, 53, 85, 10,
    44, 78, 2, 66, 31, 99, 23, 50, 8, 40};

int tmpa[30];

void merge(int a[], int tmpa[], int lpos, int rpos, int rightend){
    
    int leftend = rpos - 1;
    int tmppos = lpos;
    int n = rightend - lpos + 1;

    while (lpos <= leftend && rpos <= rightend){
        if (a[lpos] < a[rpos]){
            tmpa[tmppos++] = a[lpos++];
        }else{
            tmpa[tmppos++] = a[rpos++];
        }
    }

    while (lpos <= leftend){
        tmpa[tmppos++] = a[lpos++];
    }
    while ( rpos <= rightend){
        tmpa[tmppos++] = a[rpos++];
    }

    for (int i = 0; i < n ; i++, rightend--){
        a[rightend] = tmpa[rightend];
    }
}

void msort(int a[],int tmpa[], int left, int right){
    int center;
    if (left < right){
        center = (left + right) / 2;
        msort(a,tmpa,left,center);
        msort(a,tmpa,center+1,right);
        merge(a,tmpa,left,center+1,right);
    }
}

void show(int a[], int n){
    for (int i = 0; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Before Sort: ";
    show(a,30);
    cout << endl;

    cout << "After Merge Sort: ";
    msort(a,tmpa,0,29);
    show(a,30);
}
