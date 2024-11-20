#pragma once
#include <vector>

class tvector{
	private:

	std::vector<int> vec;

    public:
	
	int getsize() const;

	double length() const;
	
	void add(int x);

	tvector crossproduct(const tvector & other);
	
	//Overloaded Operations
	tvector operator+(const tvector& other);
	tvector operator-(const tvector& other);
	tvector operator*(const tvector& other);
	tvector operator*(const int other);


	int getValueAtIndex(int j) const;

	tvector(int i, int j);
	tvector();


	
};

std::ostream& operator<<(std::ostream& os, const tvector& object);

