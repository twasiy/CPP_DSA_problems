////Fibonacci series wih better time complextiy.
#include <iostream>

int main()
{
    size_t n = 10000;
    size_t a = 1, b = 1;

    for (int i = 0; i < n; i++){
        if(i == 0 || i == 1){
            std::cout << i << " ";
        }else if(i == 2){
            std::cout << 1 << " ";
        }else{
            size_t next = a + b;
            std::cout << next << " ";
            a = b;
            b = next;
        }
    }
    std::cout << std::endl;

    return 0;
}
