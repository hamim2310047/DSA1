#include<iostream>
using namespace std;
void ScanArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
}
void PrintArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
}

void InsertionSort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (j>=0&&arr[j]<key)
        {
            arr[j+1]=arr[j];
            --j;
        }
        
        arr[j+1]=key;
    }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    ScanArray(arr,size);
    InsertionSort(arr,size);
    PrintArray(arr,size);
}
//size: 10
//input: 3 4 1 2 5 6 9 0 7 8