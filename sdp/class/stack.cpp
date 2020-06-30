#include<iostream>
template <class T>
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
        void push_top(T);
        T pop_top();
        int length();
        bool empty();
};

template <class T>
Stack<T>::Stack() {
    max_size=10;
    current_size=0;
    data = new T[max_size];
    return;
}

template <class T>
Stack<T>::~Stack() {
    delete[] data;
    return;
}

template <class T>
void Stack<T>::push_top(T el) {
    if(current_size+1 > max_size - 5) {
        extra_thicc();
    }
    data[current_size] = el;
    current_size++;
    return;
}

template <class T>
T Stack<T>::pop_top() {
    if(current_size-1 < max_size - 10) {
        less_thicc();
    }
    current_size--;
    return data[current_size];
}

template <class T>
void Stack<T>::extra_thicc() {
    max_size = max_size + 5;
    T* new_data = new T[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

template <class T>
void Stack<T>::less_thicc() {
    max_size = max_size - 5;
    T* new_data = new T[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

template <class T>
int Stack<T>::length() {
    return current_size;
}

template <class T>
bool Stack<T>::empty() {
    if(current_size==0) {
        return true;
    }
    return false;
}

int main(int argc, char const* argv[])
{
    Stack<int> st = Stack<int>();
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
