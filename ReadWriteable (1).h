//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------

#ifndef ReadWriteable_hpp
#define ReadWriteable_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
namespace sdds{

class ReadWriteable{
public:

    virtual std::istream& read(std::istream& is = std::cin)=0;
    virtual std::ostream& write(std::ostream& os = std::cout)const =0 ;
 
    
   
    
    
    
    
    
};

   std::ostream& operator<<(std::ostream& os,const ReadWriteable&);
   std::istream& operator>>(std::istream& is, ReadWriteable&);











}




#endif /* ReadWriteable_hpp */
