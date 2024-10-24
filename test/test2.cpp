#include <iostream>
#include <random>
#include <ctime>

using namespace std;
int main(){
    srand(time(0));

    for(int i = 0; i < 1000; i++){
        cout << rand() % 100000000 << " ";
    }
}