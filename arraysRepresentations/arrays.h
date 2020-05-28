#ifndef _ARRAYS_HPP_
#define _ARRAYS_HPP_

//------------------------------------------------------------------------------
// cout_array will print an array of any type as long as the type has the <<
// operator overloaded
//------------------------------------------------------------------------------
template <typename T>
void cout_array(T arr[], int s){    
    std::cout << "[ ";
    for (int i{0}; i < s; ++i)
        std::cout << arr[i] << " ";
    std::cout << "]\n";
}

//------------------------------------------------------------------------------
// cout_addrArray will print the addresses of each array element in an array
//------------------------------------------------------------------------------
template <typename T>
void cout_addrArray(T* arr, int s){    
    std::cout << "[ ";
    for (int i{0}; i < s; ++i)
        std::cout << &arr[i] << " ";
    std::cout << "]\n";
}

//------------------------------------------------------------------------------
// add_element adds an element to the end of an array
//------------------------------------------------------------------------------
template <typename T>
T* add_element(T* arr, int& s, T val){    
    //allocate memory for new array with increased size
    T* nArr = new T[s+1];
    
    //assign the elements of the old array to the new
    for (int i{0}; i < s; ++i)
        nArr[i] = arr[i];
    
    //add the new element to the end
    std::cout << "Adding element " << val << " to array index " << s << "\n";
    nArr[s++] = val; 
    
    //delete the old array and return the new
    arr = nullptr;
    delete[] arr;
    return nArr;
}

#endif //_ARRAYS_HPP_