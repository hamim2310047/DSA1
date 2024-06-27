#include<iostream>
using namespace std;

void missingElement(int arr[],int n, int low, int high){
    for (int i = low; i <= high; i++)
    {
        bool missing=false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j]==i)
            {
                missing=true;
                break;
            }
        }
        if (!missing)
        {
            cout<<i<<" ";
        }
    }
}
int main(){
    int n,low,high;
    cin>>n>>low>>high;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    missingElement(arr,n,low,high);
    return 0;
}