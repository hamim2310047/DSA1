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
void BubbleSort(int arr[],int size){
    int temp=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    ScanArray(arr,size);
    BubbleSort(arr,size);
    PrintArray(arr,size);
}
//size: 10
//input: 3 4 1 2 5 6 9 0 7 8