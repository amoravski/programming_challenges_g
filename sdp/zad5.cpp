#include<iostream>
#include<list>
#include<math.h>

int largest_num(std::list<int> num) {
    int max_num = 0;
    num.sort();
    for(int i=0;!num.empty(); i++) {
        max_num += num.front() * pow(10, i);
        num.pop_front();
    }
    return max_num;
}
int main(int argc, char const* argv[])
{
    std::list<int> num;

    num.push_front(1);
    num.push_front(3);
    num.push_front(2);
    num.push_front(5);
    num.push_front(4);
    num.push_front(8);

    std::cout << largest_num(num);
    return 0;
}
