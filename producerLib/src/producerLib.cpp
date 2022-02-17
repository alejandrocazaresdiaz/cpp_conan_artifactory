#include <iostream>
#include "producerLib.h"

void producerLib(){
    #ifdef NDEBUG
    std::cout << "Hello World Release!" <<std::endl;
    #else
    std::cout << "Hello World Debug!" <<std::endl;
    #endif
}
