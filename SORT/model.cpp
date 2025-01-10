#include<iostream>
#define MAXSIZE 10000
using namespace std;
typedef int KeyType;

typedef struct{
    KeyType key;
    KeyType otherinfo;
}RedType;

typedef struct{
    RedType r[MAXSIZE + 1];
    int length;
}SqList;

//直接插入排序
void InssertSort(SqList &L){
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    SqList L;




}