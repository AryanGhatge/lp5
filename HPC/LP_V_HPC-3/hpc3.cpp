
#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<double> arr(n);

    cout << "Enter elements: " << endl;
    for (double &x : arr)
    {
        cin >> x;
    }

    double min_val = arr[0], max_val = arr[0], sum = 0.0, avg = 0.0;

#pragma omp parallel for reduction(min : min_val) reduction(max : max_val) reduction(+ : sum)

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min_val)
            min_val = arr[i];
        if (arr[i] > max_val)
            max_val = arr[i];
        sum += arr[i];
    }

    avg = sum / n;

    cout << "Minimum: " << min_val << endl;
    cout << "Maximum: " << max_val << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;

    return 0;
}