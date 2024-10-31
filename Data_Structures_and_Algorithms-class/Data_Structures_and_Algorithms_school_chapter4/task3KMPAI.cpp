#include <iostream>
#include <cstring>
using namespace std;
#define MAXSIZE 2000

typedef struct {
    char *ch; // 若是非空串，则按串长分配存储区，否则ch为NULL
    int length; // 串的当前长度
} HString;

void GetNext(const HString &T, int *next) {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < T.length - 1) {
        if (j == -1 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            next[i] = (T.ch[i] != T.ch[j]) ? j : next[j];
        } else {
            j = next[j];
        }
    }
}

int Index_KMP(const HString &S, const HString &T, int pos) {
    int *next = new int[T.length];
    GetNext(T, next);
    int i = pos - 1, j = 0;
    while (i < S.length && j < T.length) {
        if (j == -1 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    delete[] next;
    return (j == T.length) ? i - T.length + 1 : 0;
}

bool Virus_detection(HString &Virus, HString &Person) {
    for (int temp = 0; temp < Virus.length; ++temp) {
        HString temp_virus;
        temp_virus.length = Virus.length;
        temp_virus.ch = new char[Virus.length + 1];
        for (int i = 0; i < Virus.length; ++i) {
            temp_virus.ch[i] = Virus.ch[(temp + i) % Virus.length];
        }
        temp_virus.ch[Virus.length] = '\0';

        if (Index_KMP(Person, temp_virus, 1) > 0) {
            delete[] temp_virus.ch;
            return true;
        }
        delete[] temp_virus.ch;
    }
    return false;
}

void InputHString(HString &S) {
    char temp[MAXSIZE];
    cin >> temp;
    S.length = strlen(temp);
    S.ch = new char[S.length + 1];
    strcpy(S.ch, temp);
}

int main() {
    HString Virus, Person;

    cout << "请输入病毒序列：";
    InputHString(Virus);
    cout << "请输入人类序列：";
    InputHString(Person);

    if (Virus_detection(Virus, Person))
        cout << "病毒序列在人类序列中存在！" << endl;
    else
        cout << "病毒序列不在人类序列中！" << endl;

    return 0;
}
