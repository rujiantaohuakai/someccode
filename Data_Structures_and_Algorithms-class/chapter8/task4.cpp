#include<iostream>
using namespace std;
void Exchange(int &x,int &y)
{//交换操作
    int z;
    z=x;
    x=y;
    y=z;
}
void Process(int a[],int n)
{//数组的正负排序,使所有关键字为负值的记录排在关键字为非负值的记录之前
/**************begin************/
    int left = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            Exchange(a[i],a[left]);
            left++;
        }
    }
    /**************end************/
}
void PrintA(int a[],int n)
{//输出数据
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int i,a[n];
        for(i=0;i<n;i++)   //输入数据
            cin>>a[i];
        Process(a,n);    //数组的正负排序
        PrintA(a,n);   //输出数据
    }
    return 0;
}