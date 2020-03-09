//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------
#ifndef Magazine_hpp
#define Magazine_hpp
#include <stdio.h>
#include "PubRecord.h"

namespace sdds{


class Magazine:public PubRecord{
    public:
    Magazine();
     Magazine(const Magazine& );
     Magazine& operator = (const Magazine& src);
private:
    virtual char recID() const;//Use this function’s return value to tag the Magazine records in the file. (see the Write function).
    
    virtual void checkIn() ;
    virtual void checkOut();
    int m_volume;//1-99
    int m_issue;
    
 
   
    virtual std::istream& read(std::istream& is = std::cin);
    virtual std::ostream& write(std::ostream& os = std::cout)const;

};


}
#endif /* Magazine_hpp */
