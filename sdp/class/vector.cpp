#include<iostream>

template <class T>
class Vector {
    private:
        int max_size;
        int current_size;
        T *data;
        void extra_thicc();
        void less_thicc();
    public:
        Vector();
        ~Vector();
        void insert(int, T);
        void erase(int);
        int operator[](int);
        int length();
        T* begin();
        T* end();
        bool empty();
};

template <class T>
Vector<T>::Vector() {
    max_size=10;
    current_size=0;
    data = new T[max_size];
    return;
}

template <class T>
Vector<T>::~Vector() {
    delete[] data;
    return;
}

template <class T>
void Vector<T>::insert(int index, T el) {
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

template <class T>
void Vector<T>::erase(int index) {
    if(current_size-1 < max_size - 10) {
        less_thicc();
    }
    for (int i = index; i < current_size; i++) {
        data[i] = data[i+1];
    }
    current_size--;
    return;
}

template <class T>
int Vector<T>::operator[](int index) {
    return data[index];
}

template <class T>
void Vector<T>::extra_thicc() {
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
void Vector<T>::less_thicc() {
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
int Vector<T>::length() {
    return current_size;
}

template <class T>
T* Vector<T>::begin() {
    return data;
}

template <class T>
T* Vector<T>::end() {
    return data + length();
}

template <class T>
bool Vector<T>::empty() {
    if(current_size==0) {
        return true;
    }
    return false;
}

int main(int argc, char const* argv[])
{
    Vector<int> st = Vector<int>();
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
