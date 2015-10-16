//Person Implementation File

#include <iostream>
#include "personType.h"

using namespace std;

void personType::print() const
{
	cout<<firstName<<" "<<lastName;
}

void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

string personType::getFirstName()
{
	return firstName;
}

string personType::getLastName()
{
	return lastName;
}

personType::personType(string first, string last) //constructor with parameters
{ 
	firstName = first;
	lastName = last;
}

personType::personType()   //default constructor
{ 
	firstName = "";
	lastName = "";
}

int personType::operator==(personType other)
{
	return (firstName == other.firstName &&
			lastName == other.lastName);
}

int personType::operator!=(personType other)
{
	return (firstName != other.firstName ||
			lastName != other.lastName);
}

ostream& operator<<(ostream& os, const personType &name)
{
	os<<name.firstName<<" "<<name.lastName;
	return os;
}