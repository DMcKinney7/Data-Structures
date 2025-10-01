#include "implementation.cpp"

template <class T>
class VarList {
public:
    VarList(); // default constructor
    int getSize() const { return size; } // returns current size
    int check(T key); // returns index of element holding "key" or -1 if none
    void addValue(T); // adds value to array if not present
    void removeValue(T); // removes value from array if present
    void printList(); // prints values in array

    // Rule of Three
    VarList(const VarList<T>&); // copy constructor
    VarList<T>& operator=(const VarList<T>&); // assignment operator
    ~VarList(); // destructor

private:
    T* dArray; // pointer to dynamic array
    int size; // array size
};



