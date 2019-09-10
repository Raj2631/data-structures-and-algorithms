#include <iostream>

using namespace std;

int binarysearch(int a[], int s, int e, int key);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6 , 7, 8, 9, 10};
    int n;
    cout << "Enter the number which you want to search";
    cin >> n;
    int length = sizeof(arr) / sizeof(int);
    int start = 0, end = length - 1, index;
    index = binarysearch(arr, start, end, n);
    if (index > 0)
        cout << "The number you're searching is at index #" << index  << endl;
    else 
        cout << "Element is not present in the array." << endl;    
    return 0;
}

int binarysearch(int a[], int s, int e, int key)
{
    int mid;
    do
    {
        mid = (s + e) / 2;
        if (key > a[mid])
        {
            s = mid + 1;
        }
        else 
        {
            e = mid - 1;
        }
    }
    while (key != a[mid] && s <= e);

    if (key == a[mid])
    {
        return mid;
    }
    else 
    {
        return -1;
    }
}
