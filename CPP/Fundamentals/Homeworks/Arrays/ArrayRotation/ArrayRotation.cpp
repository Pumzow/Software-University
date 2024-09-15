#include <iostream>

using namespace std;

int main()
{
    int array[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        array[i] = num;
    }

    int r;
    cin >> r;

    int temp[100];
    for (int i = 0; i < n; i++)
    {
        temp[i] = array[i];
    }

    int k = 0;

    int p = 1;
    while (p <= r) {
        int last = array[0];
        for (int i = 0; i < n - 1; i++) {
            array[i] = array[i + 1];
        }
        array[n - 1] = last;
        p++;
    }

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    return 0;
}