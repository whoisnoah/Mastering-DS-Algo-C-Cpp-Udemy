#include "..\\commonfunctions.h"
#include "strings.hpp"


int main() {
    
//------------------------------------------------------------------------------
// print_ascii_table()
//------------------------------------------------------------------------------
/*{    
    print_ascii_table();
    
    getkey();
}*/


//------------------------------------------------------------------------------
// string_length(char* str) returns the length of the string by counting chars
// until '\0' delimiter is read. The cstring header has a function that does this 
// std::size_t strlen(const char* str);
//------------------------------------------------------------------------------
{
    char str1[] = "This string is 33 characters long";
    char str2[] = "0123456789";
    
    std::cout << "\"" << str1 << "\" is " << string_length(str1) << " characters long\n";
    std::cout << "\"" << str2 << "\" is " << string_length(str2) << " characters long\n";
    
    std::cout << std::endl;
    getkey();
}

//------------------------------------------------------------------------------
// string_to_upper(char* str)
//------------------------------------------------------------------------------
{
    char str1[] = "This Is String One";
    char str2[] = "This Is String 2";

    std::cout << "str1 is     \"" << str1 << "\"\n";
    std::cout << "str2 is     \"" << str2 << "\"\n";
    
    string_to_upper(str1);
    string_to_upper(str2);

    std::cout << "now str1 is \"" << str1 << "\"\n";
    std::cout << "now str2 is \"" << str2 << "\"\n";

    std::cout << std::endl;
    getkey();
}    

//------------------------------------------------------------------------------
// string_to_lower(char* str)
//------------------------------------------------------------------------------
{
    char str1[] = "This Is String One";
    char str2[] = "This Is String 2";

    std::cout << "str1 is     \"" << str1 << "\"\n";
    std::cout << "str2 is     \"" << str2 << "\"\n";
    
    string_to_lower(str1);
    string_to_lower(str2);

    std::cout << "now str1 is \"" << str1 << "\"\n";
    std::cout << "now str2 is \"" << str2 << "\"\n";

    std::cout << std::endl;
    getkey();
}    

//------------------------------------------------------------------------------
// string_count_words(const char* str)
//------------------------------------------------------------------------------
{
    char str1[] = "This Is String One";
    char str2[] = "This Is String 2";
    char str3[] = "     This Is String 3";
    char str4[] = "This Is String 4     ";
    char str5[] = "                     ";

    std::cout << "str1 is  \"" << str1 << "\"\n";
    std::cout << "str2 is  \"" << str2 << "\"\n";
    std::cout << "str3 is  \"" << str3 << "\"\n";
    std::cout << "str4 is  \"" << str4 << "\"\n";
    std::cout << "str5 is  \"" << str5 << "\"\n";


    std::cout << "str1 has " << string_count_words(str1) << " words in it\n";
    std::cout << "str2 has " << string_count_words(str2) << " words in it\n";
    std::cout << "str3 has " << string_count_words(str3) << " words in it\n";
    std::cout << "str4 has " << string_count_words(str4) << " words in it\n";
    std::cout << "str5 has " << string_count_words(str5) << " words in it\n";
    
    std::cout << std::endl;
    getkey();
}    

//------------------------------------------------------------------------------
// string_validate_alphanum(const char* str)
//------------------------------------------------------------------------------
{
    char str1[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str2[] = "abcdefghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str3[] = "ABCD!!!";

    std::cout << "str1 is \"" << str1 << "\"\n";
    std::cout << "str2 is \"" << str2 << "\"\n";
    std::cout << "str3 is \"" << str3 << "\"\n";
    std::cout << std::boolalpha;
    std::cout << "Is str1 alphanumeric?:  " << string_validate_alphanum(str1) << "\n";
    std::cout << "Is str1 alphanumeric?:  " << string_validate_alphanum(str2) << "\n";
    std::cout << "Is str1 alphanumeric?:  " << string_validate_alphanum(str3) << "\n";

    std::cout << std::endl;
    getkey();
}    

//------------------------------------------------------------------------------
// string_reverse(char* str)
//------------------------------------------------------------------------------
{
    char str1[] = "This Is String One";
    char str2[] = "This Is String 2";

    std::cout << "str1 is     \"" << str1 << "\"\n";
    std::cout << "str2 is     \"" << str2 << "\"\n";
    string_reverse(str1);
    string_reverse(str2);
    std::cout << "now str1 is \"" << str1 << "\"\n";
    std::cout << "now str2 is \"" << str2 << "\"\n";
    
    std::cout << std::endl;
    getkey();
}    

//------------------------------------------------------------------------------
// string_compare(char* str1, char* str2)
//------------------------------------------------------------------------------
{
    char str1[] = "this is an equivalent string";
    char str2[] = "this is not an equivalent string";
    char str3[] = "this is an equivalent string";
    char str4[] = "this is not an equivalent string also";

    std::cout << "str1 is \"" << str1 << "\"\n";
    std::cout << "str2 is \"" << str2 << "\"\n";
    std::cout << "str3 is \"" << str3 << "\"\n";
    std::cout << "str4 is \"" << str4 << "\"\n";

    std::cout << "Is str1 == str2?:  " << string_compare(str1,str2) << "\n";
    std::cout << "Is str1 == str3?:  " << string_compare(str1,str3) << "\n";
    std::cout << "Is str2 == str3?:  " << string_compare(str2,str3) << "\n";
    std::cout << "Is str2 == str4?:  " << string_compare(str2,str4) << "\n";
    
    std::cout << std::endl;
    getkey();
}

    
//------------------------------------------------------------------------------
// remove_spaces(char* str1)
//------------------------------------------------------------------------------
{
    char str1[] = "This Is String One";
    char str2[] = "This Is String 2";

    std::cout << "str1 is     \"" << str1 << "\"\n";
    std::cout << "str2 is     \"" << str2 << "\"\n";
    
    string_removes_spaces(str1);
    string_removes_spaces(str2);

    std::cout << "now str1 is \"" << str1 << "\"\n";
    std::cout << "now str2 is \"" << str2 << "\"\n";

    std::cout << std::endl;
    getkey();
}



//------------------------------------------------------------------------------
// string_ispalindrome(char* str1)
//------------------------------------------------------------------------------
{
    char str1[] = "kayak";
    char str2[] = "no lemon no melon";
    char str3[] = "palindrome";

    std::cout << "str1 is \"" << str1 << "\"\n";
    std::cout << "str2 is \"" << str2 << "\"\n";
    std::cout << "str3 is \"" << str3 << "\"\n";

    std::cout << "Is str1 a palindrome?:  " << string_ispalindrome(str1) << "\n";
    std::cout << "Is str2 a palindrome?:  " << string_ispalindrome(str2) << "\n";
    std::cout << "Is str3 a palindrome?:  " << string_ispalindrome(str3) << "\n";
        
    std::cout << std::endl;
    getkey();
}

//------------------------------------------------------------------------------
//string_find_duplicates(char* str) 
//------------------------------------------------------------------------------
{
    char str1[] = "abcdefghijklmnopqrstuvwxyzaaaaaa~!@#$%^&*()_+0123456789ABCDEFGHIJKLMNOPQRSTUV";
    char str2[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUV";
    
    std::cout << "str1 is \"" << str1 << "\"\n";
    std::cout << "str2 is \"" << str2 << "\"\n";
            
    string_find_duplicates(str1);
    std::cout << std::endl;
    string_find_duplicates(str2);
    std::cout << std::endl;

    std::cout << std::endl;
    getkey();
}        


//------------------------------------------------------------------------------
// print_cctypes()
//------------------------------------------------------------------------------
{
    print_cctypes();
    
    std::cout << std::endl;
    getkey();
}


    return 0;
    
}