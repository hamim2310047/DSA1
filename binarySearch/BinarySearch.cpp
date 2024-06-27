#include<iostream>
using namespace std;

int BinarySearch(int arr[],int key,int low,int high){
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==key)
        {
            return mid;
            break;
        }
        else if (arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
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
    cout<<"Index: "<<BinarySearch(arr,key,0,n)<<endl;
    return 0;
}