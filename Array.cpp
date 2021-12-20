#include "Array.h"

template <class P>
Array<P>::Array(const Array<P>& other) : size_(other.size_), array_(size_ == 0 ? nullptr : new P[size_]) {
	for (int i = 0; i < size_; i++) {
		array_[i] = other.array_[i];
	}
}
template <class P>
Array<P>::Array(Array<P>&& other) noexcept : size_(other.size_), array_(other.array_) {
	other.size_ = 0;
	other.array_ = nullptr;
}
template<class P>
Array<P>& Array<P>::operator=(const Array<P>& other)
{
    if (this != &other)
    {
        Array temp(other);
        swap(temp);
    }
    return *this;
}
template<class P>
Array<P>& Array<P>::operator=(Array<P>&& other) noexcept
{
    if (this != &other)
    {
        swap(other);
    }
    return *this;
}

template<class P>
void Array<P>::swap(Array<P>& other) noexcept {
    std::swap(array_, other.array_);
    std::swap(size_, other.size_);
}

template<class P>
P& Array<P>::operator[](std::size_t i)
{
    if (i >= size_)
    {
        throw std::out_of_range("Array: Wrong index");
    }
    return array_[i];
}
