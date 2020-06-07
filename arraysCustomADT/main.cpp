#include "..\\commonfunctions.h"
#include "arrayADT.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

int main() {
    
    bool pickArray {true}, editArray {true}, quit {false};  //booleans for menu control
    int userArraySel {0}, userOptionSel {0};                //integers for user selection
    std::string arrName {};                                 //string for array name display
    int userIndexSel {0};                                   //user input for array index manipulation
    int userIntElem {};                                     //user input for integer element value
    char userCharElem {};                                   //user input for character element value
    double userDblElem {};                                  //user input for double element value
    int returnIndex {-1};                                   //return value for search functions
    
    //create the arrays and set some initial values
    ArrayADT<int>    intArray1(1,0);
    ArrayADT<char>   charArray1(1,'f');
    ArrayADT<double> dblArray1(1,0.01);
    ArrayADT<int>    intArray2(1,0);
    ArrayADT<char>   charArray2(1,'F');
    ArrayADT<double> dblArray2(1,0.1);
    intArray1.insert(3,1);intArray1.insert(-2,2);intArray1.insert(1,3);                     
    intArray2.insert(-1,1);intArray2.insert(2,2);intArray2.insert(4,3);
    charArray1.insert('B',1);charArray1.insert('l',2);charArray1.insert('!',3);
    charArray2.insert('b',1);charArray2.insert('L',2);charArray2.insert('z',3);
    dblArray1.insert(0.2,1);dblArray1.insert(1.04,2);dblArray1.insert(-0.2,3);
    dblArray2.insert(1.2,1);dblArray2.insert(-1.02,2);dblArray2.insert(0.3,3);
    
    
    while (!quit){           // most external loop to run entire array manipulation program
        while (pickArray) {  // select with array to work with and validate selection, loop until valid or exit is selected
            
            std::cout << "Which array would you like to work with?\n";
            std::cout << std::setw(10) << std::left << " " << "1 - Integer Array 1\n";
            std::cout << std::setw(10) << std::left << " " << "2 - Integer Array 2\n";
            std::cout << std::setw(10) << std::left << " " << "3 - Character Array 1\n";
            std::cout << std::setw(10) << std::left << " " << "4 - Character Array 2\n";
            std::cout << std::setw(10) << std::left << " " << "5 - Float Array 1\n";
            std::cout << std::setw(10) << std::left << " " << "6 - Float Array 2\n";
            std::cout << std::setw(10) << std::left << " " << "7 - Display All Arrays\n";
            std::cout << std::setw(10) << std::left << " " << "8 - Exit Program\n" << std::endl;
            std::cout << "Please enter your selection: ";
        
            userArraySel = userIntInput();
            
            std::cout<<std::endl;
            
            if (userArraySel == 1) {
                pickArray = false;
                editArray = true;
                arrName = "intArray1";
            }
            else if (userArraySel == 2) {
                pickArray = false;
                editArray = true;
                arrName = "intArray2";
            }
            else if (userArraySel == 3) {
                pickArray = false;
                editArray = true;
                arrName = "charArray1";
            }
            else if (userArraySel == 4) {
                pickArray = false;
                editArray = true;
                arrName = "charArray2";
            }
            else if (userArraySel == 5) {
                pickArray = false;
                editArray = true;
                arrName = "dblArray1";
            }
            else if (userArraySel == 6) {
                pickArray = false;
                editArray = true;
                arrName = "dblArray2";
            }
            else if (userArraySel == 7) {
                std::cout << "intArray1  == ";
                intArray1.display();
                std::cout << "intArray2  == ";
                intArray2.display();
                std::cout << "charArray1 == ";
                charArray1.display();
                std::cout << "charArray2 == ";
                charArray2.display();
                std::cout << "dblArray1  == ";
                dblArray1.display();
                std::cout << "dblArray2  == ";
                dblArray2.display();
                std::cout << std::endl;
                
            }
            else if (userArraySel == 8) {
                pickArray = false;
                editArray = false;
                quit = true;
            }
            else {
                std::cout << "Not a valid selection, please try again\n" << std::endl;
            }
        }//end array selection while loop
        
        while (editArray) { // once the array is selected, do operations on that array until user chooses to work with a different array or exits the program
            
            //start by dispaying the current array
            std::cout << "Current Working Array - " << arrName << ": "; 
            if (userArraySel == 1)
                intArray1.display();
            else if (userArraySel == 2)
                intArray2.display();
            else if (userArraySel == 3)
                charArray1.display();
            else if (userArraySel == 4)
                charArray2.display();
            else if (userArraySel == 5)
                dblArray1.display();
            else
                dblArray2.display();
            
            std::cout<<std::endl;
            
            //show all the options in the menu
            std::cout << "What would you like to do?\n" << std::endl;
            std::cout << std::setw(10) << std::left << " " << "1  - Insert Element\n";
            std::cout << std::setw(10) << std::left << " " << "2  - Remove Element\n";
            std::cout << std::setw(10) << std::left << " " << "3  - Set Value at Index\n";
            std::cout << std::setw(10) << std::left << " " << "4  - Get Minumum Value\n";
            std::cout << std::setw(10) << std::left << " " << "5  - Get Maximum Value\n";
            std::cout << std::setw(10) << std::left << " " << "6  - Get Average Value\n";
            std::cout << std::setw(10) << std::left << " " << "7  - Sort\n";
            std::cout << std::setw(10) << std::left << " " << "8  - Check if Sorted\n";
            std::cout << std::setw(10) << std::left << " " << "9  - Reverse\n";
            std::cout << std::setw(10) << std::left << " " << "10 - Linear Search\n";
            std::cout << std::setw(10) << std::left << " " << "11 - Binary Search\n";
            std::cout << std::setw(10) << std::left << " " << "12 - Merge\n";
            std::cout << std::setw(10) << std::left << " " << "13 - Select Different Array\n";
            std::cout << std::setw(10) << std::left << " " << "14 - Exit Program\n" << std::endl;
            std::cout << "Please enter your selection: ";
            
            //get and validate the user input
            userOptionSel = userIntInput();
            std::cout << std::endl;
            
            
            //array operations based on user selection
            
            if (userOptionSel == 1) { //-----------------------------------------------------------option 1 - insert
                std::cout << "At which index would you like to insert the element into array?  ";
                userIndexSel = userIntInput();
                std::cout << std::endl;
                std::cout << "What value would you like to insert?  ";
                
                if (userArraySel == 1 || userArraySel == 2){
                    userIntElem = userIntInput();
                    std::cout << std::endl;
                    (userArraySel == 1) ? intArray1.insert(userIntElem, userIndexSel) : intArray2.insert(userIntElem, userIndexSel);
                }
                else if (userArraySel == 3 || userArraySel == 4){
                    userCharElem = userCharInput();
                    std::cout << std::endl;
                    (userArraySel == 3) ? charArray1.insert(userCharElem, userIndexSel) : charArray2.insert(userCharElem, userIndexSel);
                }
                else {
                    userDblElem = userDblInput();
                    std::cout << std::endl;
                    (userArraySel == 5) ? dblArray1.insert(userDblElem, userIndexSel) : dblArray2.insert(userDblElem, userIndexSel);
                }
            }
            else if (userOptionSel == 2) { //------------------------------------------------------option 2 - remove
                std::cout << "Which index in the array would you like to remove?  " << std::endl;
                userIndexSel = userIntInput();
                std::cout << std::endl;
                if (userArraySel == 1)
                    intArray1.remove(userIndexSel);
                else if (userArraySel == 2)
                    intArray2.remove(userIndexSel);
                else if (userArraySel == 3)
                    charArray1.remove(userIndexSel);
                else if (userArraySel == 4)
                    charArray2.remove(userIndexSel);
                else if (userArraySel == 5)
                    dblArray1.remove(userIndexSel);
                else
                    dblArray2.remove(userIndexSel);
            }
            else if (userOptionSel == 3) { //------------------------------------------------------option 3 - set
                std::cout << "At which index would you like to set the element value?  ";
                userIndexSel = userIntInput();
                std::cout << std::endl;
                std::cout << "What is the value would you like to set?  ";
                
                if (userArraySel == 1 || userArraySel == 2){
                    userIntElem = userIntInput();
                    std::cout << std::endl;
                    (userArraySel == 1) ? intArray1.set(userIntElem, userIndexSel) : intArray2.set(userIntElem, userIndexSel);
                }
                else if (userArraySel == 3 || userArraySel == 4){
                    userCharElem = userCharInput();
                    std::cout << std::endl;
                    (userArraySel == 3) ? charArray1.set(userCharElem, userIndexSel) : charArray2.set(userCharElem, userIndexSel);
                }
                else {
                    userDblElem = userDblInput();
                    std::cout << std::endl;
                    (userArraySel == 5) ? dblArray1.set(userDblElem, userIndexSel) : dblArray2.set(userDblElem, userIndexSel);
                }
            }
            else if (userOptionSel == 4) { //------------------------------------------------------option 4 - get min
                std::cout << "The minimum value in " << arrName << " is ";
                if (userArraySel == 1)
                    std::cout << intArray1.get_min();
                else if (userArraySel == 2)
                    std::cout << intArray2.get_min();
                else if (userArraySel == 3)
                    std::cout << charArray1.get_min();
                else if (userArraySel == 4)
                    std::cout << charArray2.get_min();
                else if (userArraySel == 5)
                    std::cout << dblArray1.get_min();
                else
                    std::cout << dblArray2.get_min();
                std::cout << "\n" << std::endl;
            }
            else if (userOptionSel == 5) { //------------------------------------------------------option 5 - get max
                std::cout << "The maximum value in " << arrName << " is ";
                if (userArraySel == 1)
                    std::cout << intArray1.get_max();
                else if (userArraySel == 2)
                    std::cout << intArray2.get_max();
                else if (userArraySel == 3)
                    std::cout << charArray1.get_max();
                else if (userArraySel == 4)
                    std::cout << charArray2.get_max();
                else if (userArraySel == 5)
                    std::cout << dblArray1.get_max();
                else
                    std::cout << dblArray2.get_max();
                std::cout << "\n" << std::endl;
            }
            else if (userOptionSel == 6) { //------------------------------------------------------option 6 - get average
                std::cout << "The average value in " << arrName << " is ";
                if (userArraySel == 1)
                    std::cout << intArray1.get_avg();
                else if (userArraySel == 2)
                    std::cout << intArray2.get_avg();
                else if (userArraySel == 3)
                    std::cout << charArray1.get_avg() << ", does this make sense?";
                else if (userArraySel == 4)
                    std::cout << charArray2.get_avg() << ", does this makes sense?";
                else if (userArraySel == 5)
                    std::cout << dblArray1.get_avg();
                else
                    std::cout << dblArray2.get_avg();
                std::cout << "\n" << std::endl;
            }
            else if (userOptionSel == 7) { //------------------------------------------------------option 7 - sort
                if (userArraySel == 1)
                    intArray1.sort();
                else if (userArraySel == 2)
                    intArray2.sort();
                else if (userArraySel == 3)
                    charArray1.sort();
                else if (userArraySel == 4)
                    charArray2.sort();
                else if (userArraySel == 5)
                    dblArray1.sort();
                else
                    dblArray2.sort();
                std::cout << std::endl;
            }
            else if (userOptionSel == 8) { //------------------------------------------------------option 8 - check if sorted
                std::cout << std::boolalpha << "Is " << arrName << " sorted?:  ";
                if (userArraySel == 1)
                    std::cout << intArray1.is_sorted();
                else if (userArraySel == 2)
                    std::cout << intArray2.is_sorted();
                else if (userArraySel == 3)
                    std::cout << charArray1.is_sorted();
                else if (userArraySel == 4)
                    std::cout << charArray2.is_sorted();
                else if (userArraySel == 5)
                    std::cout << dblArray1.is_sorted();
                else
                    std::cout << dblArray2.is_sorted();
                std::cout << "\n" << std::endl;
            }
            else if (userOptionSel == 9) { //------------------------------------------------------option 9 - reverse
                if (userArraySel == 1)
                    intArray1.reverse();
                else if (userArraySel == 2)
                    intArray2.reverse();
                else if (userArraySel == 3)
                    charArray1.reverse();
                else if (userArraySel == 4)
                    charArray2.reverse();
                else if (userArraySel == 5)
                    dblArray1.reverse();
                else
                    dblArray2.reverse();
                std::cout << std::endl;
            }
            else if (userOptionSel == 10){ //------------------------------------------------------option 10 - linear search
                std::cout << "Which value would you like to find?  ";
                
                if (userArraySel == 1 || userArraySel == 2){
                    userIntElem = userIntInput();
                    (userArraySel == 1) ? returnIndex = intArray1.search(userIntElem) : returnIndex = intArray2.search(userIntElem);
                }
                else if (userArraySel == 3 || userArraySel == 4){
                    userCharElem = userCharInput();
                    (userArraySel == 3) ? returnIndex = charArray1.search(userCharElem) : returnIndex = charArray2.search(userCharElem);
                }
                else {
                    userDblElem = userDblInput();
                    (userArraySel == 5) ? returnIndex = dblArray1.search(userDblElem) : returnIndex = dblArray2.search(userDblElem);
                }
                std::cout << std::endl;
                if (returnIndex != -1){
                    std::cout << "The element is at index: ";
                    std::cout << returnIndex << "\n" << std::endl;
                }
            }
            else if (userOptionSel == 11) { //-----------------------------------------------------option 11 - binary search
                std::cout << "Which value would you like to find?  ";
                
                if (userArraySel == 1 || userArraySel == 2){
                    userIntElem = userIntInput();
                    (userArraySel == 1) ? returnIndex = intArray1.binary_search(userIntElem) : returnIndex = intArray2.binary_search(userIntElem);
                }
                else if (userArraySel == 3 || userArraySel == 4){
                    userCharElem = userCharInput();
                    (userArraySel == 3) ? returnIndex = charArray1.binary_search(userCharElem) : returnIndex = charArray2.binary_search(userCharElem);
                }
                else {
                    userDblElem = userDblInput();
                    (userArraySel == 5) ? returnIndex = dblArray1.binary_search(userDblElem) : returnIndex = dblArray2.binary_search(userDblElem);
                }
                std::cout << std::endl;
                if (returnIndex != -1){
                    std::cout << "The element is at index: ";
                    std::cout << returnIndex << "\n" << std::endl;
                }
            }
            else if (userOptionSel == 12) { //-----------------------------------------------------option 12 - Merge
                if (userArraySel == 1){
                    std::cout << "Merging intArray2 into intArray1\n";
                    intArray1.merge(intArray2);
                }
                else if (userArraySel == 2){
                    std::cout << "Merging intArray1 into intArray2\n";
                    intArray2.merge(intArray1);
                }
                else if (userArraySel == 3){
                    std::cout << "Merging charArray2 into charArray1\n";
                    charArray1.merge(charArray2);
                }
                else if (userArraySel == 4){
                    std::cout << "Merging charArray1 into charArray2\n";
                    charArray2.merge(charArray1);
                }
                else if (userArraySel == 5){
                    std::cout << "Merging dblArray2 into dblArray1\n";
                    dblArray1.merge(dblArray2);
                }
                else{
                    std::cout << "Merging dblArray1 into dblArray2\n";
                    dblArray2.merge(dblArray1);
                }
            }
            else if (userOptionSel == 13) { //-----------------------------------------------------option 13 - select different array   
                editArray = false;
                pickArray = true;
            }
            else if (userOptionSel == 14) { //-----------------------------------------------------option 14 - exit program
                editArray = false;
                pickArray = false;
                quit = true;
            }
            else {
                std::cout << "Not a valid selection, please try again" << std::endl;
            }
            
        }//end array selection while loop
        
    }//end main program while loop

//------------------------------------------------------------------------------    
//------------------------------------------------------------------------------
//                                  testing
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
    
//    //the chrono std::chrono variables are used to show various execution times
//    std::chrono::steady_clock::time_point start1, start2, finish1, finish2;
//    std::chrono::duration<double,std::ratio<1, 1000000000>> timeDiff1, timeDiff2;
    
//------------------------------------------------------------------------------
// array ADT constructors and display function
//------------------------------------------------------------------------------
/*{
    int array[6] = {1,2,3,4,5,6};
    
    ArrayADT<int> myArray1(6);
    ArrayADT<int> myArray2(array, sizeof(array)/sizeof(array[0]));
    ArrayADT<char> myArray3(10, 'A');
    
    myArray1.display();
    std::cout << std::endl;
    myArray2.display();
    std::cout << std::endl;
    myArray3.display();
    std::cout << std::endl;
}*/

//------------------------------------------------------------------------------
// array ADT insert, remove, and find functions
//------------------------------------------------------------------------------
/*{
    int array[6] = {1,2,3,4,5,6};
    
    ArrayADT<int> myArray(array, sizeof(array)/sizeof(array[0]));

    std::cout << "myArray is : ";
    myArray.display();
    std::cout << std::endl;
    
    myArray.insert(0,0);
    std::cout << "myArray is : ";
    myArray.display();
    std::cout << std::endl;
    
    myArray.insert(7,7);
    std::cout << "myArray is : ";
    myArray.display();
    std::cout << std::endl;
    
    myArray.insert(100,-1);      //won't do anything
    myArray.insert(100,100);     //won't do anything
    std::cout << std::endl;
    
    myArray.remove(0);
    std::cout << "myArray is : ";
    myArray.display();
    std::cout << std::endl;
    
    myArray.remove(6);
    std::cout << "myArray is : ";
    myArray.display();
    std::cout << std::endl;
    
    myArray.remove(-1);      //won't do anything
    myArray.remove(100);     //won't do anything
    std::cout << std::endl;
    
    int foundIdx {-1};
    int searchKey {3};
    foundIdx = myArray.find(searchKey);
    if (foundIdx != -1)
        std::cout << searchKey << " is in the array at index " << foundIdx << "\n";
    else 
        std::cout << searchKey << " is not in the array\n";
        
    searchKey = 10;
    foundIdx = myArray.find(searchKey);
    if (foundIdx != -1)
        std::cout << searchKey << " is in the array at index " << foundIdx << "\n";
    else 
        std::cout << searchKey << " is not in the array\n";
}*/

//------------------------------------------------------------------------------
// basic array sort and binary search
//------------------------------------------------------------------------------
/*{
    int array[10] = {9,0,8,1,7,2,6,3,5,4};
    
    ArrayADT<int> myArray(array, sizeof(array)/sizeof(array[0]));
    
    std::cout << "myArray is : ";
    myArray.display();
    std::cout << "myArray.is_sorted() == " << myArray.is_sorted();
    std::cout << std::endl;
    std::cout << "Sorting myArray\n";
    myArray.sort();
    std::cout << "myArray is : ";
    myArray.display();
    std::cout << "myArray.is_sorted() == " << myArray.is_sorted();
    std::cout << std::endl;
    
    // this code section performs a linear search and a binary search
    // on the same array and compares execution time
    
    long long binSearchTime[512];
    long long linSearchTime[512];
    
    int iArr[512];
    for (int i {0}; i < 512; ++i)
        iArr[i] = i;
    
    ArrayADT<int> searchArray(iArr,sizeof(iArr)/sizeof(iArr[0]));
    for (int i {0}; i < 512; ++i){
        
        //get time it takes for normal search to find element i
        start1 = std::chrono::steady_clock::now();
        searchArray.search(i);
        finish1 = std::chrono::steady_clock::now();
        
        //get time it takes for binary search to find element i
        start2 = std::chrono::steady_clock::now();
        searchArray.binary_search(i);
        finish2 = std::chrono::steady_clock::now();
        
        linSearchTime[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1).count();
        binSearchTime[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2).count();
    }
    
    std::cout << "Time (in ns) to find each element in searchArray with a linear and binary search\n";
    std::cout << std::setw(15) << std::left << "linear search" << std::setw(15) << std::left << "binary search" << std::endl;
    
    for (int i {0}; i < 512; ++i){
        std::cout << std::setw(15) << std::left << linSearchTime[i] 
                  << std::setw(15) << std::left << binSearchTime[i] << std::endl;
    }

}*/

//------------------------------------------------------------------------------
// array get, set, min, max, and average functions
//------------------------------------------------------------------------------
/*{
    int    iArr[10] {0,9,1,8,2,7,3,6,4,5};
    char   cArr[10] {'a','z','c','b','d','n','q','r','v','l'};
    double fArr[10] {1.2,8.4,-3.5,4.4,10.19,-6.3,2.4,19.2,3.5,6.3};
    
    ArrayADT<int>    myArray1(iArr,10);
    ArrayADT<char>   myArray2(cArr,9);
    ArrayADT<double> myArray3(fArr,10);
    
    //display the initial arrays
    std::cout << "myArray1 == ";
    myArray1.display();
    std::cout << std::endl;
    std::cout << "myArray2 == ";
    myArray2.display();
    std::cout << std::endl;
    std::cout << "myArray3 == ";
    myArray3.display();
    std::cout << std::endl;
    
    //demonstrate get methods
    std::cout << std::setw(23) << std::left << "myArray1[3] == " << myArray1[3] <<"\n";
    std::cout << std::setw(23) << std::left << "myArray1.get_val(3) == " << myArray1.get_val(3) <<"\n";
    std::cout << std::setw(23) << std::left << "myArray2[3] == " << myArray2[3] <<"\n";
    std::cout << std::setw(23) << std::left << "myArray2.get_val(3) == " << myArray2.get_val(3) <<"\n";
    std::cout << std::setw(23) << std::left << "myArray3[3] == " << myArray3[3] <<"\n";
    std::cout << std::setw(23) << std::left << "myArray3.get_val(3) == " << myArray3.get_val(3) <<"\n";
    std::cout << std::endl;
    
    //demonstrate set methods
    myArray1[0] = 100;
    myArray1.set(101,1);
    myArray2[0] = '!';
    myArray2.set('?',1);
    myArray3[0] = -111.111;
    myArray3.set(222.22,1);
    std::cout << "myArray1[0] = 100; \n";
    std::cout << "myArray1.set(101,1); \n";
    std::cout << "myArray1 == ";
    myArray1.display();
    std::cout << std::endl;
    std::cout << "myArray2[0] = '!'; \n";
    std::cout << "myArray2.set('?',1); \n";
    std::cout << "myArray2 == ";
    myArray2.display();
    std::cout << std::endl;
    std::cout << "myArray3[0] = -111.111; \n";
    std::cout << "myArray3.set(222.22,1); \n";
    std::cout << "myArray3 == ";
    myArray3.display();
    std::cout << std::endl;
    
    //demonstrate min/max
    std::cout << std::setw(15) << std::left << " " << std::setw(14) << std::left << "Minimum Value"
                << std::setw(14) << std::left << "Maximum Value" << std::endl;
    std::cout << std::setw(15) << std::left << "myArray1" << std::setw(14) << std::left << myArray1.get_min()
                << std::setw(14) << std::left << myArray1.get_max() << std::endl;
    std::cout << std::setw(15) << std::left << "myArray2" << std::setw(14) << std::left << myArray2.get_min()
                << std::setw(14) << std::left << myArray2.get_max() << std::endl;
    std::cout << std::setw(15) << std::left << "myArray3" << std::setw(14) << std::left << myArray3.get_min()
                << std::setw(14) << std::left << myArray3.get_max() << std::endl;
}*/
    
//------------------------------------------------------------------------------
// reversing the array
//------------------------------------------------------------------------------
/*{
    int    iArr[10] {0,9,1,8,2,7,3,6,4,5};
    char   cArr[10] {'a','z','c','b','d','n','q','r','v','l'};
    double fArr[10] {1.2,8.4,-3.5,4.4,10.19,-6.3,2.4,19.2,3.5,6.3};
    
    ArrayADT<int>    myArray1(iArr,10);
    ArrayADT<char>   myArray2(cArr,9);
    ArrayADT<double> myArray3(fArr,10);
    
    //display the initial arrays
    std::cout << "myArray1 == ";
    myArray1.display();
    std::cout << std::endl;
    std::cout << "myArray2 == ";
    myArray2.display();
    std::cout << std::endl;
    std::cout << "myArray3 == ";
    myArray3.display();
    std::cout << std::endl;
    
    myArray1.sort();
    myArray2.sort();
    myArray3.sort();
    
    //display the initial arrays
    std::cout << "myArray1 == ";
    myArray1.display();
    std::cout << std::endl;
    std::cout << "myArray2 == ";
    myArray2.display();
    std::cout << std::endl;
    std::cout << "myArray3 == ";
    myArray3.display();
    std::cout << std::endl;
    
    myArray1.reverse();
    myArray2.reverse();
    myArray3.reverse();
    
    std::cout << "myArray1 == ";
    myArray1.display();
    std::cout << std::endl;
    std::cout << "myArray2 == ";
    myArray2.display();
    std::cout << std::endl;
    std::cout << "myArray3 == ";
    myArray3.display();
    std::cout << std::endl;
}*/
    
//------------------------------------------------------------------------------
// merging two sorted arrays
//------------------------------------------------------------------------------
/*{
    int    iArr[10] {0,9,1,8,2,7,3,6,4,5};
    char   cArr[10] {'a','b','c','e','g','o','p','r','s','t'};
    double fArr[10] {1.1,-2.2,3.3,-4.4,5.5,-6.6,7.7,-8.8,9.9,-10.10};
    ArrayADT<int>    intArray1(iArr,10);
    ArrayADT<char>   charArray1(cArr,9);
    ArrayADT<double> dblArray1(fArr,10);
    
    int    iArr2[10] {-1,12,-3,13,-4,14,15,16,17,-5};
    char   cArr2[10] {'h','i','k','m','n','u','w','x','y','z'};
    double fArr2[10] {-1.2,2.2,-3.2,4.2,-5.2,6.2,-7.2,8.2,-9.2,10.2};
    ArrayADT<int>    intArray2(iArr2,10);
    ArrayADT<char>   charArray2(cArr2,9);
    ArrayADT<double> dblArray2(fArr2,10);
    
    intArray1.sort();
    charArray1.sort();
    dblArray1.sort();
    intArray2.sort();
    charArray2.sort();
    dblArray2.sort();
    
    //display the initial arrays
    std::cout << "intArray1 == ";
    intArray1.display();
    std::cout << "intArray2 == ";
    intArray2.display();
    std::cout << std::endl;
    std::cout << "charArray1 == ";
    charArray1.display();
    std::cout << "charArray2 == ";
    charArray2.display();
    std::cout << std::endl;
    std::cout << "dblArray1 == ";
    dblArray1.display();
    std::cout << "dblArray2 == ";
    dblArray2.display();
    std::cout << std::endl;
    
    
    intArray1.merge(intArray2);
    charArray1.merge(charArray2);
    dblArray1.merge(dblArray2);

    std::cout << "intArray1 == ";
    intArray1.display();
    std::cout << std::endl;
    std::cout << "charArray1 == ";
    charArray1.display();
    std::cout << std::endl;
    std::cout << "dblArray1 == ";
    dblArray1.display();
    std::cout << std::endl;
}*/


    return 0;

}