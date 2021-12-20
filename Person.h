#ifndef PERSON_H
#define PERSON_H

template <class S>
class Person
{
public:
	Person(): surname_(""), name_(""), year_(""){}
	Person(const S& name, const S& surname, const S& year);
	Person(const Person& person) : name_(person.name_), surname_(person.surname_), year_(person.year_){}
	Person& operator = (const Person& person);
	~Person() = default;

	const S& getName() { return name_; }
	const S& getSurname() { return surname_; }
	const S& getYear() { return year_; }
	static bool isValidName(const S& str);
	static bool isValidSurname(const S& str);
	static bool isValidAge(const S& str);
	friend std::ostream& operator<<(std::ostream& out, const Person<S>& person);
	
private:
	static const size_t MAX_SURNAME_LENGTH = 20;
	static const size_t MIN_SURNAME_LENGTH = 3;
	static const size_t MAX_NAME_LENGTH = 10;
	static const size_t MIN_NAME_LENGTH = 2;
	static const size_t YEAR_SIZE = 4;
	S surname_;
	S name_;
	S year_;
};
#endif
