#include<iostream>
#include<queue>

void combine(std::queue<int> q1,std::queue<int> q2,std::queue<int> &new_q) {
    while(!(q1.empty() || q2.empty())) {
        if(q1.front() >= q2.front()) {
           new_q.push(q2.front());
           q2.pop();
           continue;
        }
       new_q.push(q1.front());
       q1.pop();
       continue;
    }

    while(!q1.empty()) {
       new_q.push(q1.front());
       q1.pop();
    }

    while(!q2.empty()) {
       new_q.push(q2.front());
       q2.pop();
    }
}

int main(int argc, char const* argv[])
{
    std::queue<int> q1;
    std::queue<int> q2;
    q1.push(1);
    q1.push(3);
    q1.push(5);

    q2.push(1);
    q2.push(2);
    q2.push(6);

    std::queue<int> q3;
    combine(q1, q2, q3);
    while(!q3.empty()) {
        std::cout << q3.front();
        q3.pop();
    }
    return 0;
}
