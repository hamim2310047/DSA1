#include<iostream>
using namespace std;
int RecursiveBinarySearch(int arr[],int key,int low,int high){
    if (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]<key)
        {
            return RecursiveBinarySearch(arr,key,mid+1,high);
        }
        else
        {
            return RecursiveBinarySearch(arr,key,low,mid-1);
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<"Index: "<<RecursiveBinarySearch(arr,key,0,n);
    return 0;
}