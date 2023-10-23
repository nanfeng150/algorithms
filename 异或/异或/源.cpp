#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void func(int arr[],int len) {
    int err = 0;
    for (int i = 0; i < len; i++) {
        err = err ^ arr[i];
    }
    cout << err << endl;
}
int main() {
    int arr[11] = { 2,2,3,3,4,4,2,1,2,4,4 };
    func(arr, 11);
    return 0;
}