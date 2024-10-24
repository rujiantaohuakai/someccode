#include <iostream>
using namespace std;
int times = 0;
void Han(int n, char a, char b, char c)//将第n个盘从a借助b移动到c
{
    if(n == 1){
        times++;
        cout << "The " << times << " move: Move disk " << n << " from " << a << " to " << c 
             << " using " << b << endl;
        return;
    }
    else{cout << "The " << times << " move: Move disk " << n << " from " << a << " to " << c 
             << " using " << b << endl;
        Han(n-1, a, c, b);
        times++;
        cout << "The " << times << " move: Move disk " << n << " from " << a << " to " << c 
             << " using " << b << endl;
        Han(n-1, b, a, c);
    }
}

int main()
{
    int n;
    cin >> n;
    Han(n, 'A', 'B', 'C');//将n个盘从A移到C
    return 0;
}