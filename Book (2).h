//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------

#ifndef Book_hpp
#define Book_hpp
#include <stdio.h>
#include "PubRecord.h"
//add date
namespace sdds{
class Book:public PubRecord{
    

private:
    long long  m_isb; // ISBN number
    int m_id; //borrower’s member ship id
    Date m_due; //due date
    
  public:
  
    Book();//constructor
    Book(const Book& src); //copy constr
    Book&  operator = (const Book& src);
    virtual char recID() const; //returns B
    int memberID() const; //This function returns the member id
    void checkIn();
    void  checkOut();
     virtual std::istream& read(std::istream& is = std::cin);
      virtual std::ostream& write(std::ostream& os = std::cout)const  ;
    
};
}
#endif /* Book_hpp */
