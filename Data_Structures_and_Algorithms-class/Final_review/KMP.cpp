#include<iostream>
#include<cstring>
#define MAXLEN 255
using namespace std;

typedef struct{
    char ch[MAXLEN + 1];
    int length;
}SString;

void get_next(SString T, int *next){
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length){
        if(j == 0 || T.ch[i] == T.ch[j]){
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(SString S, SString T, int pos){
    int *next = new int[T.length];
    get_next(T, next);
    int i = pos, j = 1;
    while(i <= S.length && j <= T.length){
        if(j == 0 || S.ch[i] == T.ch[j]){i++; j++;}
        else
            j = next[j];
    }
    if(j > T.length) return i - T.length; //等同于i - j + 1;  找到的话最终j比T.length大一
    else return 0;
}

int main(){
    SString S, T;
    cin >> S.length >> T.length;
    for(int i = 1; i <= S.length; i++)
        cin >> S.ch[i];
    for(int i = 1; i <= T.length; i++)
        cin >> T.ch[i];
    int pos;
    cin >> pos;
    int ans = Index_KMP(S, T, pos);
    cout << ans << endl;
    return 0;
}