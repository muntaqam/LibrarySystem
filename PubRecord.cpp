//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------
#include "PubRecord.h"
#include <cstring>
#include <iostream>
namespace sdds{

//default constructor
 PubRecord::PubRecord(){
    
     m_name=nullptr;
     m_type=0;
     m_shelf=0;
}

//copy constructor
PubRecord::PubRecord(const PubRecord& src):m_name(nullptr){
    
    operator=(src);
    
}

       
    





PubRecord& PubRecord:: operator = (const PubRecord& src){
    
    //assignment op  (PubRecord&)* this =src
    if (this != &src) {
        // shallow copy non-resource variables
         name(src.m_name);
        m_shelf = src.m_shelf;
        mediaType(src.m_type);
       

    }

  
    
    return *this;
}



void PubRecord::name(const char* name) {
   if (name != nullptr) {
      delete[] m_name;
      long length = strlen(name);
      m_name = new char[length + 1];
      strncpy(m_name, name, length);
       m_name[length] = '\0';
   }
   else {
      m_name = nullptr;
   }
}

//getName
char* PubRecord::name() const{
    
    return m_name;
    
}


//set MediaType

void PubRecord:: mediaType(int x){
    m_type=x;
}

//get MediaType

int PubRecord:: mediaType() const{
    
    return m_type;
}

int PubRecord:: shelfNo()const{
    return m_shelf;
}


// counts the amount of digits in @param number
int PubRecord:: countDigit(int number){
    int counter=0;
       while(number)
      {
             number=number/10;
             counter++;
       }
       return counter;
}

//set shelfNumber
void PubRecord:: readShelfNo(){
    
  
    int input;
    bool ok;
           do {
               ok=true;
               cin >> input;
               if (cin.fail() || input < 99 || input > 999) {
                   cin.clear();
                   cin.ignore(1000, '\n');
                   ok = false;
               }
           }while(!ok && cout << "Invalid Shelf Number, Enter again: ");
    
    m_shelf=input;
    
}

// match w/ recID operator overload==(v1)
bool PubRecord:: operator==(char x) const{
    
    if(x==recID()){
        return true;
    }else{
        return false;
    }
    
}

//isSubstring? operator== overload (v2)
bool PubRecord:: operator==(const char* lilString) const{
    if(strstr(m_name,lilString)==nullptr){
        return false;
    }else{
        return true;
    }
    
    
}
//isEmpty cast for bool
PubRecord::  operator bool() const{
    if(m_name==nullptr){
        return false;
    }else{
        return true;
    }
}


void PubRecord:: shelfNo(int value){
    
    m_shelf=value;
}
//destructor
PubRecord::~PubRecord(){
    delete[] m_name;
}




}
