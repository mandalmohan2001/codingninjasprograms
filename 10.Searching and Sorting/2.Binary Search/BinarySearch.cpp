#include <iostream>
using namespace std;

int binarySearch(int input[], int n, int x) {
    int start = 0, end = n - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(input[mid] == x) {
            return mid;
        } else if(input[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

int main() {
    // Take array input from the user
    int n;
    cin >> n;

    int input[100];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;
    cin >> x;

    cout << binarySearch(input, n, x) << endl;

    return 0;
}
