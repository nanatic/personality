#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template <class P>
class Array
{
public:
	Array():size_(0), array_(nullptr) {}
	Array(size_t size) : size_(size), array_(size == 0 ? nullptr : new P[size_]){}
	Array(const Array& other);
	Array(Array&& other) noexcept;
	~Array() { delete[]array_; }

	Array& operator=(const Array& other);     
	Array& operator=(Array&& other) noexcept;  

	P& operator[](std::size_t i);
	void swap(Array& other) noexcept;

	size_t getSize() const { return size_; }
private:
	static const int MULTIPLIER = 2;
	size_t size_;
	size_t length_;
	P* array_;
};
#endif
