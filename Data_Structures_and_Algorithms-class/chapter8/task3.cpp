#include<iostream>
using namespace std;
void Exchange(char &x,char &y)
{//交换操作
    char t;
    t=x;
    x=y;
    y=t;
}
void QkSort(char r[],int n)
{//砾石的交换排序。（红色在前，白色居中，蓝色最后）
/**************begin************/
    int L = 0, R = n-1;
    int index = 0;
    while(index <= R){
        if(r[index] == 'R'){
            Exchange(r[L],r[index]);
            L++;
            index++;
        }
        else if(r[index] == 'B'){
            Exchange(r[R],r[index]);
            R--;
        }
        else{
            index++;
        }
    }

    /**************end************/
}
void PrintC(char c[],int n)
{//输出数据
    for(int i=0;i<n-1;i++)
        cout<<c[i]<<" ";
    cout<<c[n-1]<<endl;
}
int main()
{
    int n;                       //砾石的数量n
    while(cin>>n)
    {
        if(n==0) break;
        char c[n];
        for(int i=0;i<n;i++)
            cin>>c[i];      	   //输入砾石的编号
        QkSort(c,n);              //砾石的交换排序
        PrintC(c,n);
    }
    return 0;
}