#include<iostream>
using namespace std;
int BinSearch_Cur(int a[],int key,int low,int high)
{//基于递归的折半查找
    /************begin***************/
    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] == key) return 1;
        else if(a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
    /************end***************/
}

int main()
{
    int n;//数组长度n
    while(cin>>n)
    {
        if(n==0) break;
        int a[100],k;
        for(int i=0;i<n;i++)
            cin>>a[i];			//输入n个递增排列的数字
        cin>>k;				//输入需要查找的数字k
        if(BinSearch_Cur(a,k,0,n-1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}