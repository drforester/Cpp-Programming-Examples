/*
    Binary Search
*/

#include <iostream>

using std::cout;

int binarySearchRecursive(int arr[], int l, int r, int x);
int binarySearchImperative(int arr[], int l, int r, int x);

int main()
{
    // a sorted collection
    int arr[] = {1,2,3,5,8,13,21,34};
    int x = 13; // we are searching for the index of this number
    int n = sizeof(arr) / sizeof(arr[0]);
    //int result = binarySearchRecursive(arr, 0, n-1, x);
    int result = binarySearchImperative(arr, 0, n-1, x);
    (result == -1 ) ? cout << x << " was not found.\n"
                    : cout << x << " was found at index " << result << '\n';
}


int binarySearchRecursive(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r-l)/2;
        // is x at the midpoint itself?
        if (arr[mid] == x)
            return mid;
        // if element less than mid, then look in left subarray
        if (arr[mid] > x)
            return binarySearchRecursive(arr, l, mid-1, x);
        // else look in right subarray
        return binarySearchRecursive(arr, mid+1, r, x);
    }
    // else return -1 if x not found
    return -1;
}

int binarySearchImperative(int arr[], int l, int r, int x) {
    while (r >= l) {
        int mid = l + (r-l)/2;
        // is x at the midpoint itself?
        if (arr[mid] == x)
            return mid;
        // if x less than mid, then look in left half
        if (arr[mid] > x)
            r = mid - 1;
        // else x is greater than mid, so look in right half
        else
            l = mid + 1;
    }
    // else return -1 if x not found
    return -1;
}
