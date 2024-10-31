//采药
#include<iostream>
#include<vector>
struct S{
    int time;
    int price;
};

int main(){
    int T, M;
    std::cin >> T >> M;
    std::vector<S> s(M);
    for(int i = 0; i < M; i++){
        std::cin >> s[i].time >> s[i].price;
    }
    






    return 0;
}

