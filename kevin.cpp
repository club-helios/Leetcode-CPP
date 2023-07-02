#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int m, int h)
{
    vector<int> ans(h-l+1);
    int i= l, j= m+1,k=0;
    while(i<=m && j<=h)
    {
        if(a[i] < a[j])
        {
            ans[k]=a[i];
            k++;
            i++;
        }
        else
        {
            ans[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        ans[k]=a[i];
        k++;
        i++;
    }
    while(j<=h)
    {
        ans[k]=a[j];
        k++;
        j++;
    }
    j=l;
    for(i=0;i<ans.size();i++)
    {
        a[j++] = ans[i];
    }
}
void mergeSort(vector<int> &arr, int l, int h)
{
    if(l >= h)
        return;
    int mid = (l+h)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, h);
    merge(arr, l, mid, h);
}
int main()
{
    cout << " Kevin : ";
    vector<int> a;
    int n;
    cin >> n;
    // while(n>0)
    // {
    //     int x;
    //     cin >> x;
    //     a.push_back(x);
    //     n--;
    // }
    a={4,8,9,0,6,1};
    mergeSort(a, 0, a.size()-1);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}