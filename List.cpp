#include "List.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions

using namespace std;


class List::Node //self-referential Node class
{
	public:
	   int data = 0;
	   Node* link = nullptr;
	   //link is a data member which is a pointer 
	   //to an object of the same type (i.e. Node)
	
	};//end Node class definition (can only be seen by the List class)


List::~List()
{
    while(num_elements > 0)
      remove(1);
}
	
int List::size()
 {
    return num_elements;
 }

void List::insert(int val, int k)
{
	if (k < 1 or k > num_elements +1) //if the location is invalid
	     throw out_of_range("List::insert("+to_string(val)+", " +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements+1)+")");//throw an "out_of_range" exception
	
	
	Node* newPtr = new Node{val};
	
	if(k == 1)
	{
	  newPtr->link = frontPtr;
	  frontPtr = newPtr;
	 }
	else
	 {  
	
	  Node* tmpPtr = frontPtr;
	  int loc = 1; 
	  
	    while( loc != k-1) //get pointer to (k-1)th node
	     {
		tmpPtr = tmpPtr->link;
		loc++;
	     }
	
	  newPtr->link = tmpPtr->link;
	  tmpPtr->link = newPtr;  
        }//end else

     num_elements++;
 }

void List::remove(int k)
{
	if (k < 1 or k > num_elements)//if the location is invalid 
	     throw out_of_range("List::remove(" +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements)+")");//throw an "out_of_range" exception
	
	Node* delPtr;
	
	if(k == 1)
	{
	  delPtr = frontPtr;
	  frontPtr = frontPtr->link;
	 }
	 else
	 {
	    Node* tmpPtr = frontPtr;
		
	    int loc = 1;
            
            while(loc != k-1)//get pointer to (k-1)th node
	    {
	       tmpPtr = tmpPtr->link;
		loc++;
	    }
	
	    delPtr = tmpPtr->link;
	    tmpPtr->link = delPtr->link;
	  }
	
	delete delPtr;
	num_elements--;
	}
	
	//Implementations of missing operations


int List::getelement(int k)
{
	   Node* iPtr = frontPtr;
	   
	   if(k==1)
	      {
		 return iPtr -> data;
              }
	    else 
	    {
	        for(int i=1; i <k; i++)
	           {
	             iPtr = iPtr -> link;
	           }
	             return iPtr -> data;
	   }
}
void List::empty()
{
	if(size() ==0)
	{
	   cout<<"The list is empty" <<endl;
	}
}

void List::display()
{
	if(size() == 0)
	{
	    cout<<"The list is empty" <<endl;
	}
	else 
	 {
	     Node* iPtr = frontPtr;
	      for(int i = 1; i <= size(); i++)
	        { 	
	           Node* iPtr = frontPtr;

	            if (i == 1)
		        {
				       cout << iPtr -> data <<endl;
	            }
	              else 
			     {
 			       for(int j=1; j < i; j++)
				      {
				         iPtr = iPtr -> link; 
			          } 
				
	                        cout << iPtr -> data <<endl;
	              }
	       }
	}
}
void List::clear()
{
	while(size() != 0)
	{
	   remove(1);
	}
}


	

	
