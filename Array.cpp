#include "Array.h"
#include "String.cpp"
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
enum Keys {
    SURNAME,
    NAME,
    YEAR
};
template <class P>
void Array<P>::sortArray(Keys key) {
    for (int border = 1; border < this.length_; border++)
    {
        Array* step = this.array_[border];
        int into = border - 1;
        bool greaterThanStep;
        switch (key)
        {
        case Keys::SURNAME:
            greaterThanStep = ((this.array_[into]->getSurname()).compare(step->getSurname()) > 0);
            break;
        case Keys::NAME:
            greaterThanStep = ((this.array_[into]->getName()).compare(step->getName()) > 0);
            break;
        case Keys::YEAR:
            greaterThanStep = ((this.array_[into]->getYear()).compare(step->getYear()) > 0);
            break;
        default:
            throw std::invalid_argument("Mishanding");
        }

        while (into >= 0 && greaterThanStep)
        {
            this.array_[into + 1] = this.array_[into];
            into--;
            if (into >= 0)
            {
                switch (key)
                {
                case Keys::SURNAME:
                    greaterThanStep = ((this.array_[into]->getSurname()).compare(step->getSurname()) > 0);
                    break;
                case Keys::NAME:
                    greaterThanStep = ((this.array_[into]->getName()).compare(step->getName()) > 0);
                    break;
                case Keys::YEAR:
                    greaterThanStep = ((this.array_[into]->getYear()).compare(step->getYear()) > 0);
                    break;
                }
            }
        }
        this.array_[++into] = step;
    }
}
