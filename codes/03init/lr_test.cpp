#include <iostream>

void squareN(int& n){
    n = pow(n, 2);
}

int main(){
    int num{5};
    squareN(num);
    std::cout<<num<<std::endl;
    return 0;
}