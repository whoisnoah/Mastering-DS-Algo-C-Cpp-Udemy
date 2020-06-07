#ifndef _ARRAYADT_HPP_
#define _ARRAYADT_HPP_

#include <iostream>
#include <chrono>

template <class T>
class ArrayADT 
{  
public:

    ArrayADT(int length) : length_(length) {arr_ = new T[length];}
    ArrayADT(int length, T fill);   
    ArrayADT(T arr[], int length);
    ArrayADT(const ArrayADT& rCopy);
    ArrayADT(ArrayADT&& rMove);     
    ~ArrayADT() {delete [] arr_;};

    void display();                    //print all elements to std::cout
    void insert(T elem, int idx);      //insert [elem] at index [idx]
    void remove(int idx);              //remove the element at index [idx]
    void sort();                       //sort the array from smallest to greatest element ( operator<)
    void reverse();                    //reverse the order of all the elements in the array
    void set(T elem, int idx);         //set the value of the array at [idx]
    void merge(const ArrayADT& other); //merge two sorted arrays
    int  search(T elem);               //search for [elem] in the array and return the index
    int  binary_search(T elem);        //search for [elem] in the array and return the index, binary search method
    bool is_sorted();                  //checks if the array is sorted or not
    
    
    T get_val(int idx);                //return the value at index [idx] 
    T get_max();                       //return the max value in the array (must have > operator defined)
    T get_min();                       //return the min value in the array (must have < operator defined)
    double get_avg();                  //return the average value of the array (must have + and / operators defined)
    
    
    T& operator[](int idx) {return arr_[idx];};
    T& operator=(const ArrayADT&  rCopy);
    T& operator=(ArrayADT&& rMove);

private:

    T* arr_;
    int length_;
    
};

//------------------------------------------------------------------------------
// construct an array of type T with [length] elements containing [fill]
//------------------------------------------------------------------------------
template <class T>
ArrayADT<T>::ArrayADT(int length, T fill) 
    : length_(length) 
{
    arr_ = new T[length];
    for (auto i {0}; i < length; ++i)
        arr_[i] = fill;
}

//------------------------------------------------------------------------------
// construct an array of type T using elements of a different static array
//------------------------------------------------------------------------------
template <class T>
ArrayADT<T>::ArrayADT(T arr[], int length) 
    : length_(length) 
{
    arr_ = new T[length];
    for (auto i {0}; i < length; ++i)
        arr_[i] = arr[i];
}

//------------------------------------------------------------------------------
// copy constructor - call other constructor that makes new array, and pass
// values of the reference array
//-----------------------------------------------------------------------------
template <class T>
ArrayADT<T>::ArrayADT(const ArrayADT& rCopy)
    : ArrayADT(rCopy.arr_, rCopy.length_){}


//------------------------------------------------------------------------------
// move constructor - call other constructor that makes new array, and pass
// values of the reference array
//-----------------------------------------------------------------------------
template <class T>
ArrayADT<T>::ArrayADT(ArrayADT&& rMove)
{
        arr_ = rMove.arr_;
        rMove.arr_ = nullptr;
        delete [] rMove.arr_;
}

//------------------------------------------------------------------------------
// display() simply prints the contents of the array to console
//------------------------------------------------------------------------------
template <class T>
void ArrayADT<T>::display(){
    std::cout << "[ ";
    for (auto i {0}; i < length_; ++i){
        std::cout << arr_[i];
        if (i != length_-1)
            std::cout << " | ";
        else
            std::cout << " ";
    }
    std::cout << "]\n";
}

//------------------------------------------------------------------------------
// insert(T elem, int idx) inserts an element [elem] into the array at [idx]
//------------------------------------------------------------------------------
template <class T>
void ArrayADT<T>::insert(T elem, int idx){
    
    //bounds checking on idx
    if(idx < 0 || idx > length_){
        std::cout << "Out of bounds - can not insert at index " << idx << "\n" << std::endl;
        return;
    }
    //first create a new array, with one more element than the existing
    T* temp = new T[++length_];
    //assign the elements up to idx of the new array
    if (idx > 0){
        for (int i {0}; i < idx; ++i)
            temp[i] = arr_[i];
        temp[idx] = elem;
        for (int i{idx+1}; i < length_; ++i)
            temp[i] = arr_[i-1];
    }
    //if idx is 0, all elements shift right and the first element becomes [elem]
    else{
        for (int i {1}; i < length_; ++i)
            temp[i] = arr_[i-1];
        temp[idx] = elem;
    }
    arr_ = temp;
    temp = nullptr;
    delete [] temp;
}

//------------------------------------------------------------------------------
// remove(int idx) removes the array element at [idx]
//------------------------------------------------------------------------------
template <class T>
void ArrayADT<T>::remove(int idx){
    
    //bounds checking on idx
    if(idx < 0 || idx >= length_){
        std::cout << "Out of bounds - can not remove index " << idx << "\n" << std::endl;
        return;
    }
    //first create a new array, with one less element than the existing
    T* temp = new T[--length_];
    //assign the elements up to idx of the new array
    if (idx > 0){
        for (int i {0}; i < idx; ++i)
            temp[i] = arr_[i];
        for (int i{idx+1}; i < length_; ++i)
            temp[i] = arr_[i+1];
    }
    //if idx is 0, all elements shift right and the first element becomes [elem]
    else{
        for (int i {0}; i < length_; ++i)
            temp[i] = arr_[i+1];
    }
    arr_ = temp;
    temp = nullptr;
    delete [] temp;
}

//------------------------------------------------------------------------------
// sort() arranges the elements in order from smallest to largest according to
// the operator< overload definition of the class T, this is a selection sort,
// which isn't very efficient sorting algorithm, but it's very easy to program
//------------------------------------------------------------------------------
template <class T>
void ArrayADT<T>::sort(){
    
    for (int i {0}; i < length_; ++i)
        for (int j {i}; j < length_; ++j)
            if(arr_[i] > arr_[j])
                std::swap(arr_[i], arr_[j]);
}

//------------------------------------------------------------------------------
// reverse() reverses the order of all the elements in the array
//------------------------------------------------------------------------------
template <class T>
void ArrayADT<T>::reverse(){
    
    T* temp = new T[length_];
    
    for (int i {0}; i < length_; ++i)
        temp[i] = arr_[length_-i-1];
    
    arr_ = temp;
    temp = nullptr;
    delete [] temp;
}

//------------------------------------------------------------------------------
// set(T elem, int idx) sets the value at [idx] to [elem]
//------------------------------------------------------------------------------
template <class T>
void ArrayADT<T>::set(T elem, int idx){
    
    if (idx >= 0 && idx < length_)
        arr_[idx] = elem;
    else
        std::cout << "Index out of bounds, will not set value\n";
    
}

//------------------------------------------------------------------------------
// merge(const ArrayADT& other) inserts all the elements of one sorted array
// into the arrayADT calling the merge function - will merge sorted if both
// original arrays are sorted
//------------------------------------------------------------------------------
template <class T>
void ArrayADT<T>::merge(const ArrayADT& other){
    
    int i{0}, j{0}, k{0};
    
    T* temp = new T[length_ + other.length_];
    
    while(i < length_ && j < other.length_){
        if (arr_[i] <= other.arr_[j])
            temp[k++] = arr_[i++];
        else
            temp[k++] = other.arr_[j++];
    }

    if (k < (length_+other.length_)){
        while (i < length_){
            temp[k++] = arr_[i++];
        }
        while (j < other.length_){
            temp[k++] = other.arr_[j++];
        }
    }

    length_ = length_ + other.length_;
    arr_ = temp;
    temp = nullptr;
    delete [] temp;
}

//------------------------------------------------------------------------------
// search(T elem) searches for [elem] key in the array and returns the index if
// found, returns -1 if not found
//------------------------------------------------------------------------------
template <class T>
int ArrayADT<T>::search(T elem){

    static std::chrono::steady_clock::time_point start, finish;
    static int nanosecs {0};
    
    start = std::chrono::steady_clock::now();
    for (int i {0}; i < length_; ++i){
        if(arr_[i] == elem){
            finish = std::chrono::steady_clock::now();
            nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
            std::cout << "It took " << nanosecs << " nanoseconds to find the element\n";
            return i;
        }
    }
    finish = std::chrono::steady_clock::now();
    nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
    std::cout << "It took " << nanosecs << " nanoseconds to search the entire array, ";
    std::cout << "element not found ";
    return -1;
}

//------------------------------------------------------------------------------
// binary_search(T elem) searches for [elem] key in the array and returns the
// index if found, returns -1 if not found
//------------------------------------------------------------------------------
template <class T>
int ArrayADT<T>::binary_search(T elem){
    int lo {0};
    int md {0};
    int hi {length_ - 1};
    static std::chrono::steady_clock::time_point start, finish;
    static int nanosecs {0};
    
    if (!this->is_sorted()){
        std::cout << "Array is not sorted, cannot perform binary search\n";
        return -1;
    }
    
    start = std::chrono::steady_clock::now();
    do{
        md = (hi-lo)/2 + lo;
        if (arr_[md] == elem){
            finish = std::chrono::steady_clock::now();
            nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
            std::cout << "It took " << nanosecs << " nanoseconds to find the element\n";
            return md;
        }
        else if (elem < arr_[md])
            hi = md-1;
        else
            lo = md+1;
    }while (lo <= hi);
    
    finish = std::chrono::steady_clock::now();
    nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
    std::cout << "It took " << nanosecs << " nanoseconds to search the entire array, ";
    std::cout << "element not found ";
    
    return -1;
}

//------------------------------------------------------------------------------
// is_sorted() checks whether the array has been sorted and returns true/false
//------------------------------------------------------------------------------
template <class T>
bool ArrayADT<T>::is_sorted(){
    
    for (int i {0}; i < length_-1; ++i)
            if(arr_[i] > arr_[i+1])
                return false;
    return true;
}

//------------------------------------------------------------------------------
// get_value(int idx) returns the value at [idx]
//------------------------------------------------------------------------------
template <class T>
T ArrayADT<T>::get_val(int idx){
    
    T temp {};
    
    if (idx >= 0 && idx < length_)
        return arr_[idx];
    else{
        std::cout << "Index out of bounds, can not get value\n";
        return temp;
    }
}

//------------------------------------------------------------------------------
//  get_max() returns the max value in the array (must have > operator defined)
//------------------------------------------------------------------------------
template <class T>
T ArrayADT<T>::get_max(){
    
    T max {arr_[0]};
    
    for (int i {0}; i < length_; ++i){
        if(arr_[i] > max)
            max = arr_[i];
    }
    
    return max;
}

//------------------------------------------------------------------------------
//  get_min() returns the min value in the array (must have > operator defined)
//------------------------------------------------------------------------------
template <class T>
T ArrayADT<T>::get_min(){
    
    T min {arr_[0]};
    
    for (int i {0}; i < length_; ++i){
        if(arr_[i] < min)
            min = arr_[i];
    }
    
    return min;
}

//------------------------------------------------------------------------------
// get_avg() returns the average value of the array, only if the + and /
// operators are defined.!Not a great function for a template array class!
//------------------------------------------------------------------------------
template <class T>
double ArrayADT<T>::get_avg(){
    
    T total {arr_[0]};
    
    for (int i {1}; i < length_; ++i)
        total += arr_[i];
    
    return static_cast<double>(total)/length_;
}

#endif // _ARRAYADT_HPP_
