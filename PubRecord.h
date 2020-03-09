//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------

#ifndef PubRecord_hpp
#define PubRecord_hpp


#include <stdio.h>
#include "ReadWriteable.h"
#include "Date.h"
namespace sdds{
#define SDDS_CONSOLE 10
#define SDDS_FILE 20


class PubRecord :public ReadWriteable{
    
   
    
   
    char* m_name; // name of Publication
    int m_shelf; //shelf number of publication in lib
    int m_type; //type of media either 10 or 20
    
protected:
    void name(const char*);//setName of publication
    //char* name(const char*) const;
    char* name() const; //getName
    void shelfNo(int); //to set the value of m_shelfNo
       
public:
    PubRecord(); //default constructor
    PubRecord(const PubRecord&); //copy constructor
    //~PubRecord(); //destructor
    virtual ~PubRecord();
    PubRecord& operator = (const PubRecord&); //assignment operator
    void mediaType(int); //set MediaType
    int mediaType()const; //get MediaType
    void  readShelfNo();//set ShelfNo
    int shelfNo()const; //getShelfNo
    int countDigit(int); //countsNumOfDigits
    bool operator==(char) const; 
    bool operator==(const char*) const;
    operator  bool() const;
    int getConsole()const;
    virtual void checkIn() = 0;
    virtual void checkOut() = 0;
    virtual char recID() const=0;
      

   
    
    
};









}



#endif /* PubRecord_hpp */
