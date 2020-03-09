//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------

#include "Book.h"
#include "Date.h"
#include "Utils.h"

#include <cstring>
#include <iostream>
#include <iomanip>

namespace sdds {

Book::Book(){
    m_id=0;
    m_isb=0;
    mediaType(SDDS_FILE);
}
  

Book::Book(const Book& src){
    
    operator = (src);
    
}


Book& Book:: operator = (const Book& src){
    
    (PubRecord&)* this =src;
   
        
        m_id = 0;
        m_isb = src.m_isb;
    
  



  
    
    return *this;
}
char Book::recID() const{
    
    return 'B';
}

int Book:: memberID() const{
    return m_id;
}

void Book:: checkIn(){
    m_id=0;
    cout<< *this <<" checked in!"<< endl;
}

void Book::checkOut(){
    //ask and check if 5 digit(for memberid)
    Date tday;
   // int tempId;
    cout <<"Entere Member id: ";
    readN(m_id, 10000, 99999,"Invalid Member ID, Enter again: ");
   

    
    bool ok;
        do {
           ok = true;
           cout << "Enter return date: ";
              //cin >> tday;
              m_due.read(cin);
    
            
            if(!m_due){
                m_due.dateStatus();
                cout << "." <<endl;
                ok=false;
            }else{
                if(tday>m_due){
                    cout << "Please enter a future date.";
                    ok =false;
                }else  if((m_due-tday) > 30){
                    cout << "The return date must be earlier than 30 days away from today." <<endl;
                    ok=false;
                }else{
                    ok=true;
                }
            }
            
            
            
        }while(!ok );

    
}

std::istream& Book:: read(std::istream& is ){
    char tempB[41];//tempBookName
   
    int tempID;
   
    if(mediaType()==SDDS_CONSOLE){
        m_id=0;
        cout << "Book Name: " ;
        cin.clear();
        cin.ignore(1000, '\n');
        
        readC(tempB, 40,"Book name too long, Enter again: ");
        name(tempB);
        
        cout << "ISBN: ";
        readL(m_isb, 10000000000, 9999999999999,"Invalid ISBN, Enter again: ");//removed a zero
        
        cout <<"Shelf Number: ";
        readShelfNo();
      
    }else if(mediaType()==SDDS_FILE){
              
        int tempShelf;
        long long tempISB;
        
        is.getline(tempB, 40,'\t');
        name(tempB);
        //is.ignore();
        is >> tempISB;
        is.ignore();
        is >> tempShelf;
        shelfNo(tempShelf);
        is.ignore();
        is>>tempID;
        if(tempID!=0){
            is.get();
            m_due.read(is);
        }
            if(!cin.fail()){
               
               // m_isb=tempI;
                name(tempB);
                shelfNo(tempShelf);
                m_id=tempID;
                m_isb=tempISB;
                
            }
               

     is.get();
    }
    
       return is;
    
}

std::ostream& Book:: write(std::ostream& os )const {
    
    if(mediaType()== SDDS_CONSOLE){
     
        os << left << setw(41) <<setfill(' ') << name();
        os << m_isb << "  ";
        os << shelfNo();
        if(m_id!=0){
            os << " ";
            os<< m_id;
            os << "   ";
            m_due.write(os);
        }
        
        
    }
    
    if(mediaType()==SDDS_FILE){
        os<<recID();
        os<< name();
        os<<"\t";
        os<<m_isb;
        os<<"\t";
        os<<shelfNo();
        os<<"\t";
        os<<m_id;
        if(m_id!=0){
           os<<"\t";
           m_due.write(os);
    
        }
               os<<endl;
    
    }
    
    return os;
}

}
