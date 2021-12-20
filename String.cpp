#include "String.h"
#include <iostream>
#include <cstring>

String::String() :
	pointer_(new char[1]),
	size_(0),
	capacity_(1)
{
	pointer_[0] = '\0';
}
String::String(const char* s) :
	size_(std::strlen(s)),
	capacity_(size_ + 1)
{
	pointer_ = new char[capacity_];
	strcpy_s(pointer_, capacity_, s);
}
String::String(const String& other) :
	size_(other.size_),
	capacity_(size_ + 1)
{
	pointer_ = new char[capacity_];
	strcpy_s(pointer_, capacity_, other.pointer_);
}
String::String(String&& other) noexcept :
	size_(other.size_),
	capacity_(size_ + 1),
	pointer_(other.pointer_)
{
	other.size_ = 0;
	other.pointer_ = nullptr;
}
String::String(size_t n, char* c) : 
	size_(n),
	capacity_(size_ + 1),
	pointer_(new char[capacity_])
{
	for (size_t i = 0; i < size_; i++)
		pointer_[i] = c[i];
	pointer_[size_] = '\0';
}
String::~String()
{
	delete[] pointer_;
}

void String::swap(String& other) noexcept {
	std::swap(pointer_, other.pointer_);
	std::swap(size_, other.size_);
	std::swap(capacity_, other.capacity_);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		String temp(other);
		swap(temp);
	}
	return *this;
}
String& String::operator=(String&& other) noexcept
{
	if (this != &other)
		swap(other);
	return *this;
}
String& String::operator=(const char* s)
{
	if (pointer_ != s)
	{
		String temp(s);
		swap(temp);
	}
	return *this;
}

std::size_t String::size() const
{
	return size_;
}

int String::compare(const String& other) const
{
	char* pos = pointer_;
	char* otherPos = other.pointer_;
	while (*pos)
	{
		if (*pos != *otherPos)
			return *pos - *otherPos;
		pos++;
		otherPos++;
	}
	return *pos - *otherPos;
}

char& String::operator[](size_t pos) const
{
	return *(pointer_ + pos);
}
std::ostream& operator<<(std::ostream& out, const String& string)
{
	return out << string.pointer_;
}
