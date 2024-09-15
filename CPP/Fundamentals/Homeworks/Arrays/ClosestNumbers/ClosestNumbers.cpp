#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int length = 0;

    cin >> length;
    const int len = length;
    int diff = 0;
    int arr[100];
    int minValue = INT8_MAX;
    
    if (len == 1) {
        minValue = 0;
    }

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < len; j++) {
        for (int k = j + 1; k < len; k++) {
            diff = abs(arr[j] - arr[k]);
            if (diff <= minValue) {
                minValue = diff;
            }
        }
    }
    cout << minValue << endl;
    return 0;
}