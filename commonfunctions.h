 #ifndef _COMMON_FUNCTIONS_HPP_
#define _COMMON_FUNCTIONS_HPP_

#include <iostream>
#include <sstream>

//------------------------------------------------------------------------------
// userIntInput() gets a user input from console, validates the input as an int
// and returns the validated integer. Input is required again if not valid
//------------------------------------------------------------------------------
int userIntInput(){
    
    int selection {-1};
    int checkInt {};
    bool quit {false};
    
    std::string userInput {};
     
    do {
        std::cin >> userInput;
        std::istringstream validate {userInput};
        
        if (validate >> checkInt){
            selection = checkInt;
            quit = true;
        }
        else
            std::cout << "That's not a number. Try Again: ";    
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } while (!quit);
    
    return selection;    
}

//------------------------------------------------------------------------------
// userCharInput() gets a user input from console, validates the input as an int
// and returns the validated integer. Input is required again if not valid
//------------------------------------------------------------------------------
char userCharInput(){
    
    char selection {'\0'};
    char checkChar {};
    bool quit {false};
    
    std::string userInput {};
     
    do {
        std::cin >> userInput;
        std::istringstream validate {userInput};
        
        if (validate >> checkChar){
            selection = checkChar;
            quit = true;
        }
        else
            std::cout << "That's not a character. Try Again: ";    
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } while (!quit);
    
    return selection;    
}

//------------------------------------------------------------------------------
// userIntInput() gets a user input from console, validates the input as an int
// and returns the validated integer. Input is required again if not valid
//------------------------------------------------------------------------------
double userDblInput(){
    
    double selection {0.0};
    double checkDouble {};
    bool quit {false};
    
    std::string userInput {};
     
    do {
        std::cin >> userInput;
        std::istringstream validate {userInput};
        
        if (validate >> checkDouble){
            selection = checkDouble;
            quit = true;
        }
        else
            std::cout << "That's not a number. Try Again: ";    
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } while (!quit);
    
    return selection;    
}


//------------------------------------------------------------------------------
// userIntInput() prompts the user to hit enter to continue the program and
// waits for input
//------------------------------------------------------------------------------
void getkey(){
    std::cout << "Press Enter to continue....";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
}

#endif //_COMMON_FUNCTIONS_HPP_