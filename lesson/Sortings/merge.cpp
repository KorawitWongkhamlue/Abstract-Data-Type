#include <iostream>
#include <stdio.h>
using namespace std;


//รวมสองฝั่งที่เรียงแล้ว
void merge(int a[], int tmpa[], int lpos, int rpos, int rightend){

    int i, leftend, n, tmppos;
    leftend = rpos-1;
    tmppos = lpos;
    n = rightend - lpos + 1;

    //loop จนหมดฝั่งนึง
    while (lpos <= leftend && rpos <= rightend){

        //เทียบเพื่อ insert ให้ถูกฝั่ง
        if (a[lpos] <= a[rpos]){
            tmpa[tmppos++] = a[lpos++];
        }
        else{
            tmpa[tmppos++] = a[rpos++];
        }
    }

    //หลังจากมี 1 ฝั่งหมด เอาที่เหลือยัด tmp 
    while (lpos <= leftend){
        tmpa[tmppos++] = a[lpos++];
    }

    while (rpos <= rightend){
        tmpa[tmppos++] = a[rpos++];
    }

    //สุดท้ายเอา tmp มาใส จากท้ายมาหน้า
    for (i = 0; i < n ; i++,rightend--){
        a[rightend] = tmpa[rightend];
    }
}

//แบ่งครึ่งไปเรื่อยๆ
void msort(int a[],int tmpa[], int left, int right){

    int center;
    if (left < right){
        center = (left + right)/ 2;
        msort(a,tmpa,left,center); //sort left & center
        msort(a,tmpa,center+1,right); //sort center+1 & right
        merge(a,tmpa,left,center+1,right); //เอา 2 กองตะกี้ มารวมกันตอนท้าย
    }
}



void show(int a[], int n){
    for (int i = 0; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[4] = {1,13,5,2};
    int tmpa[4];
    cout << "Before Sort: ";
    show(a,4);
    cout << endl;

    cout << "After Merge Sort: ";
    msort(a,tmpa,0,3);
    show(a,4);
}