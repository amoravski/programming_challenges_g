#include<iostream>
class Stack {
    private:
        int max_size;
        int current_size;
        int *data;
        void extra_thicc();
        void less_thicc();
    public:
        Stack();
        ~Stack();
        void push_top(int);
        int pop_top();
        int length();
        bool empty();
};

Stack::Stack() {
    max_size=10;
    current_size=0;
    data = new int[max_size];
    return;
}

Stack::~Stack() {
    delete[] data;
    return;
}

void Stack::push_top(int el) {
    if(current_size+1 > max_size - 5) {
        extra_thicc();
    }
    data[current_size] = el;
    current_size++;
    return;
}

int Stack::pop_top() {
    if(current_size-1 < max_size - 10) {
        less_thicc();
    }
    current_size--;
    return data[current_size];
}

void Stack::extra_thicc() {
    max_size = max_size + 5;
    int* new_data = new int[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

void Stack::less_thicc() {
    max_size = max_size - 5;
    int* new_data = new int[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

int Stack::length() {
    return current_size;
}

bool Stack::empty() {
    if(current_size==0) {
        return true;
    }
    return false;
}

int main(int argc, char const* argv[])
{
    Stack st = Stack();
    st.push_top(1);
    st.push_top(2);
    st.push_top(3);
    st.push_top(4);
    st.push_top(5);
    st.push_top(6);
    st.push_top(7);
    st.push_top(8);
    while(!st.empty()) {
        std::cout << st.pop_top() << ' ';
        std::cout << '\n';
    }
    return 0;
}
