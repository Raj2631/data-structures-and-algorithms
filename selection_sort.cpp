#include <iostream>

using namespace std;

void selection_sort(int a[], int n)
int main() {
    int t;
    cin >> t;
    int array[t];
    for (int i = 0; i <= t - 1; i++)
    {
        cin >> array[i];
    }
    selection_sort(array, t);

    for (int i = 0; i < t; i++)
    {
        cout << array[i] << endl;
    }
	return 0;
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) //we need to do n - 2 passes
    {
        int imin = i;//index of the i'th element is stored in imin.
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[imin]) //index at imin is compared with the other elements,
            {
                imin = j; //updating imin with value of j, element at index j will be swapped with the i'th index element.
            }
        }
        int temp = a[i];
        a[i] = a[imin];
        a[imin] = temp;
    }
}
