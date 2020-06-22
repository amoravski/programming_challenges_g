#include<deque>
#include<iostream>
int main () {
    int a = 2;
    std::deque<int> to_decimal;
    while(a>0) {
        to_decimal.push_front(a%2);
        a = a/2;
    }
    while(!to_decimal.empty()) {
        std::cout << to_decimal.front();
        to_decimal.pop_front();
    }
}
