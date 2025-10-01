#include <iostream>

// Template class declaration
template <class T>
class VarList {
public:
    VarList();
    VarList(const VarList<T>& other);
    VarList<T>& operator=(const VarList<T>& other);
    ~VarList();

    int check(T key);
    void addValue(T value);
    void removeValue(T value);
    void printList();

private:
    T* dArray;
    int size;
};

template <class T>
VarList<T>::VarList() : dArray(nullptr), size(0) {}

template <class T>
VarList<T>::VarList(const VarList<T>& other) : dArray(nullptr), size(other.size) {
    if (size > 0) {
        dArray = new T[size];
        for (int i = 0; i < size; ++i)
            dArray[i] = other.dArray[i];
    }
}

template <class T>
VarList<T>& VarList<T>::operator=(const VarList<T>& other) {
    if (this != &other) {
        delete[] dArray;
        size = other.size;
        if (size > 0) {
            dArray = new T[size];
            for (int i = 0; i < size; ++i)
                dArray[i] = other.dArray[i];
        } else {
            dArray = nullptr;
        }
    }
    return *this;
}

template <class T>
VarList<T>::~VarList() {
    delete[] dArray;
}

template <class T>
int VarList<T>::check(T key) {
    for (int i = 0; i < size; ++i)
        if (dArray[i] == key)
            return i;
    return -1;
}

template <class T>
void VarList<T>::addValue(T value) {
    if (check(value) != -1)
        return; // already present, do not add

    T* newArray = new T[size + 1];
    for (int i = 0; i < size; ++i)
        newArray[i] = dArray[i];
    newArray[size] = value;
    delete[] dArray;
    dArray = newArray;
    ++size;
}

template <class T>
void VarList<T>::removeValue(T value) {
    int idx = check(value);
    if (idx == -1)
        return; // not present, do nothing

    if (size == 1) {
        delete[] dArray;
        dArray = nullptr;
        size = 0;
        return;
    }

    T* newArray = new T[size - 1];
    int j = 0;
    for (int i = 0; i < size; ++i) {

            newArray[j++] = dArray[i];
    }
    delete[] dArray;
    dArray = newArray;
    --size;
}

template <class T>
void VarList<T>::printList() {
    for (int i = 0; i < size; ++i) {
        std::cout << dArray[i];
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}