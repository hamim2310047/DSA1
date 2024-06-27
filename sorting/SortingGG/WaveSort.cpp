#include<iostream>
using namespace std;

void waveSort(int arr[],int n){
    for (int i = 0; i < n-1; i+=2)
    {
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }   
}
void insertionSort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    insertionSort(arr,n);
    waveSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}