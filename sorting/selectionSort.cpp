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
void SelectionSort(int arr[], int size){
    for (int i = 0; i < size-1; i++)
    {
        int min=i;
        for (int j = i+1; j <size ; j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    ScanArray(arr,size);
    SelectionSort(arr,size);
    PrintArray(arr,size);
}
//size: 10
//input: 3 4 1 2 5 6 9 0 7 8