#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{

 List L1, L2, Listname;
 int ltnum, option, val, lpos, getnum;
 string alter_native, salter_native;
 
 //Do some stuff with L1, L2, ...

 do
 {
	 cout <<"Pick whichlist you want to use" <<endl;
	 cout <<" List L1 (Enter 1) or List2 (Enter 2) " <<endl;
	 cin >> ltnum;
	 
	 if(ltnum == 1)
	 {
		 Listname = L1;
	 }
	 else 
	 {
	     Listname = L2;
	 }
	  
  do 
  {
	   cout << " ******************************************** " <<endl;
	   cout << " 1 To insert to list                          " <<endl;
	   cout << " 2 To remove from list                        " <<endl;
	   cout << " 3 To display the entire list                 " <<endl;
	   cout << " 4 To get a specific element from the list    " <<endl;
	   cout << " 5 To clear list                              " <<endl;
	   cout << " 6 To get size of list                        " <<endl;
	   cout << " 7 Default                                    " <<endl;
	   cout << " ******************************************** " <<endl;
	   
	   cout << "Enter option" <<endl;
	   cin  >> option;
		  switch (option)
		  {
			  case 1: 
			  {
				  cout << "Enter a value to add to the list" <<endl;
				  cin >> val;
				  cout << "Enter the poistion from where you want the value to be entered in the list " <<endl;
				  cin >> lpos;
				  Listname.insert(val, lpos);
				  break;
			  } //end of case 1
			   
			  case 2:
			  {
				  cout << "Enter the poistion of the value you want to remove from the list " <<endl;
				  cin >> lpos;
				  Listname.remove(lpos);
				  break;
			  }//end of case 2
			  
		      case 3:
		       {
				   Listname.display();
				   break;
			   }//end of case 3
				  
			  case 4:
			  {
				  cout << "Enter the poistion of the value you want " <<endl;
				  cin >> lpos;
				  getnum = Listname.getelement(lpos);
				  cout << getnum <<endl;
				  break;
			   }//end of case 4
			    
			  case 5:
			  {
				 Listname.clear();
				 break; 
			  }//end of case 5
			  
			 case 6:
			 {
				 cout << Listname.size() <<endl;
				 break;
				 
			 }//end of case 6
			 
			case 7:
			{
				Listname.~List();
				break;
			}// end of default case
	   }//end of switch
					  
	 cout <<" Do you want to manipluate this list anymore " <<endl;
	 cout << " Yes or No" <<endl;
	 cin >> salter_native;
  }while (salter_native != "No");
	 cout << " Do you want to manipluate any of the two list anymore " <<endl;
	 cout << " Yes or No" <<endl;
	 cin >> alter_native;
}while(alter_native != "No");
return 0;

}
  

	 
