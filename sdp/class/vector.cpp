#include<iostream>
class Vector {
    private:
        int max_size;
        int current_size;
        int *data;
        void extra_thicc();
        void less_thicc();
    public:
        Vector();
        ~Vector();
        void insert(int, int);
        void erase(int);
        int operator[](int);
        int length();
        int* begin();
        int* end();
        bool empty();
};

Vector::Vector() {
    max_size=10;
    current_size=0;
    data = new int[max_size];
    return;
}

Vector::~Vector() {
    delete[] data;
    return;
}

void Vector::insert(int index, int el) {
    if(current_size + 1 > max_size - 5) {
        extra_thicc();
    }
    current_size++;
    for (int i = current_size-1; i > index; i--) {
        data[i] = data[i-1];
    }
    data[index] = el;
    return;
}

void Vector::erase(int index) {
    if(current_size-1 < max_size - 10) {
        less_thicc();
    }
    for (int i = index; i < current_size; i++) {
        data[i] = data[i+1];
    }
    current_size--;
    return;
}

int Vector::operator[](int index) {
    return data[index];
}

void Vector::extra_thicc() {
    max_size = max_size + 5;
    int* new_data = new int[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

void Vector::less_thicc() {
    max_size = max_size - 5;
    int* new_data = new int[max_size];
    for(int i=0; i<current_size; i++) {
        new_data[i]=data[i];
    }
    delete[] data;
    data = new_data;
    return;
}

int Vector::length() {
    return current_size;
}

int* Vector::begin() {
    return data;
}

int* Vector::end() {
    return data + length();
}

bool Vector::empty() {
    if(current_size==0) {
        return true;
    }
    return false;
}

int main(int argc, char const* argv[])
{
    Vector st = Vector();
    st.insert(0,1);
    st.insert(0,2);
    st.insert(0,3);
    st.insert(0,4);
    st.insert(0,5);
    st.insert(0,6);
    st.insert(0,7);
    st.insert(0,8);
    st.insert(0,9);
    st.insert(0,10);
    st.insert(0,6);
    st.insert(0,6);
    st.insert(0,6);
    st.insert(0,6);
    st.insert(0,6);
    st.insert(0,6);
    st.insert(0,6);
    st.erase(13);
    for(int* i = st.begin(); i<st.end(); i++) {
        std::cout << *i;
        std::cout << '\n';
    }
    return 0;
}
