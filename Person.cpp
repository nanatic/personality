#include "Person.h"
#include <iostream>

template <class S>
Person<S>::Person(const S& name, const S& surname, const S& year) {
	int countOfInvalids = 0;
	countOfInvalids += isValidSurname(surname);
	countOfInvalids += isValidName(name);
	countOfInvalids += isValidAge(year);
	if (countOfInvalids > 0) {
			throw std::invalid_argument("Invalid personality information");
	}
	else {
		name_ = name;
		surname_ = surname;
		year_ = year;
	}
}

template <class S>
Person<S>& Person<S>:: operator = (const Person<S>& person)
{ 
	name_ = person.name_;
	surname_ = person.surname_;
	year_ = person.year_;
	return *this; 
}

template<class S>
bool Person<S>::isValidSurname(const S& str)
{
	int length = str.size();
	if (length > MAX_SURNAME_LENGTH || length < MIN_SURNAME_LENGTH)
		return false;
	for (int i = 0; i < length; i++) {
		if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
			return false;
	}
	return true;
}


template<class S>
bool Person<S>::isValidName(const S& str)
{
	int length = str.size();
	if (length > MAX_NAME_LENGTH || length < MIN_NAME_LENGTH)
		return false;
	for (int i = 0; i < length; i++) {
		if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
			return false;
	}
	return true;
}


template<class S>
bool Person<S>::isValidAge(const S& str)
{
	int length = str.length();
	if (length != YEAR_SIZE)
		return false;
	for (int i = 0; i < length; i++) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return false;
	}
	return true;
}

template <class S>
std::ostream& operator<<(std::ostream& out, const Person<S>& person)
{
	return out << person.surname_ << ' ' << person.name_ << ' ' << person.year_ << '\n';
}

