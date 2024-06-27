#include<iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};
bool compare(struct Date* d1,struct Date* d2){
    if (d1->year<d2->year)
    {
        return true;
    }
    if (d1->year==d2->year&&d1->month<d2->month)
    {
        return true;
    }
    if (d1->year==d2->year&&d1->month==d2->month&&d1->day<d2->day)
    {
        return true;
    }
    return false;
    
}
void insertionsort(struct Date* date[],int n){
    for (int i = 1; i < n; i++)
    {
        Date* key=date[i];
        int j=i-1;
        while (j>=0&&compare(key,date[j]))
        {
            date[j+1]=date[j];
            j--;
        }
        date[j+1]=key;
    }
}
int main(){
    int n;
    cin>>n;
    struct Date* date[n];
    for (int i = 0; i < n; i++)
    {
        cin>>date[i]->day>>date[i]->month>>date[i]->year;
    }
    insertionsort(date,n);
    cout <<"sorted Dates:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<date[i]->day<<","<<date[i]->month<<","<<date[i]->year<<endl;
    }
    return 0;
}