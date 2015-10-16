
#ifndef person_H
#define person_H
#include <string>

using namespace std;

class personType
{
   friend ostream& operator<<(ostream&, const personType&);
	   // overload stream insertion operator
public:
	void print() const;
	  // Output first name and last name in the form
	  // firstName lastName
	void setName(string first, string last);
	  // set firstName and lastName according to the parameters
	  // firstName = first; lastName = last;
	string getFirstName();
	  // Function to return the first name.
	string getLastName();
	  // Function to return the first name.
	personType(string first, string last);
	  // constructor with parameters
	  // set firstName and lastName according to the parameters
	  // firstName = first; lastName = last;
  	personType(); 
  	 // default constructor;
  	 // intialize firstName and lastName to empty string
  	 // firstName = ""; lastName = "";

	  //overload operators for comparison
	int operator==(personType);
	int operator!=(personType);

private:
	string firstName; // store first name
	string lastName;  // store last name
};

#endif 