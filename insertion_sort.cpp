#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int array[t];
    for (int i = 0; i < t; i++)
    {
        cin >> array[i];
    }
    for (int i = 1; i < t; i++)
    {
        int value = array[i];
        int hole = i;
        while (hole > 0 && array[hole - 1] > value)
        {
            array[hole] = array[hole - 1];
            hole = hole - 1;
        }
        array[hole] = value;
    }
    for (int i = 0; i < t; i++)
    {
        cout << array[i] << endl;
    }
	
	return 0;
}
