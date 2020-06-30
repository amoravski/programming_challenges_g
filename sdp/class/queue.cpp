#include<iostream>
template <class T>
class Queue {
    private:
        int max_size;
        int current_size;
        int *data;
        void extra_thicc();
        void less_thicc();
    public:
        Queue();
        ~Queue();
        void push_back(int);
        void pop_front();
        int front();
        int length();
        bool empty();
};

template <class T>
Queue<T>::Queue() {
    max_size=10;
    current_size=0;
    data = new int[max_size];
    return;
}

template <class T>
Queue<T>::~Queue() {
    delete[] data;
    return;
}

template <class T>
void Queue<T>::push_back(int el) {
    if(current_size+1 > max_size - 5) {
        extra_thicc();
    }
    data[current_size] = el;
    current_size++;
    return;
}

template <class T>
void Queue<T>::pop_front() {
    if(current_size-1 < max_size - 10) {
        less_thicc();
    }
    for (int i = 0; i < current_size; i++) {
        data[i] = data[i+1];
    }
    current_size--;
    return;
}

template <class T>
void Queue<T>::extra_thicc() {
    max_size = max_size + 5;
    int* new_data = new int[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

template <class T>
void Queue<T>::less_thicc() {
    max_size = max_size - 5;
    int* new_data = new int[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

template <class T>
int Queue<T>::length() {
    return current_size;
}

template <class T>
int Queue<T>::front() {
    return data[0];
}

template <class T>
bool Queue<T>::empty() {
    if(current_size==0) {
        return true;
    }
    return false;
}

int main(int argc, char const* argv[])
{
    Queue<int> st = Queue<int>();
    st.push_back(1);
    st.push_back(2);
    st.push_back(3);
    st.push_back(4);
    st.push_back(5);
    st.push_back(6);
    st.push_back(7);
    st.push_back(8);
    while(!st.empty()) {
        std::cout << st.front();
        st.pop_front();
        std::cout << '\n';
    }
    return 0;
}
