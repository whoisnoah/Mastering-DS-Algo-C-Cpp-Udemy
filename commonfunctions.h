 #ifndef _COMMON_FUNCTIONS_HPP_
#define _COMMON_FUNCTIONS_HPP_

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

#endif //_COMMON_FUNCTIONS_HPP_