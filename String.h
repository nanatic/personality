#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
public:
	String();
	String(const char* s);
	String(const String& other);
	String(String&& other) noexcept;
	String(size_t n, char* c);
	~String();

	void swap(String& other) noexcept;
	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;
	String& operator=(const char* s);

	size_t	size() const;
	char& operator[](size_t pos) const;
	int compare(const String& other) const;

	friend std::ostream& operator<<(std::ostream& out, const String& str);

private:
	size_t size_;
	size_t capacity_;
	char* pointer_;
};
#endif
