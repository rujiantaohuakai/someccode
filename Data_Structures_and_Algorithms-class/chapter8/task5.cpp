#include<iostream>
using namespace std;
void CountSort(int a[],int b[],int n)
{//计数排序,将包括n个数据的数组a中的记录排序存入到数组b中
/**************begin************/
    for(int i = 0; i < n; i++){
        if(a[i] != 0)
            b[a[i]]++;
    }
    int index = 0;
    for(int i = 0; i < 100; i++){
        if(b[i]>0){
            for(int j = 0; j < b[i]; j++){
                a[index] = i;
                index++;
            }
        }  
    }
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }




    /**************end************/
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int i,a[100] = {0},b[100] = {0};
        for(i=0;i<n;i++)
            cin>>a[i];
        CountSort(a,b,n);     //计数排序
        for(i=0;i<n-1;i++)
            cout<<b[i]<<" ";
        cout<<b[n-1]<<endl;
    }
}