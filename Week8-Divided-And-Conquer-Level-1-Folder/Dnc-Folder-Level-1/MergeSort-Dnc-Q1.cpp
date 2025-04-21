// merge two sorted array 


#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int size, int start , int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    int k = start;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k++];
    }

    int leftindex = 0, rightindex = 0, mainindexarray = start;

    while (leftindex < len1 && rightindex < len2) {
        if (left[leftindex] < right[rightindex]) {
            arr[mainindexarray++] = left[leftindex++];
        } else {
            arr[mainindexarray++] = right[rightindex++]; // ✅ fixed
        }
    }

    while (leftindex < len1) {
        arr[mainindexarray++] = left[leftindex++];
    }

    while (rightindex < len2) {
        arr[mainindexarray++] = right[rightindex++];
    }
}


void mergesort(vector<int> &arr,int size, int start , int end)
{

    // base 
    if(start >= end)
    {
        return;
    }

    int mid = start +(end-start)/2;
    // left sort 
    mergesort(arr,size,start , mid);

    // right sort 
    mergesort(arr,size, mid+1, end);

    // merge two sort array 

    merge(arr,size, start , end);

}

int main()
{
    int size;
    cout<<"ENter the size of the array : ";
    cin>>size;

    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++)
    {
        cout<<"Enter the element of the array : ";
        cin>>arr[i];
    }

    int start =0;
    int end = size-1;

    mergesort(arr,size,start, end);


    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i] << " ";
    }

    return 0;
}