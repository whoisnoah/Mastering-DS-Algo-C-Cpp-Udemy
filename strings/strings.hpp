#ifndef _CSTRINGS_HPP_
#define _CSTRINGS_HPP_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>


//------------------------------------------------------------------------------
// print_ascii_table() prints out the ascii table for latin characters and
// shows the hex key and decimal equivalent
//------------------------------------------------------------------------------
void print_ascii_table(){
    
    char ascii {};
    std::cout << std::setw(15) << std::left << "ASCII (Hex)"
              << std::setw(15) << std::left << "ASCII (Dec)"
              << "Character" << std::endl; 
    
    for (int i{0x20}; i < 0x7f; ++i){
        ascii = i;
        std::cout << std::setw(15) << std::left << std::hex << i
                  << std::setw(15) << std::left << std::dec << i << ascii << "\n"; 
    }
    
    std::cout << std::endl;
}

//------------------------------------------------------------------------------
// string_length(char* str) returns the length of the string by counting chars
// until '\0' delimiter is read. The cstring header has a function that does this 
// std::size_t strlen(const char* str);
//------------------------------------------------------------------------------
std::size_t string_length(const char* str){
    
    std::size_t len {0};
    
    while (str[len] != '\0'){
        len++;
    }
    return len;
    
}

//------------------------------------------------------------------------------
// string_to_upper(char* str) converts a lowercase string to an uppercase string
// by checking the ascii value of each character, and subtracting 0x20 if 
// it is lowercase
// the cctype header has a function that converts a single characer to
// uppercase | int std::toupper(int ch);
//------------------------------------------------------------------------------
void string_to_upper(char* str){
    
    std::size_t len {0};
    
    while (str[len] != '\0'){
        
        if (str[len] > 0x60 && str[len] < 0x7b)
            str[len] -= 0x20;
            
//        str[len] = std::toupper(str[len]);

        len++;
    }   
}


//------------------------------------------------------------------------------
// string_to_lower(char* str) converts an uppercase string to a lowercase string
// by checking the ascii value of each character, and adding 0x20 if 
// it is uppercase
// the cctype header has a function that converts a single characer to
// uppercase | int std::tolower(int ch) 
//------------------------------------------------------------------------------
void string_to_lower(char* str){
    
    std::size_t len {0};
    
    while (str[len] != '\0'){
        
        if (str[len] > 0x40 && str[len] < 0x5b)
            str[len] += 0x20;
        
//        str[len] = std::tolower(str[len]);

        len++;
    }   
}


//------------------------------------------------------------------------------
// string_count_words(char* str) returns the number of words in a string by counting
// the number of spaces in the string  (consecutive spaces in a row count as 1)
// std::size_t strlen(const char* str);
//------------------------------------------------------------------------------
int string_count_words(const char* str){
    
    int words {0}, len{0};   
    
    while (str[len] != '\0'){
        //once a there is a space (or terminating character) after the first char
        //is found, count as a word
        if (str[len] != ' ' && (str[len + 1] == ' ' ||str[len + 1] == '\0'))
            words++;
        
        len++;
    }
    
    return words;
}

//------------------------------------------------------------------------------
// string_validate_alphanum(const char* str) checks that the string only 
// contains alphanumeric values and returns true/false
// the cctype header has a function that checks if a character is alphanumeric
// uppercase | int std::isalnum(int ch) 
//------------------------------------------------------------------------------
bool string_validate_alphanum(const char* str){
    
    //ascii numbers are 0x30 to 0x39
    //ascii uppercase letters are 0x41 to 0x5a
    //ascii lowercase letters are 0x61 to 0x7a
    int len {0};
    
    while (str[len] != '\0'){
        if (str[len] < 0x30)
            return false;
        if (str[len] > 0x39 && str[len] < 0x41)
            return false;
        if (str[len] > 0x5a && str[len] < 0x61)
            return false;
        if (str[len] > 0x7a)
            return false;
        
        len++;
    }
    
    return true;
}

//------------------------------------------------------------------------------
// string_reverse(char* str) reverses the contents of a string by creating a new
// temporary string, then assigning the values of the new string back to the
// original string
//------------------------------------------------------------------------------
void string_reverse(char* str){
    
    int len {0};
    len = string_length(str);
    
    char* temp = new char[len+1];
    temp[len] = '\0';
    
    for (int i {0}; i < len; ++i)
        temp[i] = str[len-i-1];

    for (int i {0}; i < len; ++i)
        str[i] = temp[i];
        
    temp = nullptr;
    delete [] temp;
}

//------------------------------------------------------------------------------
// string_compare(char* str1, char* str2) checks if the contents of two strings
// are equal. Does this by comparing string length, and if equal, checks that 
// each character is equal. Returns -1, 0, or 1, if str1 is <,=,or>, that str2
// The cstring header has a function that does this 
// int strcmp( const char *lhs, const char *rhs )
//------------------------------------------------------------------------------
int string_compare(char* str1, char* str2){
    
    std::size_t len1 {0}, len2 {0}, len3 {0};
    
    
    len1 = string_length(str1);
    len2 = string_length(str2);
    
    if(len1 < len2)
        len3 = len1;
    else
        len3 = len2;
    
    for (size_t i {0}; i < len3; ++i){
        if (str1[i] != str2[i]){ 
            if(str1[i] < str2[i])
                return -1;
            else
                return 1;
        }
    }
    
    
    if(len1 < len2)
        return -1;
    else if (len1 > len2)
        return 1;
    else
        return 0;
}

//------------------------------------------------------------------------------
// remove_spaces(char* str1) removes any spaces in a string by created a new
// temp string made of all non-space characters of the original string
// and copies the values back into the original string
//------------------------------------------------------------------------------
void string_removes_spaces(char* str){
    
    int len {0}, spaces {0}, newLen {0};
    len = string_length(str);
    
    for (int i {0}; i < len; ++i)
        if (str[i] == ' ')
            ++spaces;
            
    newLen = len-spaces;
    char* temp = new char[newLen];
    
    int j {0};
    for (int i {0}; i < len; ++i)
        if (str[i] != ' ')
            temp[j++] = str[i];
    
    for (int i {0}; i < newLen; ++i)
        str[i] = temp[i];
        
    str[newLen] = '\0';
        
    temp = nullptr;
    delete [] temp;
}

//------------------------------------------------------------------------------
// string_ispalindrome(char* str1) checks if a string is a
// palindrome by creating two new temp strings with any spaces removed, and 
// reverses one of them. Then compare the two new strings, if they are equal,
// the original string is a palindrome
//------------------------------------------------------------------------------
bool string_ispalindrome(char* str){
    
    size_t len {0};
    len = string_length(str);
    
    bool ispally {false};
    
    char* temp1 = new char[len+1];
    temp1[len] = '\0';
    char* temp2 = new char[len+1];
    temp2[len] = '\0';
    
    for (size_t i {0}; i < len; ++i){
        temp1[i] = str[len-i-1];
        temp2[i] = str[i];
    }
    
    string_removes_spaces(temp1);
    string_removes_spaces(temp2);
        
    if (string_compare(temp1, temp2) == 0)
        ispally = true;

    temp1 = nullptr;
    delete [] temp1;
    temp2 = nullptr;
    delete [] temp2;

    return ispally;
}

//------------------------------------------------------------------------------
// string_find_duplicates(char* str) finds and prints any duplicate values in a
// string by using ascii math and a hashing table. 
//------------------------------------------------------------------------------
bool string_find_duplicates(char* str){

    size_t len {0};
    int charcount[95];
    char duplicate {'\0'};
    bool found {false};
    
     for (int i {0}; i < 95; i++){
        charcount[i] = 0;
    }
    
    while (str[len] != '\0'){
        ++charcount[str[len]-0x20];
        ++len;
    }
    for (int i {0}; i < 95; i++){
        if (charcount[i] > 1){
            found = true;
            duplicate = i + 0x20;
            std::cout << "Character '" << duplicate << "' i is in the string " << charcount[i] << " times\n";
        }
    }
    
    if(!found){
        std::cout << "There are no duplicates in the string";
        return false;
    }
    
    return true;
    

}


//------------------------------------------------------------------------------
// print_cctypes() prints out the number of each character type in the cctype
// header from the ascii table
//------------------------------------------------------------------------------
void print_cctypes(){
        
    int j1{0},j2{0},j3{0},j4{0},j5{0},j6{0},j7{0},j8{0},j9{0},j10{0},j11{0},j12{0};
    char map[12][100];
    
   
    for (int i{0x00}; i <= 0x7f; ++i){
        //checks if a character is alphanumeric
        if (std::isalnum(i)){
            map[0][j1++] = i;
        }
        //checks if a character is alphabetic
        if (std::isalpha(i)){
            map[1][j2++] = i;
        }
        //checks if a character is lowercase
        if (std::islower(i)){
            map[2][j3++] = i;
        }
        //checks if a character is an uppercase character
        if (std::isupper(i)){
            map[3][j4++] = i;
        }
        //checks if a character is a digit
        if (std::isdigit(i)){
            map[4][j5++] = i;
        }
        //checks if a character is a hexadecimal character
        if (std::isxdigit(i)){
            map[5][j6++] = i;
        }
        //checks if a character is a control character
        if (std::iscntrl(i)){
            map[6][j7++] = i;
        }
        //checks if a character is a graphical character
        if (std::isgraph(i)){
            map[7][j8++] = i;
        }
        //checks if a character is a space character (c++11
        if (std::isspace(i)){
            map[8][j9++] = i;
        }
        //checks if a character is a blank character
        if (std::isblank(i)){
            map[9][j10++] = i;
        }
        //checks if a character is a printing character
        if (std::isprint(i)){
            map[10][j11++] = i;
        }
        //checks if a character is a punctuation character
        if (std::ispunct(i)){
            map[11][j12++] = i;
        }

    }
    
    map[0][j1] = '\0';
    map[1][j2] = '\0';
    map[2][j3] = '\0';
    map[3][j4] = '\0';
    map[4][j5] = '\0';
    map[5][j6] = '\0';
    map[6][j7] = '\0';
    map[7][j8] = '\0';
    map[8][j9] = '\0';
    map[9][j10] = '\0';
    map[10][j11] = '\0';
    map[11][j12] = '\0';
    
    std::cout << "There are " << std::setw(2) << j1  << " \"isalnum \" characters in the ascii table " << map[0] << "\n";
    std::cout << "There are " << std::setw(2) << j2  << " \"isalpha \" characters in the ascii table " << map[1] << "\n";
    std::cout << "There are " << std::setw(2) << j3  << " \"islower \" characters in the ascii table " << map[2] << "\n";
    std::cout << "There are " << std::setw(2) << j4  << " \"isupper \" characters in the ascii table " << map[3] << "\n";
    std::cout << "There are " << std::setw(2) << j5  << " \"isdigit \" characters in the ascii table " << map[4] << "\n";
    std::cout << "There are " << std::setw(2) << j6  << " \"isxdigit\" characters in the ascii table " << map[5] << "\n";
    std::cout << "There are " << std::setw(2) << j7  << " \"iscntrl \" characters in the ascii table " << "\n";
    std::cout << "There are " << std::setw(2) << j8  << " \"isgraph \" characters in the ascii table " << map[7] << "\n";
    std::cout << "There are " << std::setw(2) << j9  << " \"isspace \" characters in the ascii table " << "\n";
    std::cout << "There are " << std::setw(2) << j10 << " \"isblank \" characters in the ascii table " << "\n";
    std::cout << "There are " << std::setw(2) << j11 << " \"isprint \" characters in the ascii table " << map[10] << "\n";
    std::cout << "There are " << std::setw(2) << j12 << " \"ispunct \" characters in the ascii table " << map[11] << "\n";
}

#endif //_CSTRINGS_HPP_