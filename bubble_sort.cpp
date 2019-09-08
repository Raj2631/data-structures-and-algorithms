#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int array[t];
    for (int i = 0; i <= t - 1; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i <= t - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + `1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        /*If flag is 0, that means array is sorted already, hence it breaks out.*/
        if (flag == 0)
        {
            break;
        }

    }
    for (int i = 0; i < t; i++)
    {
        cout << array[i] << endl;
    }
	return 0;
}
