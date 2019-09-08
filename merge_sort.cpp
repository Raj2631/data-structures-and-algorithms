#include <iostream>

using namespace std;

void merge(int a[], int left, int right, int nl, int nr);
void mergesort(int a[], int n);

int main(void)
{
    int n;
    cout << "How many elements are to be entered in the array?" << endl; 
    cin >> n;
    cout << "Enter the elements of the array." << endl;
	int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
	mergesort(A, n);//Calling the mergesort function, 2 parameters passed are :- A = Array, n = array's size.
    cout << "Your array has been sorted." << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
}

/*
for this function, 5 parameters are passed, a[] is the array where we are to merge the 2 sub arrays, left[] and right[], 
nl tells us the number of elements present in the left subarray, while nr tells us the number of elements present in the right subarray.
*/
void merge(int a[], int left[], int right[], int nl, int nr)
{
	int i, j , k; 
    // i = index of left array, j = index of right array, index of the array in which left and right subarrays are to be merged.
    i = j = k = 0;
    //this condition is to make sure that the it iterates over the loop whenever the size of the indexes i and j are 
 //less than the maximum/total size of the subarray. (it's obvious, that index can't be higher than the actual size of array)
	while (i < nl && j < nr) 
	{
        //If element at i index of left array is lesser or equal to the element at j index of right array, then it is pushed 
		//to the array a[] where we are merging the 2 arrays in sorted order.
        if (left[i] <= right[j]) 
	    {
		    a[k] = left[i];
		    i++;
	    }
	//Similar to the above if part, but this executes when element at right[j] is lesser than element at left[i].
	    else 
	    {
		    a[k] = right[j];
		    j++;
	    }
        //increasing index of the parent array. (since the index is to be increased by 1 after the value at a[k] has been 
		//inserted after the above comparisons.)
		k = k + 1; 
	}
    /*
    The below 2 while loops are for when one of the arrays have had all of their elements inserted into the parent array a[], and 
	the other array is still left with some elements, the comparisons above won't work for this case, hence we had to apply a 
	different condition/ different way to insert the elements in the leftover array.
    */
	while (i < nl) 
	{
		a[k] = left[i];
		i++;
		k++;
 	}
 	while (j < nr)
 	{
 		a[k] = right[j];
 		j++;
 		k++;
 	}
}


//2 parameters, array reference, and it's size.
void mergesort(int a[], int n)
{
	// return at base case, if array is smaller than 2, i.e, then the array is already sorted since there is only 1 element present.
	if (n < 2) 
	{
        return;
    }
	int mid = n / 2; 
	int left[mid]; //The left subarray.
	int right[n - mid];//The right subarray.
	//copying the elements of the parent array into the left subarray, which is the half of the parent array
	for (int i = 0; i <= mid - 1; i++) 
	{
		left[i] = a[i];
	}    
	for (int i = mid; i <= n - 1; i++) //same thing as above, but for the right subarray.
	{
		right[i - mid] = a[i];
	}    
	mergesort(left, mid); //2 parameters, left array and it's size.
	mergesort(right, n - mid);//^^
	merge(a, left, right, mid , n - mid ); //since elements of left subarray = mid, elements of right subarray = n - mid.
}
