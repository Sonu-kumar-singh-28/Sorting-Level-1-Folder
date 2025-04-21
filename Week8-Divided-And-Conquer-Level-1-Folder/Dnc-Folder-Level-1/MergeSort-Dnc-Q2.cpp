#include<iostream>
#include<vector>
using namespace std;

int merge1(vector<int> &arr, int size, int start, int end)
{
    int mid = start+(end-start)/2;
    int len1 =mid-start+1;
    int len2 = end-mid;


    // copy array element 
    int* left= new int[len1];
    int* right = new int [len2];
    
    int k = start;

    for(int i=0; i<len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0; i<len2; i++)
    {
        right[i] = arr[k];
        k++;
    }


    int leftindex =0;
    int rightindex =0;
    int mainindexarray = start;


    // compare karna hai 

    while(leftindex<len1 && rightindex<len2)
    {
        if(left[leftindex] <right[rightindex])
        {
            arr[mainindexarray] = left[leftindex];
            leftindex++;
            mainindexarray++;
        }
        else{
            arr[mainindexarray] = right[rightindex];
            rightindex++;
            mainindexarray++;
        }
    }

    // agear left array kahatamm ho gaya hon 
    while(leftindex<len1)
    {
        arr[mainindexarray] = left[leftindex];
        leftindex++;
    }


    // ager right element aktham ho gaya ho

    while(rightindex<len2)
    {
        arr[mainindexarray] = right[rightindex];
        rightindex++;
    }

}


void mergesort1(vector<int> &arr, int size, int start, int end)
{
    int mid = start+(end-start)/2;

    if(start>=end)
    {
        return;
    }

    // left search
    mergesort1(arr,size, start , mid);
    // right search 

    mergesort1(arr,size, mid+1, end);

    merge1(arr,size,start ,end);
}

int main()
{
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++)
    {
        cout<<"Enter the element of the array : ";
        cin>>arr[i];
    }

    int start =0;
    int end = size-1;
    mergesort1(arr,size, start, end);

    for(int i=0; i<arr.size(); i++)
    {
        cout<< arr[i] << " " ;
    }
}

