#include <vector>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <sstream>
#include "tommy.hpp"

tvector::tvector(int i, int j): vec(std::vector<int>(i, j)){ };

tvector::tvector(): vec(std::vector<int>()){};

int tvector::getsize() const{
    return vec.size();
}

int tvector::getValueAtIndex(int j) const{
    return vec.at(j);
}

double tvector::length() const{
    double ret = 0;

    for (int i = 0; i < static_cast<int>(vec.size()); i ++){
        ret += std::pow(vec.at(i), 2);
    }
    ret = std::sqrt(ret);

    return ret; 
}

void tvector::add(int x) {
    vec.push_back(x);
}
// Addition of Two Vectors
tvector tvector::operator+(const tvector& other){
    //handle case where they are the same size and not the same size;
    int size = other.getsize();
    tvector ret;
    for (int i = 0; i < size; i++){
        int val = this->getValueAtIndex(i) + other.getValueAtIndex(i);
        ret.add(val);
    }
    return ret;
}

tvector tvector::operator-(const tvector& other){
    //handle case where they are the same size and not the same size;
    int size = other.getsize();
    tvector ret;
    for (int i = 0; i < size; i++){
        int val = this->getValueAtIndex(i) - other.getValueAtIndex(i);
        ret.add(val);
    }
    return ret;
}

tvector tvector::crossproduct(const tvector & other){
    tvector ret;
    //cross product only works with vectors of 3;
    if (other.getsize() != 3 or this->getsize() != 3){
        throw std::runtime_error("Cannot compute vector cross product of size other than 3.");
    }
    try
    {
    // VALUE OF I:
    double value_one = ((this->getValueAtIndex(1) * other.getValueAtIndex(2)) - (this->getValueAtIndex(2) * other.getValueAtIndex(1)));
    ret.add(value_one);
    // VALUE OF J:
    double value_two = -((this->getValueAtIndex(0) * other.getValueAtIndex(2)) - (this->getValueAtIndex(2) * other.getValueAtIndex(1)));
    ret.add(value_two);
    // VALUE OF K
    double value_three = ((this->getValueAtIndex(0) * other.getValueAtIndex(1)) - (this->getValueAtIndex(1) * other.getValueAtIndex(0)));
    ret.add(value_three);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return ret;
}

// Vector Cross Product
tvector tvector::operator*(const tvector& other){
    tvector ret;
    
}

tvector tvector::operator*(const int other){
    tvector ret;
    for (int i = 0; i < this->getsize(); i++){
        ret.add(this->getValueAtIndex(i) * other);
    }
}

std::ostream& operator<<(std::ostream& os, const tvector& object){
    int size = static_cast<int>(object.getsize());
    os << "{";
    for (int i = 0; i < size; i++){
        if (i != size - 1){
            os << object.getValueAtIndex(i) << " ";
        } else{
            os << object.getValueAtIndex(i) << "}";; 
        }
    }
    return os;
}

