//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------

#include "Magazine.h"
#include "Utils.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds{


Magazine::Magazine(){
    
    m_volume=0;
    m_issue=0;
     mediaType(SDDS_CONSOLE);
    
}


//copy constr
Magazine::Magazine(const Magazine& source) {
   operator=(source);
}

//assignment operator
Magazine& Magazine:: operator = (const Magazine& src){
    
    (PubRecord&)* this =src;
    //assignment op  (PubRecord&)* this =src in magazine and book
    
        // shallow copy non-resource variables
        m_volume = src.m_volume;
        m_issue = src.m_issue;
    
    
    
    return *this;
}



char Magazine:: recID()const{
    
 
    return 'M';
}
void Magazine:: checkIn(){
    
    cout <<"Magazines cannot be checked in or out!"<<endl;
}
void Magazine:: checkOut(){
    
     cout <<"Magazines cannot be checked in or out!"<<endl;
    
}



std::istream& Magazine:: read(std::istream& is ){
    char tempN[41];
//    int tempV;
//    int tempI;
    if(mediaType()== SDDS_CONSOLE){
        
    
        cout<< "Magazine Name: " ;
       // is.get(tempN);
        readC(tempN, 40,"Magazine name too long, Enter again: ");
        name(tempN);
        
        
        cout << "Volume: ";
        readN(m_volume, 1, 99,"Invalid Volume number, Enter again: ");
       // m_volume=tempV;
        
        cout<<"Issue: ";
        readN(m_issue, 1, 99,"Invalid Volume number, Enter again: ");
       // m_issue=tempI;
        
        cout<< "Shelf Number: ";
        readShelfNo();
        

        
    }
    else if (mediaType() == SDDS_FILE) {
        int tempS;
       //name:
       is.getline(tempN, 40, '\t');
       name(tempN);
       //volume:
       is >> m_volume;
       is.ignore();
       //issue:
       is >> m_issue;
       is.ignore();
       //shelf no:
       is >> tempS;
       shelfNo(tempS);
       is.ignore();
    }
    

    
    return is;

}

std::ostream& Magazine:: write(std::ostream& os )const {
         
    if(mediaType()== SDDS_CONSOLE){
        os << left << setw(41) << setfill(' ')<< name()<<  "       ";
        os << right<< setw(2)<< setfill('0')<< m_volume;
        os<<"(";
        os << right<< setfill('0')<< setw(2)<<  m_issue;
        os<<")";
        os<< "  "<< shelfNo();
        

                  
    }
    
    if(mediaType()== SDDS_FILE){
        os<<recID();
        os<<name();
        os<<"\t";
        os<<m_volume;
        os<<"\t";
        os<< m_issue;
        os<<"\t";
        os<<shelfNo();
        os<<endl;
        
    }
    
    return os;
     }




}
